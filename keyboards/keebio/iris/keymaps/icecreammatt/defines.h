#undef TAPPING_TERM
#define TAPPING_TERM 50

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Aliases
#define MOUSE_ENT  LT(MOUSE, KC_ENT)

// Shift keys
#define LSFT_Z     LSFT_T(KC_Z)
#define LSFT_SPC   LSFT_T(KC_SPC)
#define RSFT_SLSH  RSFT_T(KC_SLSH)

// QWERTY home row
#define HOMEROW_QW LT(QWERTY_2, KC_SPC)
#define HOMEROW_QW2 LT(QWERTY_2, KC_ESC)

// Colemak home row
#define HOMEROW_CO LT(COLEMAK_2, KC_SPC)
#define HOMEROW_CO2 LT(COLEMAK_2, KC_ESC)

#define NAV_ESC    LT(NAV, KC_ESC)
#define SYM_BSPC   LT(SYMBOL, KC_BSPC)
