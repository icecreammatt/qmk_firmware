/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" // might not need this
#include "defines.h"

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
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    LGUI_ALT = 0,
    LCTL_GUI,
    EXLM_UNDS,
    LBRC_AMPR,
    RBRC_PIPE,
    DLR_END,
    CIRC_HOME,
    C_BTN4,
    C_BTN5,
    E_STAB,
    R_TAB,
    W_TILD,
    T_ST,
    // PAST_HASH,
    AT_DOT,
    CT_CLN,
    SLSH_BSLS,
    Q_ENT,
    PGDN_PGUP,
    ESC_NAV,
    HASH_DOT,
    // CIRC_HASH,
    HOME_VOLD,
    END_VOLU,

    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J LGUI_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QUOT RSFT_T(KC_QUOT)

// Left-hand home row mods colemak
#define HOME_A LSFT_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LGUI_T(KC_T)

// Right-hand home row mods colemak
#define HOME_N LGUI_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RSFT_T(KC_O)

// Reference
//HOME_A,           KC_R,         KC_S,        KC_T,         KC_G,             KC_M,    KC_N,      KC_E,      KC_I,          LT(MOUSE, KC_O),
//HOME_A,           HOME_S,       HOME_D,      HOME_F,       KC_G,             KC_H,    HOME_J,    HOME_K,    HOME_L,        HOME_QUOT,

#define QWERTY 0
#define QWERTY_2 1
#define COLEMAK 2
#define COLEMAK_2 3
#define SYMBOL 4
#define NAV 5
#define FNAV 6
#define MOUSE 7

#define SYM_SPC LT(SYMBOL, KC_SPC)

/*
enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
}

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

#define CTL_BSP CTL_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

*/


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       TD(Q_ENT),        KC_W,             KC_E,        KC_R,        KC_T,          KC_Y,    KC_U,      KC_I,           KC_O,          KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_A,             KC_S,             KC_D,        KC_F,        KC_G,          KC_H,    KC_J,      KC_K,           KC_L,          LT(MOUSE, KC_QUOT),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),     KC_X,             KC_C,        KC_V,        KC_B,          KC_N,    KC_M,      KC_COMM,        KC_DOT,        RSFT_T(KC_SLSH),
  // ╰────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────╯
                        LT(MOUSE, _______), LT(QWERTY_2, KC_SPC),TD(LCTL_GUI),      LT(NAV, KC_ESC),    LT(SYMBOL, KC_BSPC)
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [COLEMAK] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_Q,               KC_W,           KC_F,       KC_P,           KC_B,        KC_J,      KC_L,      KC_U,      KC_Y,              KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_A,               KC_R,           KC_S,       KC_T,           KC_G,        KC_M,      KC_N,      KC_E,      KC_I,              LT(MOUSE, KC_O),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),       LALT_T(KC_X),   KC_C,       KC_D,           KC_V,        KC_K,      KC_H,      KC_COMM,   LT(NAV, KC_DOT),   RSFT_T(KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                                    _______, LT(COLEMAK_2, KC_SPC), _______,        _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [COLEMAK_2] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_Q,               KC_W,           KC_F,       KC_P,           KC_B,        KC_J,      KC_L,      KC_U,      KC_Y,              KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       HOME_A,             HOME_R,           HOME_S,       HOME_T,     KC_G,        KC_M,      HOME_N,    HOME_E,    HOME_I,            HOME_O,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),       LALT_T(KC_X),   KC_C,       KC_D,           KC_V,        KC_K,      KC_H,      KC_COMM,   LT(NAV, KC_DOT),   RSFT_T(KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                                    _______, _______, _______,                   _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

[QWERTY_2] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       TD(Q_ENT),        KC_W,         KC_E,        KC_R,         KC_T,              KC_Y,    KC_U,      KC_I,      KC_O,          KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       HOME_A,           HOME_S,       HOME_D,      HOME_F,       KC_G,              KC_H,    HOME_J,    HOME_K,    HOME_L,        HOME_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),     KC_X,         TD(C_BTN4),  TD(C_BTN5),   KC_B,              KC_N,    KC_M,      KC_COMM,   KC_DOT,        LT(MOUSE, KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        //    TD(LGUI_ALT),    KC_SPC,       KC_LCTL,                 LT(NAV, KC_ESC),  LT(SYMBOL, KC_BSPC)
                                    _______, _______, _______,                   _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [SYMBOL] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_TILD,            TD(EXLM_UNDS),TD(LBRC_AMPR),TD(RBRC_PIPE), _______,       TD(SLSH_BSLS),  KC_7,         KC_8,        KC_9,          KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LT(FNAV,KC_GRV),    KC_EQL,       KC_LPRN,     KC_RPRN,        _______,       KC_PAST,        KC_4,        LT(FNAV,KC_5),KC_6,         TD(CT_CLN),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_LSFT,            TD(AT_DOT),   KC_MINS,     KC_PPLS,        _______,       KC_PERC,        KC_1,         KC_2,        LALT_T(KC_3),  ALL_T(KC_0),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                                    _______, _______, _______,                   _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [FNAV] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       _______,              KC_UNDS,      KC_LCBR,    KC_RCBR,       _______,        _______,        KC_F7,    KC_F8,    KC_F9,         KC_F10,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       _______,              KC_SCLN,      TD(CIRC_HOME),TD(DLR_END), _______,        TO(QWERTY),     KC_F4,    KC_F5,    KC_F6,         KC_F11,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_LSFT,              A(KC_8),      KC_HASH,    KC_PAST,       _______,        TO(COLEMAK),    KC_F1,    KC_F2,    LALT_T(KC_F3), ALL_T(KC_F12),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                                    _______, _______, _______,                        _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [NAV] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       RESET,            KC_MUTE,    KC_VOLD,       KC_VOLU,        KC_MPLY,      KC_BTN4,       KC_WH_D,      KC_WH_U,      KC_BTN5,    KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LT(FNAV,KC_PGUP), KC_GRV,     S(KC_TAB),     KC_TAB,         KC_PAUSE,     KC_LEFT,       KC_DOWN,      KC_UP,        KC_RIGHT,   TD(PGDN_PGUP),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_HOME),  LALT_T(_______), _______,  _______,        KC_INS,       KC_PSCR,       KC_BTN4,      KC_BTN3,      KC_BTN5,    KC_END,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                                    _______, _______, _______,                   _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [MOUSE] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,          KC_TRNS,      KC_TRNS,           KC_TRNS,   KC_TRNS,      KC_BTN4,       KC_WH_D,      KC_WH_U,      KC_BTN5,    KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,          KC_BTN2,      DRAGSCROLL_MODE,   KC_BTN1,   KC_TRNS,      _______,       KC_BTN1,      KC_BTN3,      KC_BTN2,    _______,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,          KC_BTN4,      KC_BTN3,           KC_BTN5,   KC_TRNS,      _______,       KC_BTN4,      KC_BTN3,      KC_BTN5,    DRAGSCROLL_MODE,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                          _______,      SNIPING_MODE,      _______,               KC_BTN2,       KC_BTN1
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),
};

