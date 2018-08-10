#include "Texto.h"
#include <stdlib.h>
Texto::Texto() 
{
    int i;
    for (i = 0 ; i < 10000 ; i++)
    {
        this->lista[i]= NULL ;
    }
    this->contador=0;
}

Texto::Texto(const Texto& orig) 
{
    Texto();
    int i;
    for (i = 0 ; ((i < 10000)  && (this->lista[i]!= NULL)); i++)
    {
        this->lista[i]= orig.lista[i] ;
    }
    this->arquivo =  orig.arquivo;
    this->contador = orig.contador;
}

Texto::~Texto() 
{
    int i;
    for (i = 0 ; i < this->contador ; i++)
    {
        delete this->lista[i] ;
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
        throw(Excecao(ErroDeLeitura));
    }
    else
    {
        while (!feof(arq))
        {
            //Le palavra por palavra
            s[0]='\0';
            fscanf(arq,"%s",s);
            if (s[0]!='\0')
            {
                try
                {
                    this->adcLista(s);
                }catch(Excecao i)
                {
                    throw(i);
                }
            }
        } 
        fclose(arq);
    }
}
void Texto::gravarTexto(string arquivo)
{
   int i;
   string s;
   FILE *arq;
   arq = fopen(arquivo.c_str(),"w");  
   if(arq == NULL)
    {
      //deu ruim para criar
       throw(Excecao(ErroDeGravar));
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
string Texto::getArquivo()const
{
    return arquivo;
}

void Texto::setArquivo(string Arquivo)
{
    this->arquivo = Arquivo;
}

bool Texto::adcLista(string palavra)
{
  if(this->contador<10000)
  {
    Palavra *p1 = new Palavra(palavra);
    this->lista[this->contador] = p1;
    this->contador++;
  }
  else
  {
    throw(Excecao(ErroDeMemoria));
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

Palavra Texto::percorreTexto()
{
    if (this->contador==10000)
    {
        this->contador=0;
        throw(Excecao(ErroDeMemoria));
    }
    this->contador++;
    return(*this->lista[this->contador-1]);
}

Palavra Texto::percorreTexto(int nPalavra)
{
    if (nPalavra>=this->contador)
    {
        throw(Excecao(ErroDeMemoria));
    }
    return(*this->lista[nPalavra]);
}

int Texto::consultarPalavra(Palavra p)
{
    int i;
    for (i = 0 ; (( i < 10000) && (this->lista[i]!= NULL)); i++)
    {
        if (*this->lista[i] == p)
        {
            return i;
        }
    }
    return -1;
}

Texto& Texto::operator=(Texto t1) noexcept
{
    for (int i = 0 ; ((i < 10000)  && (this->lista[i]!= NULL)); i++)
    {
        this->lista[i]= t1.lista[i] ;
    }
    this->contador = t1.contador;
    this->arquivo = t1.arquivo;
    return *this;
}

int Texto::getContador()const
{
    return( this->contador);
}