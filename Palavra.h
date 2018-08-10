/*
 * A classe Palavra deverá conter ao menos a palavra, um método que 
 * verifique se duas palavras são semelhantes e ter o operador == sobrecarregado
 * para verificar se duas palavras são idênticas.
 */
#ifndef __TrabalhoPOO_ED1__Palavra__
#define __TrabalhoPOO_ED1__Palavra__
#include <string>

using namespace std;

class Palavra {
public:
    //Construtores e destrutores
    Palavra();
    Palavra(string p);
    Palavra(const Palavra& orig);
    virtual ~Palavra();
    
    //Metodos Gets e Sets
    void setPalavra(string palavra);
    string getPalavra()const;
    
    //Metodos
    bool operator==(Palavra &p1);
    bool operator>(Palavra &p1);
    bool operator<(Palavra &p1);
    bool operator>=(Palavra &p1);
    bool operator<=(Palavra &p1);
    bool semelhante(Palavra p2);
    int tamanho();
private:
    string palavra;
};
#endif