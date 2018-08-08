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
    //PALAVRA//
    
    Palavra *p1 = new Palavra();
    Palavra *p2 = new Palavra();
    Palavra *p3 = new Palavra();
    Palavra *p4 = new Palavra();
    Palavra *p5 = new Palavra();
    Palavra *p6 = new Palavra();
    Palavra *p7 = new Palavra();
    Palavra *p8 = new Palavra();
    p1->setPalavra("golada");
    p2->setPalavra("abacate");  
    p3->setPalavra("f");
    p4->setPalavra("e");
    p5->setPalavra("z");
    p6->setPalavra("c");
    p7->setPalavra("d");
    p8->setPalavra("t");
    
    if (*p1>*p2)
    {
        cout<<"atum > atim\n";
    }
    
    if (p1->semelhante(*p2)==1)
        cout<<"Palavras Semelhantes" <<endl;
    
    //TEXTO//
    
    Texto *t1 = new Texto();
    t1->setArquivo("texte.txt");
    t1->carregarTexto();
    string a="eae";
    string b="eba";
    string arq="textoMod.txt";
    t1->alterarPalavra(a,b);
    t1->gravarTexto(arq);
    //DICIONARIO//
       
    //ARVORE//
    Arvore *p = new Arvore();
    Dicionario *dic = new Dicionario();
    
    dic->setArquivo("dic.txt");
    dic->lerArquivo(p);
    
   p->preordem(p->getRaiz());
   p->emordem(p->getRaiz());
   
   int *posix = new int();
   
   *posix=0;
   Palavra *vet = new Palavra[10000];
   p->palavrasSemelhantes(p->getRaiz(),*p2,vet,posix);
  int ai=0;
  while(ai<90){
    cout << " "<<vet[ai].getPalavra()<<" | ";
    ai++;
  }
    
    //CORRETOR//
   Corretor *c = new Corretor();
   c->texto.setArquivo("a.txt");
   c->texto.carregarTexto();
   *t1 = c->apresentarContexto(*p1);
   
   return(0);
}