#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    // X_CTL,
    LGUI_ALT,
    LCTL_NAV,
    ESC_MOUSE,
    CT_CLN,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
// void x_finished(qk_tap_dance_state_t *state, void *user_data);
// void x_reset(qk_tap_dance_state_t *state, void *user_data);


// All tap dance functions would go here. Only showing this one.
// qk_tap_dance_action_t tap_dance_actions[] = {
    // [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
//     [TD_ESC_] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
// };


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
#define COLEMAK 2
#define SYMBOL 3
#define SYMBOL_2 4
#define MOUSE 5
#define NUMPAD 6
#define NAV 7

// https://docs.qmk.fm/#/feature_tap_dance?id=simple-example
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT(
    KC_Q,                   KC_W,            KC_E,             KC_R,                    KC_T,                                                  KC_Y,                KC_U,      KC_I,          KC_O,       KC_P,
    KC_A,                   KC_S,            KC_D,             KC_F,                    KC_G,                                                  KC_H,                KC_J,      KC_K,          KC_L,       KC_QUOT,
    LSFT_T(KC_Z),           KC_X,            KC_C,             KC_V,                    KC_B,                                                  KC_N,                KC_M,      KC_COMM,       KC_DOT,     RSFT_T(KC_SLSH),
    KC_NO,                  RESET,           KC_NO,            TD(LGUI_ALT),            LT(QWERTY_2,KC_SPC), TD(LCTL_NAV), TD(ESC_MOUSE),      LT(SYMBOL, KC_BSPC), KC_NO,     KC_NO,         KC_NO,      KC_NO
  ),

  // COLEMAK
  [COLEMAK] = LAYOUT(
    KC_Q,               KC_W,                KC_F,             KC_P,                    KC_B,                                                   KC_J,               KC_L,      KC_U,           KC_Y,            KC_QUOT,
    KC_A,               KC_R,                KC_S,             KC_T,                    KC_G,                                                   KC_M,               KC_N,      KC_E,           KC_I,            KC_O,
    LSFT_T(KC_Z),       KC_X,                KC_C,             KC_D,                    KC_V,                                                   KC_K,               KC_H,      KC_COMM,        KC_DOT,          RSFT_T(KC_SLSH),
    KC_NO,              RESET,               KC_NO,            TD(LGUI_ALT),            LT(QWERTY_2,KC_SPC), TD(LCTL_NAV), TD(ESC_MOUSE),      LT(SYMBOL, KC_BSPC), KC_NO,     KC_NO,          KC_NO,           KC_NO
  ),

  // Same as QWERTY but with GUI, ALT/OPT, CTRL, SHFT in home rows
  [QWERTY_2] = LAYOUT(
    KC_Q,                   KC_W,            KC_E,                 KC_R,                KC_T,                                                  KC_Y,                KC_U,      KC_I,           KC_O,       KC_P,
    HOME_A,                 HOME_S,          HOME_D,               HOME_F,              KC_G,                                                  KC_H,                HOME_J,    HOME_K,         HOME_L,     HOME_QUOT,
    LSFT_T(KC_Z),           KC_X,            KC_C,                 KC_V,                KC_B,                                                  KC_N,                KC_M,      KC_COMM,        KC_DOT,     RSFT_T(KC_SLSH),
    KC_NO,                  RESET,           KC_NO,                KC_LGUI,             LT(SYMBOL, KC_SPC), LCTL_T(KC_TAB),   LT(NAV, KC_ESC), LT(NUMPAD, KC_BSPC), KC_NO,     KC_NO,          KC_NO,      KC_NO
  ),

  [NUMPAD] = LAYOUT(
    KC_NO,                  KC_F7,          ALL_T(KC_F8),           KC_F9,              KC_F10,                                                KC_PSLS,             KC_7,        KC_8,        KC_9,       KC_PMNS,
    KC_PMNS,                KC_F4,          KC_F5,                  KC_F6,              KC_F11,                                                KC_PAST,             KC_4,        KC_5,        KC_6,       KC_PPLS,
    KC_NO,                  KC_F1,          KC_F2,                  KC_F3,              KC_F12,                                                KC_PERC,             KC_1,        KC_2,        KC_3,       KC_0,
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            KC_NO,   LCTL_T(KC_TAB),              LSFT_T(KC_ESC),  KC_NO,               KC_NO,       KC_NO,       KC_NO,      KC_NO
  ),

  [SYMBOL] = LAYOUT(
    KC_TILD,                KC_EXLM,        KC_LBRC,                KC_RBRC,            KC_PIPE,                                               KC_NO,               KC_HASH,     KC_PAST,     KC_ENT,     KC_DEL,
    KC_GRV,                 KC_EQL,         KC_LPRN,                KC_RPRN,            KC_AT,                                                 KC_LEFT,             KC_DOWN,     KC_UP,       KC_RIGHT,   TD(CT_CLN),
    KC_AMPR,                KC_CIRC,        KC_LCBR,                KC_RCBR,            KC_DLR,                                                KC_UNDS,             KC_MINS,     KC_PPLS,     KC_SCLN,    KC_BSLS,
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            LT(NUMPAD, KC_SPC),  LCTL_T(KC_TAB),LT(NUMPAD, KC_NO), LT(SYMBOL, KC_BSPC), KC_NO,       KC_NO,       KC_NO,      KC_NO
  ),

  [NAV] = LAYOUT(
    KC_NO,                  KC_NO,          KC_NO,                  KC_PIPE,            KC_NO,                                                 KC_NO,               KC_HASH,      KC_PAST,      KC_NO,       KC_NO,
    KC_NO,                  TO(COLEMAK),    TO(QWERTY),             KC_AT,              KC_NO,                                                 KC_NO,               KC_CIRC,      KC_DLR,       KC_0,        KC_SCLN,
    KC_NO,                  KC_NO,          KC_NO,                  KC_PERC,            KC_NO,                                                 KC_NO,               KC_UNDS,      KC_NO,        KC_NO,       KC_RSFT,
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            KC_NO,  LCTL_T(KC_TAB),                LSFT_T(KC_NO),  KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO
  ),

  [MOUSE] = LAYOUT(
    RESET,                  KC_MUTE,        KC_VOLD,                KC_VOLU,            KC_MPLY,                                               KC_NO,               KC_BTN4,      KC_BTN5,      KC_NO,       KC_NO,
    KC_GRV,                 S(KC_GRV),      S(KC_TAB),              KC_TAB,             KC_NO,                                                 KC_HOME,             KC_WH_D,      KC_WH_U,      KC_END,      KC_PGDN,
    KC_LSFT,                KC_PAUSE,       KC_PGDN,                KC_PGUP,            KC_INS,                                                KC_NO,               KC_BTN1,      KC_BTN2,      KC_BTN3,     RSFT_T(KC_PGUP),
    KC_NO,                  KC_NO,          KC_NO,                  KC_LGUI,            LT(NAV, KC_SPC),  LCTL_T(KC_TAB),      TD(ESC_MOUSE),  LT(NUMPAD, KC_BSPC), KC_NO,        KC_NO,        KC_NO,       KC_NO
  ),

};

