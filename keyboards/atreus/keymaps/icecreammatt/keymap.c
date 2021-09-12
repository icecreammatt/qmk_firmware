// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

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
// #define QWERTY_PLN 2
// #define COLEMAK_PLN 3
#define NUMERIC 3 // 10 Key
#define NUM_SPECIAL 4 // 10 key special
// #define SPECIAL 6 // Programming itesm
#define POK3R 5 // Media keys
// #define FKEYS 8
// #define WINDOW 9  // Window Tiling Mode
// #define MOUSE 10
// #define BLANK_11 11
// #define BLANK_12 12
#define GAMING 6
// #define PROGRAM 14
// #define MODE_SWITCH 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//   [QWERTY] = LAYOUT( /* 0 Qwerty */
//     LT(MODE_SWITCH, KC_Q), LT(WINDOW, KC_W),      LT(SPECIAL, KC_E), LT(NUMERIC,KC_R),      LT(MOUSE, KC_T),                                 KC_Y,    KC_U,      KC_I,     KC_O,    KC_P,
//     KC_A,                  KC_S,                  KC_D,              KC_F,                  LT(FKEYS, KC_G),                                 KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN,
//     SFT_Z,                 ALT_X,                 GUI_C,             CTL_V,                 LT(NUM_SPECIAL,KC_B),                            KC_N,    CTL_M,    GUI_COMM, ALT_DOT, SFT_SLSH,
//     KC_TAB,                TO(QWERTY_PLN),        KC_GUI,            MO(POK3R),             KC_SPC,          LCTL_T(KC_SPC), LALT_T(KC_ESC), KC_BSPC, MO(POK3R), KC_MINS,  KC_QUOT, KC_ENT
//   ),

//   [COLEMAK] = LAYOUT( /* 1 Colemak */
//     LT(MODE_SWITCH, KC_Q),  LT(WINDOW, KC_W),     LT(SPECIAL, KC_F), LT(NUMERIC, KC_P),      LT(MOUSE, KC_B),                                KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN,
//     HOME_A,                 HOME_R,               HOME_S,            HOME_T,                 LT(FKEYS, KC_G),                                KC_M,    HOME_N, HOME_E,  HOME_I,  HOME_O,
//     LSFT_T(KC_Z),           KC_X,                 KC_C,              LT(NUM_SPECIAL, KC_D),  KC_V,                                           KC_K,    KC_H,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
//     KC_TAB,                 TO(COLEMAK_PLN),      KC_ENT,           MO(POK3R),              KC_SPC,         LCTL_T(KC_SPC), LALT_T(KC_ESC), KC_BSPC, MO(POK3R), KC_MINS, KC_QUOT, KC_ENT
//     // move home row mod keys to bottom row K H COMM KC_DOT
//   ),

  // QWERTY Plain
  [QWERTY] = LAYOUT(
    KC_Q,        KC_W,                KC_E,         KC_R,      KC_T,                                     KC_Y,    KC_U,      KC_I,    KC_O,           KC_P,
    KC_A,        KC_S,                KC_D,         KC_F,      KC_G,                                     KC_H,    KC_J,      KC_K,    KC_L,           KC_QUOT,
    LSFT_T(KC_Z),KC_X,                KC_C,         KC_V,      KC_B,                                     KC_N,    KC_M,      KC_COMM, KC_DOT,         RSFT_T(KC_SLSH),
    KC_TAB,      MO(NUM_SPECIAL),     MO(NUMERIC),  KC_LGUI,   KC_SPC,  LCTL_T(KC_SPC), LALT_T(KC_ESC),  KC_BSPC, MO(POK3R), KC_MINS, ALL_T(KC_SCLN), KC_ENT
  ),

  // COLEMAK Plain
  [COLEMAK] = LAYOUT(
    KC_Q,        KC_W,                KC_F,         KC_P,      KC_B,                                     KC_J,    KC_L,      KC_U,    KC_Y,           KC_QUOT,
    KC_A,        KC_R,                KC_S,         KC_T,      KC_G,                                     KC_M,    KC_N,      KC_E,    KC_I,           KC_O,
    LSFT_T(KC_Z),KC_X,                KC_C,         KC_D,      KC_V,                                     KC_K,    KC_H,      KC_COMM, KC_DOT,         RSFT_T(KC_SLSH),
    KC_TAB,      MO(NUM_SPECIAL),     MO(NUMERIC),  KC_LGUI,   KC_SPC,  LCTL_T(KC_SPC), LALT_T(KC_ESC),  KC_BSPC, MO(POK3R), KC_MINS, ALL_T(KC_SCLN), KC_ENT
  ),

  [NUMERIC] = LAYOUT( /* NUMERIC */
    KC_PSCR,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                      KC_PSLS,    KC_7,    KC_8,     KC_9,    KC_PMNS,
    KC_SLCK,    KC_F4,    KC_F5,    KC_F6,    KC_F11,                      KC_PAST,    KC_4,    KC_5,     KC_6,    KC_PPLS,
    KC_LSFT,    KC_F1,    KC_F2,    KC_F3,    KC_F12,                      KC_NO,      KC_1,    KC_2,     KC_3,    KC_EQL,
    KC_CAPS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BSPC,    KC_0,    KC_0,     KC_PDOT, KC_ENT
  ),

  [NUM_SPECIAL] = LAYOUT( /* NUM_SPECIAL */
    KC_NO,          KC_NO,      RESET,      KC_NO,      TO(QWERTY),                      KC_PSLS,    KC_AMPR,    KC_ASTR,     KC_BSLS,    KC_PMNS,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      TO(COLEMAK),                     KC_PAST,    KC_DLR,     KC_PERC,     KC_CIRC,    KC_PIPE,
    KC_LSFT,        KC_NO,      KC_NO,      KC_NO,      TO(GAMING),                      KC_NO,      KC_EXLM,    KC_AT,       KC_HASH,    KC_EQL,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS,  KC_BSPC,    KC_NO,      KC_NO,       KC_PDOT,    KC_ENT
  ),

