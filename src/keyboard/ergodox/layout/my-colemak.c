/* ----------------------------------------------------------------------------
* ergoDOX layout : QWERTY (modified from the Kinesis layout)
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0: Colemak.
KB_MATRIX_LAYER(
	// unused
	0,
	// Left hand.
	_grave,		_1,				_2,					_3,			_4,			_5,			_esc,
	_tab,		_Q,				_W,					_F,			_P,			_G,			1,
	_guiL,		_A,				_R,					_S,			_T,			_D,
	_shiftL,	_Z,				_X,					_C,			_V,			_B,			2,
	_ctrlL,		_pound_nonUS,	_backslash_nonUS,	_altL,		1,
																			_ctrlL,		_altL,
																0,			0,			_home,
																_bs,		_del,		_end,

	// Right hand.
	_esc,			_6,			_7,			_8,			_9,			_0,			_dash,
	2,		_J,			_L,			_U,			_Y,			_semicolon,	_bracketL,
				_H,			_N,			_E,			_I,			_O,			_quote,
	1,			_K,			_M,			_comma,		_period,	_slash,		_shiftR,
							_arrowL,	_arrowD,	_arrowU,	_arrowR,	_guiR,

	_altR,		_ctrlR,
	_pageU,		0,			0,
	_pageD,		_enter,		_space
),

// LAYER 1: Function and symbol keys.
KB_MATRIX_LAYER(
	// unused
	0,
	// Left hand.
	0,			_F1,		_F2,		_F3,		_F4,		_F5,		_F11,
	0,			_bracketL,	_bracketR,	_bracketL,	_bracketR,	_semicolon,	1,
	0,			_backslash,	_slash,		_9,			_0,			_semicolon,
	0,			_1,			_2,			_3,			_4,			_5,			0,
	0,			0,			0,			0,			0,

																0,			0,
													0,			0,			0,
													0,			0,			0,

	// Right hand.
	_F12,		_F6,		_F7,		_F8,		_F9,		_F10,		_playpause_m,
	0,			0,			_equal,		_arrowU,	_dash,		_volumeU_m,	_next_m,
				0,			_arrowL,	_arrowD,	_arrowR,	_volumeD_m,	_prev_m,
	0,			_6,			_7,			_8,			_9,			_0,			_mute_m,
							0,			0,			0,			0,			0,

	0,			0,
	0,			0,			0,
	0,			0,			0
),

// LAYER 2: Numpad.
KB_MATRIX_LAYER(
	// unused
	0,
	// Left hand.
	0,			0,			0,			0,			0,			0,			0,
	0,			0,			0,			0,			0,			0,			0,
	0,			0,			0,			0,			0,			0,
	0,			0,			0,			0,			0,			0,			0,
	0,			_insert,	0,			0,			0,

																0,			0,
													0,			0,			0,
													0,			0,			0,

	// Right hand.
	0,			0,			0,			_div_kp,	_mul_kp,	_sub_kp,	0,
	2,			0,			_7_kp,		_8_kp,		_9_kp,		_add_kp,	0,
				0,			_4_kp,		_5_kp,		_6_kp,		_add_kp,	0,
	0,			0,			_1_kp,		_2_kp,		_3_kp,		_enter_kp,	0,
							0,			0,			_period,	_enter_kp,	0,

	0,			0,
	0,			0,			0,
	0,			0,			_0_kp
),
};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// Aliases

// Basic.
#define  kprrel   &kbfun_press_release
#define  ktog     &kbfun_toggle
#define  ktrans   &kbfun_transparent

// Layer push and pop functions.
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10

// Device.
#define  dbtldr   &kbfun_jump_to_bootloader

// Special.
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// Media keys
#define  mprrel	  &kbfun_mediakey_press_release

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0: Colemak.
KB_MATRIX_LAYER(
	// unused
	NULL,
	// Left hand.
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		lpush1,
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		lpush3,
	kprrel,		kprrel,		kprrel,		kprrel,		lpush1,

																kprrel,		kprrel,
													NULL,		NULL,		kprrel,
													kprrel,		kprrel,		kprrel,

	// Right hand.
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	slpunum,	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
				kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	lpush1,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
							kprrel,		kprrel,		kprrel,		kprrel,		kprrel,

	kprrel,		kprrel,
	kprrel,		NULL,		NULL,
	kprrel,		kprrel,		kprrel
),

// LAYER 1: Function and symbol keys.
KB_MATRIX_LAYER(
	// unused
	NULL,
	// Left hand.
	dbtldr,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	ktrans,		sshprre,	sshprre,	kprrel,		kprrel,		sshprre,	lpop1,
	ktrans,		kprrel,		kprrel,		sshprre,	sshprre,	kprrel,
	ktrans,		sshprre,	sshprre,	sshprre,	sshprre,	sshprre,	ktrans,
	ktrans,		ktrans,		ktrans,		ktrans,		ktrans,

																ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,

	// Right hand.
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		mprrel,
	ktrans,		NULL,		kprrel,		kprrel,		kprrel,		mprrel,		mprrel,
				NULL,		kprrel,		kprrel,		kprrel,		mprrel,		mprrel,
	NULL,		sshprre,	sshprre,	sshprre,	sshprre,	sshprre,	mprrel,
							ktrans,		ktrans,		ktrans,		ktrans,		ktrans,

	ktrans,		ktrans,
	ktrans,		ktrans,		ktrans,
	ktrans,		ktrans,		ktrans
),

// LAYER 2: Numpad.
KB_MATRIX_LAYER(
	// unused
	NULL,
	// Left hand.
	NULL,		NULL,		NULL,		NULL,		NULL,		NULL,		ktrans,
	ktrans,		NULL,		NULL,		NULL,		NULL,		NULL,		NULL,
	ktrans,		NULL,		NULL,		NULL,		NULL,		NULL,
	ktrans,		NULL,		NULL,		NULL,		NULL,		NULL,		NULL,
	ktrans,		kprrel,		ktrans,		ktrans,		ktrans,

																ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,

	// Right hand.
	ktrans,		NULL,		NULL,		kprrel,		kprrel,		kprrel,		NULL,
	slponum,	NULL,		kprrel,		kprrel,		kprrel,		kprrel,		NULL,
				NULL,		kprrel,		kprrel,		kprrel,		kprrel,		NULL,
	ktrans,		NULL,		kprrel,		kprrel,		kprrel,		kprrel,		ktrans,
							NULL,		NULL,		kprrel,		kprrel,		ktrans,

	ktrans,		ktrans,
	ktrans,		ktrans,		ktrans,
	ktrans,		ktrans,		kprrel
),
};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0: Colemak.
KB_MATRIX_LAYER(
	// unused
	NULL,
	// Left hand.
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		NULL,
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		lpop3,
	kprrel,		kprrel,		kprrel,		kprrel,		lpop1,

																kprrel,		kprrel,
													NULL,		NULL,		kprrel,
													kprrel,		kprrel,		kprrel,
	// Right hand.
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	NULL,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
				kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	lpop1,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
							kprrel,		kprrel,		kprrel,		kprrel,		kprrel,

	kprrel,		kprrel,
	kprrel,		NULL,		NULL,
	kprrel,		kprrel,		kprrel
),

// LAYER 1: Function and symbol keys.
KB_MATRIX_LAYER(
	// unused
	NULL,
	// Left hand.
	NULL,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,
	ktrans,		sshprre,	sshprre,	kprrel,		kprrel,		sshprre, 	ktrans,
	ktrans,		kprrel,		kprrel,		sshprre,	sshprre,	kprrel,
	ktrans,		sshprre,	sshprre,	sshprre,	sshprre,	sshprre,	ktrans,
	ktrans,		ktrans,		ktrans,		ktrans,		ktrans,

																ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,

	// Right hand.
	kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		kprrel,		mprrel,
	ktrans,		NULL,		kprrel,		kprrel,		kprrel,		mprrel,		mprrel,
				NULL,		kprrel,		kprrel,		kprrel,		mprrel,		mprrel,
	NULL,		sshprre,	sshprre,	sshprre,	sshprre,	sshprre,	mprrel,
							ktrans,		ktrans,		ktrans,		ktrans,		ktrans,

	ktrans,		ktrans,
	ktrans,		ktrans,		ktrans,
	ktrans,		ktrans,		ktrans
),

// LAYER 2: Numpad.
KB_MATRIX_LAYER(
	// unused
	NULL,
	// Left hand.
	NULL,		NULL,		NULL,		NULL,		NULL,		NULL,		ktrans,
	ktrans,		NULL,		NULL,		NULL,		NULL,		NULL,		NULL,
	ktrans,		NULL,		NULL,		NULL,		NULL,		NULL,
	ktrans,		NULL,		NULL,		NULL,		NULL,		NULL,		NULL,
	ktrans,		kprrel,		ktrans,		ktrans,		ktrans,

																ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,
													ktrans,		ktrans,		ktrans,

	// Right hand.
	kprrel,		NULL,		NULL,		kprrel,		kprrel,		kprrel,		NULL,
	slponum,	NULL,		kprrel,		kprrel,		kprrel,		kprrel,		NULL,
				NULL,		kprrel,		kprrel,		kprrel,		kprrel,		NULL,
	NULL,		NULL,		kprrel,		kprrel,		kprrel,		kprrel,		ktrans,
							NULL,		NULL,		kprrel,		kprrel,		ktrans,

	ktrans,		ktrans,
	ktrans,		ktrans,		ktrans,
	ktrans,		ktrans,		kprrel
),

// RELEASE L3: nothing (just making sure unused
    // functions don't get compiled out)
    KB_MATRIX_LAYER( NULL,
    // other
    kprrel, lpush8, lpop8,  NULL,   NULL,   NULL,   NULL,   NULL,
    ktog,   lpush9, lpop9,  NULL,   NULL,   NULL,   NULL,   NULL,
    ktrans, lpush10,lpop10, NULL,   NULL,   NULL,   NULL,   NULL,
    lpush1, lpop1,  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
    lpush2, lpop2,  dbtldr, NULL,   NULL,   NULL,   NULL,   NULL,
    lpush3, lpop3,  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
    lpush4, lpop4,  s2kcap, NULL,   NULL,   NULL,   NULL,   NULL,
    lpush5, lpop5,  slpunum,NULL,   NULL,   NULL,   NULL,   NULL,
    lpush6, lpop6,  slponum,NULL,   NULL,   NULL,   NULL,   NULL,
    lpush7, lpop7,  NULL,   NULL,   NULL,   NULL,   NULL,   NULL
),
};
