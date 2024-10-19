/**
 * This file is generated by dvorak_keydata_gen.py
 * Do not edit this file directly.
 */
#pragma once

#include "dvorak.h"

struct dvorak_node;

typedef struct dvorak_node dvorak_node_t;

struct dvorak_node {
    const dvorak_node_t*  parent;
    const dvorak_node_t** children;
    uint8_t               children_num;
    int8_t                key;
    const char*           value;
    bool                  reverse;
};

const dvorak_node_t dvorak_node_root;
