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
#include "tapdance.h"
#include "homerow.h"

// Layer Defines
#define QWERTY 0
#define QWERTY_2 1
#define COLEMAK 2
#define COLEMAK_2 3
#define GAMING 4
#define GAMING_2 5
#define SYMBOL 6
#define NAV 7
#define FNAV 8
#define MOUSE 9

// Aliases
#define SYM_BSPC LT(SYMBOL, KC_BSPC)
#define HOMEROW_QW LT(QWERTY_2, KC_SPC)
#define HOMEROW_CO LT(COLEMAK_2, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        TD(Q_ENT),        KC_W,             KC_E,        KC_R,        KC_T,       KC_Y,    KC_U,      KC_I,           KC_O,          KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        KC_A,             KC_S,             KC_D,        KC_F,        KC_G,       KC_H,    KC_J,      KC_K,           KC_L,          LT(MOUSE, KC_QUOT),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LSFT_T(KC_Z),     KC_X,             KC_C,        KC_V,        KC_B,       KC_N,    KC_M,      KC_COMM,        KC_DOT,        RSFT_T(KC_SLSH),
  // ╰────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────╯
                        LT(MOUSE, _______), HOMEROW_QW, TD(LCTL_GUI),             LT(NAV, KC_ESC),    SYM_BSPC
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [COLEMAK] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        TD(Q_ENT),          KC_W,           KC_F,       KC_P,           KC_B,     KC_J,      KC_L,      KC_U,      KC_Y,              KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        KC_A,               KC_R,           KC_S,       KC_T,           KC_G,     KC_M,      KC_N,      KC_E,      KC_I,              LT(MOUSE, KC_O),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LSFT_T(KC_Z),       LALT_T(KC_X),   KC_C,       KC_D,           KC_V,     KC_K,      KC_H,      KC_COMM,   LT(NAV, KC_DOT),   RSFT_T(KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______,           HOMEROW_CO, _______,                   _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [COLEMAK_2] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        TD(Q_ENT),          KC_W,           KC_F,       KC_P,           KC_B,     KC_J,      KC_L,      KC_U,      KC_Y,              KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        HOME_AC,            HOME_R,         HOME_SC,    HOME_T,         KC_G,     KC_M,      HOME_N,    HOME_E,    HOME_I,            HOME_O,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LSFT_T(KC_Z),       LALT_T(KC_X),   KC_C,       KC_D,           KC_V,     KC_K,      KC_H,      KC_COMM,   LT(NAV, KC_DOT),   RSFT_T(KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______,           _______,    _______,                   _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

[QWERTY_2] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        TD(Q_ENT),        KC_W,         KC_E,        KC_R,         KC_T,          KC_Y,    KC_U,      KC_I,      KC_O,          KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        HOME_A,           HOME_S,       HOME_D,      HOME_F,       KC_G,          KC_H,    HOME_J,    HOME_K,    HOME_L,        HOME_QUOT,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LSFT_T(KC_Z),     KC_X,         TD(C_BTN4),  TD(C_BTN5),   KC_B,          KC_N,    KC_M,      KC_COMM,   KC_DOT,        LT(MOUSE, KC_SLSH),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______,       _______, _______,                          _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [GAMING] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        TD(T_ESC),    KC_Q,             KC_W,             KC_E,        KC_R,      KC_Y,    KC_U,      KC_I,           KC_O,          KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LSFT_T(KC_G), KC_A,             KC_S,             KC_D,        KC_F,      KC_H,    KC_J,      KC_K,           KC_L,          LT(MOUSE, KC_QUOT),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        TD(B_TAB),    KC_Z,             KC_X,             KC_C,        KC_V,      KC_N,    KC_M,      KC_COMM,        KC_DOT,        RSFT_T(KC_SLSH),
  // ╰────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────╯
                        MO(GAMING_2), KC_SPC,            KC_LCTL,                 LT(NAV, KC_ESC),    SYM_BSPC
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [GAMING_2] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        KC_ESC,          KC_1,         KC_2,        KC_3,        KC_0,            KC_Y,    KC_U,      KC_I,           KC_O,          KC_P,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        KC_ENT,          KC_4,         KC_5,        KC_6,        KC_I,            KC_H,    KC_J,      KC_K,           KC_L,          LT(MOUSE, KC_QUOT),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        KC_TAB,          KC_7,         KC_8,        KC_9,        KC_M,            KC_N,    KC_M,      KC_COMM,        KC_DOT,        RSFT_T(KC_SLSH),
  // ╰────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────╯
                        _______,    _______,       KC_GRV,                        LT(NAV, KC_ESC),    SYM_BSPC
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [SYMBOL] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        KC_TILD,            TD(EXLM_UNDS),TD(LBRC_AMPR),TD(RBRC_PIPE), _______,   TD(SLSH_BSLS),  KC_7,         KC_8,        KC_9,          KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LT(FNAV,KC_GRV),    KC_EQL,       KC_LPRN,     KC_RPRN,        _______,   KC_PAST,        KC_4,        LT(FNAV,KC_5),KC_6,         TD(CT_CLN),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        KC_LSFT,            TD(AT_DOT),   KC_MINS,     KC_PPLS,        _______,   KC_PERC,        KC_1,         KC_2,        LALT_T(KC_3),  ALL_T(KC_0),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______, _______, _______,                                _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [FNAV] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        _______,              KC_UNDS,      KC_LCBR,    KC_RCBR,       _______,   TO(GAMING),     KC_F7,    KC_F8,    KC_F9,         KC_F10,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        _______,              KC_SCLN,      TD(CIRC_HOME),TD(DLR_END), _______,   TO(QWERTY),     KC_F4,    KC_F5,    KC_F6,         KC_F11,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        KC_LSFT,              A(KC_8),      KC_HASH,    KC_PAST,       _______,   TO(COLEMAK),    KC_F1,    KC_F2,    LALT_T(KC_F3), ALL_T(KC_F12),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______, _______, _______,                                _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [NAV] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        RESET,            KC_MUTE,    KC_VOLD,       KC_VOLU,        KC_MPLY,     KC_BTN4,       KC_WH_D,      KC_WH_U,      KC_BTN5,    KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LT(FNAV,KC_PGUP), KC_GRV,     S(KC_TAB),     KC_TAB,         KC_PAUSE,    KC_LEFT,       KC_DOWN,      KC_UP,        KC_RIGHT,   TD(PGDN_PGUP),
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        LSFT_T(KC_HOME),  LALT_T(_______), _______,  _______,        KC_INS,      KC_PSCR,       KC_BTN4,      KC_BTN3,      KC_BTN5,    KC_END,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______, _______, _______,                                _______, _______
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),

  [MOUSE] = LAYOUT_charybdis_3x5(
  // ╭────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────╮
        _______,        _______,      _______,           _______,   _______,      KC_BTN4,       KC_WH_D,      KC_WH_U,      KC_BTN5,    KC_DEL,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        _______,        KC_BTN2,      DRAGSCROLL_MODE,   KC_BTN1,   _______,      _______,       KC_BTN1,    DRAGSCROLL_MODE,KC_BTN2,    _______,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
        _______,        KC_BTN4,      KC_BTN3,           KC_BTN5,   _______,      _______,       KC_BTN4,      KC_BTN3,      KC_BTN5,    DRAGSCROLL_MODE,
  // ├────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────┤
                        _______,      SNIPING_MODE,      _______,                 KC_BTN2,       KC_BTN1
  //                   ╰──────────────────────────────────────────────────────╯ ╰────────────────────────────────────────────╯
  ),
};
