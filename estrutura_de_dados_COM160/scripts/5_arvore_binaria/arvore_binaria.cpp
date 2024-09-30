#include "arvore_binaria.h"
using namespace std;

void ArvoreBinaria::destruirArvore(NodeType*& arvore) {
    if (arvore != NULL) {
        destruirArvore(arvore->esquerda);
        destruirArvore(arvore->direita);
        delete arvore;
    }
}

bool ArvoreBinaria::isCheia() const {
    NodeType* temp;
    try {
        temp = new NodeType;
        delete temp;
        return false;
    } catch (bad_alloc exception) {
        return true;
    }
}

void ArvoreBinaria::buscarAluno(NodeType* arvore, Aluno& aluno, bool& achado) const {
    if (arvore == NULL)
        achado = false;
    else if (aluno.getMatricula() < arvore->aluno.getMatricula())
        buscarAluno(arvore->esquerda, aluno, achado);
    else if (aluno.getMatricula() > arvore->aluno.getMatricula())
        buscarAluno(arvore->direita, aluno, achado);
    else {
        aluno = arvore->aluno;
        achado = true;
    }
}

void ArvoreBinaria::inserirAluno(NodeType*& arvore, Aluno aluno) {
    if (arvore == NULL) {
        arvore = new NodeType;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        arvore->aluno = aluno;
    } else if (aluno.getMatricula() < arvore->aluno.getMatricula())
        inserirAluno(arvore->esquerda, aluno);
    else
        inserirAluno(arvore->direita, aluno);
}

void ArvoreBinaria::excluirAluno(NodeType*& arvore, int aluno) {
    if (aluno < arvore->aluno.getMatricula()) 
        excluirAluno(arvore->esquerda, aluno);
    else if (aluno > arvore->aluno.getMatricula())
        excluirAluno(arvore->direita, aluno);
    else if ( aluno == arvore->aluno.getMatricula())
        deletarNo(arvore);
}

void ArvoreBinaria::deletarNo(NodeType*& arvore) {
    Aluno data;
    NodeType* tempPtr = arvore;
    if (arvore->esquerda == NULL) {
        arvore = arvore->direita;
        delete tempPtr;
    } else if (arvore->direita == NULL) {
        arvore = arvore->esquerda;
        delete tempPtr;
    } else {
        getSucessor(arvore, data);
        arvore->aluno = data;
        excluirAluno(arvore->direita, data.getMatricula());
    }
}

void ArvoreBinaria::getSucessor(NodeType* arvore, Aluno& data) {
    arvore = arvore->direita;
    while (arvore->esquerda != NULL)
        arvore = arvore->esquerda;
    data = arvore->aluno;
}

void ArvoreBinaria::printPreOrdem(NodeType* arvore) const {
    if (arvore != NULL) {
        cout << arvore->aluno.getNome() << " , ";
        printPreOrdem(arvore->esquerda);
        printPreOrdem(arvore->direita);
    }
}

void ArvoreBinaria::printInOrdem(NodeType* arvore) const {
    if (arvore != NULL) {
        printPreOrdem(arvore->esquerda);
        cout << arvore->aluno.getNome() << " , ";
        printPreOrdem(arvore->direita);
    }
}

void ArvoreBinaria::printPosOrdem(NodeType* arvore) const {
    if (arvore != NULL) {
        printPreOrdem(arvore->esquerda);
        printPreOrdem(arvore->direita);
        cout << arvore->aluno.getNome() << " , ";
    }
}
