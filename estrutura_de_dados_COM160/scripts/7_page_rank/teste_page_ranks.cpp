#include "grafo.h"
using namespace std;

int main() {
    Grafo grafo;
    Vertex a("A"); grafo.insereVertice(a);
    Vertex b("B"); grafo.insereVertice(b);
    Vertex c("C"); grafo.insereVertice(c);
    Vertex d("D"); grafo.insereVertice(d);
    Vertex e("E"); grafo.insereVertice(e);

    grafo.insereAresta(a, c, 1);
    grafo.insereAresta(b, d, 1);
    grafo.insereAresta(c, b, 1);
    grafo.insereAresta(d, c, 1);
    grafo.insereAresta(a, b, 1);
    grafo.insereAresta(c, a, 1);
    grafo.insereAresta(c, d, 1);
    grafo.printMatrix();
    cout << endl;

    float* pageRanks = new float[4];
    grafo.getPageRanks(pageRanks);

    return 0;
}

