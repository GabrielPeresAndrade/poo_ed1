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

bool Dicionario::inserirPalavra(Palavra palavra,Arvore *p)
{
    p->insere1(palavra);
}

bool Dicionario::consultarPalavra(Palavra palavra, Arvore *p)
{
    
    if (p->consulta1(palavra))
        return true;
    
    else 
        return false;
}

bool Dicionario::lerArquivo(Arvore *p)
{
    //PAREI AQUI
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
                Palavra *p1 = new Palavra();
                p1->setPalavra(s);
                if (p->insere1(*p1))
                {
                    arq=arq;
                }
            }
        } 
        fclose(arq);
    }
}
