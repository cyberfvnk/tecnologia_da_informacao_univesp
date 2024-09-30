#include "item_type.h"

const int MAX_ITEMS = 100;

class Pilha {
    private:
        int tamanho;
        ItemType* estrutura;
    public:
        Pilha(); // construtor
        ~Pilha(); // destrutor
        void push(ItemType);
        ItemType pop();
        void print() const;
        bool isVazia() const;
        bool isCheia() const;
};