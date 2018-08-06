#ifndef ERROS_H
#define ERROS_H
#include "Palavra.h"
class Erros {
public:
    Erros();
    Erros(const Erros& orig);
    virtual ~Erros();
private:
    Palavra palavra;
    Palavra anterior;
    Palavra posterior;
    int ocorrencia;
};

#endif /* ERROS_H */

