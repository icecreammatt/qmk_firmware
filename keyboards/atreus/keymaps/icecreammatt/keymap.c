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

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QUOT RGUI_T(KC_QUOT)

#define QWERTY 0
#define QWERTY_2 1
#define SYMBOL 2
#define SYMBOL_2 3
#define MOUSE 5
#define NUMPAD 6
#define NAV 7

// #define COLEMAK 1
// #define STANDARD 2
// #define STDG 3
// #define NUMERIC 4
// #define NUM_SPECIAL 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT(
    KC_Q,                   KC_W,            KC_E,             KC_R,                    KC_T,                                                  KC_Y,                KC_U,      KC_I,          KC_O,       KC_P,
    KC_A,                   KC_S,            KC_D,             KC_F,                    KC_G,                                                  KC_H,                KC_J,      KC_K,          KC_L,       KC_QUOT,
    LSFT_T(KC_Z),           KC_X,            KC_C,             KC_V,                    KC_B,                                                  KC_N,                KC_M,      KC_COMM,       KC_DOT,     RSFT_T(KC_SLSH),
    KC_NO,                  RESET,           KC_NO,            KC_LGUI,                 LT(QWERTY_2,KC_SPC), LCTL_T(KC_TAB), LT(MOUSE,KC_ESC), LT(SYMBOL, KC_BSPC), KC_NO,     KC_NO,         KC_NO,      KC_NO
  ),

  // Same as QWERTY but with GUI, ALT/OPT, CTRL, SHFT in home rows
  [QWERTY_2] = LAYOUT(
    KC_Q,                   KC_W,            KC_E,                 KC_R,                KC_T,                                                  KC_Y,                KC_U,      KC_I,           KC_O,       KC_P,
    HOME_A,                 HOME_S,          HOME_D,               HOME_F,              KC_G,                                                  KC_H,                HOME_J,    HOME_K,         HOME_L,     HOME_QUOT,
    LSFT_T(KC_Z),           KC_X,            KC_C,                 KC_V,                KC_B,                                                  KC_N,                KC_M,      KC_COMM,        KC_DOT,     RSFT_T(KC_SLSH),
    KC_UNDS,                RESET,           KC_NO,                KC_LGUI,             LT(SYMBOL, KC_SPC), LCTL_T(KC_TAB),   LT(NAV, KC_ESC), LT(NUMPAD, KC_BSPC), KC_NO,     KC_NO,          KC_NO,      KC_NO
  ),

  [SYMBOL] = LAYOUT(
    KC_TILD,                KC_EXLM,        KC_LBRC,                KC_RBRC,            KC_PIPE,                                               KC_HASH,             KC_PAST,     KC_ENT,      KC_NO,      KC_DEL,
    KC_GRV,                 KC_EQL,         KC_LPRN,                KC_RPRN,            KC_AT,                                                 KC_LEFT,             KC_DOWN,     KC_UP,       KC_RIGHT,   KC_SCLN,
    KC_AMPR,                KC_CIRC,        KC_LCBR,                KC_RCBR,            KC_DLR,                                                KC_UNDS,             KC_PMNS,     KC_PPLS,     KC_COLN,    KC_BSLS,
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            LT(NUMPAD, KC_SPC),  LCTL_T(KC_TAB),   KC_NO,          LT(SYMBOL, KC_BSPC), KC_NO,       KC_NO,       KC_NO,      KC_NO
  ),

 // switch keyboard between colmak and qwerty and gaming layer / possibly emacs nav
  [NAV] = LAYOUT(
    KC_NO,                  KC_NO,          KC_NO,                  KC_PIPE,            KC_NO,                                                 KC_NO,               KC_HASH,      KC_PAST,      KC_NO,       KC_NO,
    KC_NO,                  KC_NO,          KC_NO,                  KC_AT,              KC_NO,                                                 KC_NO,               KC_CIRC,      KC_DLR,       KC_0,        KC_COLN,
    KC_NO,                  KC_NO,          KC_NO,                  KC_PERC,            KC_NO,                                                 KC_NO,               KC_UNDS,      KC_NO,        KC_NO,       KC_RSFT,
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            KC_NO,  LCTL_T(KC_TAB),                LSFT_T(KC_NO),  KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO
  ),

  [NUMPAD] = LAYOUT(
    KC_NO,                  KC_F7,          ALL_T(KC_F8),           KC_F9,              KC_F10,                                                 KC_PSLS,             KC_7,        KC_8,        KC_9,       KC_PMNS,
    KC_NO,                  KC_F4,          KC_F5,                  KC_F6,              KC_F11,                                                 KC_PAST,             KC_4,        KC_5,        KC_6,       KC_PPLS,
    KC_NO,                  KC_F1,          KC_F2,                  KC_F3,              KC_F12,                                                 KC_PERC,             KC_1,        KC_2,        KC_3,       KC_0,
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            KC_NO,   LCTL_T(KC_TAB),               LSFT_T(KC_ESC),  KC_NO,               KC_NO,       KC_NO,       KC_NO,      KC_NO
  ),

  [MOUSE] = LAYOUT(
    RESET,                  KC_NO,          KC_NO,                  KC_NO,              KC_PAUS,                                               KC_WH_L,             KC_BTN4,      KC_BTN5,      KC_WH_R,     KC_NO,
    KC_TAB,                 KC_MUTE,        KC_VOLD,                KC_VOLU,            KC_NO,                                                 KC_HOME,             KC_WH_D,      KC_WH_U,      KC_END,      KC_PGUP,
    KC_NO,                  KC_INS,         KC_NO,                  KC_MPLY,            KC_NO,                                                 KC_NO,               KC_BTN1,      KC_BTN2,      KC_BTN3,     RSFT_T(KC_PGDN),
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            LT(NAV, KC_SPC),  LCTL_T(KC_TAB),      LSFT_T(KC_ESC), LT(SYMBOL, KC_BSPC), KC_NO,        KC_NO,        KC_NO,       KC_NO
  ),

};

