/*
 * A classe Arvore deve ter na interface apenas os métodos: vazia, insere,
 * remove e Busca.
 */

using namespace std;

class Arvore {
public:
    //Construtores e destrutores
    Arvore();
    Arvore(const Arvore& orig);
    virtual ~Arvore();
    //Metodos Gets e Sets
    
    //Metodos
    bool vazia();
    bool insere();
    bool remove();
    //Busca é do tipo da Arvore
private:

};