//   [SPECIAL] = LAYOUT( /* PROGRAM SPECIAL */
//     KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PIPE,    KC_DQUO,    KC_LBRC,    KC_RBRC,   KC_PMNS,
//     KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_QUOT,    KC_LCBR,    KC_RCBR,   KC_PPLS,
//     KC_LSFT,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_GRV,     KC_LPRN,    KC_RPRN,   KC_BSLS,
//     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BSPC,    KC_NO,      KC_EQL,     KC_TILD,   KC_UNDS
//   ),

  [POK3R] = LAYOUT( /* POK3R */
    KC_MPRV,        KC_MNXT,    KC_LBRC,    KC_RBRC,    KC_MPLY,                     KC_INS,    KC_PGUP,    KC_HOME,  KC_PGDN,  KC_DEL,
    KC_GRV,         KC_MRWD,    KC_LCBR,    KC_RCBR,    KC_VOLU,                     KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT, KC_ENT,
    KC_LSFT,        KC_MFFD,    KC_LPRN,    KC_RPRN,    KC_VOLD,                     KC_NO,     KC_DEL,     KC_END,   KC_PAUS,  KC_RSFT,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MUTE,  KC_TRNS, KC_TRNS,  KC_NO,     KC_TRNS,    KC_NO,    KC_NO,    KC_NO
  ),

  [GAMING] = LAYOUT( /* GAMING */
    KC_GRV,  KC_1,     KC_2,      KC_3,      KC_4,                    KC_5,     KC_6,                   KC_7,    KC_8,      KC_9,
    KC_TAB,  KC_Q,     KC_W,      KC_E,      KC_R,                    KC_T,     KC_Y,                   KC_U,    KC_I,      KC_O,
    KC_LCTL, KC_A,     KC_S,      KC_D,      KC_F,                    KC_G,     KC_H,                   KC_J,    KC_UP,     KC_0,
    KC_LSFT ,KC_Z,     KC_X,      KC_C,      KC_V,  KC_SPC , KC_ESC,  KC_B,     TO(QWERTY),             KC_LEFT, KC_DOWN,   KC_RIGHT
  ),

//   [WINDOW] = LAYOUT( /* WINDOW */
//     LCTL(KC_UP),    KC_NO,      LCTL(KC_DOWN),KC_NO,       KC_NO,                       LCA(KC_D),     LCA(KC_E),     LCA(KC_F),     LCA(KC_T),      LCA(KC_G),
//     KC_TRNS,        KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_NO,              uu         LCA(KC_LEFT),  LCA(KC_DOWN),  LCA(KC_UP),    LCA(KC_RIGHT),  LGUI(KC_GRV),
//     KC_NO,          KC_NO,      LCA(KC_C),    LCA(KC_ENT), KC_NO,                       LCA(KC_U),     LCA(KC_J),     LCA(KC_K),     LCA(KC_I),      SGUI(KC_GRV),
//     KC_TRNS,        KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS, KC_GRV,   SGUI(KC_TAB),  LGUI(KC_TAB),  LCAG(KC_LEFT), LCAG(KC_RIGHT), KC_NO
//   ),

//   [MOUSE] = LAYOUT( /* MOUSE */
//     KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_WH_U,    KC_BTN1,    KC_BTN3,    KC_BTN2,    KC_WH_D,
//     KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_WH_U,
//     KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_WH_L,    KC_BTN4,    KC_BTN5,    KC_NO,      KC_WH_R,
//     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  LGUI(KC_R), KC_NO,      KC_ACL0,    KC_ACL1,    KC_ACL2
//   ),

  // BLANK
//   [BLANK_11] = LAYOUT(
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
//     KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO
//   ),

  // BLANK
//   [BLANK_12] = LAYOUT(
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
//     KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO
//   ),

//   [PROGRAM] = LAYOUT( /* PROGRAM MODE */
//     LT(MODE_SWITCH, KC_D),   KC_E,       KC_B,      KC_U,      KC_G,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
//     KC_NO,                   KC_NO,      KC_NO,     KC_NO,     KC_NO,                         KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,KC_NO,
//     KC_NO,                   KC_NO,      KC_NO,     KC_NO,     KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
//     KC_NO,                   KC_NO,      KC_NO,     KC_NO,     KC_NO, TO(QWERTY), KC_ENT,     KC_BSPC,  KC_NO,    EEP_RST,  DEBUG,   RESET
//   ),

//   [MODE_SWITCH] = LAYOUT( /* MODE SWITCH */
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      TO(GAMING),                       KC_NO,    KC_NO,      KC_NO,        KC_NO,        TO(PROGRAM),
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                            KC_NO,    KC_NO,      KC_NO,        KC_NO,        KC_NO,
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                            KC_NO,    KC_NO,      KC_NO,        KC_NO,        KC_NO,
//     KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,  TO(QWERTY), TO(COLEMAK),  KC_NO,    KC_NO,     DF(QWERTY),   DF(COLEMAK),  KC_NO
//   ),



  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  // [_RS] = LAYOUT( /* [> RAISE <] */
  //   KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
  //   KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
  //   KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
  //   TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  // [_LW] = LAYOUT( /* [> LOWER <] */
  //   KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
  //   KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
  //   KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
  //   KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(QWERTY), KC_PSCR, KC_SLCK, KC_PAUS )
};
