#include <iostream>
using namespace std;

void troca_por_referencia(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "antes: x = " << x << ", y = " << y << endl;
    troca_por_referencia(x, y);
    cout << "depois: x = " << x << ", y = " << y << endl;
    return 0;
}