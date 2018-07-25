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
    bool vazia(Avl *raiz);
    bool insere(Avl *raiz, Palavra palavra);
    bool consulta(Avl *raiz);
    bool altura(Avl *raiz);
    //Busca é do tipo da Arvore
private:
    Palavra dado;
    Arvore *esq;
    Arvore *dir;
    
};