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
      MO_MOD  ,  NG_A   ,  NG_S   ,  NG_D   ,  NG_F   ,  NG_G   ,PREV_APP ,  NEXT_APP ,  NG_H   ,  NG_J   ,  NG_K   ,  NG_L   , NG_SCLN , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,  NG_Z   ,  NG_X   ,  NG_C   ,  NG_V   ,  NG_B   ,                        NG_N   ,  NG_M   , NG_COMM , NG_DOT  , NG_SLSH , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              BS_alt  ,NG_LSFT2 , XXXXXXX ,   XXXXXXX ,NG_RSFT2 , KC_RGUI                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_DVO)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX , DV_QUOT , DV_COMM , DV_DOT  ,  DV_P   ,  DV_Y   , KC_LEFT ,  KC_RIGHT ,  DV_F   ,  DV_G   ,  DV_C   ,  DV_R   ,  DV_L   , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      MO_MOD  ,  DV_A   ,  DV_O   ,  DV_E   ,  DV_U   ,  DV_I   ,PREV_APP ,  NEXT_APP ,  DV_D   ,  DV_H   ,  DV_T   ,  DV_N   ,  DV_S   , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX , DV_SCLN ,  DV_Q   ,  DV_J   ,  DV_K   ,  DV_X   ,                        DV_B   ,  DV_M   ,  DV_W   ,  DV_V   ,  DV_Z   , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                             DV_LSFT1 ,DV_LSFT2 ,DV_LSFT3 ,  DV_RSFT3 ,DV_RSFT2 ,DV_RSFT1                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_MOD)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DF_GAME ,   XXXXXXX , XXXXXXX , XXXXXXX ,  KC_UP  , XXXXXXX , XXXXXXX , DF_GAME ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX , KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN ,KC_RIGHT , XXXXXXX , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      RGB_TOG , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , LSFT(KC_ENT) , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_GAME)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   , KC_ESC  ,  KC_RIGHT ,  KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , DF_DVO  ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_LSFT ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,  KC_H   ,  NEXT_APP ,  KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
       KC_M   ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                        KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              KC_LCTL , KC_SPC  ,MO_GAME2 ,   XXXXXXX , KC_ENT  , KC_RGUI                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_GAME2)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      KC_TAB  ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  , DF_DVO  ,  KC_RIGHT ,  KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   , DF_DVO  ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_LSFT ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,  KC_H   ,  NEXT_APP ,  KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , KC_SCLN , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
       KC_M   ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,                        KC_N   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              KC_LCTL , KC_SPC  , XXXXXXX ,   XXXXXXX , KC_ENT  , KC_RGUI                                            /*
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
bool gen740_prev_app_pushed = false;
bool gen740_next_app_pushed = false;

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
                gen740_next_app_pushed = true;
                if (gen740_prev_app_pushed) {
                    register_code(KC_TAB);
                } else {
                    register_code(KC_LGUI);
                }
            } else {
                gen740_next_app_pushed = false;
                if (gen740_prev_app_pushed) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_TAB);
                } else {
                    unregister_code(KC_LGUI);
                }
            }
            return false;
        case PREV_APP:
            if (record->event.pressed) {
                gen740_prev_app_pushed = true;
                if (gen740_next_app_pushed) {
                    register_code(KC_LSFT);
                    register_code(KC_TAB);
                } else {
                    register_code(KC_LGUI);
                }
            } else {
                gen740_prev_app_pushed = false;
                if (gen740_next_app_pushed) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_TAB);
                } else {
                    unregister_code(KC_LGUI);
                }
            }
            return false;
    }
    return true;
}
