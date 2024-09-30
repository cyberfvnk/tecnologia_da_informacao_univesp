#include "item_type.h"

typedef struct NodeType {
    ItemType info;
    NodeType* prox;
} NodeType;