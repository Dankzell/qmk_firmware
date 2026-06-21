// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _SYMB,
  _NAV,
  _NUM,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
* ,-----------------------------------------------------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | NAV  | Ctrl | Alt  | GUI  | SYMB |    Space    | NUM  | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
    [_QWERTY] = LAYOUT_ortho_5x12(
        KC_GRV,   KC_1,    KC_2,         KC_3,         KC_4,         KC_5,    KC_6,            KC_7,               KC_8,         KC_9,         KC_0,    KC_DEL,
        KC_TAB,   KC_Q,    KC_W,         KC_E,         KC_R,         KC_T,    KC_Y,            KC_U,               KC_I,         KC_O,         KC_P,    KC_QUOT,
        KC_ESC,   KC_A,    LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H,            RSFT_T(KC_J),       RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN, KC_BSPC,
        KC_LSFT,  KC_Z,    KC_X,         KC_C,         KC_V,         KC_B,    KC_N,            KC_M,               KC_COMM,      KC_DOT,       KC_SLSH, KC_LSFT,
        KC_NO,   KC_LGUI, KC_LALT,  KC_LCTL,   MO(_SYMB),      KC_ENT,  LT(_NUM, KC_SPC),LT(_NAV, KC_ESC), KC_RCTL,     KC_RALT,KC_RGUI, KC_NO
    ),

/* SYMB
* ,-----------------------------------------------------------------------------------.
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |   `  |   1  |   2  |   <  |   >  |   [  |   ]  |   &  |   |  |   `  |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   !  |   =  |   -  |   (  |   {  |   }  |   )  |   .  |   #  |   @  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   %  |   $  |   +  |   _  |      |   *  |   ^  |   ;  |   :  |   \  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
    [_SYMB] = LAYOUT_ortho_5x12(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,      KC_F6,   KC_F7,           KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_1,    KC_2,    S(KC_COMM), S(KC_DOT),  KC_LBRC, KC_RBRC,         KC_AMPR,    S(KC_BSLS), KC_GRV, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_EQL,  KC_MINUS,   KC_LPRN,    KC_LCBR, KC_RCBR,         KC_RPRN,    KC_DOT,  KC_HASH, KC_AT,   KC_TRNS,
        KC_TRNS, KC_PERC, KC_DLR,  KC_PLUS,    S(KC_MINS), KC_NO,   S(KC_8),         S(KC_6),    KC_SCLN, KC_COLN, KC_BSLS, KC_TRNS,
        KC_NO,   KC_LGUI, KC_LALT,  KC_LCTL,   KC_NO,      KC_ENT,  LT(_NUM, KC_SPC),LT(_NAV, KC_ESC), KC_RCTL,     KC_RALT,KC_RGUI, KC_NO
    ),

/* NAV
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Esc  |   Q  |   W  |   E  |   R  |   T  |C+Del |C+Left|      |C+Rgt |C+Bsp |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Tab  |   A  | AS   | CD   | SF   |   G  | Left | Down |  Up  |Right | Home |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |      | PgDn | PgUp |      | End  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
    [_NAV] = LAYOUT_ortho_5x12(
        KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_ESC,   KC_Q,     KC_W,        KC_E,        KC_R,        KC_T,    C(KC_DEL),  C(KC_LEFT), KC_NO,    C(KC_RIGHT), C(KC_BSPC), KC_NO,
        KC_TAB,   KC_A,     LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,   KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT, KC_HOME, KC_TRNS,
        KC_LSFT,  KC_Z,     KC_X,        KC_C,        KC_V,        KC_B,    KC_NO,      KC_PGDN,    KC_PGUP,  KC_NO,    KC_END,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
    ),

/* NUM
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |  KP- |  KP7 |  KP8 |  KP9 |  KP/ | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |      |      |  KP+ |  KP4 |  KP5 |  KP6 |  KP* | Bksp |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |  KP0 |  KP1 |  KP2 |  KP3 |  KP. |KPEnt |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
    [_NUM] = LAYOUT_ortho_5x12(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_MINUS, KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_SLASH,    KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_PLUS,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_ASTERISK, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0,     KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_DOT,      KC_KP_ENTER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS
    ),

/* ADJUST
 * RGB controls on right-hand side. Activated by holding SYMB + NAV together.
 * ,-----------------------------------------------------------------------------------.
 * | MUTE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Boot |      |      |      |      |      |      | Hue+ | Tog  | Sat+ |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EEClr |      |      |      |      |      |      | Val- | Next | Val+ |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |(held)|      |(held)|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT_ortho_5x12(
        KC_MUTE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    RM_HUEU, RM_TOGG,  RM_SATU, KC_NO, KC_NO,
        EE_CLR,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    RM_VALD, RM_NEXT,  RM_VALU, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   RM_PREV,  KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_TRNS,  KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMB, _NAV, _ADJUST);
}
bool dip_switch_update_user(uint8_t index, bool active) {
    if(active) { tap_code(KC_MUTE); } else {  }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY: oled_write_ln_P(PSTR("QWRTY"), false); break;
        case _SYMB:   oled_write_ln_P(PSTR("SYMBS"), false); break;
        case _NAV:    oled_write_ln_P(PSTR("NAV  "), false); break;
        case _NUM:    oled_write_ln_P(PSTR("NUM  "), false); break;
        case _ADJUST: oled_write_ln_P(PSTR("ADJST"), false); break;
        default:      oled_write_ln_P(PSTR("?????"), false); break;
    }

    oled_write_ln_P(host_keyboard_led_state().caps_lock ? PSTR("CAPS") : PSTR("    "), false);

    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(MOD_MASK_SHIFT & mods ? PSTR("S") : PSTR(" "), false);
    oled_write_P(MOD_MASK_CTRL  & mods ? PSTR("C") : PSTR(" "), false);
    oled_write_P(MOD_MASK_ALT   & mods ? PSTR("A") : PSTR(" "), false);
    oled_write_ln_P(MOD_MASK_GUI & mods ? PSTR("G") : PSTR(" "), false);

    return false;
}
#endif
