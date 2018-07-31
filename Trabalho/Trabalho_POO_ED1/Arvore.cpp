#include "Arvore.h"

Arvore::Arvore() {
}

Arvore::Arvore(const Arvore& orig) {
}

Arvore::~Arvore() {
	Arvore *aux = *raiz;

	while(aux != NULL);
		delete(raiz);
		aux = aux-

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
    if (raiz == NULL)
    	return false;

    Arvore *novo = new (sizeof Arvore);

    novo->dado = palavra;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;


    else if (*raiz == NULL)		//inserçao na primeira posiçao
    { 							
    	*raiz = novo;
    	return true;
    }

    Arvore *aux = raiz;
    Arvore *ant = NULL;

    else{
    	while(aux != NULL){

    		*ant = aux;

    		if (palavra == aux->dado){ // palavra ja existente na arvore
    			return false;
    		}

    		else if (palavra > aux->dado){
    			if(insere(aux->dir))
    				if(bal(aux) >= 2 || bal(aux) <= -2)
    					if(palavra > raiz->esq->info)
    						rot_DD(raiz);
    					else
    						rot_DE(raiz);
    		}

    		else if (palavra < aux->dado){
    			if(insere(aux->esq))
    				if(bal(aux) >= 2 || bal(aux) <= -2)
    					if(palavra < raiz->esq->info)
    						rot_EE(raiz);
    					else
    						rot_ED(raiz);
    		}
    	}

    	if (palavra > ant->dado){
    		ant->dir = novo;
    		return true;
    	}

    	else if (palavra < ant->dado){
    		ant->esq = novo;
    		return true;
    	}

    }

    aux->altura = maior(altura(aux->esq), altura(aux->dir) + 1);

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

int Arvore::altura(Arvore *no)
{
	if(no == NULL)
		return -1;
	else
		return no->altura;
}

int Arvore::bal(Arvore *raiz)
{
	return (altura(no->esq) - altura(no->dir));
}


int Arvore::maior(int x, int y)
{
	if(x > y)
		return x;
	else
		return y;

}

bool Arvore::rot_EE(Arvore *raiz)
{
	Arvore *aux;

	aux = raiz->esq;
	raiz->esq = no->dir;
	no->dir = *raiz
	raiz->altura = maior(altura(raiz->esq), altura(raiz->dir) + 1);
	raiz = no;

	return true;
}

bool Arvore::rot_DD(Arvore *raiz)
{
	Arvore *aux;

	aux = raiz->dir;
	raiz->dir = no->esq;
	no->esq = raiz;
	raiz->altura = maior(altura(raiz->dir), altura(raiz->esq) + 1);
	raiz = no;

	return true;
}

bool Arvore::rot_ED(Arvore *raiz)
{
	rot_DD(raiz->esq);
	rot_EE(raiz);
	return true;

}

bool Arvore::rot_DE(Arvore *raiz)
{
	rot_EE(raiz->dir);
	rot_DD(raiz);
	return true;
}