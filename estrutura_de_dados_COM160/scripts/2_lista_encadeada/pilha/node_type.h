#include "item_type.h"
#pragma once

typedef struct NodeType {
    ItemType info;
    NodeType* prox;
} NodeType;
