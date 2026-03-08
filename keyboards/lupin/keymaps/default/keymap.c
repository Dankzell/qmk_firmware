// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>

enum sofle_layers {
    _QWERTY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                           ,----------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |   ' |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  | stuff |         | Stuff|  H  |   J  |   K  |   L  |   ;  | Bspc |
 * |------+------+------+------+------+------|-------|        |------+-----+-------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  | XXXX  |       | Stuff |  N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               | LGUI | LAlt | LCTR |LOWER | /ENTER  /       \SPACE \  |RAISE | RCTR | RAlt | RGUI |
 *               `-------------------------------------'        '------''----------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_ESC,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               KC_Y,      KC_U      , KC_I        , KC_O        , KC_P,     KC_QUOT,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G, KC_NO,              KC_NO,    KC_H,      RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B,                     KC_NO,    KC_N,      KC_M        , KC_COMM     , KC_DOT      , KC_SLSH,  KC_RSFT,
                               KC_LGUI, KC_LALT, KC_LCTL , KC_ENT , KC_ENT,             KC_SPC,   KC_SPC, KC_RCTL, KC_RALT, KC_RGUI
  )};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if(active) { tap_code(KC_MUTE); } else {  }
      break;
    case 1:
      if(active) { tap_code(KC_3); } else {  }
      break;
  }
  return true;
}
