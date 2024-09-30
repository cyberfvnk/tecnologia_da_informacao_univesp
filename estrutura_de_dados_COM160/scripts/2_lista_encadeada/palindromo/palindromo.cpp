#include "fila.h"
#include "pilha.h"
#include <iostream>
using namespace std;

int main () {
    bool isPalindromo = true;
    char character, charFila, charPilha;
    Fila fila;
    Pilha pilha;

    cout << "Adicione uma sequência de caracteres: " << endl;
    cin.get(character);
    while (character != '\n') {
        fila.enqueue(character);
        pilha.push(character);
        cin.get(character);
    }

    while (!fila.isVazia() && isPalindromo) {
        charFila = fila.dequeue();
        charPilha = pilha.pop();
        if (charFila != charPilha)
            isPalindromo = false;
    }

    if (isPalindromo)
        cout << "A sequência é um palíndromo!" << endl;
    else
        cout << "A sequência não é um palíndromo!" << endl;
    
    return 0;
}