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
string Dicionario::getArquivo()
{
    return(this->arquivo);
}

bool Dicionario::inserirPalavra(Palavra palavra)
{
}
bool Dicionario::consultarPalavra(Palavra palavra)
{
}
bool Dicionario::lerArquivo()
{
    //PAREI AQUI
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
                // ADICIONA NA ARVORE
                this->raiz->insere();
        } 
        fclose(arq);
    }
}