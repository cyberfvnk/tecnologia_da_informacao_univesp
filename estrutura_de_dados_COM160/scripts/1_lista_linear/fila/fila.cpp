#include "fila.h"
#include <iostream>
using namespace std;

Fila::Fila() {
    frente = 0;
    tras = 0;
    estrutura = new ItemType[MAX_ITEMS];
}

Fila::~Fila() {
    delete [] estrutura;
}

void Fila::enqueue(ItemType item) {
    if (isCheia())
        throw "Fila cheia!";
    else {
        estrutura[tras % MAX_ITEMS] = item;
        tras++;
    }
}

ItemType Fila::dequeue() {
    if (isVazia())
        throw "Fila vazia!";
    else {
        frente++;
        return estrutura[(frente-1) % MAX_ITEMS];
    }
}

void Fila::print() const {
    cout << "Fila = ";
    for (int i = frente; i < tras; i++)
        cout << estrutura[i % MAX_ITEMS];
    cout << endl;
}

bool Fila::isVazia() const {
    return frente == tras;
}

bool Fila::isCheia() const {
    return (tras - frente) == MAX_ITEMS;
}