/*
 * A classe Arvore deve ter na interface apenas os métodos: vazia, insere,
 * remove e Busca.
 */
#include "Palavra.h"
using namespace std;

class Arvore {
public:
    //Construtores e destrutores
    Arvore();
    Arvore(const Arvore& orig);
    virtual ~Arvore();
    //Metodos Gets e Sets
    
    //Metodos
    bool vazia(Arvore *raiz);
    bool insere(Arvore *raiz, Palavra palavra);
    bool consulta(Palavra palavra, Arvore *raiz);
    int altura(Arvore *raiz);
    int bal(Arvore *raiz);
    int maior(int x, int y);
    bool rot_EE(Arvore *raiz);
    bool rot_DD(Arvore *raiz);
    bool rot_ED(Arvore *raiz);
    bool rot_DE(Arvore *raiz);

    //Busca é do tipo da Arvore
private:
    Palavra dado;
    Arvore *esq;
    Arvore *dir;
    int alt;
    
};