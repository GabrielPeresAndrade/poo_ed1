/*
 *  A classe Dicionário deverá armazenar as palavras obtidas do arquivo 
 * "dict.txt" e deverá permitir consulta e inclusão de palavras e fornecer 
 * uma lista de palavras semelhantes à uma determinada palavra (considerar 
 * palavras semelhantes aquelas que começam com as mesmas 2 letras). 
 * O relacionamento entre as classes Dicionário e Palavra deverá ser 
 * implementado por meio de uma árvore balanceada. 
 * Você poderá escolher entre AVL e vermelho-preta.
 */
#include <string>
#include "Arvore.h"
#include "Excecao.h"
using namespace std;

class Dicionario {
public:
    //Construtores e destrutores
    Dicionario();
    Dicionario(const Dicionario& orig);
    virtual ~Dicionario();
    //Metodos Gets e Sets
    void setArquivo(string nome);
    string getArquivo()const;
    Arvore *getRaiz() const;
    void setRaiz(Arvore *a);
    //Metodos
    bool inserirPalavra(Palavra palavra);
    bool consultarPalavra(Palavra palavra);
    bool lerArquivo(Arvore *p);

    Dicionario& operator=(Dicionario d1) noexcept;
private:
    string arquivo;
    Arvore *raiz;
    
};
