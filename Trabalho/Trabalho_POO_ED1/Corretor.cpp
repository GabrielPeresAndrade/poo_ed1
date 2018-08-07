#include "Corretor.h"

Corretor::Corretor() {

}

Corretor::Corretor(const Corretor& orig) {

}

Corretor::~Corretor() {

}

void Corretor::inicializaDic()
{
  
   /* Arvore *p;
    Dicionario *dic = new Dicionario();
    
    dic->setArquivo("dic.txt");
    dic->lerArquivo(p);
    
   p->preordem(p->getRaiz());
   p->emordem(p->getRaiz()); */

}


void Corretor::corrigirPalavra(Arvore *p, Palavra palavra){
    Arvore *aux = p;
        
    while (aux != NULL){
        for (int i=0; p!=NULL; i++) {
            
            if (p->semelhante(palavra, p->getPalavra())) {
                vetSem[i] = p->getPalavra();
            }
        }
    }
    
    
    
}

void Corretor::ignorarErro(){
    
}

void Corretor::selecionarPalavra(){
    
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

void Corretor::apresentarContexto(){
    
}

