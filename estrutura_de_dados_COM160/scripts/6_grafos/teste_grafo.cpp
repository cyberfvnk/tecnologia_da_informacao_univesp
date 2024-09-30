#include "grafo.h"clea
using namespace std;

int main() {
    Grafo grafo;
    Vertex a("A"); grafo.insereVertice(a);
    Vertex b("B"); grafo.insereVertice(b);
    Vertex c("C"); grafo.insereVertice(c);
    Vertex d("D"); grafo.insereVertice(d);
    Vertex e("E"); grafo.insereVertice(e);

    grafo.insereAresta(a, b, 2);
    grafo.insereAresta(b, c, 3);
    grafo.insereAresta(a, c, 1);
    grafo.insereAresta(c, e, 1);
    grafo.printMatrix();
    cout << endl;

    return 0;
}

