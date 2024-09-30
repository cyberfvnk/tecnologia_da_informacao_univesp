#include "hash.h"
#include <iostream>
using namespace std;

int main() {
    Hash alunoHash(10);
    int ras[5] = {123, 456, 789, 103, 112};
    string nomes[5] = {"Joao", "Maria", "Jose", "Ana", "Pedro"};

    for (int i = 0; i < 5; i++) {
        Aluno aluno(ras[i], nomes[i]);
        alunoHash.inserirItem(aluno);
    }
    alunoHash.print();
    cout << "-----------------" << endl;

    Aluno aluno(123, "");
    bool encontrado = false;
    alunoHash.buscarItem(aluno, encontrado);
    cout << aluno.getNome() << " -> " << encontrado << endl;
    cout << "-----------------" << endl;

    alunoHash.excluirItem(aluno);
    alunoHash.print();
}