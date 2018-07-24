#include "Dicionario.h"

Dicionario::Dicionario() {
    this->setArquivo("dict.txt");
}

Dicionario::Dicionario(const Dicionario& orig) {
}

Dicionario::~Dicionario() {
}

void Dicionario::setArquivo(string nome)
{
    this->arquivo = nome;
}

bool Dicionario::inserirPalavra(Palavra palavra)
{
}
bool Dicionario::consultarPalavra(Palavra palavra)
{
}
bool Dicionario::dicionarioVazio()
{
}
bool Dicionario::lerArquivo()
{
    //PAREI AQUI
}