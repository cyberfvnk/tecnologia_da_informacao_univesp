#include "hash.h"
#include <iostream>
using namespace std;

Hash::Hash(int tamanho_maximo) {
    tamanho = 0;
    max_items = tamanho_maximo;
    estrutura = new Aluno[max_items];
}

Hash::~Hash() {
    delete[] estrutura;
}

bool Hash::isCheia() const {
    return tamanho == max_items;
}

int Hash::getTamanho() const {
    return tamanho;
}

void Hash::buscarItem(Aluno& aluno, bool& encontrado) {
    int localInicial = getHash(aluno);
    bool buscaMais = true;
    int local = localInicial;
    do {
        if (estrutura[local].getMatricula() == aluno.getMatricula() || estrutura[local].getMatricula() == -1) {
            buscaMais = false;
        } else {
            local = (local + 1) % max_items;
        }
    } while (local != localInicial && buscaMais);

    encontrado = estrutura[local].getMatricula() == aluno.getMatricula();
    if (encontrado) {
        aluno = estrutura[local];
    }
}

void Hash::inserirItem(Aluno aluno) {
    int local = getHash(aluno);
    estrutura[local] = aluno;
    
    while (estrutura[local].getMatricula() > 0)
        local = (local + 1) % max_items;
    
    estrutura[local] = aluno;
    tamanho++;
}

void Hash::excluirItem(Aluno aluno) {
    int localInicial = getHash(aluno);
    bool buscaMais = true;
    int local = localInicial;
    do {
        if (estrutura[local].getMatricula() == aluno.getMatricula() || estrutura[local].getMatricula() == -1) {
            buscaMais = false;
        } else {
            local = (local + 1) % max_items;
        }
    } while (local != localInicial && buscaMais);

    if (estrutura[local].getMatricula() == aluno.getMatricula()) {
        estrutura[local] = Aluno(-2, "");
        tamanho--;
    }
}

void Hash::print() {
    for (int i = 0; i < max_items; i++) {
        cout << i << ":" << estrutura[i].getMatricula() << "," << estrutura[i].getNome() << endl;
    }
}

int Hash::getHash(Aluno aluno) {
    return aluno.getMatricula() % max_items;
}

