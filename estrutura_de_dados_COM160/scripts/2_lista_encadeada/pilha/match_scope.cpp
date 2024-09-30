#include "pilha.h"
#include <iostream>
using namespace std;

int main() {
    Pilha p;
    ItemType item;
    ItemType character;
    bool isMatched = true;

    cout << "Insira uma string: ";
    cin.get(character);

    while (isMatched && character != '\n') {
        if (character == '(' || character == '[' || character == '{')
            p.push(character);
        else if (character == ')' || character == ']' || character == '}') {
            if (p.isVazia())
                isMatched = false;
            else {
                item = p.pop();
                isMatched = ((character == ')' && item != '(') 
                            || (character == ']' && item != '[') 
                            || (character == '}' && item != '{'));
            }
        }
        cin.get(character);
    }

    if (isMatched && p.isVazia()) {
        cout << "Expressão bem formad!" << endl;
    } else {
        cout << "Expressão mal formada!" << endl;
    }
    return 0;
}