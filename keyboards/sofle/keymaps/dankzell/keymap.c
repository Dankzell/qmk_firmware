// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _SWEQWERTY,
    _SYMBOLS,
    _NAV,
    _NUM,
    _GAME1,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_LSTRT,
    KC_LEND,
    TOGGLE_GAME,
    SS_CONSOLE_LOG,
};

#define SFTLLCK RSFT_T(KC_0)
#define CTLALT MT(MOD_LCTL|MOD_LALT, KC_NO)

enum {
    TD_U_CONSOLE_LOG,
};

// void u_console_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code(KC_U);
//     } else if (state->count == 2) {
//         SEND_STRING("console.log();");
//         tap_code(KC_LEFT);
//         tap_code(KC_LEFT);
//     }
// }

// void u_console_reset(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         unregister_code(KC_U);
//     }
// }

// tap_dance_action_t tap_dance_actions[] = {
//     [TD_U_CONSOLE_LOG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_console_finished, u_console_reset),
// };

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
    KC_ESC,   KC_Q,   KC_W        , KC_E        , KC_R         , KC_T,                               KC_Y,           KC_U      , KC_I        , KC_O        , KC_P,     KC_QUOT,
    KC_TAB,   KC_A,   LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F) , KC_G,                               KC_H,           RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,   KC_X        , KC_C        , KC_V         , KC_B, KC_MUTE,             XXXXXXX, KC_N,           KC_M        , KC_COMM     , KC_DOT      , KC_SLSH,  SFTLLCK,
                        KC_LGUI, KC_LALT, KC_LCTL, MO(_SYMBOLS), KC_ENT,      LT(_NUM, KC_SPC), LT(_NAV, KC_ESC), KC_RCTL, KC_RALT, KC_RGUI
  ),

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

 [_SWEQWERTY] = LAYOUT(
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
   * add function buttons to this layer?
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

    /* _GAME1
    ,-----------------------------------------.                    ,-----------------------------------------.
    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    | ESC  |   1  |   2  |   3  |   4  |   5  |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |  F7  |  F8  |  F9  | F10  | F11  | F12  |                    |   6  |   Q  |   W  |   E  |   R  |   T  |
    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    |  Up  | Left | Down |Right | PgUp | PgDn |-------.    ,-------| Tab  |   A  |   S  |   D  |   F  |   G  |
    |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    | LCtl | LAlt | Home | End  | Ins  | Del  |-------|    |-------|LShift|   Z  |   X  |   C  |   V  |   B  |
    `-----------------------------------------/       /     \      \-----------------------------------------'
            | LGUI | LAlt | Enter| Space| /ENTER  /       \ SPACE \  |Enter | RCTR | RAlt | RGUI |
            |      |      |      |      |/       /         \      \ |      |      |      |      |
            `----------------------------------'           '------''---------------------------'
   */
  [_GAME1] = LAYOUT(
     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                        KC_1   , KC_2  , KC_3  , KC_4  , KC_5 , KC_ESC,
    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,                         KC_6   , KC_Q  , KC_W  , KC_E  , KC_R , KC_T,
    KC_UP  , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN,                         KC_TAB , KC_A  , KC_S  , KC_D  , KC_F , KC_G, 
    KC_LCTL, KC_LALT, KC_HOME, KC_END , KC_INS , KC_DEL , _______,       _______, KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V , KC_B,
                      _______, _______, KC_ENT , KC_SPC , _______,       KC_SPC, KC_ENT , _______, _______, _______
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


// COMBOS
#ifdef COMBO_ENABLE
enum combo_events {
    GAME_TOGGLE_COMBO,
};

const uint16_t PROGMEM game_toggle_combo[] = {KC_ESC, KC_TAB, COMBO_END};

combo_t key_combos[] = {
    [GAME_TOGGLE_COMBO] = COMBO(game_toggle_combo, TOGGLE_GAME),
};

#endif

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
        case TOGGLE_GAME:
            if (record->event.pressed) {
                layer_invert(_GAME1); //Toggles game layer on or off
            }
            return false;
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
        case _GAME1:
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
  if (host_keyboard_led_state().caps_lock || is_caps_word_on()) {
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
