#include QMK_KEYBOARD_H
#include "gen740.h"
#include "naginata.h"

#include "define_macros.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(L_DVO)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      QK_GESC , KC_QUOT , KC_COMM , KC_DOT  ,  KC_P   ,  KC_Y   , XXXXXXX ,   XXXXXXX ,  KC_F   ,  KC_G   ,  KC_C   ,  KC_R   ,  KC_L   , KC_LBRC ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      TAB_sft ,  KC_A   ,  KC_O   ,  KC_E   ,  KC_U   ,  KC_I   , XXXXXXX ,   XXXXXXX ,  KC_D   ,  KC_H   ,  KC_T   ,  KC_N   ,  KC_S   ,RBRC_sft ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_SLSH , KC_SCLN ,  KC_Q   ,  KC_J   ,  KC_K   ,  KC_X   ,                        KC_B   ,  KC_M   ,  KC_W   ,  KC_V   ,  KC_Z   , KC_MINS ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              BS_alt  , KC_LCTL , KC_SPC  ,   ENT_mod ,  RAISE  , KC_RGUI                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_RAI)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      RGB_TOG , KC_CIRC , KC_PERC , KC_PLUS , KC_LPRN , KC_HASH ,RGB_RMOD ,   RGB_MOD , KC_EQL  , KC_RPRN , KC_ASTR , KC_DLR  , KC_EXLM , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_BSLS ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   , RGB_SPD ,   RGB_SPI ,  KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   , KC_GRV  ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX , XXXXXXX , XXXXXXX , KC_AMPR , XXXXXXX , RGB_VAD ,                       RGB_VAI , XXXXXXX ,  KC_AT  , KC_PIPE , XXXXXXX , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              KC_BSPC , KC_LCTL , ADJUST  ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_ADJ)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
       KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  , XXXXXXX ,   XXXXXXX ,  KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_F11  , KC_F12  ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX , XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU , XXXXXXX ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              HF_RST  , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_MOD)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , DF_GAME , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX ,  KC_UP  , XXXXXXX , XXXXXXX , G_PLUS  ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      G(KC_AT) , KK_VOLD , KC_VOLD , KC_MUTE , KC_VOLU , KK_VOLU , XXXXXXX ,   XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX ,   G_0   ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , G_MINS  ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_NAG)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX ,  NG_Q   ,  NG_W   ,  NG_E   ,  NG_R   ,  NG_T   , KC_LEFT ,  KC_RIGHT ,  NG_Y   ,  NG_U   ,  NG_I   ,  NG_O   ,  NG_P   , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_LSFT ,  NG_A   ,  NG_S   ,  NG_D   ,  NG_F   ,  NG_G   , XXXXXXX ,   XXXXXXX ,  NG_H   ,  NG_J   ,  NG_K   ,  NG_L   , NG_SCLN , KC_RSFT ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,  NG_Z   ,  NG_X   ,  NG_C   ,  NG_V   ,  NG_B   ,                        NG_N   ,  NG_M   , NG_COMM , NG_DOT  , NG_SLSH , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              KC_BSPC ,NG_LSHFT , KC_SPC  ,   KC_ENT  ,NG_RSHFT , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_MEH)                                                                                                                                      /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX ,MEH_QUOT ,MEH_COMM , MEH_DOT ,MEH_KC_P ,MEH_KC_Y , XXXXXXX ,   XXXXXXX ,MEH_KC_F ,MEH_KC_G ,MEH_KC_C ,MEH_KC_R ,MEH_KC_L , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,MEH_KC_A ,MEH_KC_O ,MEH_KC_E ,MEH_KC_U ,MEH_KC_I , XXXXXXX ,   XXXXXXX ,MEH_KC_D ,MEH_KC_H ,MEH_KC_T ,MEH_KC_N ,MEH_KC_S , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,MEH_SCLN ,MEH_KC_Q ,MEH_KC_J ,MEH_KC_K ,MEH_KC_X ,                      MEH_KC_B ,MEH_KC_M ,MEH_KC_W ,MEH_KC_V ,MEH_KC_Z , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_HYPER)                                                                                                                                    /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX ,HYPR_QUOT,HYPR_KC_Z,HYPR_DOT ,HYPR_KC_P,HYPR_KC_Y, XXXXXXX ,   XXXXXXX ,HYPR_KC_F,HYPR_KC_G,HYPR_KC_C,HYPR_KC_R,HYPR_KC_L, XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,HYPR_KC_A,HYPR_KC_O,HYPR_KC_E,HYPR_KC_U,HYPR_KC_I, XXXXXXX ,   XXXXXXX ,HYPR_KC_D,HYPR_KC_H,HYPR_KC_T,HYPR_KC_N,HYPR_KC_S, XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      QK_BOOT ,HYPR_SCLN,HYPR_KC_Q,HYPR_KC_J,HYPR_KC_K,HYPR_KC_X,                      HYPR_KC_B,HYPR_KC_M,HYPR_KC_W,HYPR_KC_V,HYPR_KC_Z, QK_BOOT ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_LCAG)                                                                                                                                     /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      XXXXXXX ,LCAG_QUOT,LCAG_COMM,LCAG_DOT ,LCAG_KC_P,LCAG_KC_Y, XXXXXXX ,   XXXXXXX ,LCAG_KC_F,LCAG_KC_G,LCAG_KC_C,LCAG_KC_R,LCAG_KC_L, XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,LCAG_KC_A,LCAG_KC_O,LCAG_KC_E,LCAG_KC_U,LCAG_KC_I, XXXXXXX ,   XXXXXXX ,LCAG_KC_D,LCAG_KC_H,LCAG_KC_T,LCAG_KC_N,LCAG_KC_S, XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      XXXXXXX ,LCAG_SCLN,LCAG_KC_Q,LCAG_KC_J,LCAG_KC_K,LCAG_KC_X,                      LCAG_KC_B,LCAG_KC_M,LCAG_KC_W,LCAG_KC_V,LCAG_KC_Z, XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              XXXXXXX , XXXXXXX , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_GAME)                                                                                                                                     /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
      KC_ESC  ,  KC_P   ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   , KC_M ,   XXXXXXX , XXXXXXX , XXXXXXX ,  KC_UP  , XXXXXXX , XXXXXXX , DF_DVO  ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_TAB  , KC_LSFT ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   , KC_B ,   XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
      KC_SLSH , KC_SCLN ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                             MO_GAME2 , KC_LCTL ,KC_SPACE ,   KC_ENT  , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),

  LAYOUT(L_GAME2)                                                                                                                                    /*
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓ ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓  */
       KC_F1  ,  KC_T   ,  KC_Y   ,  KC_U   ,  KC_I   ,  KC_R   , XXXXXXX ,   XXXXXXX , XXXXXXX , XXXXXXX ,  KC_UP  , XXXXXXX , XXXXXXX , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫ ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
       KC_F5  ,  KC_G   ,  KC_H   ,  KC_J   ,  KC_K   ,  KC_L   , XXXXXXX ,   XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX ,  /*
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛ ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫  */
       KC_F3  ,  KC_F4  ,  KC_N   ,  KC_M   , KC_COMM , KC_DOT  ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  /*
    ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓ ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛  */
                                              XXXXXXX , KC_LALT , KC_SPC  ,   XXXXXXX , XXXXXXX , XXXXXXX                                            /*
                                            ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛ ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛                                          */ ),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_naginata(keycode, record)) {
        return false;
    }
    return true;
}
