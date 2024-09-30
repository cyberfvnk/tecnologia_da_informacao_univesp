#include "node_type.h"

class Pilha {
    private:
        NodeType* estrutura;
    public:
        Pilha(); // construtor
        ~Pilha(); // destrutor
        void push(ItemType);
        ItemType pop();
        void print() const;
        bool isVazia() const;
        bool isCheia() const;
};