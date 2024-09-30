#include "vertex.h"
#include "fila.h"

class Grafo {
    private:
        int ARESTA_NULL;
        int maxVertices;
        int numVertices;
        Vertex* vertices;
        int** arestas;
        bool* marcacao;
        int getIndice(Vertex);
    public:
        Grafo(int max = 50, int null = 0);
        ~Grafo();
        void insereVertice(Vertex);
        void insereAresta(Vertex, Vertex, int);
        int getPesoAresta(Vertex, Vertex);
        void getVerticesAdjacentes(Vertex, Fila&);
        void limpaMarcacao();
        void marcaVertice(Vertex);
        bool isMarcado(Vertex);
        void printMatrix();
};