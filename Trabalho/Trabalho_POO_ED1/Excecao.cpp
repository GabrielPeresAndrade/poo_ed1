#include "Excecao.h"

Excecao::Excecao() {
}

Excecao::Excecao(const Excecao& orig) {
}

Excecao::~Excecao() {
}

void Excecao::Msg()
{
    switch(this->numErro)
    {
        case ErroDeLeitura:
            //Mensagem de Erro
            break;
        case ErroDeGravar:
            //Mensagem de Erro
            break;
        case ErroDeMemoria:
            //Mensagem de Erro
            break;
        case 4:
            //Mensagem de Erro
            break;
        case 5:
            //Mensagem de Erro
            break;
        case 6:
            //Mensagem de Erro
            break;   
    }       
    
}
Excecao::Excecao(int numErro)
{
    Excecao();
    this->numErro = numErro;
}