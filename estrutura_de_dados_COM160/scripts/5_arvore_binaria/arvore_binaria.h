#include "aluno.h"
#include "node_type.h"
#include <iostream>

class ArvoreBinaria {
    private:
        NodeType* raiz;
        void destruirArvore(NodeType*& arvore);
        void buscarAluno(NodeType* arvore, Aluno& aluno, bool& achado) const;
        void inserirAluno(NodeType*& arvore, Aluno aluno);
        void excluirAluno(NodeType*& arvore, int aluno);
        void deletarNo(NodeType*& arvore);
        void getSucessor(NodeType* arvore, Aluno& data);
        void printArvore(NodeType* arvore) const;
        void printPreOrdem(NodeType* arvore) const;
        void printInOrdem(NodeType* arvore) const;
        void printPosOrdem(NodeType* arvore) const;
    public:
        ArvoreBinaria() { raiz = NULL ; }
        ~ArvoreBinaria() { destruirArvore(raiz); }
        bool isVazia() { return raiz == NULL; }
        bool isCheia() const;
        void buscarAluno(Aluno& item, bool& achado) const { buscarAluno(raiz, item, achado); }
        void inserirAluno(Aluno item) { inserirAluno(raiz, item); }
        void excluirAluno(int item) { excluirAluno(raiz, item); }
        void printPreOrdem() const { printPreOrdem(raiz); }
        void printInOrdem() const { printInOrdem(raiz); }
        void printPosOrdem() const { printPosOrdem(raiz); }
};