// Add back gaming modes
// Alt F4

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
 *                                               single tap      - esc
 *                                               single tap hold - mouse
 *                                               double tap - mouse lock on
 *                                               double tap hold - numpad
 *
 *                                                       single tap      - backspace
 *                                                       single tap hold - shift
 *                                                       double tap      - enter
 *                                                       double tap hold - symbol
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

/* SYMBOL: Symbols
 * TODO:
 * switch ] ) } to | @ $ with double tap
 * switch [ ( { to ! = ^ with double tap
 * switch * to # when double tapping
 * switch - to _ when double tapping
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |  ~  |  !  |  [  |  ]  |  |  |                      |     |  #  |  *  | ENT | DEL |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |  `  |  =  |  (  |  )  |  @  |                      |LEFT |DOWN | UP  |RGHT |  :  | <-- ; key should trigger mouse layer when held
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |  &  |  ^  |  {  |  }  |  $  |                      |  _  |  -  |  +  |  ;  |SHF\ |
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
 *               | LGUI  |L3/SPC |CTR    |      |MO(NUM)|(hold) |
 *               '-------'-------'-------'      '-------'-------'
 */

/* NAV: Symbols Shifted
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |     |  |  |     |                      |     |  #  |  *  |     | DEL |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |     |     |     |  @  |     |                      |     |  ^  |  $  |  0  |  ;  |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     |     |     |  %  |     |                      |     |  _  |  &  |     |     |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *               .-------.-------.-------.      .-------.-------.
 *               |       | hold  |       |      | hold  |       |
 *               '-------'-------'-------'      '-------'-------'
 */

/* MOUSE: Layer move and mouse mode
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |RESET|MUTE |VOL- |VOL+ |PLAY |                      |WH_L | M4  | M5  |WH_R |     |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * | GRV |S(GRV|S(TAB| TAB |     |                      |HOME |WH_D |WH_U | END |PGUP |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |SHIFT|PAUSE|PGDN |PGUP | INS |                      |     | M1  | M2  | M3  |PGDN |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *              double tap WH D/U for left and right scroll
 *              double tap PGDN PGUP for home and end
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |  SPC  |CTR/TAB|      |  ESC  |       |
 *               '-----------------------'      '-------'-------'
 *                                               DOUBLE TAP ESC to leave mouse mode? maybe just single click?
 */

