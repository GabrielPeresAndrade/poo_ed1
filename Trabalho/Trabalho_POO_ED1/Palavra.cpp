#include "Palavra.h"
#include <string.h>
using namespace std;

Palavra::Palavra()
{
}
Palavra::Palavra(string p)
{
    Palavra();
    this->setPalavra(p);
}
Palavra::Palavra(const Palavra& orig) 
{
    Palavra();
    this->setPalavra(orig.palavra);
}

Palavra::~Palavra()
{
}

bool Palavra::operator==(Palavra& p1)
{
    if (p1.palavra == this->palavra)
    {
        return  1;
    }
    return 0;
}

void Palavra::setPalavra(string palavra)
{
    this->palavra = palavra;
}

string Palavra::getPalavra()
{
    return this->palavra;
}

bool Palavra::semelhante(Palavra p2)
{
    //Depois de ter a arvore provavelmente isso irá mudar
    int i,j,t,k;
    i = this->tamanho();
    j = p2.tamanho();
    string a= this->getPalavra();
    string b= p2.getPalavra();
    t=0;
    for(k=0 ;((i > 0) && (j > 0));k++)
    {
        if (a[k]==b[k])
        {
            t++;
        }
        i--;
        j--;
    }
    if (t>this->tamanho()*3/4)
    {
        return true;
    }
    return false;
}

int Palavra::tamanho()
{
    return palavra.length();
}