// Setup JJ as ESC
// Setup JK as ESC
// SETUP CG NORM/SWAP
// figure out how to do cmd 1 or ctrl 1 with numbers doesn't seem to be working
// figure out how to do keys like option 8 to get degrees symbol might be working on mac already but needs confirm
// figure out | symbol on / key with shift on layer
// reduce taps to toggle F layer
// add double tap ESC to toggle mouse mode

// enter key

/* QWERTY: Base keys
 *
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * | Q   | W   | E   | R   | T   |                      | Y   | U   | I   | O   | P   |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * | A   | S   | D   | F   | G   |                      | H   | J   | K   | L   | ' " | <-- hold ' to trigger mouse layer
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |SHF/Z| X/AL| C   | V   | B   |                      | N   | M   | <,  | >.MO|SHF/?|
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *                     >. key when held long activates mouse mode L4?
 *                     holding SPC triggers 0.1
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |L01 SPC|CTR/TAB|      |  ESC  |L1/BSP |
 *               '-------'-------'-------'      '-------'-------'
 *                                               double tap ESC to toggle mouse mode
 *                                               long hold ESC for shift mode
 *
 *  single tap ctr sets num mode for one press?
 *
 */

/* QWERTY_2: Base keys
 *
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * | Q   | W   | E   | R   | T   |                      | Y   | U   | I   | O   | P   |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |(G) A|(A) S|(C) D|(S) F| G   |                      | H   |(S)J |(C)K |(A)L |(G)'"|
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |SHF/Z| X/AL| C   | V   | B   |                      | N   | M   | <,  | >.MO|SHF/?|
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *                     >. key when held long activates mouse mode L4
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |L01 SPC|CTR/TAB|      |  ESC  |L1/BSP |
 *               '-------'-------'-------'      '-------'-------'
 *                CMD/TAB - replace cmd/tab with mouse layer/tab
 */

/* SYMBOL: Symbols
 *
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |  ~  |  !  |  [  |  ]  |  |  |                      |  #  |  *  | ENT |TO(M)| DEL | TO(M) maybe swap with Backspace
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |L2 ` |L4  =|L11( |L3 ) |  @  |                      |LEFT |DOWN | UP  |RGHT |  ;  | <-- ; key should trigger mouse layer when held
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |  &  |  ^  |  {  |  }  |  $  |                      |  _  |  -  |  +  |  :  |SHF\ |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *                      ` key when held temp does layer2,1 (Fkeys)
 *                      = key when held temp does layer1,1
 *                      ( key when held temp does layer4(mouse)
 *                      ; key when held temp does layer4(mouse)
 *                      # key when tapped layer moves to layer4(mouse)
 *                      ) key when held temp does numpad
 * left shift is page down when tapped
 * left alt is page up when tapped
 * home is ctrl up
 * end is ctrl down
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |L3/SPC |CTR    |      |  ESC  |(hold) |
 *               '-------'-------'-------'      '-------'-------'
 */

