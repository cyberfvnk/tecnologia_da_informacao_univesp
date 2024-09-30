#include "pilha.h"
#include <iostream>
using namespace std;

Pilha::Pilha() {
    estrutura = NULL;
}

Pilha::~Pilha() {
    NodeType* tempPtr;
    while (estrutura != NULL) {
        tempPtr = estrutura;
        estrutura = estrutura -> prox;
        delete tempPtr;
    }
}

bool Pilha::isVazia() const {
    return (estrutura == NULL);
}

bool Pilha::isCheia() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (bad_alloc exception) {
        return true;
    }
};

void Pilha::push(ItemType item) {
    if (isCheia()) {
        throw "A pilha está cheia.";
    } else {
        NodeType* location = new NodeType;
        location -> info = item;
        location -> prox = estrutura;
        estrutura = location;
    }
}

ItemType Pilha::pop() {
    if (isVazia()) {
        throw "A pilha está vazia.";
    } else {
        NodeType* tempPtr = estrutura;
        ItemType item = estrutura -> info;
        estrutura = estrutura -> prox;
        delete tempPtr;
        return item;
    }
}

void Pilha::print() const {
    NodeType* tempPtr = estrutura;
    while (tempPtr != NULL) {
        cout << tempPtr -> info << endl;
        tempPtr = tempPtr -> prox;
    }
}