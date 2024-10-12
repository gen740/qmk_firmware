#pragma once

#include "naginata.h"

// カナ変換テーブル //
typedef struct {
    uint32_t    key;
    const char* kana;
} naginata_keymap;

enum { NAGINATA_KEY_NUMBER = 204 };

extern const PROGMEM naginata_keymap ngmap[NAGINATA_KEY_NUMBER];
