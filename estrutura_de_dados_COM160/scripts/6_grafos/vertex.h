#include <iostream>
using namespace std;
#pragma once

class Vertex {
    private:
        string nome;
    public:
        Vertex() { this->nome = ""; };
        Vertex(string nome) { this->nome = nome; };
        string getNome() { return this->nome; };
};