/* NAV: Symbols Shifted
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |     |  |  |     |                      |     |  #  |  *  |     | DEL |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |     |     |     |  @  |     |                      |     |  ^  |  $  |  0  |  :  |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     |     |     |  %  |     |                      |     |  _  |     |     |     |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               .-------.-------.-------.      .-------.-------.
 *               |       | hold  |       |      | hold  |       |
 *               '-------'-------'-------'      '-------'-------'
 */

/* NUMPAD: Numpad/FKeys
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     | F7  | F8  | F9  | F10 |                      |  /  |  7  |  8  |  9  |  -  |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |     | F4  | F5  | F6  | F11 |                      |  *  |  4  |  5  |  6  |  +  |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     | F1  | F2  | F3  | F12 |                      |  %  |  1  |  2  |  3  |  0  |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               F8 bound to long press for ALL_T
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |  SPC  |CTR    |      |  ESC  |L1/BSP |
 *               '-----------------------'      '-------'-------'
 */

/* MOUSE: Layer move and mouse mode
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |RESET|     |     |     |PAUSE|                      |WH_L | M4  | M5  |WH_R |     |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * | TAB |MUTE |VOL+ |VOL- |     |                      |HOME |WH_D |WH_U | END |PGUP |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     | INS |     |PLAY |     |                      |     | M1  | M2  | M3  |PGDN |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *              double tap WH D/U for left and right scroll
 *              double tap PGDN PGUP for home and end
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |  SPC  |CTR/TAB|      |  ESC  |       |
 *               '-----------------------'      '-------'-------'
 *                                               DOUBLE TAP ESC to leave mouse mode? maybe just single click?
 */





















//   [BLANK] = LAYOUT(
//     KC_NO,                  KC_NO,          KC_NO,                  KC_NO,              KC_NO,                                                 KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO,
//     KC_NO,                  KC_NO,          KC_NO,                  KC_NO,              KC_NO,                                                 KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO,
//     KC_NO,                  KC_NO,          KC_NO,                  KC_NO,              KC_NO,                                                 KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO,
//     KC_NO,                  KC_NO,          KC_NO,                  LGUI_T(KC_TAB),     KC_NO,  LCTL_T(KC_TAB), LSFT_T(KC_ESC),                KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO
//   ),

  // Numeric
//   [NUMERIC] = LAYOUT(
//     KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F10,                                                       KC_INS,     KC_PGDN,            KC_HOME,            KC_PGUP,            KC_DEL,
//     KC_SLCK,    KC_F4,    KC_F5,    KC_F6,    KC_F11,                                                       KC_LEFT,    KC_DOWN,            KC_UP,              KC_RIGHT,           KC_CAPS,
//     KC_LSFT,    KC_F7,    KC_F8,    KC_F9,    KC_F12,                                                       KC_MPLY,    KC_WH_D,            KC_END,             KC_WH_U,            LSFT_T(KC_MUTE),
//     KC_TAB,     KC_TRNS,  KC_PSCR,  KC_PAUS,  KC_TRNS,  LCTL_T(KC_SPC),  LT(NUMERIC, KC_ESC),               CG_NORM,    KC_VOLD,            ALL_T(KC_DEL),      LALT_T(KC_VOLU),    CG_SWAP
//   ),

  // COLEMAK
//   [COLEMAK] = LAYOUT(
//     KC_Q,        KC_W,                KC_F,             KC_P,      KC_B,                                                   KC_J,             KC_L,      KC_U,           KC_Y,            KC_QUOT,
//     KC_A,        KC_R,                KC_S,             KC_T,      KC_G,                                                   KC_M,             KC_N,      KC_E,           KC_I,            KC_O,
//     LSFT_T(KC_Z),KC_X,                KC_C,             KC_D,      KC_V,                                                   KC_K,             KC_H,      KC_COMM,        KC_DOT,          RSFT_T(KC_SLSH),
//     KC_TAB,      LALT_T(KC_MINS),     MO(NUM_SPECIAL),  KC_LGUI,   KC_SPC,  LCTL_T(KC_MINS), LT(NUMERIC, KC_ESC),          LSFT_T(KC_BSPC),  MO(NUMPAD), ALL_T(KC_DEL),  LALT_T(KC_SCLN), KC_ENT
//   ),

  // Gaming
