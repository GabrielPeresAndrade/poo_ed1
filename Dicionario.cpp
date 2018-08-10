#include "Dicionario.h"

Dicionario::Dicionario() {
    this->raiz = new Arvore();
}

Dicionario::Dicionario(const Dicionario& orig) {
    Dicionario();
    this->arquivo = orig.arquivo;
    this->raiz = orig.raiz;
}

Dicionario::~Dicionario() {
}

void Dicionario::setArquivo(string nome)
{
    this->arquivo = nome;
}
string Dicionario::getArquivo() const
{
    return(this->arquivo);
}

bool Dicionario::inserirPalavra(Palavra palavra)
{
    this->getArvore()->insere(palavra);
}

bool Dicionario::consultarPalavra(Palavra palavra)
{
    
    if (this->getArvore()->consulta(palavra))
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
                if (p->insere(*p1))
                {
                    arq=arq;
                }
            }
        } 
        fclose(arq);
    }
}

Arvore * Dicionario::getArvore() const
{
    return(this->raiz);
}
void Dicionario::setArvore(Arvore *a)

{
    this->raiz = a ;
}


Dicionario& Dicionario::operator=(Dicionario d1) noexcept
{
    this->arquivo = d1.arquivo;
    this->raiz = d1.raiz;
    return *this;
}