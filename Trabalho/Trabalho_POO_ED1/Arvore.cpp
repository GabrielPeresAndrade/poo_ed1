#include "Arvore.h"

Arvore::Arvore() {
}

Arvore::Arvore(const Arvore& orig) {
}

Arvore::~Arvore() {
}

bool Arvore::vazia(Arvore *raiz)
{
    if(raiz == NULL)
    	return 1;
    else
    	return 0;
}
bool Arvore::insere(Arvore *raiz, Palavra palavra)   
{
    true;
}

bool Arvore::consulta(Palavra palavra,Arvore *raiz)
{
	if (raiz == NULL)				//caso arvore vazia e nao encontrou palavra
		return 0;												

	Arvore *aux = raiz;

	while (aux){
		if (palavra == raiz->dado){
			return 1;
		}
		else if (palavra < raiz->dado)
			aux = aux->esq;

		else
			aux = aux->dir;
	}
	return 0;

}

bool Arvore::altura(Arvore *raiz)
{
	if(raiz == NULL)
		return 0;

	int altura_e = altura(raiz->esq);
	int altura_d = altura(raiz->dir);

	if(altura_e > altura_d)
		return(altura_e + 1);
	else
		return(altura_d + 1);
}