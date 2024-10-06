#include "combo.h"

#include "gen740.h"
#include "naginata.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM dvo_to_nagi_combo[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM dvo_null_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM nagi_to_dvo_combo[] = {NG_F, NG_G, COMBO_END};
const uint16_t PROGMEM vim_dvo_to_nagi_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM vim_dvo_null_combo[] = {KC_K, KC_X, COMBO_END};
const uint16_t PROGMEM vim_nagi_to_dvo[] = {NG_V, NG_B, COMBO_END};
const uint16_t PROGMEM cr_combo[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM oneshot_meh_l[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM oneshot_hyper_r[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM oneshot_hyper_l[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM oneshot_lcag_r[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM oneshot_lcag_l[] = {KC_Q, KC_J, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [DVO_TO_NAGI_COMBO] = COMBO_ACTION(dvo_to_nagi_combo),  //
    [DVO_NULL_COMBO] = COMBO_ACTION(dvo_null_combo),     //
    [NAGI_TO_DVO] = COMBO_ACTION(nagi_to_dvo_combo),
    [VIM_DVO_TO_NAGI_COMBO] = COMBO_ACTION(vim_dvo_to_nagi_combo),  //
    [VIM_DVO_NULL_COMBO] = COMBO_ACTION(vim_dvo_null_combo),     //
    [VIM_NAGI_TO_DVO] = COMBO_ACTION(vim_nagi_to_dvo),
    [ONESHOT_MEH_R] = COMBO_ACTION(cr_combo),           //
    [ONESHOT_MEH_L] = COMBO_ACTION(oneshot_meh_l),      //
    [ONESHOT_HYPER_R] = COMBO_ACTION(oneshot_hyper_r),  //
    [ONESHOT_HYPER_L] = COMBO_ACTION(oneshot_hyper_l),  //
    [ONESHOT_LCAG_R] = COMBO_ACTION(oneshot_lcag_r),    //
    [ONESHOT_LCAG_L] = COMBO_ACTION(oneshot_lcag_l),    //
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
    case DVO_TO_NAGI_COMBO:
      if (pressed) {
        tap_code(KC_LNG1);
        layer_move(L_NAG);
      }
      break;
    case DVO_NULL_COMBO:
      break;
    case NAGI_TO_DVO:
      if (pressed) {
        tap_code(KC_LNG2);
        layer_move(L_DVO);
      }
      break;

    case VIM_DVO_TO_NAGI_COMBO:
      if (pressed) {
        tap_code16(C(KC_J));
        layer_move(L_NAG);
      }
      break;
    case VIM_DVO_NULL_COMBO:
      break;
    case VIM_NAGI_TO_DVO:
      if (pressed) {
        tap_code16(KC_ESC);
        layer_move(L_DVO);
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
    default:
      break;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {  //
  state = update_tri_layer_state(state, L_RAI, L_ADJ, L_ADJ);
  return state;
}
