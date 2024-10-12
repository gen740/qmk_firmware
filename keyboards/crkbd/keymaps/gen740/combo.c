#include "combo.h"

#include "gen740.h"
#include "naginata.h"
#include "dvorak.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM nagi_to_dvo_combo[] = {NG_F, NG_G, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [NAGI_TO_DVO] = COMBO_ACTION(nagi_to_dvo_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
    case NAGI_TO_DVO:
      if (pressed) {
        tap_code(KC_LNG2);
        layer_move(L_DVO);
      }
      break;

    /*case ONESHOT_MEH_R:*/
    /*case ONESHOT_MEH_L:*/
    /*  if (pressed) {*/
    /*    set_oneshot_layer(L_MEH, ONESHOT_START);*/
    /*  } else {*/
    /*    clear_oneshot_layer_state(ONESHOT_PRESSED);*/
    /*  }*/
    /*  break;*/
    /*case ONESHOT_HYPER_R:*/
    /*case ONESHOT_HYPER_L:*/
    /*  if (pressed) {*/
    /*    set_oneshot_layer(L_HYPER, ONESHOT_START);*/
    /*  } else {*/
    /*    clear_oneshot_layer_state(ONESHOT_PRESSED);*/
    /*  }*/
    /*  break;*/
    /*case ONESHOT_LCAG_R:*/
    /*case ONESHOT_LCAG_L:*/
    /*  if (pressed) {*/
    /*    set_oneshot_layer(L_LCAG, ONESHOT_START);*/
    /*  } else {*/
    /*    clear_oneshot_layer_state(ONESHOT_PRESSED);*/
    /*  }*/
    /*  break;*/
    default:
      break;

  }
}
