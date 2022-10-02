#include QMK_KEYBOARD_H
#include "combo.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM naginata_combo[] = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM dvorak_combo[]   = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM delete_combo[]   = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM nagi_to_dvo[]    = {NG_F, NG_G, COMBO_END};
const uint16_t PROGMEM km_enter[]       = {KC_K, KC_M, COMBO_END};

combo_t key_combos[] = {
    [NAGI_COMBO]   = COMBO_ACTION(naginata_combo), //
    [DVO_COMBO]    = COMBO_ACTION(dvorak_combo),   //
    [DELETE_COMBO] = COMBO_ACTION(delete_combo),   //
    [NAGI_TO_DVO]  = COMBO_ACTION(nagi_to_dvo),    //
    [KM_ENTER]     = COMBO_ACTION(km_enter),       //
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
