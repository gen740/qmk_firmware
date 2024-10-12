#include QMK_KEYBOARD_H
#include "gen740.h"
#include "dvorak.h"
#include "naginata.h"

#include "define_macros.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(L_NAG)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX ,  NG_Q   ,  NG_W   ,  NG_E   ,  NG_R   ,  NG_T   , KC_LEFT ,  KC_RIGHT ,  NG_Y   ,  NG_U   ,  NG_I   ,  NG_O   ,  NG_P   , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,  NG_A   ,  NG_S   ,  NG_D   ,  NG_F   ,  NG_G   ,  KC_UP  ,   KC_DOWN ,  NG_H   ,  NG_J   ,  NG_K   ,  NG_L   , NG_SCLN , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,  NG_Z   ,  NG_X   ,  NG_C   ,  NG_V   ,  NG_B   ,                        NG_N   ,  NG_M   , NG_COMM , NG_DOT  , NG_SLSH , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              KC_BSPC ,NG_LSHFT , XXXXXXX ,   KC_ENT  ,NG_RSHFT , KC_RGUI                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_DVO)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX , DV_QUOT , DV_COMM , DV_DOT  ,  DV_P   ,  DV_Y   , KC_LEFT ,  KC_RIGHT ,  DV_F   ,  DV_G   ,  DV_C   ,  DV_R   ,  DV_L   , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,  DV_A   ,  DV_O   ,  DV_E   ,  DV_U   ,  DV_I   ,  KC_UP  ,   KC_DOWN ,  DV_D   ,  DV_H   ,  DV_T   ,  DV_N   ,  DV_S   , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      QK_BOOT , DV_SCLN ,  DV_Q   ,  DV_J   ,  DV_K   ,  DV_X   ,                        DV_B   ,  DV_M   ,  DV_W   ,  DV_V   ,  DV_Z   , QK_BOOT ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              KC_BSPC , DV_LSFT , KC_SPC  ,   KC_ENT  , DV_RSFT , KC_RGUI                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),


};

uint32_t deferred_unregister_gui(uint32_t trigger_time, void *cb_arg) {
    unregister_code(KC_LGUI);
    return 0;
}

uint32_t defferred_unregister_gui_sft(void) {
    unregister_code(KC_LGUI);
    unregister_code(KC_LSFT);
    return 0;
}

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_dvorak(keycode, record)) {
        return false;
    }
    if (!process_naginata(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case NEXT_APP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                defer_exec(1000, deferred_unregister_gui, NULL);
            }
            return false;
        case PREV_APP:
            if (record->event.pressed) {
            }
            return false;
    }
    return true;
}
