
#ifndef EXCECAO_H
#define EXCECAO_H
#define ErroDeLeitura 1
#define ErroDeGravar 2
//#define ErroDeLeitura 1
//#define ErroDeLeitura 1
//#define ErroDeLeitura 1
class Excecao {
public:
    Excecao();
    Excecao(int numErro);
    Excecao(const Excecao& orig);
    virtual ~Excecao();
    void Msg();
private:
    int numErro;
};

#endif /* EXCECAO_H */

