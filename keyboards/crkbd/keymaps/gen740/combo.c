#include "combo.h"
#include "naginata.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM naginata_combo[]  = {KC_H, KC_D, COMBO_END};
const uint16_t PROGMEM dvorak_combo[]    = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM delete_combo[]    = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM nagi_to_dvo[]     = {NG_F, NG_G, COMBO_END};
const uint16_t PROGMEM km_enter[]        = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM oneshot_meh_r[]   = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM oneshot_meh_l[]   = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM oneshot_hyper_r[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM oneshot_hyper_l[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM oneshot_lcag_r[]  = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM oneshot_lcag_l[]  = {KC_Q, KC_J, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [NAGI_COMBO]      = COMBO_ACTION(naginata_combo),  //
    [DVO_COMBO]       = COMBO_ACTION(dvorak_combo),    //
    [DELETE_COMBO]    = COMBO_ACTION(delete_combo),    //
    [NAGI_TO_DVO]     = COMBO_ACTION(nagi_to_dvo),     //
    [KM_ENTER]        = COMBO_ACTION(km_enter),        //
    [ONESHOT_MEH_R]   = COMBO_ACTION(oneshot_meh_r),   //
    [ONESHOT_MEH_L]   = COMBO_ACTION(oneshot_meh_l),   //
    [ONESHOT_HYPER_R] = COMBO_ACTION(oneshot_hyper_r), //
    [ONESHOT_HYPER_L] = COMBO_ACTION(oneshot_hyper_l), //
    [ONESHOT_LCAG_R]  = COMBO_ACTION(oneshot_lcag_r),  //
    [ONESHOT_LCAG_L]  = COMBO_ACTION(oneshot_lcag_l),  //
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
        case ONESHOT_MEH_R:
        case ONESHOT_MEH_L:
            if (pressed) {
                set_oneshot_layer(L_MEH, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
        case ONESHOT_HYPER_R:
        case ONESHOT_HYPER_L:
            if (pressed) {
                set_oneshot_layer(L_HYPER, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
        case ONESHOT_LCAG_R:
        case ONESHOT_LCAG_L:
            if (pressed) {
                set_oneshot_layer(L_LCAG, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) { //
    state = update_tri_layer_state(state, L_RAISE, L_ADJUST, L_ADJUST);
    return state;
}
