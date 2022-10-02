#pragma once
#include "naginata.h"

// EEPROMに保存する設定

#define NG_SAFE_RANGE (SAFE_RANGE + 42)

enum my_keycodes {
    NAG_ESC = NG_SAFE_RANGE,
    SV_COUNT,
    RST_COUNT,
};

enum combo_events { //
    NAGI_COMBO,
    DVO_COMBO,
    DELETE_COMBO,
    NAGI_TO_DVO,
    KM_ENTER,
    COMBO_LENGTH
};


// vim:set sw=4 ts=4 sts=4:
