/* File:   main.cpp
 * Author: Gabriel Peres
 * Created on 8 de Maio de 2018, 22:48
 */
#include <iostream>
#include <cstdlib>
#include "Corretor.h"

using namespace std;

int main(int argc, char** argv) 
{
    Palavra *p1 = new Palavra();
    Palavra *p2 = new Palavra();
    p1->setPalavra("golada");
    p2->setPalavra("abacate");  
    Texto *t1 = new Texto();
   Corretor *c = new Corretor();
   c->nomeTexto("a.txt");
   c->carregarTexto();
   t1 = c->apresentarContexto(*p1);
   c->nomeArquivo("dic.txt");
   c->getDicionario().lerArquivo(c->getDicionario().getRaiz()); 
   c->getDicionario().getRaiz()->preordem(c->getDicionario().getRaiz()->getRaiz());
   c->getDicionario().getRaiz()->emordem(c->getDicionario().getRaiz()->getRaiz());
   c->palavrasSemelhantes(*p2); 
   
   return(0);
}