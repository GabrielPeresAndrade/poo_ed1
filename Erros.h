#ifndef ERROS_H
#define ERROS_H
#include "Palavra.h"
class Erros {
    
public:
    Erros();
    Erros(const Erros& orig);
    virtual ~Erros();
   Palavra getPalavra()const;
    int getOcorrencia()const;
    void setPalavra(Palavra p);
    void setOcorrencia(int num);
private:
    Palavra palavra;
    int ocorrencia;
};

#endif /* ERROS_H */

