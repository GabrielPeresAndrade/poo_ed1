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
    p1->setPalavra("atum!");
    p2->setPalavra("atim!");  
    if (*p1>*p2)
    {
        cout<<"atum > atim\n";
    }
    
    if (p1->semelhante(*p2)==1)
        cout<<"Palavras Semelhantes";
    
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
    
    //CORRETOR//
    
    //ARVORE//
    
    
    return 0;
}

