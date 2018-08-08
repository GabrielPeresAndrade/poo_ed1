#include "Corretor.h"

Corretor::Corretor() {

}

Corretor::Corretor(const Corretor& orig) {

}

Corretor::~Corretor() {

}

void corrigirPalavra(){
    
}

void ignorarErro(){
    
}

void selecionarPalavra(){
    
}
void Corretor::palavrasSemelhantes(Palavra p)
{
    
}
Texto Corretor::apresentarContexto(Palavra p)
{
    int a;
    Texto *t = new Texto();
    a = this->texto.consultarPalavra(p); 
    if(a!=-1)
    {
        t->adcLista(this->texto.percorreTexto(a-1).getPalavra());
        t->adcLista(this->texto.percorreTexto(a+1).getPalavra());
    }
    return *t;
}

bool Corretor::adicionarPalavraDic(Palavra palavra, Arvore *p){
    
    if(!p->consulta1(palavra))
        return (p->insere1(palavra));
    else 
        return false;
}

bool Corretor::apresentarErro(Palavra palavra, Arvore *p){
    if(!p->consulta1(palavra))
        return true;
    
    else
        return false;
    
}
