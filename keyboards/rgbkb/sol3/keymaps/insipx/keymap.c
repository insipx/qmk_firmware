/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌────── ┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC  │   1  │   2  │   3  │   4  │   5  │   =  │  │   =  │   6  │   7  │   8  │   9  │   0  │   -  │
 * ├────── ┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab   │   Q  │   W  │   E  │   R  │   T  │   -  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├────── ┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ FN    │   A  │   S  │   D  │   F  │   G  │   =  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├────── ┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift  │   Z  │   X  │   C  │   V  │   B  │   -  │  │   }  │   N  │   M  │   ,  │   .  │   /  │  Sys │
 * ├────── ┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl  │  RBG │  ADJ │  WIN │ ALT  │      │ MEH  │  │ Esc  │      │ [    │   ]  │   [  │   ]  │ Rctl │
 * └────── ┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Enter├──────┴──────┴──────┴──────┴──────┘
 *                                     │      │ Bspc │  │ Tab  │      │
 *                                     └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _QWERTY,
    _COLEMAK,
    _GAME,
    _FN,
    _ADJUST
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)
#define COLEMAK  DF(_COLEMAK)
#define GAME     DF(_GAME)
#define QWERTY   DF(_QWERTY)
#define FN_TAB   LT(_FN, KC_TAB)
#define LCTL_Z   LCTL_T(KC_Z) // HOLD CTRL, TAP Z
//#define RGB_ADJ  LT(_ADJUST, RGB_TOG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,                   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        FN,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_EQL,                   KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  LCTL_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,                  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI,
        KC_LCTL,  RGB_TOG, ADJUST,  KC_LGUI, KC_LALT, KC_SPC,  MOD_MEH, KC_BSPC, KC_TAB,  KC_ESC,  KC_ENT, KC_LBRC, KC_RBRC, KC_LBRC, KC_RBRC, KC_RCTL,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______,                   _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______,                   _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,                   _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, KC_F1,                     KC_F5,   _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F2,                     KC_F6,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F3,                     KC_F7,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F4,                     KC_F8,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,                   _______, _______, KC_HOME, _______, KC_END,  KC_PSCR, KC_PGUP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  KC_PGDN,
        _______, AU_TOGG, MU_TOGG, MU_NEXT, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, CK_TOGG,   CK_UP, CK_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT, _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, QWERTY,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, COLEMAK,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, GAME,
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemk"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game  "), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
                  ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1 ... 4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                  ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