// #ifdef POINTING_DEVICE_ENABLE
// #    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD ||
//         abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
//         if (auto_pointer_layer_timer == 0) {
//             layer_on(MOUSE);
// // #        ifdef RGB_MATRIX_ENABLE
// //             rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
// //             rgb_matrix_sethsv_noeeprom(HSV_GREEN);
// // #        endif  // RGB_MATRIX_ENABLE
//         }
//         auto_pointer_layer_timer = timer_read();
//     }
//     return mouse_report;
// }

// void matrix_scan_kb(void) {
//     if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(),
//         auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
//         auto_pointer_layer_timer = 0;
//         layer_off(MOUSE);
// // #        ifdef RGB_MATRIX_ENABLE
// //         rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
// // #        endif  // RGB_MATRIX_ENABLE
//     }
//     matrix_scan_user();
// }
// #    endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #endif      // POINTING_DEVICE_ENABLE


// clang-format on

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

// td_tap_t for ESC key
static td_tap_t esctap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    guitap_state.state = cur_dance(state);
    switch (guitap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: register_code(KC_LGUI); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you wat to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LCTL); register_code(KC_LCTL);
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: register_code(KC_LCTL); register_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: break;
    }
}

void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (guitap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LGUI);
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LCTL);
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: break;
    }
    guitap_state.state = TD_NONE;
}



void gui_finished(qk_tap_dance_state_t *state, void *user_data) {
    guitap_state.state = cur_dance(state);
    switch (guitap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: register_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you wat to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LGUI); register_code(KC_LGUI);
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: register_code(KC_LGUI); register_code(KC_SPC); break;
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
        case TD_TRIPLE_TAP: unregister_code(KC_LGUI); unregister_code(KC_SPC); break;
        case TD_TRIPLE_HOLD: break;
    }
    guitap_state.state = TD_NONE;
}

//// mouse lock
void esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    esctap_state.state = cur_dance(state);
    switch (esctap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_I); break;
        case TD_SINGLE_HOLD: layer_on(MOUSE); break;
        case TD_DOUBLE_TAP: {
            if (layer_state_is(MOUSE)) {
                layer_off(MOUSE);
            } else {
                layer_on(MOUSE);
            }
            break;
        }
        case TD_DOUBLE_HOLD: break; //layer_on(NUMPAD); break;
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
        case TD_SINGLE_TAP: unregister_code(KC_I); break;
        case TD_SINGLE_HOLD: {
            if(esctap_state.state == TD_SINGLE_HOLD) {
                layer_off(MOUSE);
            }
            esctap_state.state = TD_NONE;
            break;
        }
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break; //{
        //     if(esctap_state.state == TD_DOUBLE_HOLD) {
        //         layer_off(NUMPAD);
        //     }
        //     esctap_state.state = TD_NONE;
        //     break;
        // }
        case TD_DOUBLE_SINGLE_TAP: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
    }
    esctap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_ENT),
    [EXLM_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_UNDS),
    [LBRC_AMPR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_AMPR),
    [RBRC_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_PIPE),
    [C_BTN4] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_BTN4),
    [C_BTN5] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_BTN5),
    [E_STAB] = ACTION_TAP_DANCE_DOUBLE(KC_E, S(KC_TAB)),
    [R_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_TAB),
    [W_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_GRV),
    [T_ST] = ACTION_TAP_DANCE_DOUBLE(KC_T, S(KC_T)),
    // [PAST_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_HASH),
    [AT_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_AT, A(KC_8)),
    [SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),

    [CIRC_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_HOME),
    [DLR_END] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_END),

    [Q_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ENT),
    [PGDN_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_PGUP),
    [LCTL_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
    [LGUI_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_finished, gui_reset),
    [HOME_VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_VOLD),
    [END_VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_VOLU),
    [ESC_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset)
    // [CIRC_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_HASH),
    // [DLR_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_UNDS)
};
