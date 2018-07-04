#include "Texto.h"
#include <stdlib.h>
Texto::Texto() 
{
    int i;
    for (i = 0 ; i < 10000 ; i++)
    {
        this->lista[i]= NULL ;
    }
}

Texto::Texto(const Texto& orig) 
{
}

Texto::~Texto() 
{
}

void Texto::carregarTexto()
{
    FILE *arq;
    char s[100];
    arq = fopen(this->getArquivo().c_str(),"r");
    if (arq == NULL)
    {
        //deu merda para abrir
    }
    else
    {
        while (!feof(arq))
        {
            //Le palavra por palavra
            fscanf(arq,"%s",s);
            this->adcLista(s);
        } 
        fclose(arq);
    }
}
void Texto::gravarTexto()
{
   FILE *arq;
   arq = fopen(this->getArquivo().c_str(),"w");  
   if(arq == NULL)
    {
      //deu ruim para criar
    }
   else
   {
       fprintf(arq,"%s","kkk eae boy");
       fclose(arq);
   }
}
string Texto::getArquivo()
{
    return arquivo;
}

void Texto::setArquivo(string Arquivo)
{
    this->arquivo = Arquivo;
}

bool Texto::adcLista(string palavra)
{
    int i;
    for (i = 0 ; i < 10000 ; i++)
    {
        if (this->lista[i] == NULL)
        {
            Palavra *p1 = new Palavra(palavra);
            this->lista[i] = p1;
            i = 10000;
        }
    }
}