#pragma once

#include "dvorak.h"

// Dvorak keymap data

typedef struct {
    const char* key;
    const char* val;
} dvorak_keymap;

enum { DVORAK_KEY_NUMBER = 20 };

extern const PROGMEM dvorak_keymap dvmap[DVORAK_KEY_NUMBER];
