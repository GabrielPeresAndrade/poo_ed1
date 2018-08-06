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
using namespace std;

class Corretor{
public:
    //Construtores e destrutores
    Corretor();
    Corretor(const Corretor& orig);
    virtual ~Corretor();
    //Metodos Gets e Sets
    
    //Metodos
    void inicializaDic();
    void corrigirPalavra();
    void ignorarErro();
    void selecionarPalavra();
    void adicionarPalavraDic();
    void apresentarErro();
    void apresentarContexto();
private:
    Dicionario dicionario;
    Texto texto;
    Erros erros[10000];
    
};

