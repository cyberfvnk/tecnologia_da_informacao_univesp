#include <iostream>
using namespace std;

void aloca_memoria(int* ponteiro) {
    ponteiro = new int;
    *ponteiro = 99;
    // o ponteiro aponta para novo um endereço de memória alocado, o ponteiro original não é modificado
}

void modifica_memoria(int* ponteiro) {
    *ponteiro = 99;
    // o valor alocado na memória é modificado, o ponteiro permanece apontando para a mesma região
}

void referencia_memoria(int*& ponteiro) {
    ponteiro = new int;
    *ponteiro = 99;
    // o ponteiro original é modificado para apontar para um novo endereço de memória
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    int* p1 = &a;
    int* p2 = &b;
    int* p3 = &c;

    cout << "Antes: " << p1 << " " << p2 << " " << p3 << endl;
    cout << "Antes: " << *p1 << " " << *p2 << " " << *p3 << endl;

    aloca_memoria(p1);
    modifica_memoria(p2);
    referencia_memoria(p3);

    cout << "Depois: " << p1 << " " << p2 << " " << p3 << endl;
    cout << "Depois: " << *p1 << " " << *p2 << " " << *p3 << endl;
    cout << "Depois: " << a << " " << b << " " << c << endl;

    return 0;
}