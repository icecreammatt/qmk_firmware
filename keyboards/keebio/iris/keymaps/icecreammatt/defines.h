#undef TAPPING_TERM
#define TAPPING_TERM 50

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J RGUI_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QUOT RSFT_T(KC_QUOT)

#define QWERTY_MIN 0
#define QWERTY 1
#define GAMING 2
#define GAMING2 3
#define GAMING3 4
#define COLEMAK 5
#define QWERTY_2 6
#define SYMBOL 7
#define NAV 8
#define FNAV 9
#define MOUSE 10

#define SYM_SPC LT(SYMBOL, KC_SPC)

// #undef TAPPING_TERM
// #define QWERTY 0
// #define NAV 1
// #define SYMBOL 2
// #define FNAV 3
