#include QMK_KEYBOARD_H

#include "naginata.h"
#include "genf.h"

typedef union {
    uint32_t pr_counter;
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) { //
    user_config.pr_counter = eeconfig_read_user();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_DVORAK] = LAYOUT_wrapper(
        ________DVORAK_1________,
        ________DVORAK_2________,
        ________DVORAK_3________,
        _______DVORAK_MOD_______
    ),
    [L_LOWER] = LAYOUT_wrapper(
        ________LOWER_1________,
        ________LOWER_2________,
        ________LOWER_3________,
        _______LOWER_MOD_______
    ),
    [L_NAGINATA] = LAYOUT_wrapper(
        _______NAGINATA_1_______,
        _______NAGINATA_2_______,
        _______NAGINATA_3_______,
        ______NAGINATA_MOD______
    ),
    [L_RAISE] = LAYOUT_wrapper(
        _________RAISE_1________,
        _________RAISE_2________,
        _________RAISE_3________,
        ________RAISE_MOD_______
    ),
    [L_ADJUST] = LAYOUT_wrapper(
        ________ADJUST_1________,
        ________ADJUST_2________,
        ________ADJUST_3________,
        _______ADJUST_MOD_______
    ),
    [L_MODIFIER] = LAYOUT_wrapper(
        _______MODIFIER_1_______,
        _______MODIFIER_2_______,
        _______MODIFIER_3_______,
        ______MODIFIER_MOD______
    ),
    [L_GAME] = LAYOUT_wrapper(
        _______GAME_1_______,
        _______GAME_2_______,
        _______GAME_3_______,
        ______GAME_MOD______
    ),
    [L_GAME2] = LAYOUT_wrapper(
        _______GAME2_1_______,
        _______GAME2_2_______,
        _______GAME2_3_______,
        ______GAME2_MOD______
    ),
};

// clang-format on

// TODO
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        user_config.pr_counter++;
    }
    switch (keycode) {
        case NAG_ESC:
            if (record->event.pressed) {
                tap_code(KC_LANG2);
                set_single_persistent_default_layer(L_DVORAK);
                register_code(KC_ESC);
            }
            return false;
            break;
        case SV_COUNT:
            eeconfig_update_user(user_config.pr_counter);
            return false;
            break;
        case RST_COUNT:
            user_config.pr_counter = 0;
            return false;
            break;
        default:
            if (!process_naginata(keycode, record)) {
                return false;
            }
            return true;
    }
}

#ifdef OLED_ENABLE

#    ifdef IS_RIGHT
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180; // flips the display 180 degrees if offhand
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, //
        0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, //
        0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, //
        0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, //
        0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, //
        0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, //
        0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, //
        0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00  //
    };

    oled_write_P(qmk_logo, false);
}
#    else

const char numbers[12][24] = {
    {0xfc, 0xfe, 0x07, 0x83, 0xc3, 0xe3, 0x73, 0x37, 0xfe, 0xfc, 0x00, 0x00, 0x0f, 0x1f, 0x3b, 0x33, 0x31, 0x30, 0x30, 0x38, 0x1f, 0x0f, 0x00, 0x00}, //
    {0x00, 0x00, 0x00, 0x18, 0x1c, 0x0e, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x3f, 0x3f, 0x30, 0x30, 0x00, 0x00}, //
    {0x1c, 0x1e, 0x07, 0x03, 0x03, 0x83, 0xc3, 0xe7, 0x7e, 0x3c, 0x00, 0x00, 0x30, 0x38, 0x3c, 0x3e, 0x37, 0x33, 0x31, 0x30, 0x38, 0x3c, 0x00, 0x00}, //
    {0x0c, 0x0e, 0x07, 0x03, 0xc3, 0xc3, 0xc3, 0xe7, 0xfe, 0x3c, 0x00, 0x00, 0x0c, 0x1c, 0x38, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
    {0x80, 0xe0, 0xf0, 0x38, 0x1c, 0x0e, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x3f, 0x3f, 0x03, 0x03, 0x00, 0x00}, //
    {0xf0, 0xff, 0xdf, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x03, 0x00, 0x00, 0x0c, 0x1c, 0x38, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
    {0xfc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0x8e, 0x0c, 0x00, 0x00, 0x0f, 0x1f, 0x38, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
    {0x06, 0x07, 0x03, 0x03, 0x03, 0x83, 0xc3, 0xe3, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3f, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}, //
    {0x3c, 0xfe, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0xfe, 0x3c, 0x00, 0x00, 0x0f, 0x1f, 0x39, 0x30, 0x30, 0x30, 0x30, 0x39, 0x1f, 0x0f, 0x00, 0x00}, //
    {0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0x67, 0xfe, 0xfc, 0x00, 0x00, 0x0c, 0x1c, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1f, 0x0f, 0x00, 0x00}, //
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3e, 0x1e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00}, //
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //
};

void write_num(int num, int index) {
    for (int i = 0; i < 24; ++i) {
        oled_write_raw_byte(numbers[num][i], i + i / 12 * 116 + index);
    }
}
#    endif

bool oled_task_user(void) {
#    ifdef IS_RIGHT
    render_logo();
#    else
    uint32_t buf                = 0;
    uint8_t  data               = 0;
    char     pressed_counter[9] = {11, 11, 11, 11, 11, 11, 11, 11, 0};
    int      n                  = 0;
    buf                         = user_config.pr_counter;
    while (buf > 0) {
        data = buf % 10;
        if (n <= 8) {
            pressed_counter[8 - n] = data;
            if ((n == 2 || n == 6) && buf >= 10) {
                n++;
                pressed_counter[8 - n] = 10;
            }
        }
        buf = buf / 10;
        n++;
    }
    for (int i = 0; i < 9; ++i) {
        write_num(pressed_counter[i], 12 * i + 138);
    }
#    endif
    return false;
}

#endif

// vim:set sw=4 ts=4 sts=4:
