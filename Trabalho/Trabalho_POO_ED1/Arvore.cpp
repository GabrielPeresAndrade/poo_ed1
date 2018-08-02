#include <iostream>
#include "Arvore.h"

using namespace std;

Arvore::Arvore() {
    raiz = NULL;
}

Arvore::Arvore(const Arvore& orig) {
    raiz == NULL;
}

Arvore::~Arvore() {
    desmatar(raiz);
}


void Arvore::desmatar(no* p)
{
        if(p == NULL)
            return;
        desmatar(p->esq);
        desmatar(p->dir);
        delete p;
}
  
bool Arvore::vazia()
{
    if(this == NULL)
    	return 1;
    else
    	return 0;
}
Arvore::no* Arvore::insere(no* p, Palavra palavra)   
{
    if(p == NULL)
    {
        p = new no;
        p->dado = palavra;
        p->alt = 0;
        p->esq = NULL;
        p->dir = NULL;
        
        return p;
    }
    
    else if(palavra < p->dado)
    {
       p->esq = insere(p->esq, palavra);
       
       if(altura(p->esq) - altura(p->dir) == 2)
       {
           if(palavra < p->esq->dado)
               p = rot_EE(p);
           else
               p = rot_ED(p);
       }
    }
    else if(palavra > p->dado)
    {
        p->dir = insere(p->dir, palavra);
        
        if(altura(p->dir) - altura(p->esq) == 2)
        {
            if(palavra > p->dir->dado)
                p = rot_DD(p);
            else
                p = rot_DE(p);
        }
    }

    p->alt = maior(altura(p->esq), altura(p->dir)) + 1;
    
    return p;
}


bool Arvore::insere1(Palavra palavra)
{
    raiz = insere(raiz, palavra);
    return true;
}

int Arvore::altura(no* p)
{
    if(p == NULL)
        return 0;
    else
        return maior(altura(p->esq), altura(p->dir)) + 1;
}

int Arvore::maior(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

Arvore::no* Arvore::rot_EE(no* p)
    {
    no* aux;
    
    aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;
  
    return aux;
    }
Arvore::no* Arvore::rot_DD(no* p)
{
    no* aux;
    
    aux = p->dir;
    p->dir = aux->esq;
    aux->esq = p;
    
    
    return aux;   
}

Arvore::no* Arvore::rot_ED(no* p)
{
     no* aux;
     no* aux2;
    
    aux = p->esq;
    aux2 = aux->dir;
    p->esq = aux2->dir;
    aux->dir = aux2->esq;
    aux2->dir = p;
    aux2->esq = aux;
    
    return aux2;
}
Arvore::no* Arvore::rot_DE(no* p)
{
    no* aux;
    no*aux2;
    
    aux = p->dir;
    aux2 = aux->esq;
    p->dir = aux2->esq;
    aux->esq = aux2->dir;
    aux2->esq = p;
    aux2->dir = aux;
    
    return aux2;
    
}

void Arvore::emordem(no* p)
{
    if(p == NULL)
        return;
    
    emordem(p->esq);
    cout << p->dado.getPalavra() << " " << endl;
    emordem(p->dir);
}
void Arvore::preordem(no* p)
{   
    if(p == NULL)
        return;
    
    cout << p->dado.getPalavra() << " " << endl;
    preordem(p->esq);
    preordem(p->dir);
}

Arvore::no* Arvore::getRaiz()
{
    return(this->raiz);
}