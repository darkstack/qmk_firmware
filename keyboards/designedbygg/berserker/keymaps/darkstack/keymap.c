/* Copyright 2023 Dimitris Mantzouranis <d3xter93@gmail.com>
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

#define _BASE 0
#define _SECOND 1
#define _THIRD 2
#define _FOURTH 3
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Scr│Pse│
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │ │Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent│ └───┴───┴───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│ FN │Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
     */
    [_BASE] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,

        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,             KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(1),  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_SECOND] = LAYOUT_tkl_iso(
        QK_BOOT,         KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, _______, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, _______, _______, _______, _______, RGB_TOG,    _______, _______, _______,

        _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,
        KC_MS_BTN3, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______, _______, _______, _______, _______, _______, RALT(KC_5), RALT(KC_MINS),                     _______, _______, _______,
        _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, _______, _______, _______, _______, _______, RALT(KC_4), RALT(KC_EQL),      _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          MO(2),             RGB_MOD,
        _______, 0x700b, _______,                            _______,                            _______, KC_APP, _______, _______,    RGB_SAI, RGB_HUI, RGB_SPI
    ),
    [_THIRD] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,

        KC_NUM_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,
        _______, KC_P7, KC_P5,KC_P6, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_P1,KC_P2,KC_P3, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            KC_P0,                            _______, _______, _______, _______,    _______, _______, _______
    )
//    [_FOURTH] = LAYOUT_tkl_iso(
//        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
//
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
//        _______, _______, _______,                            _______,                            _______, _______, _______, _______,    _______, _______, _______
//    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SECOND]   = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_THIRD]   = {ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT) }
//    [_FOURTH]   = {ENCODER_CCW_CW(KC_NO, KC_NO) },
};
#endif

__attribute__((weak)) bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (host_keyboard_led_state().caps_lock)
        RGB_MATRIX_INDICATOR_SET_COLOR(49,255,0,0)
    if (host_keyboard_led_state().scroll_lock)
        RGB_MATRIX_INDICATOR_SET_COLOR(14,255,0,0)

    bool change = false;
    RGB rgb = {0, 0, 0};

    if (layer_state_is(_SECOND)) {
        rgb.g = 255;
        change = true;
    } 
    if(layer_state_is(_THIRD)) {
        rgb.g = 0;
        rgb.b = 255;
        change = true;
    }

    if(change)
        for (uint8_t i = led_min; i < led_max; i++) {
            
            if(HAS_FLAGS(g_led_config.flags[i],LED_FLAG_MODIFIER) | (i == 49))
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }

    return true;
}


void keyboard_post_init_user(void) {
}
