#include "node_type.h"

class Fila {
    private:
        NodeType* inicio;
        NodeType* fim;
    public:
        Fila(); // construtor
        ~Fila(); // destrutor
        void enqueue(ItemType);
        ItemType dequeue();
        void print() const;
        bool isVazia() const;
        bool isCheia() const;
};