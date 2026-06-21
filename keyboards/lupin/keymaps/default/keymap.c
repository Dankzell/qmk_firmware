// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include "action.h"
#include "action_layer.h"
#include "caps_word.h"
#include "keycodes.h"
#include "process_tap_dance.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "report.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "print.h"
#include "mousekey.h"

enum lupin_layers {
    _QWERTY,
    _SYMB,
    _NAV,
    _NUM,
    _EXTRA,
};

enum lupin_keycode {
    ENC_MOD = SAFE_RANGE
};

enum rotary_encoder_1_layers {
    _VOL,
    _SCROLL_X,
};

enum rotary_encoder_2_layers {
    _ZOOM,
    _SCROLL_Y,
};

static uint8_t enc_mode_1[2] = {_VOL, _SCROLL_X};
static uint8_t enc_mode_2[2] = {_ZOOM, _SCROLL_Y};
static bool enc_mod_active = false;
static uint8_t enc_idx[2] = {0, 0};

enum {
    TD_LGUI_CAPS_WORD
};

void gui_caps_word_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            register_code(KC_LGUI);
        } else {
            tap_code(KC_LGUI);
        }
    } else if (state->count == 2) {
        caps_word_toggle();
    }
}

void gui_caps_word_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LGUI);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_CAPS_WORD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_caps_word_finished, gui_caps_word_reset)
};

enum joystick_modes {
    _MOUSE,
    _ARROW
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                           ,----------------------------------------.
 * |  ``  |   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |   ' |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  | stuff |         | Stuff|  H  |   J  |   K  |   L  |   ;  | Bspc |
 * |------+------+------+------+------+------|-------|        |------+-----+-------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  | XXXX  |       | Stuff |  N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               | LGUI | LAlt | LCTR |LOWER | /ENTER  /       \SPACE \  |RAISE | RCTR | RAlt | RGUI |
 *               `-------------------------------------'        '------''----------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GRV,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               KC_Y,      KC_U      , KC_I        , KC_O        , KC_P,     KC_QUOT,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G, KC_NO,              KC_NO,    KC_H,      RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B,                     KC_NO,    KC_N,      KC_M        , KC_COMM     , KC_DOT      , KC_SLSH,  KC_RSFT,
        KC_LALT, LCTL_T(KC_TAB) , LT(KC_ESC, _SYMB) , LT(_EXTRA, KC_ENT), KC_LGUI,    KC_NO,   LT(_NUM, KC_SPC), LT(_NAV, KC_BSPC), RCTL_T(KC_ESC), KC_RALT
  ),

/*
 * SYMB
 * ,-----------------------------------------.                           ,----------------------------------------.
 * |  `   |   1  |   2  |   <  |   >  |   [  |                          |   ]  |   &  |   |  |   `  |      |      |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * |      |   !  |   =  |   -  |   (  |   {  |        |         |      |   }  |   )  |   .  |   #  |   @  |      |
 * |------+------+------+------+------+------|-------|        |------+------+------+------+------+------+------|
 * |      |   %  |   $  |   +  |   _  |      |        |        |      |   *  |   ^  |   ;  |   :  |   \  |      |
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               | LAlt |TD CTL| SYMB |EXTRA | /ENTER  /       \SPACE \  | NUM  | NAV  | RCtl | RAlt |
 *               `-------------------------------------'        '------''----------------------------'
 */
 [_SYMB] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,   S(KC_COMM), S(KC_DOT),  KC_LBRC,                              KC_RBRC,  KC_AMPR, S(KC_BSLS), KC_GRV,  KC_TRNS, KC_DEL,
    KC_TRNS, KC_EXLM, KC_EQL, KC_MINUS,   KC_LPRN,    KC_LCBR,  KC_TRNS,       KC_TRNS,     KC_RCBR,  KC_RPRN, KC_DOT,     KC_HASH, KC_AT,   KC_TRNS,
    KC_TRNS, KC_PERC, KC_DLR, KC_PLUS,    S(KC_MINS), XXXXXXX,               KC_TRNS,     S(KC_8),  S(KC_6), KC_SCLN,    KC_COLN, KC_BSLS, KC_TRNS,
          KC_LALT, KC_TRNS, MO(_SYMB), LT(_EXTRA, KC_ENT), KC_TRNS,    KC_NO, LT(_NUM, KC_SPC), LT(_NAV, KC_ESC), KC_RCTL, KC_RALT
  ),

/*
 * NAV
 * ,-----------------------------------------.                           ,----------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |   ' |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  | stuff |         | Stuff| lA   | dA   |  uA  |  rA  |   ;  | Bspc |
 * |------+------+------+------+------+------|-------|        |------+-----+-------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  | XXXX  |       | Stuff |  N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               | LGUI | LAlt | LCTR |LOWER | /ENTER  /       \SPACE \  |RAISE | RCTR | RAlt | RGUI |
 *               `-------------------------------------'        '------''----------------------------'
 */

 [_NAV] = LAYOUT(
    KC_ESC,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               C(KC_DEL), C(KC_LEFT), KC_NO,   C(KC_RIGHT), C(KC_BSPC), KC_DEL,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_MOD:
            if (record->event.pressed) {
                enc_mod_active = true;
            }
            return false;
    }
    return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (enc_mod_active) {
        enc_mod_active = false;
        uint8_t mode_count = (index == 0) ? 2 : 2;
        enc_idx[index] = (enc_idx[index] + (clockwise ? 1 : mode_count - 1)) % mode_count;
        return false;
    }
    if (index == 0) {
        if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                mk_max_speed = MIN(mk_max_speed + MOUSE_SPEED_STEP , 255);
            } else {
                mk_max_speed = MAX(mk_max_speed - MOUSE_SPEED_STEP, 1);
            }
        } else {
            switch (enc_mode_1[enc_idx[0]]) {
                case _VOL:
                    tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    break;
                case _SCROLL_X: /* horizontal scroll */
                    tap_code(clockwise ? MS_WHLR : MS_WHLL);
                    break;
            }
        }
    } else {
        switch (enc_mode_2[enc_idx[1]]) {
            case _ZOOM:    /* zoom */
                tap_code16(clockwise ? C(KC_EQL) : C(KC_MINUS));
                print("zoom");
                break;
            case _SCROLL_Y:
                tap_code(clockwise ? MS_WHLU : MS_WHLD);
                print("scroll y");
                break;
        }
    return false;
    }
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if(active) {
          tap_code(KC_MUTE);
          print("Mute");
      } else {  }
      break;
    case 1:
      if(active) {
          tap_code(KC_3);
          print("3");
      } else {  }
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

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Home row mods: double-tap then hold repeats the tapped key
        // (QMK's default Quick Tap Term behavior) instead of holding the mod.
        case LALT_T(KC_S):
        case LCTL_T(KC_D):
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
        case RCTL_T(KC_K):
        case RALT_T(KC_L):
            return QUICK_TAP_TERM;
        default:
            return QUICK_TAP_TERM;
    }
}

void keyboard_post_init_user(void) {
    debug_enable = true;
    print("Keyboard started\n");
}


