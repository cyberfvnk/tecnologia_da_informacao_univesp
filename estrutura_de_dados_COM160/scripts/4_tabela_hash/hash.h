#include "aluno.h"

class Hash {
    private:
        int getHash(Aluno aluno);
        int tamanho;
        int max_items;
        Aluno* estrutura;
    public:
        Hash(int tamanho = 100);
        ~Hash();
        bool isCheia() const;
        int getTamanho() const;

        void buscarItem(Aluno& aluno, bool& encontrado);
        void inserirItem(Aluno aluno);
        void excluirItem(Aluno aluno);
        void print();
};