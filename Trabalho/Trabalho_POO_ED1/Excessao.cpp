#include "Excessao.h"

Excessao::Excessao() {
}

Excessao::Excessao(const Excessao& orig) {
}

Excessao::~Excessao() {
}

void Excessao::Msg()
{
    switch(this->numErro)
    {
        case ErroDeLeitura:
            //Mensagem de Erro
            break;
        case ErroDeGravar:
            //Mensagem de Erro
            break;
        case 3:
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
Excessao::Excessao(int numErro)
{
    Excessao();
    this->numErro = numErro;
}