#include "Palavra.h"

Palavra::Palavra()
{
}

Palavra::Palavra(const Palavra& orig) 
{
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