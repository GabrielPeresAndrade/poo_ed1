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
    Texto();
    int i;
    for (i = 0 ; ((i < 10000)  && (this->lista[i]!= NULL)); i++)
    {
        this->lista[i]= orig.lista[i] ;
    }
}

Texto::~Texto() 
{
    int i;
    for (i = 0 ; i < 10000 ; i++)
    {
        this->lista[i]= NULL ;
    }
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
            s[0]='\0';
            fscanf(arq,"%s",s);
            if (s[0]!='\0')
                this->adcLista(s);
        } 
        fclose(arq);
    }
}
void Texto::gravarTexto()
{
   int i;
   string s;
   FILE *arq;
   arq = fopen(this->getArquivo().c_str(),"w");  
   if(arq == NULL)
    {
      //deu ruim para criar
    }
   else
   {
        for (i = 0 ; (( i < 10000) && (this->lista[i]!= NULL)); i++)
        {
            fprintf(arq,"%s ",(this->lista[i])->getPalavra().c_str());
        }
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

void Texto::alterarPalavra(string tirar,string colocar)
{
    int i;
    for (i = 0 ; (( i < 10000) && (this->lista[i]!= NULL)); i++)
    {
        if ((this->lista[i])->getPalavra() == tirar)
        {
            (this->lista[i])->setPalavra(colocar);
        }
    }
}