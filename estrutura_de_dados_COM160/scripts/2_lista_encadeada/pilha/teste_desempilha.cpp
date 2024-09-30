#include "pilha.h"
#include <iostream>
using namespace std;

int main() {
    Pilha pilha;
    ItemType character;

    cout << "Adicione uma String." << endl;
    cin.get(character);
    while (character != '\n') {
        pilha.push(character);
        cin.get(character);
    }
    cout << "String invertida: ";
    while (!pilha.isVazia()) {
        cout << pilha.pop();
    }
    cout << endl;
    return 0;
}