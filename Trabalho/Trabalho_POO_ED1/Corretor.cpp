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

bool adicionarPalavraDic(Palavra palavra, Arvore *p){
    p->insere1(palavra);
    
}

bool apresentarErro(Palavra palavra, Arvore *p){
    if(!p->consulta1(palavra))
        return true;
    
    else
        return false;
    
}

void apresentarContexto(){
    
}

