#include "Erros.h"

Erros::Erros() {
}

Erros::Erros(const Erros& orig) {
    Erros();
}

Erros::~Erros() {
}


Palavra Erros::getPalavra()const
{
    return this->palavra;
}
int Erros::getOcorrencia()const
{
    return this->ocorrencia;
}
void Erros::setPalavra(Palavra p)
{
    this->palavra= p;
}
void Erros::setOcorrencia(int num)
{
    this->ocorrencia = num;
}
