#include "pilha.h"
#include <iostream>
using namespace std;

Pilha::Pilha() {
    tamanho = 0;
    estrutura = new ItemType[MAX_ITEMS];
}

Pilha::~Pilha() {
    delete [] estrutura;
}

bool Pilha::isVazia() const {
    return tamanho == 0;
}

bool Pilha::isCheia() const {
    return tamanho == MAX_ITEMS;
}

void Pilha::push(ItemType item) {
    if (isCheia()) {
        throw "A pilha está cheia!";
    } else {
        estrutura[tamanho] = item;
        tamanho++;
    }
}

ItemType Pilha::pop() {
    if (isVazia()) {
        throw "A pilha está vazia!";
        return 0;
    } else {
        tamanho--;
        return estrutura[tamanho];
    }
}

void Pilha::print() const {
    cout << "Pilha: [ ";
    for (int i = 0; i < tamanho; i++) {
        cout << estrutura[i];
    }
    cout << " ]" << endl;
}