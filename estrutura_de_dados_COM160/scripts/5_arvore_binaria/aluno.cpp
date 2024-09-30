#include "aluno.h"

Aluno::Aluno() {
    this->matricula = -1;
    this->nome = "";
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
