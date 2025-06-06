// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _SYMBOLS,
    _NAV,
    _NUM,
    _GAME,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_LSTRT,
    KC_LEND,
};

#define SFTLLCK RSFT_T(KC_0)
#define CTLALT MT(MOD_LCTL|MOD_LALT, KC_NO)

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
 *            | LGUI | LAlt | LCTR |LOWER | /ENTER  /       \SPACE \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2        , KC_3        , KC_4         , KC_5,                               KC_6,           KC_7        , KC_8        , KC_9        , KC_0,     XXXXXXX,
    KC_ESC,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               KC_Y,           KC_U        , KC_I        , KC_O        , KC_P,     KC_QUOT,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G,                               KC_H,           RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B, KC_MUTE,             XXXXXXX, KC_N,           KC_M        , KC_COMM     , KC_DOT      , KC_SLSH,  SFTLLCK,
                        KC_LGUI, KC_LALT, KC_LCTL, MO(_SYMBOLS), KC_ENT,      LT(_NUM, KC_SPC), LT(_NAV, KC_ESC), KC_RCTL, KC_RALT, KC_RGUI
  ),
  
  
  /* SYMBOLS
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  `   |   1  |   2  |   <  |   >  |   [  |                    |   ]  |   &  |   |  |  `   |  F12 |   '  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |  !  |   =  |   -  |   (  |   {   |-------.    ,-------|   }  |   )  |   .  |   #   |   @  |      |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |     |  %   |   $   |  +   |   _  |      |-------|    |-------|   *  |   ^  |   ;  |   :  |   \  |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |SYMBOL | /ENTER  /       \SPACE \  |ADJST | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_SYMBOLS] = LAYOUT(
    _______, KC_F1  , KC_F2 , KC_F3      , KC_F4      , KC_F5,                           KC_F6  , KC_F7  , KC_F8     , KC_F9  , KC_F10 , KC_F11,
    KC_GRV , KC_1   , KC_2  , S(KC_COMMA), S(KC_DOT)  , KC_LBRC,                         KC_RBRC, KC_AMPR, S(KC_BSLS), KC_GRV , KC_F12 , _______,
    _______, KC_EXLM, KC_EQL, KC_MINUS   , KC_LPRN    , KC_LCBR,                         KC_RCBR, KC_RPRN, KC_DOT    , KC_HASH, KC_AT  , _______,
    _______, KC_PERC, KC_DLR, KC_PLUS    , S(KC_MINUS), XXXXXXX, _______,       _______, S(KC_8), S(KC_6), KC_SCLN   , KC_COLN, KC_BSLS, _______,
                      _______, _______, _______, _______, _______,                  _______,  MO(_ADJUST),   _______, _______, _______
  ),
  
  /* 
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Esc  | Ins  | Pscr | Menu |   <  |   >  |                    |FDLine| CLeft |  Up |CRight| DLine| Bspc |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |      | LAt  | LCtl |LShift|     |-------.    ,-------| Bspc | Left | Down | Right|  Del | Bspc |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |Shift | Undo |  Cut | Copy | Paste| CAPS |-------|    |-------| PGdn | Home |      | End  |      | Shift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |ADJST | /ENTER  /       \SPACE \  |LOWER | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______   , _______,                         _______,    _______, _______,    _______,    _______,  _______,
    _______, KC_INS , KC_PSCR, KC_APP , S(KC_COMM), S(KC_DOT),                       C(KC_DEL), C(KC_LEFT),   KC_UP, C(KC_RGHT), C(KC_BSPC),  KC_BSPC,
    _______, CTLALT , KC_LALT, KC_LCTL, KC_LSFT   , KC_EQL,                          KC_PGUP,    KC_LEFT, KC_DOWN,    KC_RGHT,     KC_DEL,  KC_BSPC,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V)   , KC_CAPS, _______,       _______, KC_PGDN,    KC_HOME, _______,     KC_END,    XXXXXXX,  _______,
                _______, _______, _______, MO(_ADJUST), _______,               _______, _______,    _______, _______, _______
  ),

  /* NUM
   * add function button to this layer?
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Esc  |      |      |      |      |      |                    |   +  | NUM7 | NUM8 | NUM9 |   y   |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |      |      |      |      |      |-------.    ,-------|   -  | NUM4 | NUM5 | NUM6 |  .   |      |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |Shift |      |      |      |      |      |-------|    |-------| NUM0 | NUM1 | NUM2 | NUM3 |      |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |      | /ENTER  /       \SPACE \  |      | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______    , _______, _______, _______,  _______ , _______,
    _______, _______, _______, _______, _______, _______,                         KC_KP_PLUS , KC_P7  , KC_P8  , KC_P9   ,  KC_PEQL , _______,
    _______, _______, _______, _______, _______, _______,                         KC_KP_MINUS, KC_P4  , KC_P5  , KC_P6   ,  KC_PDOT , _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, KC_KP_0    , KC_P1  , KC_P2  , KC_P3   ,  KC_PCMM , _______,
                      _______, _______, _______, XXXXXXX, _______,       _______, _______,    _______, _______, _______
  ),

    /* _GAME
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Esc  |      |      |      |      |      |                    |   +  | Q |   W   | E |  =   |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |      |      |      |      |      |-------.    ,-------|   -  | NUM4 | NUM5 | NUM6 |  .   |      |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |Shift |      |      |      |      |      |-------|    |-------| NUM0 | NUM1 | NUM2 | NUM3 |      |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |      | /ENTER  /       \Enter \  |      | RCTR | RAlt | RGUI |
   *            |      |      |      |      |/       /         \      \ |      |      |      |      |
   *            `----------------------------------'           '------''---------------------------'
   */
  [_GAME] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______    , _______, _______, _______,  _______ , _______,
    _______, _______, _______, _______, _______, _______,                         KC_KP_PLUS , KC_P7  , KC_P8  , KC_P9   ,  KC_PEQL , _______,
    _______, _______, _______, _______, _______, _______,                         KC_KP_MINUS, KC_P4  , KC_P5  , KC_P6   ,  KC_PDOT , _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, KC_KP_0    , KC_P1  , KC_P2  , KC_P3   ,  KC_PCMM , _______,
                      _______, _______, _______, XXXXXXX, _______,       _______, _______,    _______, _______, _______
  ),
  
  
  /* ADJUST
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    | RGB B| RGB R|RGB SW| RGB K|RGB TW|      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |QKBOOT|      |      |      |      |      |                    |      | R Hu+| R Tog| R Sa+|      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------
   * |ROMCLR|      | CGTOG|      |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
   * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *            | LGUI | LAlt | LCTR |LOWER | /ENTER  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
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
    switch(keycode) {
        case SFTLLCK:
            if (record->tap.count) {
                if (record->event.pressed) {
                    layer_lock_invert(get_highest_layer(layer_state));
                }
                return false;
            }
            break;    
          }
        return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

// Function to render layer state
void oled_render_layer_state(void) {
    oled_write_ln_P(PSTR("Layer "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("SYMBS"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV  "), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("NUM  "), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

// Function to render modifier states
void oled_render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods: "), false);
    oled_write_ln_P(MOD_MASK_SHIFT & modifiers ? PSTR("SFT ") : PSTR("    "), false);
    oled_write_ln_P(MOD_MASK_CTRL & modifiers ? PSTR("CTL ") : PSTR("    "), false);
    oled_write_ln_P(MOD_MASK_ALT & modifiers ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_ln_P(MOD_MASK_GUI & modifiers ? PSTR("GUI ") : PSTR("    "), false);
}

// Function to render caps lock status
void oled_render_caps_lock(void) {
  if (host_keyboard_led_state().caps_lock) {
    oled_write_ln_P(PSTR("CAPS"), true);
  } else {
    oled_write_ln_P(PSTR("CAPS"), false);
  }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Master side - show layer and status info
        oled_render_layer_state();
        oled_render_caps_lock();
        oled_render_mod_status(get_mods() | get_oneshot_mods());
    } else {
        // Slave side - could show different info or mirror master
        oled_write_ln_P(PSTR("Sofle"), false);
        oled_write_ln_P(PSTR("Keyboard"), false);
    }
    return false;
}
#endif