/* BLANK:
 * ,-----.-----.-----.-----.-----.                      ,-----.-----.-----.-----.-----.
 * |     |     |     |     |     |                      |     |     |     |     |     |
 * |-----+-----+-----+-----+-----|                      |-----+-----+-----+-----+-----|
 * |     |     |     |     |     |                      |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+                      |-----+-----+-----+-----+-----|
 * |     |     |     |     |     |                      |     |     |     |     |     |
 * `-----'-----'-----'-----'-----'                      `-----'-----'-----'-----'-----'
 *              double tap WH D/U for left and right scroll
 *              double tap PGDN PGUP for home and end
 *              S-TAB is for tabbing in reverse (window switching, tab, switching)
 *               .-------.-------.-------.      .-------.-------.
 *               | LGUI  |  SPC  | hold  |      | hold  |       |
 *               '-----------------------'      '-------'-------'
 *                                               DOUBLE TAP ESC to leave mouse mode? maybe just single click?
 */



//   [BLANK] = LAYOUT(
//     KC_NO,                  KC_NO,          KC_NO,                  KC_NO,              KC_NO,                                                 KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO,
//     KC_NO,                  KC_NO,          KC_NO,                  KC_NO,              KC_NO,                                                 KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO,
//     KC_NO,                  KC_NO,          KC_NO,                  KC_NO,              KC_NO,                                                 KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO,
//     KC_NO,                  KC_NO,          KC_NO,                  LGUI_T(KC_TAB),     KC_NO,  LCTL_T(KC_TAB), LSFT_T(KC_ESC),                KC_NO,               KC_NO,        KC_NO,        KC_NO,       KC_NO
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
//   )


/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t guitap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// td_tap_t for LCTL key
static td_tap_t ctrltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// td_tap_t for ESC key
static td_tap_t esctap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// void x_finished(qk_tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: register_code(KC_X); break;
//         case TD_SINGLE_HOLD: register_code(KC_LCTRL); break;
//         case TD_DOUBLE_TAP: register_code(KC_ESC); break;
//         case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
//         // Last case is for fast typing. Assuming your key is `f`:
//         // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//         // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//         case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
//         case TD_UNKNOWN: break;
//         case TD_NONE: break;
//         case TD_TRIPLE_TAP: break;
//         case TD_TRIPLE_HOLD: break;
//     }
// }

// void x_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: unregister_code(KC_X); break;
//         case TD_SINGLE_HOLD: unregister_code(KC_LCTRL); break;
//         case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
//         case TD_DOUBLE_HOLD: unregister_code(KC_LALT);
//         case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X);
//         case TD_UNKNOWN: break;
//         case TD_NONE: break;
//         case TD_TRIPLE_TAP: break;
//         case TD_TRIPLE_HOLD: break;
//     }
//     xtap_state.state = TD_NONE;
// }


//////////////////////////////////////////////////////////

void gui_finished(qk_tap_dance_state_t *state, void *user_data) {
    guitap_state.state = cur_dance(state);
    switch (guitap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: register_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LGUI); register_code(KC_LGUI);
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
}

void gui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (guitap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT);
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LGUI);
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
    guitap_state.state = TD_NONE;
}

void ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ctrltap_state.state = cur_dance(state);
    switch (ctrltap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: layer_on(NAV); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
}

void ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctrltap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: {
            if(ctrltap_state.state == TD_DOUBLE_HOLD) {
                layer_off(NAV);
            }
            ctrltap_state.state = TD_NONE;
            break;
        };
        case TD_DOUBLE_SINGLE_TAP: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
    ctrltap_state.state = TD_NONE;
}

//// mouse lock
void esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    esctap_state.state = cur_dance(state);
    switch (esctap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ESC); break;
        case TD_SINGLE_HOLD: layer_on(MOUSE); break;
        case TD_DOUBLE_TAP: {
            if (layer_state_is(MOUSE)) {
                layer_off(MOUSE);
            } else {
                layer_on(MOUSE);
            }
            break;
        }
        case TD_DOUBLE_HOLD: layer_on(NUMPAD); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
}

void esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (esctap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: {
            if(esctap_state.state == TD_SINGLE_HOLD) {
                layer_off(MOUSE);
            }
            esctap_state.state = TD_NONE;
            break;
        }
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: {
            if(esctap_state.state == TD_DOUBLE_HOLD) {
                layer_off(NUMPAD);
            }
            esctap_state.state = TD_NONE;
            break;
        }
        case TD_DOUBLE_SINGLE_TAP: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
    esctap_state.state = TD_NONE;
}

void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_COLN);
    } else {
        register_code(KC_SCLN);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // [X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [LGUI_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_finished, gui_reset),
    [LCTL_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset),
    [ESC_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset)
};
