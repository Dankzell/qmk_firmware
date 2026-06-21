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

// Tap once: one-shot shift; twice: caps_word; three times: KC_3
enum {
    TD_OSM_CAPS
};

void osm_caps_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    } else if (state->count == 2) {
        caps_word_toggle();
    } else if (state->count >= 3) {
        tap_code(KC_3);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_OSM_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, osm_caps_finished, NULL)
};

enum combos {
    C_L_PAREN,
    C_R_PAREN,
    C_L_BRACE,
    C_R_BRACE,
    C_L_BRACKET,
    C_R_BRACKET,
    C_EQ,
    C_MINUS,
    C_UNDER,
    COMBO_LENGTH
};

const uint16_t PROGMEM combo_l_paren[]   = {LCTL_T(KC_D),  LSFT_T(KC_F),    COMBO_END};
const uint16_t PROGMEM combo_r_paren[]   = {RSFT_T(KC_J),  RCTL_T(KC_K),    COMBO_END};
const uint16_t PROGMEM combo_l_brace[]   = {LALT_T(KC_S),  LCTL_T(KC_D),    COMBO_END};
const uint16_t PROGMEM combo_r_brace[]   = {RCTL_T(KC_K),  RALT_T(KC_L),    COMBO_END};
const uint16_t PROGMEM combo_l_bracket[] = {LGUI_T(KC_A),  LALT_T(KC_S),    COMBO_END};
const uint16_t PROGMEM combo_r_bracket[] = {RALT_T(KC_L),  RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM combo_eq[]        = {KC_V,          KC_B,            COMBO_END};
const uint16_t PROGMEM combo_minus[]     = {KC_W,          KC_E,            COMBO_END};
const uint16_t PROGMEM combo_under[]     = {KC_E,          KC_R,            COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [C_L_PAREN]   = COMBO(combo_l_paren,   KC_LPRN),
    [C_R_PAREN]   = COMBO(combo_r_paren,   KC_RPRN),
    [C_L_BRACE]   = COMBO(combo_l_brace,   KC_LCBR),
    [C_R_BRACE]   = COMBO(combo_r_brace,   KC_RCBR),
    [C_L_BRACKET] = COMBO(combo_l_bracket, KC_LBRC),
    [C_R_BRACKET] = COMBO(combo_r_bracket, KC_RBRC),
    [C_EQ]        = COMBO(combo_eq,        KC_EQL),
    [C_MINUS]     = COMBO(combo_minus,     KC_MINS),
    [C_UNDER]     = COMBO(combo_under,     KC_UNDS),
};

enum joystick_modes {
    _MOUSE,
    _ARROW
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY (mirrors tiny-micro default_layer)
 * ,-----------------------------------------.                           ,----------------------------------------.
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  |   ' |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * | ESC  | A(G) | S(A) | D(C) | F(S) |   G  |ENC_MOD|         |      |  H  | J(S) | K(C) | L(A) | ;(G) | Bspc |
 * |------+------+------+------+------+------|-------|        |------+-----+-------+------+------+------+------|
 * |OSM/CW|   Z  |   X  |   C  |   V  |   B  |       |        |      |  N  |   M  |   ,  |   .  |   /  |RShft |
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               | LGUI | LAlt | LCtl | SYMB | /ENT  /       \NUM/SPC\  |NAV/ESC| RCtl | RAlt | RGUI |
 *               `-------------------------------------'        '-------''---------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GRV,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               KC_Y,      KC_U      , KC_I        , KC_O        , KC_P,     KC_QUOT,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G, KC_NO,              KC_NO,    KC_H,      RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B,                     KC_NO,    KC_N,      KC_M        , KC_COMM     , KC_DOT      , KC_SLSH,  KC_RSFT,
        KC_LALT, LCTL_T(KC_TAB) , LT(KC_ESC, _SYMB) , LT(_EXTRA, KC_ENT), KC_LGUI,    KC_NO,   LT(_NUM, KC_SPC), LT(_NAV, KC_BSPC), RCTL_T(KC_ESC), KC_RALT
  ),

/*
 * SYMB (mirrors tiny-micro symb_layer)
 * ,-----------------------------------------.                           ,----------------------------------------.
 * |  `   |   1  |   2  |   <  |   >  |   [  |                          |   ]  |   &  |   |  |   `  |      |      |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * |      |   !  |   =  |   -  |   (  |   {  |        |         |      |   }  |   )  |   .  |   #  |   @  |      |
 * |------+------+------+------+------+------|-------|        |------+------+------+------+------+------+------|
 * |      |   %  |   $  |   +  |   _  |      |        |        |      |   *  |   ^  |   ;  |   :  |   \  |      |
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               |      |      |      | SYMB |       |       |       |      |      |      |      |
 *               `-------------------------------------'        '-------''---------------------------'
 */
 [_SYMB] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,   S(KC_COMM), S(KC_DOT),  KC_LBRC,                              KC_RBRC,  KC_AMPR, S(KC_BSLS), KC_GRV,  KC_TRNS, KC_DEL,
    KC_TRNS, KC_EXLM, KC_EQL, KC_MINUS,   KC_LPRN,    KC_LCBR,  KC_TRNS,       KC_TRNS,     KC_RCBR,  KC_RPRN, KC_DOT,     KC_HASH, KC_AT,   KC_TRNS,
    KC_TRNS, KC_PERC, KC_DLR, KC_PLUS,    S(KC_MINS), XXXXXXX,               KC_TRNS,     S(KC_8),  S(KC_6), KC_SCLN,    KC_COLN, KC_BSLS, KC_TRNS,
          KC_LALT, KC_TRNS, MO(_SYMB), LT(_EXTRA, KC_ENT), KC_TRNS,    KC_NO, LT(_NUM, KC_SPC), LT(_NAV, KC_ESC), KC_RCTL, KC_RALT
  ),

/*
 * NAV (mirrors tiny-micro nav_layer)
 * ,-----------------------------------------.                           ,----------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                          |C(Del)|C(←) |      |C(→) |C(Bs)|      |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * | TAB  |   A  | S(A) | D(C) | F(S) |   G  |        |         |      |  ←  |   ↓  |   ↑  |  →  | Home |      |
 * |------+------+------+------+------+------|-------|        |------+-----+-------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  | CAPS |        |        |      |     | PgDn | PgUp |     | End  |      |
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               | LCtl | SYMB | ENT  | LGUI |       |       | Spc  |      | RCtl | RAlt |      |
 *               `-------------------------------------'        '-------''---------------------------'
 */

 [_NAV] = LAYOUT(
    KC_ESC,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               C(KC_DEL), C(KC_LEFT), KC_NO,   C(KC_RIGHT), C(KC_BSPC), KC_DEL,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G, KC_NO,              KC_NO,    KC_LEFT,   KC_DOWN,    KC_UP,   KC_RIGHT,    KC_HOME,    KC_TRNS,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B,                     KC_NO,    KC_NO,     KC_PGDN,    KC_PGUP, KC_NO,       KC_END,     KC_TRNS,
                    KC_LALT, KC_LCTL , MO(_SYMB) , LT(_EXTRA, KC_ENT), KC_LGUI,            KC_NO,   LT(_NUM, KC_SPC), LT(_NAV, KC_ESCAPE), KC_RCTL, KC_RALT
  ),


/*
 * NUM (mirrors tiny-micro num_layer; BT keycodes have no QMK equivalent, left side has F-keys)
 * ,-----------------------------------------.                           ,----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                          |  K-  |  7   |  8   |  9   |  K/  | Del  |
 * |------+------+------+------+------+------|--------|         ,-----|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |         | Num  |  K+  |  4   |  5   |  6   |  K*  | Bspc |
 * |------+------+------+------+------+------|-------|        |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |        |        |      |  0   |  1   |  2   |  3   |  K.  | KEnter|
 * `-----------------------------------------|-------|      |-------|-----------------------------------------'
 *               |      |      |      |      |       |       |      |      |      |      |      |
 *               `-------------------------------------'        '-------''---------------------------'
 */
[_NUM] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                 KC_PMNS, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_DEL,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,      KC_NUM,           KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PAST, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_NO,                  KC_P0,   KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/*
 * EXTRA / GAME (mirrors tiny-micro game_layer)
 * Same as NAV but with LSHIFT and B on row 2 (no home-row mods on row 2)
 */
[_EXTRA] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,         KC_E,         KC_R,         KC_T,                               C(KC_DEL), C(KC_LEFT), KC_NO,   C(KC_RIGHT), C(KC_BSPC), KC_NO,
    KC_TAB,  KC_A,    LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_NO,      KC_NO,           KC_LEFT,   KC_DOWN,    KC_UP,   KC_RIGHT,    KC_HOME,    KC_TRNS,
    KC_LSFT, KC_Z,    KC_X,         KC_C,         KC_V,         KC_B,         KC_NO,                KC_NO,     KC_PGDN,    KC_PGUP, KC_NO,       KC_END,     KC_TRNS,
    KC_LCTL, MO(_SYMB), KC_ENT, KC_LGUI, KC_NO,    KC_SPC, KC_TRNS, KC_RCTL, KC_RALT, KC_NO
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

void keyboard_post_init_user(void) {
    debug_enable = true;
    print("Keyboard started\n");
}


