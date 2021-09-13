#include QMK_KEYBOARD_H

#undef TAPPING_TERM
#define TAPPING_TERM 300

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define QWERTY 0
#define COLEMAK 1
#define STANDARD 2
#define STDG 3
#define NUMERIC 4
#define NUM_SPECIAL 5
#define POK3R 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // QWERTY
  [QWERTY] = LAYOUT(
    KC_Q,        KC_W,                KC_E,         KC_R,      KC_T,                                     KC_Y,    KC_U,      KC_I,    KC_O,           KC_P,
    KC_A,        KC_S,                KC_D,         KC_F,      KC_G,                                     KC_H,    KC_J,      KC_K,    KC_L,           KC_QUOT,
    LSFT_T(KC_Z),KC_X,                KC_C,         KC_V,      KC_B,                                     KC_N,    KC_M,      KC_COMM, KC_DOT,         RSFT_T(KC_SLSH),
    KC_TAB,      MO(NUM_SPECIAL),     MO(NUMERIC),  KC_LGUI,   KC_SPC,  LCTL_T(KC_SPC), LALT_T(KC_ESC),  KC_BSPC, MO(POK3R), KC_MINS, ALL_T(KC_SCLN), KC_ENT
  ),

  // COLEMAK
  [COLEMAK] = LAYOUT(
    KC_Q,        KC_W,                KC_F,         KC_P,      KC_B,                                     KC_J,    KC_L,      KC_U,    KC_Y,           KC_QUOT,
    KC_A,        KC_R,                KC_S,         KC_T,      KC_G,                                     KC_M,    KC_N,      KC_E,    KC_I,           KC_O,
    LSFT_T(KC_Z),KC_X,                KC_C,         KC_D,      KC_V,                                     KC_K,    KC_H,      KC_COMM, KC_DOT,         RSFT_T(KC_SLSH),
    KC_TAB,      MO(NUM_SPECIAL),     MO(NUMERIC),  KC_LGUI,   KC_SPC,  LCTL_T(KC_SPC), LALT_T(KC_ESC),  KC_BSPC, MO(POK3R), KC_MINS, ALL_T(KC_SCLN), KC_ENT
  ),

  [STANDARD] = LAYOUT( /* GAMING */
    KC_GRV,  KC_1,     KC_2,      KC_3,      KC_4,                    KC_5,     KC_6,                   KC_7,    KC_8,      KC_9,
    KC_TAB,  KC_Q,     KC_W,      KC_E,      KC_R,                    KC_T,     KC_Y,                   KC_U,    KC_I,      KC_O,
    KC_LCTL, KC_A,     KC_S,      KC_D,      KC_F,                    KC_G,     KC_H,                   KC_J,    KC_UP,     KC_0,
    KC_LSFT, KC_Z,     KC_X,      KC_C,      KC_V,  KC_TRNS, KC_TRNS,  KC_B,    TO(QWERTY),             KC_LEFT, KC_DOWN,   KC_RIGHT
  ),

  [STDG] = LAYOUT( /* GAMING 2 */
    KC_TAB,  KC_Q,     KC_W,             KC_E,             KC_R,                       KC_T,        KC_Y,                KC_U,    KC_I,      KC_O,
    KC_LCTL, KC_A,     KC_S,             KC_D,             KC_F,                       KC_G,        KC_H,                KC_J,    KC_K,      KC_L,
    KC_LSFT, KC_Z,     KC_X,             KC_C,             KC_V,                       KC_B,        KC_N,                KC_M,    KC_UP,     KC_P,
    KC_GRV,  KC_NO,    MO(NUMERIC),      MO(NUM_SPECIAL),  KC_SPC,  KC_TRNS, KC_TRNS,  KC_BSPC,     TO(QWERTY),          KC_LEFT, KC_DOWN,   KC_RIGHT
  ),

  [NUMERIC] = LAYOUT( /* NUMERIC */
    KC_PSCR,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                      KC_PSLS,    KC_7,    KC_8,     KC_9,    KC_PMNS,
    KC_SLCK,    KC_F4,    KC_F5,    KC_F6,    KC_F11,                      KC_PAST,    KC_4,    KC_5,     KC_6,    KC_PPLS,
    KC_LSFT,    KC_F1,    KC_F2,    KC_F3,    KC_F12,                      KC_NO,      KC_1,    KC_2,     KC_3,    KC_EQL,
    KC_CAPS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BSPC,    KC_0,    KC_0,     ALL_T(KC_PDOT), KC_ENT
  ),

  [NUM_SPECIAL] = LAYOUT( /* NUM_SPECIAL */
    RESET,          KC_1,      KC_2,      KC_3,      TO(QWERTY),                      KC_PSLS,    KC_AMPR,    KC_ASTR,     KC_BSLS,           KC_PMNS,
    TO(STDG),       KC_4,      KC_5,      KC_6,      TO(COLEMAK),                     KC_PAST,    KC_DLR,     KC_PERC,     KC_CIRC,           KC_PIPE,
    KC_LSFT,        KC_7,      KC_8,      KC_9,      TO(STANDARD),                    KC_NO,      KC_EXLM,    KC_AT,       KC_HASH,           KC_EQL,
    KC_TRNS,        KC_TRNS,   KC_0,      KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS,  KC_BSPC,    KC_NO,      KC_NO,       ALL_T(KC_PDOT),    KC_ENT
  ),

  [POK3R] = LAYOUT( /* POK3R */
    KC_MPRV,        KC_MNXT,    KC_LBRC,    KC_RBRC,    KC_MPLY,                     KC_INS,    KC_PGUP,    KC_HOME,  KC_PGDN,  KC_DEL,
    KC_GRV,         KC_MRWD,    KC_LCBR,    KC_RCBR,    KC_VOLU,                     KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT, KC_ENT,
    KC_LSFT,        KC_MFFD,    KC_LPRN,    KC_RPRN,    KC_VOLD,                     CG_SWAP,   KC_DEL,     KC_END,   KC_PAUS,  KC_RSFT,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MUTE,  KC_TRNS, KC_TRNS,  CG_NORM,   KC_TRNS,    KC_NO,    EEP_RST,    KC_NO
  ),


};
