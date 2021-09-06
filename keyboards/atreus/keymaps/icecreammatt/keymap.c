// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)


// These are for Colmak layer
// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define COLEMAK 1
#define NUMERIC 2 // 10 Key
#define NUM_SPECIAL 3 // 10 key special
// #define _LW 3
#define SPECIAL 4 // Programming itesm
#define WINDOW 5  // Window Tiling Mode
#define FN 6
// #define _RS 6
#define POK3R 7
#define MOUSE 8
#define FKEYS 10
#define GAMING 13
#define PROGRAM 14
#define MODE_SWITCH 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT( /* 0 Qwerty */
    LT(MODE_SWITCH, KC_Q), LT(WINDOW, KC_W),      KC_E,              KC_R,              LT(MOUSE, KC_T),                                 KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,
    CTL_A,                 ALT_S,                 GUI_D,             SFT_F,             LT(FKEYS, KC_G),                                 KC_H,    SFT_J,  GUI_K,   ALT_L,   CTL_SCLN,
    LSFT_T(KC_Z),          LT(NUM_SPECIAL, KC_X), LT(NUMERIC, KC_C), LT(SPECIAL, KC_V), KC_B,                                            KC_N,    KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    KC_ESC,                KC_TAB,                KC_LGUI,           KC_LSFT,           KC_SPC,          LCTL_T(KC_SPC), LALT_T(KC_ESC), KC_BSPC, MO(FN), KC_MINS, KC_QUOT, KC_ENT
  ),

  [COLEMAK] = LAYOUT( /* 1 Colemak */
    LT(MODE_SWITCH, KC_Q),  LT(WINDOW, KC_W),      KC_F,              KC_P,              LT(MOUSE, KC_B),                                KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN,
    HOME_A,                 HOME_R,                HOME_S,            HOME_T,            LT(FKEYS, KC_G),                                KC_M,    HOME_N, HOME_E,  HOME_I,  HOME_O,
    LSFT_T(KC_Z),           LT(NUM_SPECIAL, KC_X), LT(NUMERIC, KC_C), LT(SPECIAL, KC_D), KC_V,                                           KC_K,    KC_H,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    KC_ESC,                 KC_TAB,                KC_LGUI,           KC_LSFT,           KC_SPC,         LCTL_T(KC_SPC), LALT_T(KC_ESC), KC_BSPC, MO(FN), KC_MINS, KC_QUOT, KC_ENT
  ),

  [NUMERIC] = LAYOUT( /* 2 NUMERIC */
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PSLS,    KC_7,    KC_8,     KC_9,    KC_PMNS,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PAST,    KC_4,    KC_5,     KC_6,    KC_PPLS,
    KC_LSFT,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_ENT,     KC_1,    KC_2,     KC_3,    KC_EQL,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BSPC,    KC_0,    KC_0,     KC_PDOT, KC_ENT
  ),

  [NUM_SPECIAL] = LAYOUT( /* 3 NUM_SPECIAL */
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PSLS,    KC_AMPR,    KC_ASTR,     KC_BSLS,    KC_PMNS,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PAST,    KC_DLR,     KC_PERC,     KC_CIRC,    KC_PPLS,
    KC_LSFT,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_ENT,     KC_EXLM,    KC_AT,       KC_HASH,    KC_EQL,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BSPC,    KC_NO,      KC_NO,       KC_PDOT,    KC_ENT
  ),

  [SPECIAL] = LAYOUT( /* 4 PROGRAM SPECIAL */
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PSLS,    KC_LBRC,    KC_RBRC,    KC_BSLS,   KC_PMNS,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_DQUO,    KC_LCBR,    KC_RCBR,    KC_QUOT,   KC_PPLS,
    KC_LSFT,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_UNDS,    KC_LPRN,    KC_RPRN,    KC_GRV,    KC_EQL,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BSPC,    KC_NO,      KC_NO,      KC_TILD,   KC_PIPE
  ),

  [WINDOW] = LAYOUT( /* WINDOW 5 */
    KC_NO,          KC_NO,      LSFT(KC_TAB), KC_TAB,      LSFT(KC_GRV),                LCTL(KC_LEFT),   LCTL(KC_DOWN),  LCTL(KC_UP),  LCTL(KC_RIGHT), KC_NO,
    KC_NO,          KC_NO,      KC_NO,        LAG(KC_F),   KC_GRV,                      LAG(KC_LEFT),    LAG(KC_DOWN),   LAG(KC_UP),   LAG(KC_RIGHT),  KC_NO,
    KC_NO,          LAG(KC_C),  KC_NO,        KC_NO,       KC_NO,                       KC_NO,           KC_NO,          KC_NO,        KC_NO,          KC_NO,
    KC_TRNS,        KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_NO,           LCAG(KC_LEFT),  LAG(KC_C),    LCAG(KC_RIGHT), KC_ENT
  ),

  [FN] = LAYOUT( /* FN #6 */
    KC_EXLM,        KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                     KC_CIRC,   KC_AMPR,    KC_ASTR,  KC_LPRN,  KC_RPRN,
    KC_NO,          KC_NO,      KC_LBRC,    KC_RBRC,    KC_NO,                       KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT, KC_NO,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,     KC_END,     KC_END,   KC_NO,    KC_NO,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_DEL,    KC_NO,      KC_NO,    KC_NO,    KC_NO
  ),

  [POK3R] = LAYOUT( /* POK3R 7 */
    KC_MRWD,        KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MFFD,                     KC_INS,    KC_PGUP,    KC_HOME,  KC_PGDN,  KC_PAUS,
    KC_NO,          KC_NO,      KC_VOLD,    KC_VOLU,    KC_MUTE,                     KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT, KC_NO,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,     KC_END,     KC_END,   KC_NO,    KC_NO,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_DEL,    KC_NO,      KC_NO,    KC_NO,    KC_NO
  ),

  [MOUSE] = LAYOUT( /* MOUSE 8 */
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_WH_U,    KC_BTN1,    KC_BTN3,    KC_BTN2,    KC_WH_D,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_NO,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_WH_L,    KC_BTN4,    KC_BTN5,    KC_NO,      KC_WH_R,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  LGUI(KC_R), KC_NO,      KC_ACL0,    KC_ACL1,    KC_ACL2
  ),

  [FKEYS] = LAYOUT( /* FKEYS 10 */
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_CAPS,    KC_F7,    KC_F8,    KC_F9,    KC_F13,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_PSCR,    KC_F4,    KC_F5,    KC_F6,    KC_F14,
    KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_SLCK,    KC_F1,    KC_F2,    KC_F3,    KC_F15,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_PAUS,    KC_F10,   KC_F11,   KC_F12,   KC_F16
  ),

  //TODO
  [GAMING] = LAYOUT( /* GAMING 13 */
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,        TO(PROGRAM),
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,  TO(_QW), TO(COLEMAK),  KC_NO,    KC_NO,    DF(_QW),  DF(COLEMAK),  TO(GAMING)
  ),

  [PROGRAM] = LAYOUT( /* PROGRAM MODE 14 */
    LT(MODE_SWITCH, KC_D),   KC_NO,      KC_NO,     KC_NO,     KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_NO,                   KC_NO,      KC_NO,     KC_NO,     KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_NO,                   KC_NO,      KC_NO,     KC_NO,     KC_NO,                         KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_NO,                   KC_NO,      KC_NO,     KC_NO,     KC_NO,  TO(_QW), TO(COLEMAK),  KC_NO,    KC_NO,    EEP_RST,  DEBUG,   RESET
  ),

  [MODE_SWITCH] = LAYOUT( /* MODE SWITCH 15 */
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        TO(PROGRAM),
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,                         KC_NO,    KC_NO,    KC_NO,      KC_NO,        KC_NO,
    KC_NO,        KC_NO,      KC_NO,      KC_NO,      KC_NO,  TO(_QW), TO(COLEMAK),  KC_NO,    KC_NO,    DF(_QW),    DF(COLEMAK),  TO(GAMING)
  ),



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
  //   KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )
};
