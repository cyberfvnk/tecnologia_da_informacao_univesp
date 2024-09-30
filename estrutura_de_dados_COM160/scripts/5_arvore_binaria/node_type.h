#include "aluno.h"

struct NodeType {
    Aluno aluno;
    NodeType* esquerda;
    NodeType* direita;
};