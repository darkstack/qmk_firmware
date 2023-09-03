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

#include <stdalign.h>
#include <sys/types.h>
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
        QK_BOOT,         KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, _______, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, _______, _______, _______, QK_REBOOT, RGB_TOG,    _______, _______, _______,

        _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, RGB_VAI,
        KC_MS_BTN3, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______, _______, _______, _______, _______, _______, _______, RALT(KC_5), RALT(KC_MINS),                     _______, _______, _______,
        _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, _______, _______, _______, _______, _______, RALT(KC_4), RALT(KC_EQL),      _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          MO(2),             RGB_MOD,
        _______, 0x700b, _______,                            _______,                            _______, KC_APP, _______, _______,    RGB_SAI, RGB_HUI, RGB_SPI
    ),
    [_THIRD] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,

        KC_NUM_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______,
        _______, KC_P4, KC_P5,KC_P6, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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


typedef struct _indicator_config_t {
    uint8_t h;
    uint8_t s;
    uint8_t v;
    bool    enabled;
} indicator_config;

typedef struct _berserker_config_t {
    indicator_config caps_lock;
    indicator_config num_lock;
    indicator_config layer1;
    indicator_config layer2;
} berserker_config;

berserker_config config; 


enum via_config_enums {
    id_config_caps_lock_enabled = 1,
    id_config_caps_lock_brightness = 2,
    id_config_caps_lock_color = 3,
    id_config_num_lock_enabled = 4,
    id_config_num_lock_brightness = 5,
    id_config_num_lock_color = 6,
    id_config_layer1_enabled = 7,
    id_config_layer1_brightness = 8,
    id_config_layer1_color = 9,
    id_config_layer2_enabled = 10,
    id_config_layer2_brightness = 11,
    id_config_layer2_color = 12
};


void eeconfig_init_user(void) {
    // Default values
    config.caps_lock.h       = 0;
    config.caps_lock.s       = 255;
    config.caps_lock.v       = 255;
    config.caps_lock.enabled = true;

    config.num_lock.h       = 0;
    config.num_lock.s       = 255;
    config.num_lock.v       = 255;
    config.num_lock.enabled = true;

    config.layer1.h       = 85;
    config.layer1.s       = 255;
    config.layer1.v       = 255;
    config.layer1.enabled = true;

    config.layer2.h       = 170;
    config.layer2.s       = 255;
    config.layer2.v       = 255;
    config.layer2.enabled = true;
    eeconfig_update_kb_datablock(&config);
}


void keyboard_post_init_user(void) {
    eeconfig_read_kb_datablock(&config);
}


void config_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_config_caps_lock_enabled: {
            config.caps_lock.enabled = value_data[0];
            break;
        }
        case id_config_caps_lock_brightness: {
            config.caps_lock.v = value_data[0];
            break;
        }
        case id_config_caps_lock_color: {
            config.caps_lock.h = value_data[0];
            config.caps_lock.s = value_data[1];
            break;
        }

        case id_config_num_lock_enabled: {
            config.num_lock.enabled = value_data[0];
            break;
        }
        case id_config_num_lock_brightness: {
            config.num_lock.v = value_data[0];
            break;
        }
        case id_config_num_lock_color: {
            config.num_lock.h = value_data[0];
            config.num_lock.s = value_data[1];
            break;
        }


        case id_config_layer1_enabled: {
            config.layer1.enabled = value_data[0];
            break;
        }
        case id_config_layer1_brightness: {
            config.layer1.v = value_data[0];
            break;
        }
        case id_config_layer1_color: {
            config.layer1.h = value_data[0];
            config.layer1.s = value_data[1];
            break;
        }

        case id_config_layer2_enabled: {
            config.layer2.enabled = value_data[0];
            break;
        }
        case id_config_layer2_brightness: {
            config.layer2.v = value_data[0];
            break;
        }
        case id_config_layer2_color: {
            config.layer2.h = value_data[0];
            config.layer2.s = value_data[1];
            break;
        }
    }
}

void config_get_value(uint8_t *data) {
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_config_caps_lock_enabled: {
            value_data[0] = config.caps_lock.enabled;
            break;
        }
        case id_config_caps_lock_brightness: {
            value_data[0] = config.caps_lock.v;
            break;
        }
        case id_config_caps_lock_color: {
            value_data[0] = config.caps_lock.h;
            value_data[1] = config.caps_lock.s;
            break;
        }

        case id_config_num_lock_enabled: {
            value_data[0] = config.num_lock.enabled;
            break;
        }
        case id_config_num_lock_brightness: {
            value_data[0] = config.num_lock.v;
            break;
        }
        case id_config_num_lock_color: {
            value_data[0] = config.num_lock.h;
            value_data[1] = config.num_lock.s;
            break;
        }

        case id_config_layer1_enabled: {
            value_data[0] = config.layer1.enabled;
            break;
        }
        case id_config_layer1_brightness: {
            value_data[0] = config.layer1.v;
            break;
        }
        case id_config_layer1_color: {
            value_data[0] = config.layer1.h;
            value_data[1] = config.layer1.s;
            break;
        }

        case id_config_layer2_enabled: {
            value_data[0] = config.layer2.enabled;
            break;
        }
        case id_config_layer2_brightness: {
            value_data[0] = config.layer2.v;
            break;
        }
        case id_config_layer2_color: {
            value_data[0] = config.layer2.h;
            value_data[1] = config.layer2.s;
            break;
        }
    }
}

void config_save(void) {
    eeconfig_update_kb_datablock(&config);
}


void via_custom_value_command_kb(uint8_t *data,uint8_t length){
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if (*channel_id == id_custom_channel) {
        switch (*command_id) {
            case id_custom_set_value: {
                config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value: {
                config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save: {
                config_save();
                break;
            }
            default: {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    *command_id = id_unhandled;
}

#define CAPS_LOCK_INDEX 49
#define NUM_LOCK_INDEX 16

__attribute__((weak)) bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    

//    if (host_keyboard_led_state().scroll_lock)
//        RGB_MATRIX_INDICATOR_SET_COLOR(14,255,0,0);

    bool change = false;
    RGB rgb = {0, 0, 0};

    if (layer_state_is(_SECOND)) {
        if(config.layer1.enabled){
            HSV config_color = {config.layer1.h, config.layer1.s, config.layer1.v};
            rgb = hsv_to_rgb(config_color);
            change = true;
        }
    } 

    if(layer_state_is(_THIRD)) {
        if(config.layer2.enabled){
            HSV config_color = {config.layer2.h, config.layer2.s, config.layer2.v};
            rgb = hsv_to_rgb(config_color);
            change = true;
        }
        else{
            //invalide previous change just in case
            change = false;
        }
    }

    if(change){
        for (uint8_t i = led_min; i < led_max; i++) {
            
            if(HAS_FLAGS(g_led_config.flags[i],LED_FLAG_MODIFIER))
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }

    if (config.caps_lock.enabled && host_keyboard_led_state().caps_lock)
    {
        HSV config_color = {config.caps_lock.h, config.caps_lock.s, config.caps_lock.v};
        RGB rgb_color = hsv_to_rgb(config_color);

        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX,rgb_color.r,rgb_color.g,rgb_color.b);
    }

    if (config.num_lock.enabled && host_keyboard_led_state().num_lock)
    {
        HSV config_color = {config.num_lock.h, config.num_lock.s, config.num_lock.v};
        RGB rgb_color = hsv_to_rgb(config_color);

        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_INDEX,rgb_color.r,rgb_color.g,rgb_color.b);
    }

    return true;
}
