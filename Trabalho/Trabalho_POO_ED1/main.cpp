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
    p1->setPalavra("g");
    p2->setPalavra("b");  
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
    Arvore *p;
    Dicionario *dic = new Dicionario();
    
    dic->setArquivo("dic.txt");
    dic->lerArquivo(p);
    
   p->preordem(p->getRaiz());
   p->emordem(p->getRaiz());
   
   //CORRETOR//
   
   FILE *texto;
   texto = fopen("texto.txt", "r");
   char s[100];
   if (texto == NULL){
       throw(Excecao(ErroDeLeitura));
   }
   
   while (!feof){
       s[0]='\0';
            fscanf(texto,"%s",s);
            if (s[0]!='\0')
            {
                Palavra *ptxt = new Palavra();
                ptxt->setPalavra(s);
            }
       
}