//   [STANDARD] = LAYOUT(
//     KC_GRV,  KC_1,     KC_2,      KC_3,      KC_4,                     KC_5,     KC_6,                   KC_7,    KC_8,      KC_9,
//     KC_TAB,  KC_Q,     KC_W,      KC_E,      KC_R,                     KC_T,     KC_Y,                   KC_U,    KC_I,      KC_O,
//     KC_LCTL, KC_A,     KC_S,      KC_D,      KC_F,                     KC_G,     KC_H,                   KC_J,    KC_UP,     KC_0,
//     KC_LSFT, KC_Z,     KC_X,      KC_C,      KC_V,  KC_TRNS, KC_TRNS,  KC_B,     TO(QWERTY),             KC_LEFT, KC_DOWN,   KC_RIGHT
//   ),

  // Gaming II
//   [STDG] = LAYOUT(
//     KC_GRV,  KC_Q,          KC_X,             KC_E,             KC_R,                       KC_T,        KC_Y,                KC_U,    KC_I,      KC_O,
//     KC_LSFT, KC_A,          KC_W,             KC_D,             KC_F,                       KC_G,        KC_H,                KC_J,    KC_K,      KC_L,
//     KC_LGUI, KC_Z,          KC_S,             KC_C,             KC_V,                       KC_B,        KC_N,                KC_M,    KC_UP,     KC_P,
//     KC_TAB,  MO(NUMERIC),   MO(NUM_SPECIAL),  MO(NUM_SPECIAL),  KC_SPC,  KC_LGUI, KC_TRNS,  KC_BSPC,     KC_ENT,              KC_LEFT, KC_DOWN,   KC_RIGHT
//   ),

  // Numeric
//   [NUMERIC] = LAYOUT(
//     KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F10,                                                       KC_INS,     KC_PGDN,            KC_HOME,            KC_PGUP,            KC_DEL,
//     KC_SLCK,    KC_F4,    KC_F5,    KC_F6,    KC_F11,                                                       KC_LEFT,    KC_DOWN,            KC_UP,              KC_RIGHT,           KC_CAPS,
//     KC_LSFT,    KC_F7,    KC_F8,    KC_F9,    KC_F12,                                                       KC_MPLY,    KC_WH_D,            KC_END,             KC_WH_U,            LSFT_T(KC_MUTE),
//     KC_TAB,     KC_TRNS,  KC_PSCR,  KC_PAUS,  KC_TRNS,  LCTL_T(KC_SPC),  LT(NUMERIC, KC_ESC),               CG_NORM,    KC_VOLD,            ALL_T(KC_DEL),      LALT_T(KC_VOLU),    CG_SWAP
//   ),



  // Special
//   [NUM_SPECIAL] = LAYOUT(
//     KC_WH_U,        KC_1,              KC_2,      KC_3,     TO(QWERTY),                                                 KC_PSLS,           KC_AMPR,            KC_ASTR,         KC_BSLS,           KC_COLN,
//     KC_BTN3,        KC_4,              KC_5,      KC_6,     TO(COLEMAK),                                                KC_PAST,           KC_DLR,             KC_PERC,         KC_CIRC,           KC_SCLN,
//     KC_WH_D,        KC_7,              KC_8,      KC_9,     TO(STDG),                                                   RESET,             KC_EXLM,            KC_AT,           KC_HASH,           LSFT_T(KC_EQL),
//     KC_TAB,         LALT_T(KC_MINS),   KC_0,      KC_TRNS,  TO(STANDARD),     LCTL_T(KC_MINS),  LT(NUMERIC, KC_ESC),    LSFT_T(KC_BSPC),   ALL_T(KC_DEL),      ALL_T(KC_PIPE),  LALT_T(KC_PDOT),   KC_ENT
//   ),

  // NUMPAD - special characters and numbers
//   [NUMPAD] = LAYOUT(
//     KC_TILD,        KC_EXLM,            KC_LBRC,    KC_RBRC,    KC_PIPE,                                                    KC_PSLS,            KC_7,     KC_8,             KC_9,               KC_PMNS,
//     KC_GRV,         KC_EQL,             KC_LPRN,    KC_RPRN,    KC_DLR,                                                     KC_PAST,            KC_4,     KC_5,             KC_6,               KC_PPLS,
//     KC_CIRC,        KC_AMPR,            KC_LCBR,    KC_RCBR,    KC_AT,                                                      KC_PERC,            KC_1,     KC_2,             KC_3,               LSFT_T(KC_EQL),
//     KC_TAB,         LALT_T(KC_UNDS),    KC_HASH,    KC_LGUI,    KC_SPC,   LCTL_T(KC_MINS),  LT(NUMERIC, KC_ESC),            LSFT_T(KC_BSPC),    KC_TRNS,  ALL_T(KC_0),      LALT_T(KC_PDOT),    KC_ENT
//   ),
