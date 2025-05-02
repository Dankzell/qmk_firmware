// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_QWERTY PDF(_QWERTY)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   '  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_QUOT,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                      KC_LGUI, KC_LALT, KC_LCTL, LT(_RAISE, KC_LGUI), KC_ENT,      KC_SPC,  LT(_LOWER, KC_ESC),   KC_RCTL, KC_RALT, KC_RGUI
  ),
  
  
  /* LOWER
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |   !  |   @  |   #  |  (   |   )  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * | Shift|  %  |   $  |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |ADJST | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,  KC_HASH, KC_LPRN, KC_RPRN,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_PERC, KC_DLR, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______,       _______,  MO(3),   _______, _______, _______
  ),
  
  /* RAISE
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Esc  | Ins  | Pscr | Menu |   <  |   >  |                    | PGup | CLeft |  Up  |CRight| DLine| Bspc |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  | LAt  | LCtl |LShift|   -  |   =  |-------.    ,-------| Bspc | Left | Down | Right|  Del | Bspc |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |Shift | Undo |  Cut | Copy | Paste| CAPS |-------|    |-------| PGdn | Home |      | End  |      | Shift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |ADJST | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______,    _______, _______,    _______,    _______,  _______,
    _______, KC_INS,  KC_PSCR, KC_APP,  S(KC_COMM), S(KC_DOT),                         KC_PGUP, C(KC_LEFT),   KC_UP, C(KC_RGHT), C(KC_BSPC),  KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, KC_MINUS, KC_EQL,                         KC_BSPC,    KC_LEFT, KC_DOWN,    KC_RGHT,     KC_DEL,  KC_BSPC,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_CAPS, _______,       _______, KC_PGDN,    KC_HOME, _______,     KC_END,    XXXXXXX,  _______,
                      _______, _______, _______, MO(3),   _______,       _______, _______,    _______, _______, _______
  ),
  
  /* ADJUST
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    | RGB B| RGB R|RGB SW| RGB K|RGB TW|      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |QKBOOT|      |      |      |      |      |                    |      | R Hu+| R Tog| R Sa+|      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |ROMCLR|      | CGTOG|      |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_K, RGB_M_TW, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, RGB_HUI, RGB_TOG,  RGB_SAI, XXXXXXX,  XXXXXXX,
    EE_CLR,  XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_VOLD, KC_MUTE,  KC_VOLU, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY,  KC_MNXT, XXXXXXX,  XXXXXXX,
                      _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  )};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state,
            _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
