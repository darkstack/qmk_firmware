#if VIA_ENABLE
#if (!(CAPS_LOCK_INDEX | NUM_LOCK_INDEX))
#error "NO CAPS LOCK OR NUM LOCK DEFINED"
#endif

#include <via.h>
#include "quantum.h"

typedef struct _indicator_config_t {
    uint8_t h;
    uint8_t s;
    uint8_t v;
    bool    enabled;
} indicator_config;

typedef struct _designed_by_gg_config_t {
    indicator_config caps_lock;
    indicator_config num_lock;
    indicator_config layer1;
    indicator_config layer2;
} designed_by_gg_config_t;

designed_by_gg_config_t config; 


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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    
    bool change = false;
    RGB rgb = {0, 0, 0};

    if (layer_state_is(1)) {
        if(config.layer1.enabled){
            HSV config_color = {config.layer1.h, config.layer1.s, config.layer1.v};
            rgb = hsv_to_rgb(config_color);
            change = true;
        }
    } 

    if(layer_state_is(2)) {
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

    return false;
}

#endif
