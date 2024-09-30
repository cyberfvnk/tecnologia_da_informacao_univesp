#include "grafo.h"

Grafo::Grafo(int max, int aresta_null) {
    this->ARESTA_NULL = aresta_null;
    this->maxVertices = max;
    this->numVertices = 0;
    this->vertices = new Vertex[max];
    this->arestas = new int*[max];
    this->marcacao = new bool[max];
    
    for (int linha = 0; linha < max; linha++) {
        this->arestas[linha] = new int[max];
        for (int coluna = 0; coluna < max; coluna++) {
            this->arestas[linha][coluna] = this->ARESTA_NULL;
        }
    }
}

Grafo::~Grafo() {
    delete[] this->vertices;
    delete[] this->marcacao;
    for (int linha = 0; linha < this->maxVertices; linha++) {
        delete[] this->arestas[linha];
    }
    delete[] this->arestas;
}

int Grafo::getIndice(Vertex vertice) {
    // busca sequencial, pode ser melhorada para desempenho
    int index = 0;
    while (!(vertice.getNome() == this->vertices[index].getNome())) {
        index++;
    } return index;
}

void Grafo::insereVertice(Vertex vertice) {
    if (this->numVertices < this->maxVertices) {
        this->vertices[this->numVertices] = vertice;
        this->numVertices++;
    }
}

void Grafo::insereAresta(Vertex origem, Vertex destino, int peso) {
    int indexLinha = this->getIndice(origem);
    int indexColuna = this->getIndice(destino);
    this->arestas[indexLinha][indexColuna] = peso;
// se o grafo for direcionado, comente a linha abaixo
//    this->arestas[indexColuna][indexLinha] = peso;
}

int Grafo::getPesoAresta(Vertex origem, Vertex destino) {
    int indexLinha = this->getIndice(origem);
    int indexColuna = this->getIndice(destino);
    return this->arestas[indexLinha][indexColuna];
}

void Grafo::getVerticesAdjacentes(Vertex vertice, Fila& fila) {
    int index = this->getIndice(vertice);
    for (int coluna = 0; coluna < this->numVertices; coluna++) {
        if (this->arestas[index][coluna] != this->ARESTA_NULL) {
            fila.enqueue(this->vertices[coluna]);
        }
    }
}

void Grafo::limpaMarcacao() {
    for (int i = 0; i < this->numVertices; i++) {
        this->marcacao[i] = false;
    }
}

void Grafo::marcaVertice(Vertex vertice) {
    int index = this->getIndice(vertice);
    this->marcacao[index] = true;
}

bool Grafo::isMarcado(Vertex vertice) {
    int index = this->getIndice(vertice);
    return this->marcacao[index];
}

void Grafo::printMatrix() {
    for (int linha = 0; linha < this->numVertices; linha++) {
        for (int coluna = 0; coluna < this->numVertices; coluna++) {
            cout << this->arestas[linha][coluna] << ", ";
        } cout << endl;
    }
}

void Grafo::getPageRanks(float* pageRanks) {
    int* grauSaida = new int[this->numVertices];
    
    for (int i = 0; i < this->numVertices; i++) {
        grauSaida[i] = 0;
        for (int j = 0; j < this->numVertices; j++) {
            if (this->arestas[i][j] != this->ARESTA_NULL) {
                grauSaida[i]++;
            }
        }
    }

    float* pageRankAnterior = new float[this->numVertices];
    float* pageRankAtual = new float[this->numVertices];

// inicializa o page rank de cada vértice com 1/n
    for (int i = 0; i < this->numVertices; i++) {
        pageRankAnterior[i] = 1.0 / this->numVertices;
    }

    float d = 0.85;
    for (int numInter = 0; numInter < 100; numInter++) { // numero de interacoes do page rank
        for (int i = 0; i < this->numVertices; i++) {  // para cada vertice
            pageRankAtual[i] = 0; // inicializa o page rank do vertice i com 0
            for (int j = 0; j < this->numVertices; j++) { // para cada vertice j
                if (this->arestas[j][i] != this->ARESTA_NULL) { // se existe aresta de j para i
                    pageRankAtual[i] += pageRankAnterior[j] / grauSaida[j]; // atualiza o page rank
                }
            }
            pageRankAtual[i] = (1 - d) / this->numVertices + d * pageRankAtual[i];
        }
        for (int i = 0; i < this->numVertices; i++) {
            pageRankAnterior[i] = pageRankAtual[i];
        }
    }

    for (int i = 0; i < this->numVertices; i++) {
        pageRanks[i] = pageRankAtual[i];
    }

    delete[] grauSaida;
    delete[] pageRankAnterior;
    delete[] pageRankAtual;
}
