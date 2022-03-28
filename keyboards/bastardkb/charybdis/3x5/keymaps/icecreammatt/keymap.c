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

//  qmk compile -kb bastardkb/charybdis/3x5 -km icecreammatt

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
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
// X_CTL,
enum {
    LGUI_ALT = 0,
    LCTL_NAV,
    EXLM_UNDS,
    LBRC_AMPR,
    RBRC_PIPE,
    PAST_HASH,
    AT_DOT,
    CT_CLN,
    SLSH_BSLS,
    Q_ENT,
    PGDN_PGUP,
    // W_TAB,
    ESC_MOUSE,
    HASH_DOT,
    // CIRC_HASH,

    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

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
#define COLEMAK 1
#define SYMBOL 2
#define FNAV 3
#define MOUSE 4
#define QWERTY_2 5

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       TD(Q_ENT),        KC_W,             KC_E,        KC_R,        KC_T,          KC_Y,    KC_U,      KC_I,      KC_O,              KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_A,             KC_S,             KC_D,        KC_F,        KC_G,          KC_H,    KC_J,      KC_K,      KC_L,              KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),     LALT_T(KC_X),     KC_C,        KC_V,        KC_B,          KC_N,    KC_M,      KC_COMM,   LT(MOUSE, KC_DOT), RSFT_T(KC_SLSH),
  // ╰────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────╯
                         TD(LGUI_ALT),     LT(SYMBOL,KC_SPC),        KC_LCTL,       LT(MOUSE, KC_ESC),  LT(SYMBOL, KC_BSPC)
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [COLEMAK] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_Q,               KC_W,             KC_F,       KC_P,           KC_B,     KC_J,      KC_L,      KC_U,      KC_Y,              KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_A,               KC_R,             KC_S,       KC_T,           KC_G,     KC_M,      KC_N,      KC_E,      KC_I,              KC_O,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),       LALT_T(KC_X),     KC_C,       KC_D,           KC_V,     KC_K,      KC_H,      KC_COMM,   LT(MOUSE, KC_DOT), RSFT_T(KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                           TD(LGUI_ALT),     LT(SYMBOL,KC_SPC),  KC_LCTL,          LT(MOUSE,  KC_ESC),   LT(SYMBOL, KC_BSPC)
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [QWERTY_2] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_Q,               KC_W,            KC_E,         KC_R,        KC_T,       KC_Y,        KC_U,      KC_I,           KC_O,       KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       HOME_A,             HOME_S,          HOME_D,       HOME_F,      KC_G,       KC_H,        HOME_J,    HOME_K,         HOME_L,     HOME_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_Z),       KC_X,            KC_C,         KC_V,        KC_B,       KC_N,        KC_M,      KC_COMM,        KC_DOT,     RSFT_T(KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                           TD(LGUI_ALT),    KC_SPC,       KC_LCTL,                 KC_ESC,      KC_BSPC
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [SYMBOL] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_TILD,            TD(EXLM_UNDS),TD(LBRC_AMPR),TD(RBRC_PIPE), KC_HASH,     TD(SLSH_BSLS),  KC_7,         KC_8,        KC_9,          KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LT(FNAV,KC_GRV),    KC_EQL,       KC_LPRN,     KC_RPRN,        KC_DLR,      KC_PAST,        KC_4,         KC_5,        KC_6,          TD(CT_CLN),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_LSFT,            TD(AT_DOT),   KC_MINS,     KC_PPLS,        KC_CIRC,     KC_PERC,        KC_1,         KC_2,        LALT_T(KC_3),  ALL_T(KC_0),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                           TD(LGUI_ALT), LT(QWERTY_2, KC_SPC),  LCTL_T(KC_ESC),    LALT_T(KC_TAB), LT(KC_NO, KC_BSPC)
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [FNAV] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       KC_TILD,            KC_UNDS,      KC_LCBR,    KC_RCBR,          KC_NO,        TO(COLEMAK),    KC_F7,    KC_F8,    KC_F9,         KC_F10,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_NO,              KC_SCLN,      KC_CIRC,    KC_DLR,           KC_NO,        TO(QWERTY),     KC_F4,    KC_F5,    KC_F6,         KC_F11,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_LSFT,            A(KC_8),      KC_HASH,    KC_PAST,          KC_NO,        KC_NO,          KC_F1,    KC_F2,    LALT_T(KC_F3), ALL_T(KC_F12),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                           TD(LGUI_ALT), LT(QWERTY_2, KC_SPC), LCTL_T(KC_TAB),       LALT_T(KC_TAB), LT(KC_NO, KC_BSPC)
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [MOUSE] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
       RESET,            KC_MUTE,    KC_VOLD,       KC_VOLU,        KC_MPLY,      KC_BTN4,       KC_WH_D,      KC_WH_U,      KC_BTN5,    KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       KC_PGUP,          KC_GRV,     S(KC_TAB),     KC_TAB,         KC_PAUSE,     KC_LEFT,       KC_DOWN,      KC_UP,        KC_RIGHT,   TD(PGDN_PGUP),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_HOME),  LALT_T(KC_END), DRAGSCROLL_MODE,SNIPING_MODE, KC_INS,    KC_BTN3,       KC_BTN1,      KC_BTN2,      KC_BTN3,    DRAGSCROLL_MODE,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                         KC_LGUI,    KC_SPC,        LCTL_T(KC_TAB),               TD(ESC_MOUSE), KC_BSPC
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),
};

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
        // For example, when typing the word `buffer`, and you wat to make sure that you send `ff` and not `Esc`.
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

void ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ctrltap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;//{
        //     if(ctrltap_state.state == TD_DOUBLE_HOLD) {
        //         layer_off(NUMPAD);
        //     }
        //     ctrltap_state.state = TD_NONE;
        //     break;
        // };
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
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
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
    [EXLM_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_UNDS),
    [LBRC_AMPR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_AMPR),
    [RBRC_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_PIPE),
    [PAST_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_HASH),
    [AT_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_AT, A(KC_8)),
    [SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    // [CIRC_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_HASH),
    // [DLR_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_UNDS),
    [Q_ENT] =    ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ENT),
    [PGDN_PGUP] =    ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_PGUP),
    // [W_TAB] =    ACTION_TAP_DANCE_DOUBLE(KC_W, KC_TAB),
    [LGUI_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_finished, gui_reset),
    [LGUI_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_finished, gui_reset),
    [LCTL_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset),
    [ESC_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset)
};





/*
enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

#define CTL_BSP CTL_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         CTL_BSP, SFT_SPC,   LOWER,      RAISE, GUI_ENT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       RGB_TOG, KC_MNXT, KC_MPLY, KC_MPRV, XXXXXXX,    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PMNS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,   RESET,    KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,      RESET, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
*/

    // clang-format on
