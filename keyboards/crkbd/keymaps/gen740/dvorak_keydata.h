#pragma once

#include "dvorak.h"

// Dvorak keymap data

typedef struct {
    uint32_t key;
    const char* val;
} dvorak_keymap;

enum { DVORAK_KEY_NUMBER = 200 };

extern const PROGMEM dvorak_keymap dvmap[DVORAK_KEY_NUMBER];
