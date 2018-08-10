#include "Corretor.h"

Corretor::Corretor() {

}

Corretor::Corretor(const Corretor& orig) {
    Corretor();
    
    this->dicionario.setArquivo(orig.dicionario.getArquivo());
    this->dicionario.setRaiz(orig.dicionario.getRaiz());
    this->texto = orig.texto;
   // this->erros = orig.erros;
}

Corretor::~Corretor() {
    
}

void corrigirPalavra(){
    
}

void ignorarErro(){
    
}

Palavra *Corretor::palavrasSemelhantes(Palavra p)
{
    int *posix = new int();   
   *posix=0;
   Palavra *vet = new Palavra[10000];
   this->dicionario.getRaiz()->palavrasSemelhantes(this->dicionario.getRaiz()->getRaiz(),p,vet,posix);
   for(int ai=0; ai<*posix;ai++)
   {
    cout << " "<<vet[ai].getPalavra()<<" | ";
  }
   delete posix;
   return(vet);
}
Texto *Corretor::apresentarContexto(Palavra p)
{
    int a;
    Texto *t =new Texto() ;
    a = this->texto.consultarPalavra(p); 
    if(a!=-1)
    {
        t->adcLista(this->texto.percorreTexto(a-1).getPalavra());
        cout << "Palavra anterior: "<< this->texto.percorreTexto(a-1).getPalavra() <<" | Palavra seguinte:" << this->texto.percorreTexto(a+1).getPalavra();
        t->adcLista(this->texto.percorreTexto(a+1).getPalavra());
    }
    return t;
}

bool Corretor::adicionarPalavraDic(Palavra palavra){
    
        return (dicionario.getRaiz()->insere1(palavra));
}

bool Corretor::apresentarErro(Palavra palavra, Arvore *p){
    if(!p->consulta1(palavra))
        return true;
    
    else
        return false;
    
}

Texto Corretor::getTexto()
{
    return(this->texto);
}
Dicionario Corretor::getDicionario()
{
    return(this->dicionario);
}
void Corretor::setTexto(Texto t)
{
    this->texto = t;
}
void Corretor::setDicionario(Dicionario d)
{
    this->dicionario = d;
}
void Corretor::nomeArquivo(string s)
{
    this->dicionario.setArquivo(s);
}
void Corretor::nomeTexto(string s)
{
    this->texto.setArquivo(s);
}
void Corretor::carregarTexto()
{
    this->texto.carregarTexto();
}

void Corretor::corrigirPalavra(Palavra palavra){
    
    Palavra *aux = new Palavra[10000];
    aux = this->palavrasSemelhantes(palavra);
    
    string selecionada = this->selecionarPalavra(aux);
    
   this->texto.alterarPalavra(palavra.getPalavra(), selecionada);
    
}

string Corretor::selecionarPalavra(Palavra *vet){
   int posicao;
   cin >> posicao;
  
   string novaPalavra = vet[posicao - 1].getPalavra(); 
   
   return novaPalavra;
}

void Corretor::gravarTexto(string s)
{
    this->texto.gravarTexto(s);
}