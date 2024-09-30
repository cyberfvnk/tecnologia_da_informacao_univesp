#include "pilha.h"
#include <iostream>
using namespace std;

int main() {
    Pilha pilha;
    ItemType itemPilha;
    int opcao;
    cout << "Programa de teste da pilha" << endl;
    do {
        cout << "Digite 0 para parar o programa" << endl;
        cout << "Digite 1 para inserir um elemento" << endl;
        cout << "Digite 2 para remover um elemento" << endl;
        cout << "Digite 3 para imprimir a pilha" << endl;
        cin >> opcao;
        switch (opcao) {
        case 0:
            break;
        case 1:
            cout << "Digite o elemento a ser inserido: ";
            cin >> itemPilha;
            pilha.push(itemPilha);
            break;
        case 2:
            itemPilha = pilha.pop();
            cout << "Elemento removido: " << itemPilha << endl;
            break;
        case 3:
            pilha.print();
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (opcao != 0);
    return 0;
}