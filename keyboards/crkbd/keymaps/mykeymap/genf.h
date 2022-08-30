#pragma once

#include QMK_KEYBOARD_H
#include "naginata.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define KC_C_BS CTL_T(KC_BSPC)
#define KC_M_ENT LT(L_MODIFIER, KC_ENT)

#define RAISE MO(L_RAISE)
#define LOWER MO(L_LOWER)
#define ADJUST MO(L_ADJUST)

#define KC_S_TAB SFT_T(KC_TAB)
#define KC_S_RBRC SFT_T(KC_RBRC)
#define KK_VOLU A(S(KC_VOLU))
#define KK_VOLD A(S(KC_VOLD))

NGKEYS naginata_keys;

enum my_keycodes {
    NAG_ESC = NG_SAFE_RANGE,
    SV_COUNT,
    RST_COUNT,
};

// clang-format off
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define ________DVORAK_1________    KC_GESC,    KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       /*┃*/   KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_LBRC     //┃
#define ________DVORAK_2________    KC_S_TAB,   KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       /*┃*/   KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_S_RBRC   //┃
#define ________DVORAK_3________    KC_SLSH,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,       /*┃*/   KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_MINS     //┃
#define _______DVORAK_MOD_______                                        KC_LALT,    KC_C_BS,    KC_SPC,     /*┃*/   KC_M_ENT,   RAISE,      KC_RGUI                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define _______NAGINATA_1_______    NAG_ESC,    NG_Q,       NG_W,       NG_E,       NG_R,       NG_T,       /*┃*/   NG_Y,       NG_U,       NG_I,       NG_O,       NG_P,       _______     //┃
#define _______NAGINATA_2_______    _______,    NG_A,       NG_S,       NG_D,       NG_F,       NG_G,       /*┃*/   NG_H,       NG_J,       NG_K,       NG_L,       NG_SCLN,    _______     //┃
#define _______NAGINATA_3_______    RAISE,      NG_Z,       NG_X,       NG_C,       NG_V,       NG_B,       /*┃*/   NG_N,       NG_M,       NG_COMM,    NG_DOT,     NG_SLSH,    RAISE       //┃
#define ______NAGINATA_MOD______                                        S(KC_SPC),  NG_SHFT,    _______,    /*┃*/   KC_ENT,     NG_SHFT,    KC_RGUI                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define _________RAISE_1________    _______,    KC_CIRC,    KC_PERC,    KC_PLUS,    KC_LPRN,    KC_HASH,    /*┃*/   KC_EQL,     KC_RPRN,    KC_ASTR,    KC_DLR,     KC_EXLM,    _______     //┃
#define _________RAISE_2________    KC_BSLS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /*┃*/   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_GRV      //┃
#define _________RAISE_3________    _______,    _______,    _______,    KC_AMPR,    KC_LCBR,    _______,    /*┃*/   _______,    KC_RCBR,    KC_AT,      KC_PIPE,    _______,    _______     //┃
#define ________RAISE_MOD_______                                        _______,    _______,    ADJUST,     /*┃*/   _______,    _______,    _______                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define ________ADJUST_1________    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      /*┃*/   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F11      //┃
#define ________ADJUST_2________    RGB_TOG,    _______,    _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,    RGB_HUD,    RGB_HUD,    RGB_SAI     //┃
#define ________ADJUST_3________    RGB_MOD,    _______,    _______,    KC_BRID,    KC_BRIU,    SV_COUNT,   /*┃*/   RST_COUNT,  _______,    _______,    _______,    RGB_SPD,    RGB_SPI     //┃
#define _______ADJUST_MOD_______                                        EEP_RST,    _______,    _______,    /*┃*/   _______,    _______,    _______                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━┳━━━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━┓
#define ________LOWER_1________     _______,    _______,    _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,    _______,    _______,    _______     //┃
#define ________LOWER_2________     _______,    _______,    _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,    _______,    _______,    _______     //┃
#define ________LOWER_3________     _______,    _______,    _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,    _______,    _______,    _______     //┃
#define _______LOWER_MOD_______                                         _______,    _______,    _______,    /*┃*/   _______,    _______,    _______                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define _______MODIFIER_1_______    RGB_VAI,    _______,    KC_MPRV,    KC_MPLY,    KC_MNXT,    _______,    /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS)  //┃
#define _______MODIFIER_2_______    RGB_VAD,    KK_VOLD,    KC_VOLD,    KC_MUTE,    KC_VOLU,    KK_VOLU,    /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)     //┃
#define _______MODIFIER_3_______    _______,    _______,    _______,    _______,    _______,    _______,    /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS)  //┃
#define ______MODIFIER_MOD______                                        TG(L_GAME), _______,    _______,    /*┃*/   _______,    _______,    _______                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define _______GAME_1_______        KC_ESC,     _______,    KC_Q,       KC_W,       KC_E,       KC_R,       /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS)  //┃
#define _______GAME_2_______        KC_TAB,     KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)     //┃
#define _______GAME_3_______        _______,    _______,    KC_Z,       KC_X,       KC_C,       KC_V,       /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS)  //┃
#define ______GAME_MOD______                                            MO(L_GAME2),KC_LCTL,    KC_SPC,     /*┃*/   TG(L_GAME), _______,    _______                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1 ━━━━━━━━━ 2 ━━━━━━━━━ 3 ━━━━━━━━━ 4 ━━━━━━━━━ 5 ━━━━━━━━━ 6 ━━━━━━━━━━━┳━━━━━ 7 ━━━━━━━━━ 8 ━━━━━━━━━ 9 ━━━━━━━━━ 10 ━━━━━━━━ 11 ━━━━━━━━ 12 ━━━━━━━━━━┓
#define _______GAME2_1_______       KC_ESC,     _______,    KC_Q,       KC_W,       KC_E,       KC_R,       /*┃*/   _______,    _______,    KC_UP,      _______,    _______,    G(KC_PLUS)  //┃
#define _______GAME2_2_______       KC_TAB,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /*┃*/   _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    G(KC_0)     //┃
#define _______GAME2_3_______       _______,    _______,    KC_Z,       KC_X,       KC_C,       KC_V,       /*┃*/   _______,    _______,    _______,    _______,    _______,    G(KC_MINS)  //┃
#define ______GAME2_MOD______                                           KC_LSFT,    _______,    KC_SPC,     /*┃*/   _______,    _______,    _______                                         //┃
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

