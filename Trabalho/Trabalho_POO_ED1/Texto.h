/*
 * A classe Texto deverá conter uma lista de palavras, o nome do arquivo 
 * original do texto e permitir carregar um texto a partir de um arquivo,
 * percorrer o texto, palavra por palavra, alterar uma palavra e gravar 
 * o texto em um arquivo (não necessariamente o original).
 */
#include <string>
#include "Palavra.h"
#include "Excecao.h"
using namespace std;

class Texto {
public:
    //Construtores e destrutores
    Texto();
    Texto(const Texto& orig);
    virtual ~Texto();       
    
    //Metodos Gets e Sets
    string getArquivo()const;
    void setArquivo(string Arquivo);
    Palavra percorreTexto();
    Palavra percorreTexto(int nPalavra);
    //Metodos
    void alterarPalavra(string tirar,string colocar);
    int consultarPalavra(Palavra p);
    void carregarTexto();
    void gravarTexto(string arquivo);
    bool adcLista(string palavra);
    
    Texto& operator=(Texto t1) noexcept;
private:
    //Lista de palavras   (vetor de ponteiros)
    Palavra *lista[10000];
    //Nome do arquivo original
    string arquivo;
    int contador;
    
};

