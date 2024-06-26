/*============================================================================
This C source fragment is part of the SoftFloat IEC/IEEE Floating-point
Arithmetic Package, Release 2b.

Written by John R. Hauser.  This work was made possible in part by the
International Computer Science Institute, located at Suite 600, 1947 Center
Street, Berkeley, California 94704.  Funding was partially provided by the
National Science Foundation under grant MIP-9311980.  The original version
of this code was written as part of a project to build a fixed-point vector
processor in collaboration with the University of California at Berkeley,
overseen by Profs. Nelson Morgan and John Wawrzynek.  More information
is available through the Web page `http://www.cs.berkeley.edu/~jhauser/
arithmetic/SoftFloat.html'.

THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has
been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES
RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS
AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ALL LOSSES,
COSTS, OR OTHER PROBLEMS THEY INCUR DUE TO THE SOFTWARE, AND WHO FURTHERMORE
EFFECTIVELY INDEMNIFY JOHN HAUSER AND THE INTERNATIONAL COMPUTER SCIENCE
INSTITUTE (possibly via similar legal notice) AGAINST ALL LOSSES, COSTS, OR
OTHER PROBLEMS INCURRED BY THEIR CUSTOMERS AND CLIENTS DUE TO THE SOFTWARE.

Derivative works are acceptable, even for commercial purposes, so long as
(1) the source code for the derivative work includes prominent notice that
the work is derivative, and (2) the source code includes prominent notice with
these four paragraphs for those parts of this code that are retained.
=============================================================================*/

/*============================================================================
 * Adapted for Bochs (x86 achitecture simulator) by
 *            Stanislav Shwartsman [sshwarts at sourceforge net]
 * ==========================================================================*/

#ifndef _SOFTFLOAT_MACROS_H_
#define _SOFTFLOAT_MACROS_H_