// clang-format on

enum combo_events { //
    NAGI_COMBO,
    DVO_COMBO,
    DELETE_COMBO,
    // RSHIFT_COMBO,
    // LSHIFT_COMBO,
    // RCTRL_COMBO,
    // LCTRL_COMBO,
    NAGI_TO_DVO,
    KM_ENTER,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// #ifndef IS_RIGHT
//

const uint16_t PROGMEM naginata_combo[] = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM dvorak_combo[]   = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM delete_combo[]   = {KC_F, KC_G, COMBO_END};
// const uint16_t PROGMEM rshift_combo[]   = {KC_T, KC_N, COMBO_END};
// const uint16_t PROGMEM lshift_combo[]   = {KC_O, KC_E, COMBO_END};
// const uint16_t PROGMEM rctrl_combo[]    = {KC_E, KC_U, COMBO_END};
// const uint16_t PROGMEM lctrl_combo[]    = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM nagi_to_dvo[] = {NG_F, NG_G, COMBO_END};
const uint16_t PROGMEM km_enter[]    = {KC_K, KC_M, COMBO_END};

combo_t key_combos[] = {
    [NAGI_COMBO]   = COMBO_ACTION(naginata_combo), //
    [DVO_COMBO]    = COMBO_ACTION(dvorak_combo),   //
    [DELETE_COMBO] = COMBO_ACTION(delete_combo),   //
    // [RSHIFT_COMBO] = COMBO_ACTION(rshift_combo),   //
    // [LSHIFT_COMBO] = COMBO_ACTION(lshift_combo),   //
    // [RCTRL_COMBO]  = COMBO_ACTION(rctrl_combo),    //
    // [LCTRL_COMBO]  = COMBO_ACTION(lctrl_combo),    //
    [NAGI_TO_DVO] = COMBO_ACTION(nagi_to_dvo), //
    [KM_ENTER]    = COMBO_ACTION(km_enter),    //
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case NAGI_COMBO:
            if (pressed) {
                tap_code(KC_LANG1);
                set_single_persistent_default_layer(L_NAGINATA);
            }
            break;
        case DVO_COMBO:
            if (pressed) {
                tap_code(KC_LANG2);
                set_single_persistent_default_layer(L_DVORAK);
            }
            break;
        case DELETE_COMBO:
            if (pressed) {
                tap_code(KC_BSPC);
            }
            break;
        case NAGI_TO_DVO:
            if (pressed) {
                tap_code(KC_LANG2);
                set_single_persistent_default_layer(L_DVORAK);
            }
            break;
        case KM_ENTER:
            if (pressed) {
                tap_code(KC_ENT);
                set_single_persistent_default_layer(L_DVORAK);
            }
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) { //
    state = update_tri_layer_state(state, L_RAISE, L_ADJUST, L_ADJUST);
    return state;
}

// #endif

// vim:set sw=4 ts=4 sts=4:
