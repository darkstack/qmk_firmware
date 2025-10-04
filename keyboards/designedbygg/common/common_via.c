#if (!(CAPS_LOCK_INDEX | NUM_LOCK_INDEX))
#error "NO CAPS LOCK OR NUM LOCK DEFINED"
#endif

#include "quantum.h"

typedef struct _indicator_config_t {
    uint8_t h;
    uint8_t s;
    uint8_t v;
    bool    enabled;
} indicator_config;


typedef union {
    uint32_t raw;
    struct {
    indicator_config caps_lock;
    indicator_config num_lock;
    indicator_config win_key;
    indicator_config layer1;
    indicator_config layer2;
    };
} user_config_t;

user_config_t user_config;

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
    id_config_layer2_color = 12,
    id_config_win_key_enabled = 13,
    id_config_win_key_brightness = 14,
    id_config_win_key_color = 15,
};


void eeconfig_init_user(void) {
    user_config.raw = 0;
    // Default values
    user_config.caps_lock.h       = 0;
    user_config.caps_lock.s       = 255;
    user_config.caps_lock.v       = 255;
    user_config.caps_lock.enabled = true;

    user_config.num_lock.h       = 0;
    user_config.num_lock.s       = 255;
    user_config.num_lock.v       = 255;
    user_config.num_lock.enabled = true;

    #if WIN_LOCK_INDEX
    user_config.win_key.h       = 0;
    user_config.win_key.s       = 255;
    user_config.win_key.v       = 255;
    user_config.win_key.enabled = true;
    #endif

    user_config.layer1.h       = 85;
    user_config.layer1.s       = 255;
    user_config.layer1.v       = 255;
    user_config.layer1.enabled = true;

    user_config.layer2.h       = 170;
    user_config.layer2.s       = 255;
    user_config.layer2.v       = 255;
    user_config.layer2.enabled = true;
    eeconfig_update_user(user_config.raw);
}


void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}


void config_save(void) {
    eeconfig_update_user(user_config.raw);
}

#if VIA_ENABLE
#include <via.h>
void config_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_config_caps_lock_enabled: {
            user_config.caps_lock.enabled = value_data[0];
            break;
        }
        case id_config_caps_lock_brightness: {
            user_config.caps_lock.v = value_data[0];
            break;
        }
        case id_config_caps_lock_color: {
            user_config.caps_lock.h = value_data[0];
            user_config.caps_lock.s = value_data[1];
            break;
        }

        case id_config_num_lock_enabled: {
            user_config.num_lock.enabled = value_data[0];
            break;
        }
        case id_config_num_lock_brightness: {
            user_config.num_lock.v = value_data[0];
            break;
        }
        case id_config_num_lock_color: {
            user_config.num_lock.h = value_data[0];
            user_config.num_lock.s = value_data[1];
            break;
        }


        case id_config_layer1_enabled: {
            user_config.layer1.enabled = value_data[0];
            break;
        }
        case id_config_layer1_brightness: {
            user_config.layer1.v = value_data[0];
            break;
        }
        case id_config_layer1_color: {
            user_config.layer1.h = value_data[0];
            user_config.layer1.s = value_data[1];
            break;
        }

        case id_config_layer2_enabled: {
            user_config.layer2.enabled = value_data[0];
            break;
        }
        case id_config_layer2_brightness: {
            user_config.layer2.v = value_data[0];
            break;
        }
        case id_config_layer2_color: {
            user_config.layer2.h = value_data[0];
            user_config.layer2.s = value_data[1];
            break;
        }

    #if WIN_LOCK_INDEX
        case id_config_win_key_enabled: {
            user_config.win_key.enabled = value_data[0];
            break;
        }
        case id_config_win_key_brightness: {
            user_config.win_key.v = value_data[0];
            break;
        }
        case id_config_win_key_color: {
            user_config.win_key.h = value_data[0];
            user_config.win_key.s = value_data[1];
            break;
        }

    #endif

    }
}

void config_get_value(uint8_t *data) {
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_config_caps_lock_enabled: {
            value_data[0] = user_config.caps_lock.enabled;
            break;
        }
        case id_config_caps_lock_brightness: {
            value_data[0] = user_config.caps_lock.v;
            break;
        }
        case id_config_caps_lock_color: {
            value_data[0] = user_config.caps_lock.h;
            value_data[1] = user_config.caps_lock.s;
            break;
        }

        case id_config_num_lock_enabled: {
            value_data[0] = user_config.num_lock.enabled;
            break;
        }
        case id_config_num_lock_brightness: {
            value_data[0] = user_config.num_lock.v;
            break;
        }
        case id_config_num_lock_color: {
            value_data[0] = user_config.num_lock.h;
            value_data[1] = user_config.num_lock.s;
            break;
        }

        case id_config_layer1_enabled: {
            value_data[0] = user_config.layer1.enabled;
            break;
        }
        case id_config_layer1_brightness: {
            value_data[0] = user_config.layer1.v;
            break;
        }
        case id_config_layer1_color: {
            value_data[0] = user_config.layer1.h;
            value_data[1] = user_config.layer1.s;
            break;
        }

        case id_config_layer2_enabled: {
            value_data[0] = user_config.layer2.enabled;
            break;
        }
        case id_config_layer2_brightness: {
            value_data[0] = user_config.layer2.v;
            break;
        }
        case id_config_layer2_color: {
            value_data[0] = user_config.layer2.h;
            value_data[1] = user_config.layer2.s;
            break;
        }


    #if WIN_LOCK_INDEX
        case id_config_win_key_enabled: {
            value_data[0] = user_config.win_key.enabled;
            break;
        }
        case id_config_win_key_brightness: {
            value_data[0] = user_config.win_key.v;
            break;
        }
        case id_config_win_key_color: {
            value_data[0] = user_config.win_key.h;
            value_data[1] = user_config.win_key.s;
            break;
        }
    #endif
    }
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
#endif
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    bool change = false;
    RGB rgb = {0, 0, 0};

    if (layer_state_is(1)) {
        if(user_config.layer1.enabled){
            HSV config_color = {user_config.layer1.h, user_config.layer1.s, user_config.layer1.v};
            rgb = hsv_to_rgb(config_color);
            change = true;
        }
    }

    if(layer_state_is(2)) {
        if(user_config.layer2.enabled){
            HSV config_color = {user_config.layer2.h, user_config.layer2.s, user_config.layer2.v};
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

    if (user_config.caps_lock.enabled && host_keyboard_led_state().caps_lock)
    {
        HSV config_color = {user_config.caps_lock.h, user_config.caps_lock.s, user_config.caps_lock.v};
        RGB rgb_color = hsv_to_rgb(config_color);

        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX,rgb_color.r,rgb_color.g,rgb_color.b);
    }

    if (user_config.num_lock.enabled && host_keyboard_led_state().num_lock)
    {
        HSV config_color = {user_config.num_lock.h, user_config.num_lock.s, user_config.num_lock.v};
        RGB rgb_color = hsv_to_rgb(config_color);

        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_INDEX,rgb_color.r,rgb_color.g,rgb_color.b);
    }
    #if WIN_LOCK_INDEX
    if (user_config.win_key.enabled && keymap_config.no_gui)
    {
        HSV config_color = {user_config.win_key.h, user_config.win_key.s, user_config.win_key.v};
        RGB rgb_color = hsv_to_rgb(config_color);

        RGB_MATRIX_INDICATOR_SET_COLOR(WIN_LOCK_INDEX,rgb_color.r,rgb_color.g,rgb_color.b);
    }
    #endif


    return false;
}