/*----------------------------------------------------------------------------
| Shifts `a' right by the number of bits given in `count'.  If any nonzero
| bits are shifted off, they are ``jammed'' into the least significant bit of
| the result by setting the least significant bit to 1.  The value of `count'
| can be arbitrarily large; in particular, if `count' is greater than 64, the
| result will be either 0 or 1, depending on whether `a' is zero or nonzero.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE Bit64u shift64RightJamming(Bit64u a, int count)
{
    Bit64u z;

    if (count == 0) {
        z = a;
    }
    else if (count < 64) {
        z = (a>>count) | ((a << ((-count) & 63)) != 0);
    }
    else {
        z = (a != 0);
    }

    return z;
}

/*----------------------------------------------------------------------------
| Shifts the 128-bit value formed by concatenating `a0' and `a1' right by 64
| _plus_ the number of bits given in `count'.  The shifted result is at most
| 64 nonzero bits; this is stored at the location pointed to by `z0Ptr'.  The
| bits shifted off form a second 64-bit result as follows:  The _last_ bit
| shifted off is the most-significant bit of the extra result, and the other
| 63 bits of the extra result are all zero if and only if _all_but_the_last_
| bits shifted off were all zero.  This extra result is stored in the location
| pointed to by `z1Ptr'.  The value of `count' can be arbitrarily large.
|     (This routine makes more sense if `a0' and `a1' are considered to form
| a fixed-point value with binary point between `a0' and `a1'.  This fixed-
| point value is shifted right by the number of bits given in `count', and
| the integer part of the result is returned at the location pointed to by
| `z0Ptr'.  The fractional part of the result may be slightly corrupted as
| described above, and is returned at the location pointed to by `z1Ptr'.)
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void shift64ExtraRightJamming(Bit64u a0, Bit64u a1, int count, Bit64u *z0Ptr, Bit64u *z1Ptr)
{
    Bit64u z0, z1;
    int negCount = (-count) & 63;

    if (count == 0) {
        z1 = a1;
        z0 = a0;
    }
    else if (count < 64) {
        z1 = (a0<<negCount) | (a1 != 0);
        z0 = a0>>count;
    }
    else {
        if (count == 64) {
            z1 = a0 | (a1 != 0);
        }
        else {
            z1 = ((a0 | a1) != 0);
        }
        z0 = 0;
    }
    *z1Ptr = z1;
    *z0Ptr = z0;
}

/*----------------------------------------------------------------------------
| Adds the 128-bit value formed by concatenating `a0' and `a1' to the 128-bit
| value formed by concatenating `b0' and `b1'.  Addition is modulo 2^128, so
| any carry out is lost.  The result is broken into two 64-bit pieces which
| are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void add128(Bit64u a0, Bit64u a1, Bit64u b0, Bit64u b1, Bit64u *z0Ptr, Bit64u *z1Ptr)
{
    Bit64u z1 = a1 + b1;
    *z1Ptr = z1;
    *z0Ptr = a0 + b0 + (z1 < a1);
}

/*----------------------------------------------------------------------------
| Subtracts the 128-bit value formed by concatenating `b0' and `b1' from the
| 128-bit value formed by concatenating `a0' and `a1'.  Subtraction is modulo
| 2^128, so any borrow out (carry out) is lost.  The result is broken into two
| 64-bit pieces which are stored at the locations pointed to by `z0Ptr' and
| `z1Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void
 sub128(Bit64u a0, Bit64u a1, Bit64u b0, Bit64u b1, Bit64u *z0Ptr, Bit64u *z1Ptr)
{
    *z1Ptr = a1 - b1;
    *z0Ptr = a0 - b0 - (a1 < b1);
}

/*----------------------------------------------------------------------------
| Multiplies `a' by `b' to obtain a 128-bit product.  The product is broken
| into two 64-bit pieces which are stored at the locations pointed to by
| `z0Ptr' and `z1Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void mul64To128(Bit64u a, Bit64u b, Bit64u *z0Ptr, Bit64u *z1Ptr)
{
    Bit32u aHigh, aLow, bHigh, bLow;
    Bit64u z0, zMiddleA, zMiddleB, z1;

    aLow = (Bit32u) a;
    aHigh = (Bit32u)(a>>32);
    bLow = (Bit32u) b;
    bHigh = (Bit32u)(b>>32);
    z1 = ((Bit64u) aLow) * bLow;
    zMiddleA = ((Bit64u) aLow) * bHigh;
    zMiddleB = ((Bit64u) aHigh) * bLow;
    z0 = ((Bit64u) aHigh) * bHigh;
    zMiddleA += zMiddleB;
    z0 += (((Bit64u) (zMiddleA < zMiddleB))<<32) + (zMiddleA>>32);
    zMiddleA <<= 32;
    z1 += zMiddleA;
    z0 += (z1 < zMiddleA);
    *z1Ptr = z1;
    *z0Ptr = z0;
}

/*----------------------------------------------------------------------------
| Returns an approximation to the 64-bit integer quotient obtained by dividing
| `b' into the 128-bit value formed by concatenating `a0' and `a1'.  The
| divisor `b' must be at least 2^63.  If q is the exact quotient truncated
| toward zero, the approximation returned lies between q and q + 2 inclusive.
| If the exact quotient q is larger than 64 bits, the maximum positive 64-bit
| unsigned integer is returned.
*----------------------------------------------------------------------------*/

#ifdef USE_estimateDiv128To64
static Bit64u estimateDiv128To64(Bit64u a0, Bit64u a1, Bit64u b)
{
    Bit64u b0, b1;
    Bit64u rem0, rem1, term0, term1;
    Bit64u z;

    if (b <= a0) return BX_CONST64(0xFFFFFFFFFFFFFFFF);
    b0 = b>>32;
    z = (b0<<32 <= a0) ? BX_CONST64(0xFFFFFFFF00000000) : (a0 / b0)<<32;
    mul64To128(b, z, &term0, &term1);
    sub128(a0, a1, term0, term1, &rem0, &rem1);
    while (((Bit64s) rem0) < 0) {
        z -= BX_CONST64(0x100000000);
        b1 = b<<32;
        add128(rem0, rem1, b0, b1, &rem0, &rem1);
    }
    rem0 = (rem0<<32) | (rem1>>32);
    z |= (b0<<32 <= rem0) ? 0xFFFFFFFF : rem0 / b0;
    return z;
}
#endif

