#include "fila.h"
#include <iostream>
using namespace std;

Fila::Fila() {
    inicio = NULL;
    fim = NULL;
}

Fila::~Fila() {
    NodeType* tempPtr;
    while (inicio != NULL) {
        tempPtr = inicio;
        inicio = inicio->prox;
        delete tempPtr;
    }
    fim = NULL;
}

bool Fila::isVazia() const {
    return (inicio == NULL);
}

bool Fila::isCheia() const {
    NodeType* location;
    try { 
        location = new NodeType;
        delete location;
        return false;
    } catch (bad_alloc exception) {
        return true;
    }
}

void Fila::enqueue(ItemType item) {
    if (isCheia())
        throw "A fila está cheia!\n";
    else {
        NodeType* novoNo = new NodeType;
        novoNo->info = item;
        novoNo->prox = NULL;
        if (inicio == NULL)
            inicio = novoNo;
        else
            fim->prox = novoNo;
        fim = novoNo;
    }
}

ItemType Fila::dequeue() {
    if (isVazia())
        throw "A fila está vazia!\n";
    else {
        NodeType* tempPtr = inicio;
        ItemType item = inicio->info;
        inicio = inicio->prox;
        if (inicio == NULL)
            fim = NULL;
        delete tempPtr;
        return item;
    }
}
