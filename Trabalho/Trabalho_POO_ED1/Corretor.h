/*
 * A classe corretor deverá conter métodos para a interação com o usuário e 
 * também para manipular as classes dicionário e texto.
 * corrigir a palavra, ignorar o erro, selecionar uma palavra a partir de
 *  uma lista de palavras semelhantes ou adicionar a palavra no dicionario.
 *  Ao apresentar um erro para ser corrigido, o corretor devera apresentar 
 * tambem ao usuario, o contexto em que o erro ocorreu (a palavra anterior e
 *  a palavra seguinte ao erro). O corretor devera tambem manter uma lista 
 * dos erros encontrados no texto (corrigidos ou nao). Essa lista devera 
 * conter apenas uma entrada para cada palavra errada e devera manter o numero
 *  de vezes que o mesmo erro ocorreu no texto. O Corretor devera ser uma 
 * classe que contenha um dicionario, um texto e a lista das palavras erradas.
 */
#include "Texto.h"
#include "Dicionario.h"
#include "Erros.h"
#include <iostream>
using namespace std;

class Corretor{
public:
    //Construtores e destrutores
    Corretor();
    Corretor(const Corretor& orig);
    virtual ~Corretor();
    //Metodos Gets e Sets
    Texto getTexto();
    Dicionario getDicionario();
    void setTexto(Texto t);
    void setDicionario(Dicionario d);
    //Metodos
    void ignorarErro(int numero);
    void listarErros();
    void selecionarPalavra();
    Palavra *palavrasSemelhantes(Palavra p);
    bool adicionarPalavraDic(Palavra palavra);
    bool apresentarErro(Palavra palavra, Arvore *p);
    Texto *apresentarContexto(Palavra p);
    void nomeArquivo(string s);
    void nomeTexto(string s);
    void carregarTexto();
    void gravarTexto(string s);
    string selecionarPalavra(Palavra *vet);
    void corrigirPalavra(Palavra palavra);
    void corrigirManualmente(Palavra p,string palavra);
    void mostrarErros();
private:
    Dicionario dicionario;
    Texto texto;
    Erros *erros[10000];
    int qtdErros;
    
};