static const int countLeadingZeros8[] = {
  8, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*----------------------------------------------------------------------------
| Returns the number of leading 0 bits before the most-significant 1 bit of
| `a'.  If `a' is zero, 32 is returned.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int countLeadingZeros32(Bit32u a)
{
    int shiftCount = 0;
    if (a < 0x10000) {
        shiftCount += 16;
        a <<= 16;
    }
    if (a < 0x1000000) {
        shiftCount += 8;
        a <<= 8;
    }
    shiftCount += countLeadingZeros8[a>>24];
    return shiftCount;
}

/*----------------------------------------------------------------------------
| Returns the number of leading 0 bits before the most-significant 1 bit of
| `a'.  If `a' is zero, 64 is returned.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int countLeadingZeros64(Bit64u a)
{
    int shiftCount = 0;
    if (a < BX_CONST64(0x100000000)) {
        shiftCount += 32;
    }
    else {
        a >>= 32;
    }
    shiftCount += countLeadingZeros32((Bit32u)(a));
    return shiftCount;
}

#ifdef FLOATX80

/*----------------------------------------------------------------------------
| Shifts the 128-bit value formed by concatenating `a0' and `a1' right by the
| number of bits given in `count'.  Any bits shifted off are lost.  The value
| of `count' can be arbitrarily large; in particular, if `count' is greater
| than 128, the result will be 0.  The result is broken into two 64-bit pieces
| which are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void shift128Right(Bit64u a0, Bit64u a1, int count, Bit64u *z0Ptr, Bit64u *z1Ptr)
{
    Bit64u z0, z1;
    int negCount = (-count) & 63;

    if (count == 0) {
        z1 = a1;
        z0 = a0;
    }
    else if (count < 64) {
        z1 = (a0<<negCount) | (a1>>count);
        z0 = a0>>count;
    }
    else {
        z1 = (count < 128) ? (a0>>(count & 63)) : 0;
        z0 = 0;
    }
    *z1Ptr = z1;
    *z0Ptr = z0;
}

/*----------------------------------------------------------------------------
| Shifts the 128-bit value formed by concatenating `a0' and `a1' left by the
| number of bits given in `count'.  Any bits shifted off are lost.  The value
| of `count' must be less than 64.  The result is broken into two 64-bit
| pieces which are stored at the locations pointed to by `z0Ptr' and `z1Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void shortShift128Left(Bit64u a0, Bit64u a1, int count, Bit64u *z0Ptr, Bit64u *z1Ptr)
{
    *z1Ptr = a1<<count;
    *z0Ptr = (count == 0) ? a0 : (a0<<count) | (a1>>((-count) & 63));
}

/*----------------------------------------------------------------------------
| Adds the 192-bit value formed by concatenating `a0', `a1', and `a2' to the
| 192-bit value formed by concatenating `b0', `b1', and `b2'.  Addition is
| modulo 2^192, so any carry out is lost.  The result is broken into three
| 64-bit pieces which are stored at the locations pointed to by `z0Ptr',
| `z1Ptr', and `z2Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void add192(
     Bit64u a0,
     Bit64u a1,
     Bit64u a2,
     Bit64u b0,
     Bit64u b1,
     Bit64u b2,
     Bit64u *z0Ptr,
     Bit64u *z1Ptr,
     Bit64u *z2Ptr
)
{
    Bit64u z0, z1, z2;
    unsigned carry0, carry1;

    z2 = a2 + b2;
    carry1 = (z2 < a2);
    z1 = a1 + b1;
    carry0 = (z1 < a1);
    z0 = a0 + b0;
    z1 += carry1;
    z0 += (z1 < carry1);
    z0 += carry0;
    *z2Ptr = z2;
    *z1Ptr = z1;
    *z0Ptr = z0;
}

/*----------------------------------------------------------------------------
| Returns 1 if the 128-bit value formed by concatenating `a0' and `a1'
| is equal to the 128-bit value formed by concatenating `b0' and `b1'.
| Otherwise, returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int eq128(Bit64u a0, Bit64u a1, Bit64u b0, Bit64u b1)
{
    return (a0 == b0) && (a1 == b1);
}

/*----------------------------------------------------------------------------
| Returns 1 if the 128-bit value formed by concatenating `a0' and `a1' is less
| than or equal to the 128-bit value formed by concatenating `b0' and `b1'.
| Otherwise, returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int le128(Bit64u a0, Bit64u a1, Bit64u b0, Bit64u b1)
{
    return (a0 < b0) || ((a0 == b0) && (a1 <= b1));
}

/*----------------------------------------------------------------------------
| Returns 1 if the 128-bit value formed by concatenating `a0' and `a1' is less
| than the 128-bit value formed by concatenating `b0' and `b1'.  Otherwise,
| returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int lt128(Bit64u a0, Bit64u a1, Bit64u b0, Bit64u b1)
{
    return (a0 < b0) || ((a0 == b0) && (a1 < b1));
}

#endif	/* FLOATX80 */

/*----------------------------------------------------------------------------
| Multiplies the 128-bit value formed by concatenating `a0' and `a1' by
| `b' to obtain a 192-bit product.  The product is broken into three 64-bit
| pieces which are stored at the locations pointed to by `z0Ptr', `z1Ptr', and
| `z2Ptr'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void mul128By64To192(
     Bit64u a0,
     Bit64u a1,
     Bit64u b,
     Bit64u *z0Ptr,
     Bit64u *z1Ptr,
     Bit64u *z2Ptr
)
{
    Bit64u z0, z1, z2, more1;

    mul64To128(a1, b, &z1, &z2);
    mul64To128(a0, b, &z0, &more1);
    add128(z0, more1, 0, z1, &z0, &z1);
    *z2Ptr = z2;
    *z1Ptr = z1;
    *z0Ptr = z0;
}

#ifdef FLOAT128

/*----------------------------------------------------------------------------
| Shifts the 192-bit value formed by concatenating `a0', `a1', and `a2' right
| by 64 _plus_ the number of bits given in `count'.  The shifted result is
| at most 128 nonzero bits; these are broken into two 64-bit pieces which are
| stored at the locations pointed to by `z0Ptr' and `z1Ptr'.  The bits shifted
| off form a third 64-bit result as follows:  The _last_ bit shifted off is
| the most-significant bit of the extra result, and the other 63 bits of the
| extra result are all zero if and only if _all_but_the_last_ bits shifted off
| were all zero.  This extra result is stored in the location pointed to by
| `z2Ptr'.  The value of `count' can be arbitrarily large.
|     (This routine makes more sense if `a0', `a1', and `a2' are considered
| to form a fixed-point value with binary point between `a1' and `a2'.  This
| fixed-point value is shifted right by the number of bits given in `count',
| and the integer part of the result is returned at the locations pointed to
| by `z0Ptr' and `z1Ptr'.  The fractional part of the result may be slightly
| corrupted as described above, and is returned at the location pointed to by
| `z2Ptr'.)
*----------------------------------------------------------------------------*/

BX_CPP_INLINE void shift128ExtraRightJamming(
     Bit64u a0,
     Bit64u a1,
     Bit64u a2,
     int count,
     Bit64u *z0Ptr,
     Bit64u *z1Ptr,
     Bit64u *z2Ptr
)
{
    Bit64u z0, z1, z2;
    int negCount = (-count) & 63;

    if (count == 0) {
        z2 = a2;
        z1 = a1;
        z0 = a0;
    }
    else {
        if (count < 64) {
            z2 = a1<<negCount;
            z1 = (a0<<negCount) | (a1>>count);
            z0 = a0>>count;
        }
        else {
            if (count == 64) {
                z2 = a1;
                z1 = a0;
            }
            else {
                a2 |= a1;
                if (count < 128) {
                    z2 = a0<<negCount;
                    z1 = a0>>(count & 63);
                }
                else {
                    z2 = (count == 128) ? a0 : (a0 != 0);
                    z1 = 0;
                }
            }
            z0 = 0;
        }
        z2 |= (a2 != 0);
    }
    *z2Ptr = z2;
    *z1Ptr = z1;
    *z0Ptr = z0;
}

#endif  /* FLOAT128 */

#endif
