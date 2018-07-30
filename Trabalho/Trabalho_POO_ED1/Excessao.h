
#ifndef EXCESSAO_H
#define EXCESSAO_H
#define ErroDeLeitura 1
#define ErroDeGravar 2
//#define ErroDeLeitura 1
//#define ErroDeLeitura 1
//#define ErroDeLeitura 1
class Excessao {
public:
    Excessao();
    Excessao(int numErro);
    Excessao(const Excessao& orig);
    virtual ~Excessao();
    void Msg();
private:
    int numErro;
};

#endif /* EXCESSAO_H */

