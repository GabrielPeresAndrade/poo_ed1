/* File:   main.cpp
 * Author: Gabriel Peres
 * Created on 8 de Maio de 2018, 22:48
 */
#include <iostream>
#include <cstdlib>
//#include "Palavra.h"
#include "Corretor.h"
#include "Dicionario.h"
#include "Texto.h"

using namespace std;

int main(int argc, char** argv) 
{
    //PALAVRA//
    
    Palavra *p1 = new Palavra();
    Palavra *p2 = new Palavra();
    p1->setPalavra("atum!");
    p2->setPalavra("atim!");  
    
    if (p1->semelhante(*p2)==1)
        cout<<"Palavras Semelhantes";
    
    //TEXTO//
    
    Texto *t1 = new Texto();
    t1->setArquivo("texte.txt");
    t1->carregarTexto();
    string a="eae";
    string b="eba";
    t1->alterarPalavra(a,b);
    t1->gravarTexto();
    //DICIONARIO//
    
    //CORRETOR//
    
    //ARVORE//
    
    
    return 0;
}

