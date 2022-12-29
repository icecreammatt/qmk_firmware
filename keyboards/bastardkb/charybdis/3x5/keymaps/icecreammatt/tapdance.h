#include "layers.h"

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
    AT_DOT,
    CT_CLN,
    SLSH_BSLS,
    Q_ENT,
    T_ESC,
    B_TAB,
    PGDN_PGUP,
    HASH_DOT,
    HOME_VOLD,
    END_VOLU
};

td_state_t cur_dance(qk_tap_dance_state_t *state);


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

void ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    guitap_state.state = cur_dance(state);
    switch (guitap_state.state) {
        case TD_SINGLE_TAP: {
           if(layer_state_is(QWERTY)) {
                layer_on(QWERTY_2);
                break;
           } else if (layer_state_is(COLEMAK)) {
                layer_on(COLEMAK_2);               
                break;
           } else if(layer_state_is(QWERTY_2)) {
                layer_off(QWERTY_2);
                break;
           } else if (layer_state_is(COLEMAK_2)) {
                layer_off(COLEMAK_2);               
                break;
           }
           break;
        };
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;
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
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LCTL);
        case TD_UNKNOWN: break;
        case TD_NONE: break;
        case TD_TRIPLE_TAP: unregister_code(KC_LCTL); unregister_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: break;
    }
    guitap_state.state = TD_NONE;
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
    [AT_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_AT, A(KC_8)),
    [SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [CIRC_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_HOME),
    [DLR_END] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_END),
    [B_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_TAB),
    [T_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_ESC),
    [Q_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ENT),
    [PGDN_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_PGUP),
    [LCTL_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_finished, ctl_reset),
    [HOME_VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_VOLD),
    [END_VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_VOLU),
};
