#pragma once

#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define KC_C_BS CTL_T(KC_BSPC)
#define KC_M_ENT LT(_MODIFIER, KC_ENT)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define KC_S_TAB SFT_T(KC_TAB)
#define KC_S_RBRC SFT_T(KC_RBRC)
#define KK_VOLU A(S(KC_VOLU))
#define KK_VOLD A(S(KC_VOLD))

NGKEYS naginata_keys;

enum my_keycodes {
    // NAGINATA = NG_SAFE_RANGE,
    // QWERTY,
    // DVORAK,
    NAG_ESC = NG_SAFE_RANGE,
    MM_QWE,
    NAG_DSFT,
    SV_COUNT,
    RST_COUNT,
};

// clang-format off
// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define ________DVORAK_1________ KC_GESC,     KC_QUOT,     KC_COMM,     KC_DOT,      KC_P,        KC_Y,           KC_F,        KC_G,        KC_C,        KC_R,        KC_L,        KC_LBRC
#define ________DVORAK_2________ KC_S_TAB,    KC_A,        KC_O,        KC_E,        KC_U,        KC_I,           KC_D,        KC_H,        KC_T,        KC_N,        KC_S,        KC_S_RBRC
#define ________DVORAK_3________ KC_SLSH,     KC_SCLN,     KC_Q,        KC_J,        KC_K,        KC_X,           KC_B,        KC_M,        KC_W,        KC_V,        KC_Z,        KC_MINS
#define _______DVORAK_MOD_______                                        KC_LALT,     KC_C_BS,     KC_SPC,         KC_M_ENT,    RAISE,       KC_RGUI

// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define ________QWERTY_1________ KC_GESC,     KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,           KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC
#define ________QWERTY_2________ KC_S_TAB,    KC_A,        KC_S,        KC_D,        KC_F,        KC_G,           KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_S_RBRC
#define ________QWERTY_3________ KC_SLSH,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,           KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_MINS
#define _______QWERTY_MOD_______                                        KC_LALT,     KC_C_BS,     KC_SPC,         KC_M_ENT,    RAISE,       KC_RGUI

// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define _______NAGINATA_1_______ NAG_ESC,     NG_Q,        NG_W,        NG_E,        NG_R,        NG_T,           NG_Y,        NG_U,        NG_I,        NG_O,        NG_P,        _______
#define _______NAGINATA_2_______ NAG_DSFT,    NG_A,        NG_S,        NG_D,        NG_F,        NG_G,           NG_H,        NG_J,        NG_K,        NG_L,        NG_SCLN,     NAG_DSFT
#define _______NAGINATA_3_______ RAISE,       NG_Z,        NG_X,        NG_C,        NG_V,        NG_B,           NG_N,        NG_M,        NG_COMM,     NG_DOT,      NG_SLSH,     RAISE
#define ______NAGINATA_MOD______                                        S(KC_SPC),   NG_SHFT,     _______,        KC_ENT,      NG_SHFT,     KC_RGUI

// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define _________RAISE_1________ _______,     KC_CIRC,     KC_PERC,     KC_PLUS,     KC_LPRN,     KC_HASH,        KC_EQL,      KC_RPRN,     KC_ASTR,     KC_DLR,      KC_EXLM,     _______
#define _________RAISE_2________ KC_BSLS,     KC_1,        KC_2,        KC_3,        KC_4,        KC_5,           KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_GRV
#define _________RAISE_3________ _______,     _______,     _______,     KC_AMPR,     KC_LCBR,     _______,        _______,     KC_RCBR,     KC_AT,       KC_PIPE,     _______,     _______
#define ________RAISE_MOD_______                                        _______,     LOWER,       _______,        _______,     _______,     _______

// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define ________ADJUST_1________ RGB_TOG,     _______,     _______,     _______,     _______,     C(S(KC_B)),     C(S(KC_F)),  _______,     _______,     _______,     RGB_HUI,     RGB_SAI
#define ________ADJUST_2________ RGB_MOD,     _______,     _______,     G(S(KC_3)),  G(S(KC_4)),  G(S(KC_5)),     _______,     _______,     _______,     _______,     RGB_HUD,     RGB_SAD
#define ________ADJUST_3________ RGB_RMOD,    _______,     _______,     KC_BRID,     KC_BRIU,     SV_COUNT,       RST_COUNT,   _______,     _______,     _______,     RGB_SPD,     RGB_SPI
#define _______ADJUST_MOD_______                                        EEP_RST,     _______,     _______,        _______,     _______,     _______

// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define ________LOWER_1________ RGB_TOG,     _______,     _______,     _______,     _______,     C(S(KC_B)),     C(S(KC_F)),  _______,     _______,     _______,     RGB_HUI,     RGB_SAI
#define ________LOWER_2________ RGB_MOD,     KC_F1,     KC_F2,     KC_F3,    KC_F4,  KC_F5,     _______,     _______,     _______,     _______,     RGB_HUD,     RGB_SAD
#define ________LOWER_3________ RGB_RMOD,    _______,     _______,     KC_BRID,     KC_BRIU,     SV_COUNT,       RST_COUNT,   _______,     _______,     _______,     RGB_SPD,     RGB_SPI
#define _______LOWER_MOD_______                                        EEP_RST,     _______,     _______,        _______,     _______,     _______

// ----------------------------- 1 ---------- 2 ---------- 3 ---------- 4 ---------- 5 ---------- 6 ----------    7 ---------- 8 ---------- 9 ---------- 10 --------- 11 --------- 12 ---------
#define _______MODIFIER_1_______ RGB_VAI,     _______,     KC_MPRV,     KC_MPLY,     KC_MNXT,     _______,        _______,     _______,     KC_UP,       _______,     _______,     G(KC_PLUS)
#define _______MODIFIER_2_______ RGB_VAD,     KK_VOLD,     KC_VOLD,     KC_MUTE,     KC_VOLU,     KK_VOLU,        _______,     KC_LEFT,     KC_DOWN,     KC_RGHT,     _______,     G(KC_0)
#define _______MODIFIER_3_______ _______,     _______,     _______,     _______,     _______,     _______,        _______,     _______,     _______,     _______,     _______,     G(KC_MINS)
#define ______MODIFIER_MOD______                                        _______,     LOWER,     _______,        _______,     _______,     _______

#ifndef IS_RIGHT
enum combo_events {  //
    NAGI_COMBO,
    DVO_COMBO,
    DELETE_COMBO,
    NAGI_TO_DVO,
    KM_ENTER,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM naginata_combo[]   = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM dvorak_combo[]     = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM delete_combo[]     = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM nagi_to_dvo[]      = {NG_F, NG_G, COMBO_END};
const uint16_t PROGMEM km_enter[]      = {KC_K, KC_M, COMBO_END};

combo_t key_combos[] = {
    [NAGI_COMBO]    = COMBO_ACTION(naginata_combo),    //
    [DVO_COMBO]     = COMBO_ACTION(dvorak_combo),      //
    [DELETE_COMBO]     = COMBO_ACTION(delete_combo),      //
    [NAGI_TO_DVO]   = COMBO_ACTION(nagi_to_dvo),       //
    [KM_ENTER]   = COMBO_ACTION(km_enter),       //
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case NAGI_COMBO:
            if (pressed) {
                tap_code(KC_LANG1);
                set_single_persistent_default_layer(_NAGINATA);
            }
            break;
        case DVO_COMBO:
            if (pressed) {
                tap_code(KC_LANG2);
                set_single_persistent_default_layer(_DVORAK);
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
                set_single_persistent_default_layer(_DVORAK);
            }
            break;
        case KM_ENTER:
            if (pressed) {
                tap_code(KC_ENT);
                set_single_persistent_default_layer(_DVORAK);
            }
            break;
    }
}
#endif

// vim:set sw=4 ts=4 sts=4:
//
