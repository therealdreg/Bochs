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
INSTITUTE (possibly via similar legal warning) AGAINST ALL LOSSES, COSTS, OR
OTHER PROBLEMS INCURRED BY THEIR CUSTOMERS AND CLIENTS DUE TO THE SOFTWARE.

Derivative works are acceptable, even for commercial purposes, so long as
(1) the source code for the derivative work includes prominent notice that
the work is derivative, and (2) the source code includes prominent notice with
these four paragraphs for those parts of this code that are retained.
=============================================================================*/

#ifndef _SOFTFLOAT_SPECIALIZE_H_
#define _SOFTFLOAT_SPECIALIZE_H_

#include "softfloat.h"

/*============================================================================
 * Adapted for Bochs (x86 achitecture simulator) by
 *            Stanislav Shwartsman [sshwarts at sourceforge net]
 * ==========================================================================*/

#define int16_indefinite ((Bit16s)0x8000)
#define int32_indefinite ((Bit32s)0x80000000)
#define int64_indefinite BX_CONST64(0x8000000000000000)

#define uint16_indefinite (0xffff)
#define uint32_indefinite (0xffffffff)
#define uint64_indefinite BX_CONST64(0xffffffffffffffff)

/*----------------------------------------------------------------------------
| Internal canonical NaN format.
*----------------------------------------------------------------------------*/

typedef struct {
    int sign;
    Bit64u hi, lo;
} commonNaNT;

/*----------------------------------------------------------------------------
| Commonly used half-precision floating point constants
*----------------------------------------------------------------------------*/
const float16 float16_negative_inf  = 0xfc00;
const float16 float16_positive_inf  = 0x7c00;
const float16 float16_negative_zero = 0x8000;
const float16 float16_positive_zero = 0x0000;

/*----------------------------------------------------------------------------
| The pattern for a default generated half-precision NaN.
*----------------------------------------------------------------------------*/
const float16 float16_default_nan = 0xFE00;

#define FLOAT16_EXP_BIAS 0xF

/*----------------------------------------------------------------------------
| Packs the sign `zSign', exponent `zExp', and significand `zSig' into a
| single-precision floating-point value, returning the result.  After being
| shifted into the proper positions, the three fields are simply added
| together to form the result.  This means that any integer portion of `zSig'
| will be added into the exponent.  Since a properly normalized significand
| will have an integer portion equal to 1, the `zExp' input should be 1 less
| than the desired result exponent whenever `zSig' is a complete, normalized
| significand.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE float16 packFloat16(int zSign, int zExp, Bit16u zSig)
{
    return (((Bit16u) zSign)<<15) + (((Bit16u) zExp)<<10) + zSig;
}

/*----------------------------------------------------------------------------
| Commonly used single-precision floating point constants
*----------------------------------------------------------------------------*/
const float32 float32_negative_inf  = 0xff800000;
const float32 float32_positive_inf  = 0x7f800000;
const float32 float32_negative_zero = 0x80000000;
const float32 float32_positive_zero = 0x00000000;
const float32 float32_negative_one  = 0xbf800000;
const float32 float32_positive_one  = 0x3f800000;
const float32 float32_max_float     = 0x7f7fffff;
const float32 float32_min_float     = 0xff7fffff;

/*----------------------------------------------------------------------------
| The pattern for a default generated single-precision NaN.
*----------------------------------------------------------------------------*/
const float32 float32_default_nan   = 0xffc00000;

#define FLOAT32_EXP_BIAS 0x7F

/*----------------------------------------------------------------------------
| Packs the sign `zSign', exponent `zExp', and significand `zSig' into a
| single-precision floating-point value, returning the result.  After being
| shifted into the proper positions, the three fields are simply added
| together to form the result.  This means that any integer portion of `zSig'
| will be added into the exponent.  Since a properly normalized significand
| will have an integer portion equal to 1, the `zExp' input should be 1 less
| than the desired result exponent whenever `zSig' is a complete, normalized
| significand.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE float32 packFloat32(int zSign, Bit16s zExp, Bit32u zSig)
{
    return (((Bit32u) zSign)<<31) + (((Bit32u) zExp)<<23) + zSig;
}

/*----------------------------------------------------------------------------
| Commonly used single-precision floating point constants
*----------------------------------------------------------------------------*/
const float64 float64_negative_inf  = BX_CONST64(0xfff0000000000000);
const float64 float64_positive_inf  = BX_CONST64(0x7ff0000000000000);
const float64 float64_negative_zero = BX_CONST64(0x8000000000000000);
const float64 float64_positive_zero = BX_CONST64(0x0000000000000000);
const float64 float64_negative_one  = BX_CONST64(0xbff0000000000000);
const float64 float64_positive_one  = BX_CONST64(0x3ff0000000000000);
const float64 float64_max_float     = BX_CONST64(0x7fefffffffffffff);
const float64 float64_min_float     = BX_CONST64(0xffefffffffffffff);

/*----------------------------------------------------------------------------
| The pattern for a default generated double-precision NaN.
*----------------------------------------------------------------------------*/
const float64 float64_default_nan = BX_CONST64(0xFFF8000000000000);

#define FLOAT64_EXP_BIAS 0x3FF

/*----------------------------------------------------------------------------
| Packs the sign `zSign', exponent `zExp', and significand `zSig' into a
| double-precision floating-point value, returning the result.  After being
| shifted into the proper positions, the three fields are simply added
| together to form the result.  This means that any integer portion of `zSig'
| will be added into the exponent.  Since a properly normalized significand
| will have an integer portion equal to 1, the `zExp' input should be 1 less
| than the desired result exponent whenever `zSig' is a complete, normalized
| significand.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE float64 packFloat64(int zSign, Bit16s zExp, Bit64u zSig)
{
    return (((Bit64u) zSign)<<63) + (((Bit64u) zExp)<<52) + zSig;
}

#ifdef FLOATX80

/*----------------------------------------------------------------------------
| The pattern for a default generated extended double-precision NaN.  The
| `high' and `low' values hold the most- and least-significant bits,
| respectively.
*----------------------------------------------------------------------------*/
#define floatx80_default_nan_exp 0xFFFF
#define floatx80_default_nan_fraction BX_CONST64(0xC000000000000000)

#define floatx80_fraction extractFloatx80Frac
#define floatx80_exp extractFloatx80Exp
#define floatx80_sign extractFloatx80Sign

#define FLOATX80_EXP_BIAS 0x3FFF

/*----------------------------------------------------------------------------
| Returns the fraction bits of the extended double-precision floating-point
| value `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE Bit64u extractFloatx80Frac(floatx80 a)
{
    return a.fraction;
}

/*----------------------------------------------------------------------------
| Returns the exponent bits of the extended double-precision floating-point
| value `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE Bit32s extractFloatx80Exp(floatx80 a)
{
    return a.exp & 0x7FFF;
}

/*----------------------------------------------------------------------------
| Returns the sign bit of the extended double-precision floating-point value
| `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int extractFloatx80Sign(floatx80 a)
{
    return a.exp>>15;
}

/*----------------------------------------------------------------------------
| Packs the sign `zSign', exponent `zExp', and significand `zSig' into an
| extended double-precision floating-point value, returning the result.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE floatx80 packFloatx80(int zSign, Bit32s zExp, Bit64u zSig)
{
    floatx80 z;
    z.fraction = zSig;
    z.exp = (zSign << 15) + zExp;
    return z;
}

/*----------------------------------------------------------------------------
| Returns 1 if the extended double-precision floating-point value `a' is a
| NaN; otherwise returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int floatx80_is_nan(floatx80 a)
{
    return ((a.exp & 0x7FFF) == 0x7FFF) && (Bit64s) (a.fraction<<1);
}

/*----------------------------------------------------------------------------
| Returns 1 if the extended double-precision floating-point value `a' is a
| signaling NaN; otherwise returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int floatx80_is_signaling_nan(floatx80 a)
{
    Bit64u aLow = a.fraction & ~BX_CONST64(0x4000000000000000);
    return ((a.exp & 0x7FFF) == 0x7FFF) &&
            ((Bit64u) (aLow<<1)) && (a.fraction == aLow);
}

/*----------------------------------------------------------------------------
| Returns 1 if the extended double-precision floating-point value `a' is an
| unsupported; otherwise returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int floatx80_is_unsupported(floatx80 a)
{
    return ((a.exp & 0x7FFF) && !(a.fraction & BX_CONST64(0x8000000000000000)));
}

/*----------------------------------------------------------------------------
| Returns the result of converting the extended double-precision floating-
| point NaN `a' to the canonical NaN format. If `a' is a signaling NaN, the
| invalid exception is raised.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE commonNaNT floatx80ToCommonNaN(floatx80 a, float_status_t &status)
{
    commonNaNT z;
    if (floatx80_is_signaling_nan(a)) float_raise(status, float_flag_invalid);
    z.sign = a.exp >> 15;
    z.lo = 0;
    z.hi = a.fraction << 1;
    return z;
}

/*----------------------------------------------------------------------------
| Returns the result of converting the canonical NaN `a' to the extended
| double-precision floating-point format.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE floatx80 commonNaNToFloatx80(commonNaNT a)
{
    floatx80 z;
    z.fraction = BX_CONST64(0xC000000000000000) | (a.hi>>1);
    z.exp = (((Bit16u) a.sign)<<15) | 0x7FFF;
    return z;
}

/*----------------------------------------------------------------------------
| Takes two extended double-precision floating-point values `a' and `b', one
| of which is a NaN, and returns the appropriate NaN result.  If either `a' or
| `b' is a signaling NaN, the invalid exception is raised.
*----------------------------------------------------------------------------*/

floatx80 propagateFloatx80NaN(floatx80 a, floatx80 b, float_status_t &status);

/*----------------------------------------------------------------------------
| Takes extended double-precision floating-point  NaN  `a' and returns the
| appropriate NaN result. If `a' is a signaling NaN, the invalid exception
| is raised.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE floatx80 propagateFloatx80NaN(floatx80 a, float_status_t &status)
{
    if (floatx80_is_signaling_nan(a))
        float_raise(status, float_flag_invalid);

    a.fraction |= BX_CONST64(0xC000000000000000);

    return a;
}

/*----------------------------------------------------------------------------
| The pattern for a default generated extended double-precision NaN.
*----------------------------------------------------------------------------*/
extern const floatx80 floatx80_default_nan;

#endif /* FLOATX80 */

#ifdef FLOAT128

#include "softfloat-macros.h"

/*----------------------------------------------------------------------------
| The pattern for a default generated quadruple-precision NaN. The `high' and
| `low' values hold the most- and least-significant bits, respectively.
*----------------------------------------------------------------------------*/
#define float128_default_nan_hi BX_CONST64(0xFFFF800000000000)
#define float128_default_nan_lo BX_CONST64(0x0000000000000000)

#define float128_exp extractFloat128Exp

/*----------------------------------------------------------------------------
| Returns the least-significant 64 fraction bits of the quadruple-precision
| floating-point value `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE Bit64u extractFloat128Frac1(float128 a)
{
    return a.lo;
}

/*----------------------------------------------------------------------------
| Returns the most-significant 48 fraction bits of the quadruple-precision
| floating-point value `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE Bit64u extractFloat128Frac0(float128 a)
{
    return a.hi & BX_CONST64(0x0000FFFFFFFFFFFF);
}

/*----------------------------------------------------------------------------
| Returns the exponent bits of the quadruple-precision floating-point value
| `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE Bit32s extractFloat128Exp(float128 a)
{
    return ((Bit32s)(a.hi>>48)) & 0x7FFF;
}

/*----------------------------------------------------------------------------
| Returns the sign bit of the quadruple-precision floating-point value `a'.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int extractFloat128Sign(float128 a)
{
    return (int)(a.hi >> 63);
}

/*----------------------------------------------------------------------------
| Packs the sign `zSign', the exponent `zExp', and the significand formed
| by the concatenation of `zSig0' and `zSig1' into a quadruple-precision
| floating-point value, returning the result.  After being shifted into the
| proper positions, the three fields `zSign', `zExp', and `zSig0' are simply
| added together to form the most significant 32 bits of the result.  This
| means that any integer portion of `zSig0' will be added into the exponent.
| Since a properly normalized significand will have an integer portion equal
| to 1, the `zExp' input should be 1 less than the desired result exponent
| whenever `zSig0' and `zSig1' concatenated form a complete, normalized
| significand.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE float128 packFloat128(int zSign, Bit32s zExp, Bit64u zSig0, Bit64u zSig1)
{
    float128 z;
    z.lo = zSig1;
    z.hi = (((Bit64u) zSign)<<63) + (((Bit64u) zExp)<<48) + zSig0;
    return z;
}

/*----------------------------------------------------------------------------
| Packs two 64-bit precision integers into into the quadruple-precision
| floating-point value, returning the result.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE float128 packFloat128(Bit64u zHi, Bit64u zLo)
{
    float128 z;
    z.lo = zLo;
    z.hi = zHi;
    return z;
}

#ifdef _MSC_VER
#define PACK_FLOAT_128(hi,lo) { lo, hi }
#else
#define PACK_FLOAT_128(hi,lo) packFloat128(BX_CONST64(hi),BX_CONST64(lo))
#endif

/*----------------------------------------------------------------------------
| Returns 1 if the quadruple-precision floating-point value `a' is a NaN;
| otherwise returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int float128_is_nan(float128 a)
{
    return (BX_CONST64(0xFFFE000000000000) <= (Bit64u) (a.hi<<1))
        && (a.lo || (a.hi & BX_CONST64(0x0000FFFFFFFFFFFF)));
}

/*----------------------------------------------------------------------------
| Returns 1 if the quadruple-precision floating-point value `a' is a
| signaling NaN; otherwise returns 0.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE int float128_is_signaling_nan(float128 a)
{
    return (((a.hi>>47) & 0xFFFF) == 0xFFFE)
        && (a.lo || (a.hi & BX_CONST64(0x00007FFFFFFFFFFF)));
}

/*----------------------------------------------------------------------------
| Returns the result of converting the quadruple-precision floating-point NaN
| `a' to the canonical NaN format.  If `a' is a signaling NaN, the invalid
| exception is raised.
*----------------------------------------------------------------------------*/

BX_CPP_INLINE commonNaNT float128ToCommonNaN(float128 a, float_status_t &status)
{
    commonNaNT z;
    if (float128_is_signaling_nan(a)) float_raise(status, float_flag_invalid);
    z.sign = (int)(a.hi>>63);
    shortShift128Left(a.hi, a.lo, 16, &z.hi, &z.lo);
    return z;
}

/*----------------------------------------------------------------------------
| The pattern for a default generated quadruple-precision NaN.
*----------------------------------------------------------------------------*/
extern const float128 float128_default_nan;

#endif /* FLOAT128 */

#endif
