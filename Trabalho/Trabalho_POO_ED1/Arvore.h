/*
 * A classe Arvore deve ter na interface apenas os métodos: vazia, insere,
 * remove e Busca.
 */
#include "Palavra.h"
using namespace std;

class Arvore {
    
    struct no
    {
        Palavra dado;
        no *esq;
        no *dir;
        int alt;
    };

    no* raiz;
    
public:
    //Construtores e destrutores
    Arvore();
    Arvore(const Arvore& orig);
    virtual ~Arvore();
    //Metodos Gets e Sets
    no* getRaiz();
    //Metodos
    bool vazia();
    void desmatar(no* p);
    bool insere1(Palavra palavra);
    no* insere(no* p, Palavra palavra);
//    bool consulta(Palavra palavra);
    int altura(no* p);
    int maior(int x, int y);
    no* rot_EE(no* p);
    no* rot_DD(no* p);
    no* rot_ED(no* p);
    no* rot_DE(no* p);
    void emordem(no* p);
    void preordem(no* p);
    
   
};