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
    KC_Q,        KC_W,                KC_E,             KC_R,      KC_T,                                                    KC_Y,             KC_U,      KC_I,           KC_O,            KC_P,
    KC_A,        KC_S,                KC_D,             KC_F,      KC_G,                                                    KC_H,             KC_J,      KC_K,           KC_L,            KC_QUOT,
    LSFT_T(KC_Z),KC_X,                KC_C,             KC_V,      KC_B,                                                    KC_N,             KC_M,      KC_COMM,        KC_DOT,          RSFT_T(KC_SLSH),
    KC_TAB,      LALT_T(KC_MINS),     MO(NUM_SPECIAL),  KC_LGUI,   KC_SPC,  LCTL_T(KC_MINS), LT(NUMERIC, KC_ESC),           LSFT_T(KC_BSPC),  MO(POK3R), ALL_T(KC_DEL),  LALT_T(KC_SCLN), KC_ENT
  ),

  // COLEMAK
  [COLEMAK] = LAYOUT(
    KC_Q,        KC_W,                KC_F,             KC_P,      KC_B,                                                   KC_J,             KC_L,      KC_U,           KC_Y,            KC_QUOT,
    KC_A,        KC_R,                KC_S,             KC_T,      KC_G,                                                   KC_M,             KC_N,      KC_E,           KC_I,            KC_O,
    LSFT_T(KC_Z),KC_X,                KC_C,             KC_D,      KC_V,                                                   KC_K,             KC_H,      KC_COMM,        KC_DOT,          RSFT_T(KC_SLSH),
    KC_TAB,      LALT_T(KC_MINS),     MO(NUM_SPECIAL),  KC_LGUI,   KC_SPC,  LCTL_T(KC_MINS), LT(NUMERIC, KC_ESC),          LSFT_T(KC_BSPC),  MO(POK3R), ALL_T(KC_DEL),  LALT_T(KC_SCLN), KC_ENT
  ),

  // Gaming
  [STANDARD] = LAYOUT(
    KC_GRV,  KC_1,     KC_2,      KC_3,      KC_4,                     KC_5,     KC_6,                   KC_7,    KC_8,      KC_9,
    KC_TAB,  KC_Q,     KC_W,      KC_E,      KC_R,                     KC_T,     KC_Y,                   KC_U,    KC_I,      KC_O,
    KC_LCTL, KC_A,     KC_S,      KC_D,      KC_F,                     KC_G,     KC_H,                   KC_J,    KC_UP,     KC_0,
    KC_LSFT, KC_Z,     KC_X,      KC_C,      KC_V,  KC_TRNS, KC_TRNS,  KC_B,     TO(QWERTY),             KC_LEFT, KC_DOWN,   KC_RIGHT
  ),

  // Gaming II
  [STDG] = LAYOUT(
    KC_GRV,  KC_Q,          KC_X,             KC_E,             KC_R,                       KC_T,        KC_Y,                KC_U,    KC_I,      KC_O,
    KC_LSFT, KC_A,          KC_W,             KC_D,             KC_F,                       KC_G,        KC_H,                KC_J,    KC_K,      KC_L,
    KC_LGUI, KC_Z,          KC_S,             KC_C,             KC_V,                       KC_B,        KC_N,                KC_M,    KC_UP,     KC_P,
    KC_TAB,  MO(NUMERIC),   MO(NUM_SPECIAL),  MO(NUM_SPECIAL),  KC_SPC,  KC_LGUI, KC_TRNS,  KC_BSPC,     KC_ENT,              KC_LEFT, KC_DOWN,   KC_RIGHT
  ),

  // Numeric
  [NUMERIC] = LAYOUT(
    KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F10,                                                       KC_INS,     KC_PGDN,            KC_HOME,            KC_PGUP,            KC_DEL,
    KC_SLCK,    KC_F4,    KC_F5,    KC_F6,    KC_F11,                                                       KC_LEFT,    KC_DOWN,            KC_UP,              KC_RIGHT,           KC_CAPS,
    KC_LSFT,    KC_F7,    KC_F8,    KC_F9,    KC_F12,                                                       KC_MPLY,    KC_WH_D,            KC_END,             KC_WH_U,            LSFT_T(KC_MUTE),
    KC_TAB,     KC_TRNS,  KC_PSCR,  KC_PAUS,  KC_TRNS,  LCTL_T(KC_SPC),  LT(NUMERIC, KC_ESC),               CG_NORM,    KC_VOLD,            ALL_T(KC_DEL),      LALT_T(KC_VOLU),    CG_SWAP
  ),

  // Special
  [NUM_SPECIAL] = LAYOUT(
    KC_WH_U,        KC_1,              KC_2,      KC_3,     TO(QWERTY),                                                 KC_PSLS,           KC_AMPR,            KC_ASTR,         KC_BSLS,           KC_COLN,
    KC_BTN3,        KC_4,              KC_5,      KC_6,     TO(COLEMAK),                                                KC_PAST,           KC_DLR,             KC_PERC,         KC_CIRC,           KC_SCLN,
    KC_WH_D,        KC_7,              KC_8,      KC_9,     TO(STDG),                                                   RESET,             KC_EXLM,            KC_AT,           KC_HASH,           LSFT_T(KC_EQL),
    KC_TAB,         LALT_T(KC_MINS),   KC_0,      KC_TRNS,  TO(STANDARD),     LCTL_T(KC_MINS),  LT(NUMERIC, KC_ESC),    LSFT_T(KC_BSPC),   ALL_T(KC_DEL),      ALL_T(KC_PIPE),  LALT_T(KC_PDOT),   KC_ENT
  ),

  // Pok3r - special characters and numbers
  [POK3R] = LAYOUT(
    KC_TILD,        KC_EXLM,            KC_LBRC,    KC_RBRC,    KC_PIPE,                                                    KC_PSLS,            KC_7,     KC_8,             KC_9,               KC_PMNS,
    KC_GRV,         KC_EQL,             KC_LPRN,    KC_RPRN,    KC_DLR,                                                     KC_PAST,            KC_4,     KC_5,             KC_6,               KC_PPLS,
    KC_CIRC,        KC_AMPR,            KC_LCBR,    KC_RCBR,    KC_AT,                                                      KC_PERC,            KC_1,     KC_2,             KC_3,               LSFT_T(KC_EQL),
    KC_TAB,         LALT_T(KC_UNDS),    KC_HASH,    KC_LGUI,    KC_SPC,   LCTL_T(KC_MINS),  LT(NUMERIC, KC_ESC),            LSFT_T(KC_BSPC),    KC_TRNS,  ALL_T(KC_0),      LALT_T(KC_PDOT),    KC_ENT
  ),

};

