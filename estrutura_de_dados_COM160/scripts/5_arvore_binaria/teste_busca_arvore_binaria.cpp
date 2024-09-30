#include "arvore_binaria.h"
using namespace std;

const int NUM_ALUNOS = 8;

int main() {
    ArvoreBinaria arvore;

    int matricula[NUM_ALUNOS] = {50, 30, 70, 20, 40, 60, 80, 10};
    string nomes[NUM_ALUNOS] = {"Flora", "Donatela", "Ze Bob", "Alice", "Lara", "Irma Boazuda da Cida", "Seu Coppola", "Cida"};
    Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++) {
        Aluno aluno = Aluno(matricula[i], nomes[i]);
        alunos[i] = aluno;
        arvore.inserirAluno(aluno);
    }

    cout << "Pre-Ordem: ";
    arvore.printPreOrdem();
    cout << endl;
    cout << "In-Ordem: ";
    arvore.printInOrdem();
    cout << endl;
    cout << "Pos-Ordem: ";
    arvore.printPosOrdem();
    cout << endl;

    arvore.excluirAluno(alunos[0].getMatricula());
    cout << "******************************" << endl;
    cout << "Pre-Ordem: ";
    arvore.printPreOrdem();
    cout << endl;
    cout << "In-Ordem: ";
    arvore.printInOrdem();
    cout << endl;
    cout << "Pos-Ordem: ";
    arvore.printPosOrdem(); 
    cout << endl;

    return 0;
}