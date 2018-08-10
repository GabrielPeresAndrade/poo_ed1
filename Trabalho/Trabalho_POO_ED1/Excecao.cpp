#include "Excecao.h"

Excecao::Excecao() {
}

Excecao::Excecao(const Excecao& orig) {
    this->numErro = orig.numErro;
}

Excecao::~Excecao() {
}

void Excecao::Msg()
{
    switch(this->numErro)
    {
        case ErroDeLeitura:
            //Mensagem de Erro
            cout << "!!!ERRO DE LEITURA DE ARQUIVO!!!"<< endl;
            break;
        case ErroDeGravar:
            //Mensagem de Erro
            cout << "!!!ERRO DE GRAVAÇÃO DE ARQUIVO!!!"<< endl;
            break;
        case ErroDeMemoria:
            //Mensagem de Erro
            cout << "!!!ERRO DE MEMÓRIA!!!"<< endl;
            break;
    } 
}       
    
Excecao::Excecao(int numErro)
{
    Excecao();
    this->numErro = numErro;
}