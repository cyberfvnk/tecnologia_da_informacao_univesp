#include "aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno() {
    matricula = -1;
    nome = "";
}

Aluno::Aluno(int matricula, string nome) {
    this->matricula = matricula;
    this->nome = nome;
}

int Aluno::getMatricula() const {
    return matricula;
}

string Aluno::getNome() const {
    return nome;
}