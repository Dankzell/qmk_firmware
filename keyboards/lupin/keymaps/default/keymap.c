// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>

enum lupin_layers {
    _QWERTY,
    _SYMB,
    _NAV,
    _NUM,
    _EXTRA,
};

enum {
    TD_LCTRL_CAPS_WORD
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
        KC_LALT, TD(TD_LCTRL_CAPS_WORD) , MO(_SYMB) , LT(_EXTRA, KC_ENT), KC_LGUI,    KC_NO,   LT(_NUM, KC_SPC), LT(_NAV, KC_ESC), KC_RCTL, KC_RALT
  ),

 /* QWERTY
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

 [_NAV] = LAYOUT(
    KC_ESC,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               C(KC_DEL), C(KC_LEFT), KC_NO,   C(KC_RIGHT), C(KC_BSPC), KC_NO,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G, KC_NO,              KC_NO,    KC_LEFT,   KC_DOWN,    KC_UP,   KC_RIGHT,    KC_HOME,    KC_TRNS,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B,                     KC_NO,    KC_NO,     KC_PGDN,    KC_PGUP, KC_NO,       KC_END,     KC_TRNS,
                    KC_LALT, KC_LCTL , MO(_SYMB) , LT(_EXTRA, KC_ENT), KC_LGUI,            KC_NO,   LT(_NUM, KC_SPC), LT(_NAV, KC_ESCAPE), KC_RCTL, KC_RALT
  ),


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

 [_NUM] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_KP_MINUS,  KC_KP_7, KC_KP_8,  KC_KP_9, KC_KP_SLASH,    KC_DEL,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,          KC_NUM,    KC_KP_PLUS,   KC_KP_4, KC_KP_5,  KC_KP_6, KC_KP_ASTERISK, KC_BSPC,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_NO,     KC_KP_0,      KC_KP_1, KC_KP_2,  KC_KP_3, KC_KP_DOT,    KC_KP_ENTER,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    LT(_NUM, KC_ESC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )};


void ctrl_capsword_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            register_code(KC_LCTL);   // hold ctrl
        } else {
            tap_code(KC_LCTL);        // tap ctrl
        }
    } else if (state->count == 2) {
        tap_code16(QK_CAPS_WORD_TOGGLE);
    }
}

void ctrl_capsword_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LCTL);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTRL_CAPS_WORD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_capsword_finished, ctrl_capsword_reset)
};


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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif
