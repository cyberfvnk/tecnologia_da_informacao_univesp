#include <iostream>
#include "fila.h"
using namespace std;

int main() {
    char character;
    Fila fila;
    char queueChar;

    cout << "Adicione uma sequência de caracteres para a fila: " << endl;
    cin.get(character);
    
    while (character != '\n' && !fila.isCheia()) {
        try {
            fila.enqueue(character);
        } catch (const char* e) {
            cout << e << endl;
        }
        cin.get(character);
    }

    while (!fila.isVazia()) {
        queueChar = fila.dequeue();
        cout << queueChar;
    }
    cout << endl;
}