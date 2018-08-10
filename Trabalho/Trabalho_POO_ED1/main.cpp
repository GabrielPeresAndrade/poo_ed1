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
   c->nomeArquivo("b.txt");
   c->getDicionario().lerArquivo(c->getDicionario().getRaiz()); 
   c->getDicionario().getRaiz()->preordem(c->getDicionario().getRaiz()->getRaiz());
   c->getDicionario().getRaiz()->emordem(c->getDicionario().getRaiz()->getRaiz());
   c->palavrasSemelhantes(*p1); 
  try{
     c->corrigirPalavra(*p1);
    }catch(Excecao i)
    {
        
    }
   c->gravarTexto("vai.txt");
   if (c->adicionarPalavraDic(*p1)==1)
   {
       //adicionou
       c->palavrasSemelhantes(*p1); 
   }
   else
   {
       //nao adicionou
       c->palavrasSemelhantes(*p1); 
   }
   c->corrigirManualmente(*p1,"goladas");
   c->listarErros();
   cout << endl;
   c->mostrarErros();
   c->ignorarErro(3);
   c->mostrarErros();
   return(0);
}