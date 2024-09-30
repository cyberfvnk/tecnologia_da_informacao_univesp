#include "item_type.h"

const int MAX_ITEMS = 100;

class Fila {
    private:
        int frente;
        int tras;
        ItemType* estrutura;
    public:
        Fila(); // construtor
        ~Fila(); // destrutor
        void enqueue(ItemType);
        ItemType dequeue();
        void print() const;
        bool isVazia() const;
        bool isCheia() const;
};