// Try use JK as alternate esc?
// figure out esc key

// enter key
// alt/opion key

/* Layer 0: Base keys
 *
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * | Q   | W   | E   | R   | T   |                      | Y   | U   | I   | O   | P   |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * | A   | S   | D   | F   | G   |                      | H   | J   | K   | L   | ' " | <-- ' trigger mouse layer
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |SHF/Z| X/AL| C   | V   | B   |                      | N   | M   | <,  | >.MO|SHF/?|
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *                     >. key when held long activates mouse mode L4
 *               .-------.-------.-------.      .-------.-------.
 *               |CMD/ESC|  SPC  |CTR/TAB|      | ENTER |L1/BSP |
 *               '-------'-------'-------'      '-------'-------'
 */

/* Layer 1: Symbols
 *
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |  ~  |  !  |  [  |  ]  |  |  |                      |  ^  |  &  |  *  |TO(M)| DEL |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |L2 ` |L11 =|L4 ( |L3 ) |  @  |                      |LEFT |DOWN | UP  |RGHT | ;:  | <-- ; key should trigger mouse layer when held
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * | SHF | ALT |CMD {|CTR }|  %  |                      |  #  |  -_ |  +  |  :  |SHF\ |
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
 *               |CMD/ESC|L3/SPC |CTR/TAB|      |       |(hold) |
 *               '-------'-------'-------'      '-------'-------'
 */

/* Layer 1.1: Symbols Shifted - accessed by shift key on layer 1
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |     |     |     |                      |     |  #  |  *  |  %  |     |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |     |hold |  |  |  @  |     |                      |     |  ^  |  $  |  0  |  :  |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     |     |     |     |     |                      |     |  _  |     |     |     |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               .-------.-------.-------.      .-------.-------.
 *               |CMD/ESC|L2/SPC |CTR/TAB|      |       |(hold) |
 *               '-------'-------'-------'      '-------'-------'
 */

/* Layer 2: Function keys
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |ALL_T|     |     |                      |     | F7  | F8  | F9  | F10 |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |hold |PLAY |VOL- |VOL+ |     |                      |     | F4  | F5  | F6  | F11 |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * | SHF | ALT | CMD |MUTE |     |                      |     | F1  | F2  | F3  | F12 |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               .-------.-------.-------.      .-------.-------.
 *               |       |       |       |      |       |  DEL  |
 *               '-----------------------'      '-------'-------'
 */

/* Layer 3: Calc/Numpad
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |ALL_T|     |     |                      |  /  |  7  |  8  |  9  |  -  |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |T(L0)|     |     |hold |     |                      |  *  |  4  |  5  |  6  |  +  |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * | SHF | ALT |     |     |     |                      |  %  |  1  |  2  |  3  |  0  |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               .-------.-------.-------.      .-------.-------.
 *               |CMD/ESC|  SPC  |CTR/TAB|      | ENTER |L1/BSP |
 *               '-----------------------'      '-------'-------'
 */

/* Layer 4: Layer move and mouse mode
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |     |HOME |PAUSE|                      |M4   |PGDN |PGUP |     |     |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |QWERT|COLEM| hold|GAME1|GAME2|                      |WH_L | M1  | M2  |WH_R |     |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     |     |     |END  |     |                      |M5   |WH_D |WH_U |hold | M3  |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               .-------.-------.-------.      .-------.-------.
 *               |CMD/ESC|  SPC  |CTR/TAB|      | ENTER |L1/BSP |
 *               '-----------------------'      '-------'-------'
 */

/* Layer 4.1: Layer move and mouse mode
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |     |HOME |PAUSE|                      | M4  |PGDN |PGUP |HOME |     |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |QWERT|COLEM| hold|GAME1|GAME2|                      | SPC | M1  | M2  | M3  |held |< held also as mouse4 or whatever back nav for browser is
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * | SHF | ALT |     |END  |     |                      | M5  |WH_D |WH_U | END | SHF |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *              double tap WH D/U for left and right scroll
 *              double tap PGDN PGUP for home and end
 *               .-------.-------.-------.      .-------.-------.
 *               |CMD/ESC|  SPC  |CTR/TAB|      | ENTER | TO(0) |
 *               '-----------------------'      '-------'-------'
 */
