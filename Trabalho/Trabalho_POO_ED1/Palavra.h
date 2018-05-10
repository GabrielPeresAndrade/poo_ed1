/*
 * A classe Palavra deverá conter ao menos a palavra, um método que 
 * verifique se duas palavras são semelhantes e ter o operador == sobrecarregado
 * para verificar se duas palavras são idênticas.
 */
#include <string>

using namespace std;

class Palavra {
public:
    //Construtores e destrutores
    Palavra();
    Palavra(const Palavra& orig);
    virtual ~Palavra();
    
    //Metodos Gets e Sets
    void setPalavra(string palavra);
    string getPalavra();
    
    //Metodos
    bool operator==(Palavra &p1);

private:
    string palavra;
};
