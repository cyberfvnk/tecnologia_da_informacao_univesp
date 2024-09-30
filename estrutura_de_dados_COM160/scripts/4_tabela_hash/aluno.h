#include <string>
using namespace std;

class Aluno {   
    private: 
        int matricula;
        string nome;
    public:
        Aluno();
        Aluno(int matricula, string nome);
        int getMatricula() const;
        string getNome() const;
};