/////////////////////////////////////////////////////////////////////////
// $Id: wxgtkkeys.h,v 1.1 2002-10-15 16:48:10 vruppert Exp $
/////////////////////////////////////////////////////////////////////////
//
// This file is simply a list of wxGTK key symbols taken from <gdk/gdkkeysyms.h>.
// The order in this file is not important.  In wx.cc, DEF_WX_KEY() is
// defined as a macro and then it includes this file to fill in all the data in
// its key mapping table.
// 
// The symbols, such as GDK_Return, are used for two purposes.  They
// are converted into a string (by the # operator in processor), which is 
// compared to the host key name in the keymap file.  Also, the value of
// the symbol is inserted into the key mapping table.  Then the value is
// compared with the keysym field of each key up/down event as it arrives.
// 
// If you get undefined symbol errors in this file, it must mean that
// your GTK library version doesn't define those same GDK_* symbols in
// <gdk/gdkkeysyms.h>.  You can't fix it with #ifdef GDK_SYM because
// they are enums, so you'll just have to comment out the offending line.
// The list was generated using symbols from  gtk 1.2.

DEF_WX_KEY( GDK_VoidSymbol )
DEF_WX_KEY( GDK_BackSpace )
DEF_WX_KEY( GDK_Tab )
DEF_WX_KEY( GDK_Linefeed )
DEF_WX_KEY( GDK_Clear )
DEF_WX_KEY( GDK_Return )
DEF_WX_KEY( GDK_Pause )
DEF_WX_KEY( GDK_Scroll_Lock )
DEF_WX_KEY( GDK_Sys_Req )
DEF_WX_KEY( GDK_Escape )
DEF_WX_KEY( GDK_Delete )
DEF_WX_KEY( GDK_Multi_key )
DEF_WX_KEY( GDK_SingleCandidate )
DEF_WX_KEY( GDK_MultipleCandidate )
DEF_WX_KEY( GDK_PreviousCandidate )
DEF_WX_KEY( GDK_Kanji )
DEF_WX_KEY( GDK_Muhenkan )
DEF_WX_KEY( GDK_Henkan_Mode )
DEF_WX_KEY( GDK_Henkan )
DEF_WX_KEY( GDK_Romaji )
DEF_WX_KEY( GDK_Hiragana )
DEF_WX_KEY( GDK_Katakana )
DEF_WX_KEY( GDK_Hiragana_Katakana )
DEF_WX_KEY( GDK_Zenkaku )
DEF_WX_KEY( GDK_Hankaku )
DEF_WX_KEY( GDK_Zenkaku_Hankaku )
DEF_WX_KEY( GDK_Touroku )
DEF_WX_KEY( GDK_Massyo )
DEF_WX_KEY( GDK_Kana_Lock )
DEF_WX_KEY( GDK_Kana_Shift )
DEF_WX_KEY( GDK_Eisu_Shift )
DEF_WX_KEY( GDK_Eisu_toggle )
DEF_WX_KEY( GDK_Zen_Koho )
DEF_WX_KEY( GDK_Mae_Koho )
DEF_WX_KEY( GDK_Home )
DEF_WX_KEY( GDK_Left )
DEF_WX_KEY( GDK_Up )
DEF_WX_KEY( GDK_Right )
DEF_WX_KEY( GDK_Down )
DEF_WX_KEY( GDK_Prior )
DEF_WX_KEY( GDK_Page_Up )
DEF_WX_KEY( GDK_Next )
DEF_WX_KEY( GDK_Page_Down )
DEF_WX_KEY( GDK_End )
DEF_WX_KEY( GDK_Begin )
DEF_WX_KEY( GDK_Select )
DEF_WX_KEY( GDK_Print )
DEF_WX_KEY( GDK_Execute )
DEF_WX_KEY( GDK_Insert )
DEF_WX_KEY( GDK_Undo )
DEF_WX_KEY( GDK_Redo )
DEF_WX_KEY( GDK_Menu )
DEF_WX_KEY( GDK_Find )
DEF_WX_KEY( GDK_Cancel )
DEF_WX_KEY( GDK_Help )
DEF_WX_KEY( GDK_Break )
DEF_WX_KEY( GDK_Mode_switch )
DEF_WX_KEY( GDK_script_switch )
DEF_WX_KEY( GDK_Num_Lock )
DEF_WX_KEY( GDK_KP_Space )
DEF_WX_KEY( GDK_KP_Tab )
DEF_WX_KEY( GDK_KP_Enter )
DEF_WX_KEY( GDK_KP_F1 )
DEF_WX_KEY( GDK_KP_F2 )
DEF_WX_KEY( GDK_KP_F3 )
DEF_WX_KEY( GDK_KP_F4 )
DEF_WX_KEY( GDK_KP_Home )
DEF_WX_KEY( GDK_KP_Left )
DEF_WX_KEY( GDK_KP_Up )
DEF_WX_KEY( GDK_KP_Right )
DEF_WX_KEY( GDK_KP_Down )
DEF_WX_KEY( GDK_KP_Prior )
DEF_WX_KEY( GDK_KP_Page_Up )
DEF_WX_KEY( GDK_KP_Next )
DEF_WX_KEY( GDK_KP_Page_Down )
DEF_WX_KEY( GDK_KP_End )
DEF_WX_KEY( GDK_KP_Begin )
DEF_WX_KEY( GDK_KP_Insert )
DEF_WX_KEY( GDK_KP_Delete )
DEF_WX_KEY( GDK_KP_Equal )
DEF_WX_KEY( GDK_KP_Multiply )
DEF_WX_KEY( GDK_KP_Add )
DEF_WX_KEY( GDK_KP_Separator )
DEF_WX_KEY( GDK_KP_Subtract )
DEF_WX_KEY( GDK_KP_Decimal )
DEF_WX_KEY( GDK_KP_Divide )
DEF_WX_KEY( GDK_KP_0 )
DEF_WX_KEY( GDK_KP_1 )
DEF_WX_KEY( GDK_KP_2 )
DEF_WX_KEY( GDK_KP_3 )
DEF_WX_KEY( GDK_KP_4 )
DEF_WX_KEY( GDK_KP_5 )
DEF_WX_KEY( GDK_KP_6 )
DEF_WX_KEY( GDK_KP_7 )
DEF_WX_KEY( GDK_KP_8 )
DEF_WX_KEY( GDK_KP_9 )
DEF_WX_KEY( GDK_F1 )
DEF_WX_KEY( GDK_F2 )
DEF_WX_KEY( GDK_F3 )
DEF_WX_KEY( GDK_F4 )
DEF_WX_KEY( GDK_F5 )
DEF_WX_KEY( GDK_F6 )
DEF_WX_KEY( GDK_F7 )
DEF_WX_KEY( GDK_F8 )
DEF_WX_KEY( GDK_F9 )
DEF_WX_KEY( GDK_F10 )
DEF_WX_KEY( GDK_F11 )
DEF_WX_KEY( GDK_L1 )
DEF_WX_KEY( GDK_F12 )
DEF_WX_KEY( GDK_L2 )
DEF_WX_KEY( GDK_F13 )
DEF_WX_KEY( GDK_L3 )
DEF_WX_KEY( GDK_F14 )
DEF_WX_KEY( GDK_L4 )
DEF_WX_KEY( GDK_F15 )
DEF_WX_KEY( GDK_L5 )
DEF_WX_KEY( GDK_F16 )
DEF_WX_KEY( GDK_L6 )
DEF_WX_KEY( GDK_F17 )
DEF_WX_KEY( GDK_L7 )
DEF_WX_KEY( GDK_F18 )
DEF_WX_KEY( GDK_L8 )
DEF_WX_KEY( GDK_F19 )
DEF_WX_KEY( GDK_L9 )
DEF_WX_KEY( GDK_F20 )
DEF_WX_KEY( GDK_L10 )
DEF_WX_KEY( GDK_F21 )
DEF_WX_KEY( GDK_R1 )
DEF_WX_KEY( GDK_F22 )
DEF_WX_KEY( GDK_R2 )
DEF_WX_KEY( GDK_F23 )
DEF_WX_KEY( GDK_R3 )
DEF_WX_KEY( GDK_F24 )
DEF_WX_KEY( GDK_R4 )
DEF_WX_KEY( GDK_F25 )
DEF_WX_KEY( GDK_R5 )
DEF_WX_KEY( GDK_F26 )
DEF_WX_KEY( GDK_R6 )
DEF_WX_KEY( GDK_F27 )
DEF_WX_KEY( GDK_R7 )
DEF_WX_KEY( GDK_F28 )
DEF_WX_KEY( GDK_R8 )
DEF_WX_KEY( GDK_F29 )
DEF_WX_KEY( GDK_R9 )
DEF_WX_KEY( GDK_F30 )
DEF_WX_KEY( GDK_R10 )
DEF_WX_KEY( GDK_F31 )
DEF_WX_KEY( GDK_R11 )
DEF_WX_KEY( GDK_F32 )
DEF_WX_KEY( GDK_R12 )
DEF_WX_KEY( GDK_F33 )
DEF_WX_KEY( GDK_R13 )
DEF_WX_KEY( GDK_F34 )
DEF_WX_KEY( GDK_R14 )
DEF_WX_KEY( GDK_F35 )
DEF_WX_KEY( GDK_R15 )
DEF_WX_KEY( GDK_Shift_L )
DEF_WX_KEY( GDK_Shift_R )
DEF_WX_KEY( GDK_Control_L )
DEF_WX_KEY( GDK_Control_R )
DEF_WX_KEY( GDK_Caps_Lock )
DEF_WX_KEY( GDK_Shift_Lock )
DEF_WX_KEY( GDK_Meta_L )
DEF_WX_KEY( GDK_Meta_R )
DEF_WX_KEY( GDK_Alt_L )
DEF_WX_KEY( GDK_Alt_R )
DEF_WX_KEY( GDK_Super_L )
DEF_WX_KEY( GDK_Super_R )
DEF_WX_KEY( GDK_Hyper_L )
DEF_WX_KEY( GDK_Hyper_R )
DEF_WX_KEY( GDK_ISO_Left_Tab )
DEF_WX_KEY( GDK_dead_grave )
DEF_WX_KEY( GDK_dead_acute )
DEF_WX_KEY( GDK_dead_circumflex )
DEF_WX_KEY( GDK_dead_tilde )
DEF_WX_KEY( GDK_dead_macron )
DEF_WX_KEY( GDK_dead_breve )
DEF_WX_KEY( GDK_dead_abovedot )
DEF_WX_KEY( GDK_dead_diaeresis )
DEF_WX_KEY( GDK_dead_abovering )
DEF_WX_KEY( GDK_dead_doubleacute )
DEF_WX_KEY( GDK_dead_caron )
DEF_WX_KEY( GDK_dead_cedilla )
DEF_WX_KEY( GDK_dead_ogonek )
DEF_WX_KEY( GDK_dead_iota )
DEF_WX_KEY( GDK_dead_voiced_sound )
DEF_WX_KEY( GDK_dead_semivoiced_sound )
DEF_WX_KEY( GDK_dead_belowdot )
DEF_WX_KEY( GDK_First_Virtual_Screen )
DEF_WX_KEY( GDK_Prev_Virtual_Screen )
DEF_WX_KEY( GDK_Next_Virtual_Screen )
DEF_WX_KEY( GDK_Last_Virtual_Screen )
DEF_WX_KEY( GDK_Terminate_Server )
DEF_WX_KEY( GDK_AccessX_Enable )
DEF_WX_KEY( GDK_AccessX_Feedback_Enable )
DEF_WX_KEY( GDK_RepeatKeys_Enable )
DEF_WX_KEY( GDK_SlowKeys_Enable )
DEF_WX_KEY( GDK_BounceKeys_Enable )
DEF_WX_KEY( GDK_StickyKeys_Enable )
DEF_WX_KEY( GDK_MouseKeys_Enable )
DEF_WX_KEY( GDK_MouseKeys_Accel_Enable )
DEF_WX_KEY( GDK_Overlay1_Enable )
DEF_WX_KEY( GDK_Overlay2_Enable )
DEF_WX_KEY( GDK_AudibleBell_Enable )
DEF_WX_KEY( GDK_Pointer_Left )
DEF_WX_KEY( GDK_Pointer_Right )
DEF_WX_KEY( GDK_Pointer_Up )
DEF_WX_KEY( GDK_Pointer_Down )
DEF_WX_KEY( GDK_Pointer_UpLeft )
DEF_WX_KEY( GDK_Pointer_UpRight )
DEF_WX_KEY( GDK_Pointer_DownLeft )
DEF_WX_KEY( GDK_Pointer_DownRight )
DEF_WX_KEY( GDK_Pointer_Button_Dflt )
DEF_WX_KEY( GDK_Pointer_Button1 )
DEF_WX_KEY( GDK_Pointer_Button2 )
DEF_WX_KEY( GDK_Pointer_Button3 )
DEF_WX_KEY( GDK_Pointer_Button4 )
DEF_WX_KEY( GDK_Pointer_Button5 )
DEF_WX_KEY( GDK_Pointer_DblClick_Dflt )
DEF_WX_KEY( GDK_Pointer_DblClick1 )
DEF_WX_KEY( GDK_Pointer_DblClick2 )
DEF_WX_KEY( GDK_Pointer_DblClick3 )
DEF_WX_KEY( GDK_Pointer_DblClick4 )
DEF_WX_KEY( GDK_Pointer_DblClick5 )
DEF_WX_KEY( GDK_Pointer_Drag_Dflt )
DEF_WX_KEY( GDK_Pointer_Drag1 )
DEF_WX_KEY( GDK_Pointer_Drag2 )
DEF_WX_KEY( GDK_Pointer_Drag3 )
DEF_WX_KEY( GDK_Pointer_Drag4 )
DEF_WX_KEY( GDK_Pointer_Drag5 )
DEF_WX_KEY( GDK_Pointer_EnableKeys )
DEF_WX_KEY( GDK_Pointer_Accelerate )
DEF_WX_KEY( GDK_Pointer_DfltBtnNext )
DEF_WX_KEY( GDK_Pointer_DfltBtnPrev )
DEF_WX_KEY( GDK_3270_Duplicate )
DEF_WX_KEY( GDK_3270_FieldMark )
DEF_WX_KEY( GDK_3270_Right2 )
DEF_WX_KEY( GDK_3270_Left2 )
DEF_WX_KEY( GDK_3270_BackTab )
DEF_WX_KEY( GDK_3270_EraseEOF )
DEF_WX_KEY( GDK_3270_EraseInput )
DEF_WX_KEY( GDK_3270_Reset )
DEF_WX_KEY( GDK_3270_Quit )
DEF_WX_KEY( GDK_3270_PA1 )
DEF_WX_KEY( GDK_3270_PA2 )
DEF_WX_KEY( GDK_3270_PA3 )
DEF_WX_KEY( GDK_3270_Test )
DEF_WX_KEY( GDK_3270_Attn )
DEF_WX_KEY( GDK_3270_CursorBlink )
DEF_WX_KEY( GDK_3270_AltCursor )
DEF_WX_KEY( GDK_3270_KeyClick )
DEF_WX_KEY( GDK_3270_Jump )
DEF_WX_KEY( GDK_3270_Ident )
DEF_WX_KEY( GDK_3270_Rule )
DEF_WX_KEY( GDK_3270_Copy )
DEF_WX_KEY( GDK_3270_Play )
DEF_WX_KEY( GDK_3270_Setup )
DEF_WX_KEY( GDK_3270_Record )
DEF_WX_KEY( GDK_3270_ChangeScreen )
DEF_WX_KEY( GDK_3270_DeleteWord )
DEF_WX_KEY( GDK_3270_ExSelect )
DEF_WX_KEY( GDK_3270_CursorSelect )
DEF_WX_KEY( GDK_3270_PrintScreen )
DEF_WX_KEY( GDK_3270_Enter )
DEF_WX_KEY( GDK_space )
DEF_WX_KEY( GDK_exclam )
DEF_WX_KEY( GDK_quotedbl )
DEF_WX_KEY( GDK_numbersign )
DEF_WX_KEY( GDK_dollar )
DEF_WX_KEY( GDK_percent )
DEF_WX_KEY( GDK_ampersand )
DEF_WX_KEY( GDK_apostrophe )
DEF_WX_KEY( GDK_quoteright )
DEF_WX_KEY( GDK_parenleft )
DEF_WX_KEY( GDK_parenright )
DEF_WX_KEY( GDK_asterisk )
DEF_WX_KEY( GDK_plus )
DEF_WX_KEY( GDK_comma )
DEF_WX_KEY( GDK_minus )
DEF_WX_KEY( GDK_period )
DEF_WX_KEY( GDK_slash )
DEF_WX_KEY( GDK_0 )
DEF_WX_KEY( GDK_1 )
DEF_WX_KEY( GDK_2 )
DEF_WX_KEY( GDK_3 )
DEF_WX_KEY( GDK_4 )
DEF_WX_KEY( GDK_5 )
DEF_WX_KEY( GDK_6 )
DEF_WX_KEY( GDK_7 )
DEF_WX_KEY( GDK_8 )
DEF_WX_KEY( GDK_9 )
DEF_WX_KEY( GDK_colon )
DEF_WX_KEY( GDK_semicolon )
DEF_WX_KEY( GDK_less )
DEF_WX_KEY( GDK_equal )
DEF_WX_KEY( GDK_greater )
DEF_WX_KEY( GDK_question )
DEF_WX_KEY( GDK_at )
DEF_WX_KEY( GDK_A )
DEF_WX_KEY( GDK_B )
DEF_WX_KEY( GDK_C )
DEF_WX_KEY( GDK_D )
DEF_WX_KEY( GDK_E )
DEF_WX_KEY( GDK_F )
DEF_WX_KEY( GDK_G )
DEF_WX_KEY( GDK_H )
DEF_WX_KEY( GDK_I )
DEF_WX_KEY( GDK_J )
DEF_WX_KEY( GDK_K )
DEF_WX_KEY( GDK_L )
DEF_WX_KEY( GDK_M )
DEF_WX_KEY( GDK_N )
DEF_WX_KEY( GDK_O )
DEF_WX_KEY( GDK_P )
DEF_WX_KEY( GDK_Q )
DEF_WX_KEY( GDK_R )
DEF_WX_KEY( GDK_S )
DEF_WX_KEY( GDK_T )
DEF_WX_KEY( GDK_U )
DEF_WX_KEY( GDK_V )
DEF_WX_KEY( GDK_W )
DEF_WX_KEY( GDK_X )
DEF_WX_KEY( GDK_Y )
DEF_WX_KEY( GDK_Z )
DEF_WX_KEY( GDK_bracketleft )
DEF_WX_KEY( GDK_backslash )
DEF_WX_KEY( GDK_bracketright )
DEF_WX_KEY( GDK_asciicircum )
DEF_WX_KEY( GDK_underscore )
DEF_WX_KEY( GDK_grave )
DEF_WX_KEY( GDK_quoteleft )
DEF_WX_KEY( GDK_a )
DEF_WX_KEY( GDK_b )
DEF_WX_KEY( GDK_c )
DEF_WX_KEY( GDK_d )
DEF_WX_KEY( GDK_e )
DEF_WX_KEY( GDK_f )
DEF_WX_KEY( GDK_g )
DEF_WX_KEY( GDK_h )
DEF_WX_KEY( GDK_i )
DEF_WX_KEY( GDK_j )
DEF_WX_KEY( GDK_k )
DEF_WX_KEY( GDK_l )
DEF_WX_KEY( GDK_m )
DEF_WX_KEY( GDK_n )
DEF_WX_KEY( GDK_o )
DEF_WX_KEY( GDK_p )
DEF_WX_KEY( GDK_q )
DEF_WX_KEY( GDK_r )
DEF_WX_KEY( GDK_s )
DEF_WX_KEY( GDK_t )
DEF_WX_KEY( GDK_u )
DEF_WX_KEY( GDK_v )
DEF_WX_KEY( GDK_w )
DEF_WX_KEY( GDK_x )
DEF_WX_KEY( GDK_y )
DEF_WX_KEY( GDK_z )
DEF_WX_KEY( GDK_braceleft )
DEF_WX_KEY( GDK_bar )
DEF_WX_KEY( GDK_braceright )
DEF_WX_KEY( GDK_asciitilde )
DEF_WX_KEY( GDK_nobreakspace )
DEF_WX_KEY( GDK_exclamdown )
DEF_WX_KEY( GDK_cent )
DEF_WX_KEY( GDK_sterling )
DEF_WX_KEY( GDK_currency )
DEF_WX_KEY( GDK_yen )
DEF_WX_KEY( GDK_brokenbar )
DEF_WX_KEY( GDK_section )
DEF_WX_KEY( GDK_diaeresis )
DEF_WX_KEY( GDK_copyright )
DEF_WX_KEY( GDK_ordfeminine )
DEF_WX_KEY( GDK_guillemotleft )
DEF_WX_KEY( GDK_notsign )
DEF_WX_KEY( GDK_hyphen )
DEF_WX_KEY( GDK_registered )
DEF_WX_KEY( GDK_macron )
DEF_WX_KEY( GDK_degree )
DEF_WX_KEY( GDK_plusminus )
DEF_WX_KEY( GDK_twosuperior )
DEF_WX_KEY( GDK_threesuperior )
DEF_WX_KEY( GDK_acute )
DEF_WX_KEY( GDK_mu )
DEF_WX_KEY( GDK_paragraph )
DEF_WX_KEY( GDK_periodcentered )
DEF_WX_KEY( GDK_cedilla )
DEF_WX_KEY( GDK_onesuperior )
DEF_WX_KEY( GDK_masculine )
DEF_WX_KEY( GDK_guillemotright )
DEF_WX_KEY( GDK_onequarter )
DEF_WX_KEY( GDK_onehalf )
DEF_WX_KEY( GDK_threequarters )
DEF_WX_KEY( GDK_questiondown )
DEF_WX_KEY( GDK_Agrave )
DEF_WX_KEY( GDK_Aacute )
DEF_WX_KEY( GDK_Acircumflex )
DEF_WX_KEY( GDK_Atilde )
DEF_WX_KEY( GDK_Adiaeresis )
DEF_WX_KEY( GDK_Aring )
DEF_WX_KEY( GDK_AE )
DEF_WX_KEY( GDK_Ccedilla )
DEF_WX_KEY( GDK_Egrave )
DEF_WX_KEY( GDK_Eacute )
DEF_WX_KEY( GDK_Ecircumflex )
DEF_WX_KEY( GDK_Ediaeresis )
DEF_WX_KEY( GDK_Igrave )
DEF_WX_KEY( GDK_Iacute )
DEF_WX_KEY( GDK_Icircumflex )
DEF_WX_KEY( GDK_Idiaeresis )
DEF_WX_KEY( GDK_ETH )
DEF_WX_KEY( GDK_Eth )
DEF_WX_KEY( GDK_Ntilde )
DEF_WX_KEY( GDK_Ograve )
DEF_WX_KEY( GDK_Oacute )
DEF_WX_KEY( GDK_Ocircumflex )
DEF_WX_KEY( GDK_Otilde )
DEF_WX_KEY( GDK_Odiaeresis )
DEF_WX_KEY( GDK_multiply )
DEF_WX_KEY( GDK_Ooblique )
DEF_WX_KEY( GDK_Ugrave )
DEF_WX_KEY( GDK_Uacute )
DEF_WX_KEY( GDK_Ucircumflex )
DEF_WX_KEY( GDK_Udiaeresis )
DEF_WX_KEY( GDK_Yacute )
DEF_WX_KEY( GDK_THORN )
DEF_WX_KEY( GDK_Thorn )
DEF_WX_KEY( GDK_ssharp )
DEF_WX_KEY( GDK_agrave )
DEF_WX_KEY( GDK_aacute )
DEF_WX_KEY( GDK_acircumflex )
DEF_WX_KEY( GDK_atilde )
DEF_WX_KEY( GDK_adiaeresis )
DEF_WX_KEY( GDK_aring )
DEF_WX_KEY( GDK_ae )
DEF_WX_KEY( GDK_ccedilla )
DEF_WX_KEY( GDK_egrave )
DEF_WX_KEY( GDK_eacute )
DEF_WX_KEY( GDK_ecircumflex )
DEF_WX_KEY( GDK_ediaeresis )
DEF_WX_KEY( GDK_igrave )
DEF_WX_KEY( GDK_iacute )
DEF_WX_KEY( GDK_icircumflex )
DEF_WX_KEY( GDK_idiaeresis )
DEF_WX_KEY( GDK_eth )
DEF_WX_KEY( GDK_ntilde )
DEF_WX_KEY( GDK_ograve )
DEF_WX_KEY( GDK_oacute )
DEF_WX_KEY( GDK_ocircumflex )
DEF_WX_KEY( GDK_otilde )
DEF_WX_KEY( GDK_odiaeresis )
DEF_WX_KEY( GDK_division )
DEF_WX_KEY( GDK_oslash )
DEF_WX_KEY( GDK_ugrave )
DEF_WX_KEY( GDK_uacute )
DEF_WX_KEY( GDK_ucircumflex )
DEF_WX_KEY( GDK_udiaeresis )
DEF_WX_KEY( GDK_yacute )
DEF_WX_KEY( GDK_thorn )
DEF_WX_KEY( GDK_ydiaeresis )
DEF_WX_KEY( GDK_Aogonek )
DEF_WX_KEY( GDK_breve )
DEF_WX_KEY( GDK_Lstroke )
DEF_WX_KEY( GDK_Lcaron )
DEF_WX_KEY( GDK_Sacute )
DEF_WX_KEY( GDK_Scaron )
DEF_WX_KEY( GDK_Scedilla )
DEF_WX_KEY( GDK_Tcaron )
DEF_WX_KEY( GDK_Zacute )
DEF_WX_KEY( GDK_Zcaron )
DEF_WX_KEY( GDK_Zabovedot )
DEF_WX_KEY( GDK_aogonek )
DEF_WX_KEY( GDK_ogonek )
DEF_WX_KEY( GDK_lstroke )
DEF_WX_KEY( GDK_lcaron )
DEF_WX_KEY( GDK_sacute )
DEF_WX_KEY( GDK_caron )
DEF_WX_KEY( GDK_scaron )
DEF_WX_KEY( GDK_scedilla )
DEF_WX_KEY( GDK_tcaron )
DEF_WX_KEY( GDK_zacute )
DEF_WX_KEY( GDK_doubleacute )
DEF_WX_KEY( GDK_zcaron )
DEF_WX_KEY( GDK_zabovedot )
DEF_WX_KEY( GDK_Racute )
DEF_WX_KEY( GDK_Abreve )
DEF_WX_KEY( GDK_Lacute )
DEF_WX_KEY( GDK_Cacute )
DEF_WX_KEY( GDK_Ccaron )
DEF_WX_KEY( GDK_Eogonek )
DEF_WX_KEY( GDK_Ecaron )
DEF_WX_KEY( GDK_Dcaron )
DEF_WX_KEY( GDK_Dstroke )
DEF_WX_KEY( GDK_Nacute )
DEF_WX_KEY( GDK_Ncaron )
DEF_WX_KEY( GDK_Odoubleacute )
DEF_WX_KEY( GDK_Rcaron )
DEF_WX_KEY( GDK_Uring )
DEF_WX_KEY( GDK_Udoubleacute )
DEF_WX_KEY( GDK_Tcedilla )
DEF_WX_KEY( GDK_racute )
DEF_WX_KEY( GDK_abreve )
DEF_WX_KEY( GDK_lacute )
DEF_WX_KEY( GDK_cacute )
DEF_WX_KEY( GDK_ccaron )
DEF_WX_KEY( GDK_eogonek )
DEF_WX_KEY( GDK_ecaron )
DEF_WX_KEY( GDK_dcaron )
DEF_WX_KEY( GDK_dstroke )
DEF_WX_KEY( GDK_nacute )
DEF_WX_KEY( GDK_ncaron )
DEF_WX_KEY( GDK_odoubleacute )
DEF_WX_KEY( GDK_udoubleacute )
DEF_WX_KEY( GDK_rcaron )
DEF_WX_KEY( GDK_uring )
DEF_WX_KEY( GDK_tcedilla )
DEF_WX_KEY( GDK_abovedot )
DEF_WX_KEY( GDK_Hstroke )
DEF_WX_KEY( GDK_Hcircumflex )
DEF_WX_KEY( GDK_Iabovedot )
DEF_WX_KEY( GDK_Gbreve )
DEF_WX_KEY( GDK_Jcircumflex )
DEF_WX_KEY( GDK_hstroke )
DEF_WX_KEY( GDK_hcircumflex )
DEF_WX_KEY( GDK_idotless )
DEF_WX_KEY( GDK_gbreve )
DEF_WX_KEY( GDK_jcircumflex )
DEF_WX_KEY( GDK_Cabovedot )
DEF_WX_KEY( GDK_Ccircumflex )
DEF_WX_KEY( GDK_Gabovedot )
DEF_WX_KEY( GDK_Gcircumflex )
DEF_WX_KEY( GDK_Ubreve )
DEF_WX_KEY( GDK_Scircumflex )
DEF_WX_KEY( GDK_cabovedot )
DEF_WX_KEY( GDK_ccircumflex )
DEF_WX_KEY( GDK_gabovedot )
DEF_WX_KEY( GDK_gcircumflex )
DEF_WX_KEY( GDK_ubreve )
DEF_WX_KEY( GDK_scircumflex )
DEF_WX_KEY( GDK_kra )
DEF_WX_KEY( GDK_kappa )
DEF_WX_KEY( GDK_Rcedilla )
DEF_WX_KEY( GDK_Itilde )
DEF_WX_KEY( GDK_Lcedilla )
DEF_WX_KEY( GDK_Emacron )
DEF_WX_KEY( GDK_Gcedilla )
DEF_WX_KEY( GDK_Tslash )
DEF_WX_KEY( GDK_rcedilla )
DEF_WX_KEY( GDK_itilde )
DEF_WX_KEY( GDK_lcedilla )
DEF_WX_KEY( GDK_emacron )
DEF_WX_KEY( GDK_gcedilla )
DEF_WX_KEY( GDK_tslash )
DEF_WX_KEY( GDK_ENG )
DEF_WX_KEY( GDK_eng )
DEF_WX_KEY( GDK_Amacron )
DEF_WX_KEY( GDK_Iogonek )
DEF_WX_KEY( GDK_Eabovedot )
DEF_WX_KEY( GDK_Imacron )
DEF_WX_KEY( GDK_Ncedilla )
DEF_WX_KEY( GDK_Omacron )
DEF_WX_KEY( GDK_Kcedilla )
DEF_WX_KEY( GDK_Uogonek )
DEF_WX_KEY( GDK_Utilde )
DEF_WX_KEY( GDK_Umacron )
DEF_WX_KEY( GDK_amacron )
DEF_WX_KEY( GDK_iogonek )
DEF_WX_KEY( GDK_eabovedot )
DEF_WX_KEY( GDK_imacron )
DEF_WX_KEY( GDK_ncedilla )
DEF_WX_KEY( GDK_omacron )
DEF_WX_KEY( GDK_kcedilla )
DEF_WX_KEY( GDK_uogonek )
DEF_WX_KEY( GDK_utilde )
DEF_WX_KEY( GDK_umacron )
DEF_WX_KEY( GDK_overline )
DEF_WX_KEY( GDK_horizconnector )
DEF_WX_KEY( GDK_leftarrow )
DEF_WX_KEY( GDK_uparrow )
DEF_WX_KEY( GDK_rightarrow )
DEF_WX_KEY( GDK_downarrow )
DEF_WX_KEY( GDK_leftdoublequotemark )
DEF_WX_KEY( GDK_rightdoublequotemark )
