#include "Corretor.h"

Corretor::Corretor() {
    int i;
    for (i = 0 ; i < 10000 ; i++)
    {
        this->erros[i]= NULL ;
    }
    this->qtdErros=0;
}

Corretor::Corretor(const Corretor& orig) {
    Corretor();
    
    this->dicionario.setArquivo(orig.dicionario.getArquivo());
    this->dicionario.setArvore(orig.dicionario.getArvore());
    this->texto = orig.texto;
    this->qtdErros= orig.qtdErros;
    int i;
    for (i = 0 ; i < 10000 ; i++)
    {
        this->erros[i] = new Erros();
        this->erros[i]= orig.erros[i] ;
    }
}

Corretor::~Corretor() {
    int i;
    for (i = 0 ; i < this->qtdErros ; i++)
    {
        delete this->erros[i] ;
    }
    
}

void Corretor::ignorarErro(int numero){
    if (numero==this->qtdErros)
    {
        this->erros[numero]->setOcorrencia(-1);
    }
    for (int i=numero; i < this->qtdErros-1 ;i++)
    {
        this->erros[i]->setPalavra(this->erros[i+1]->getPalavra());
        this->erros[i]->setOcorrencia(this->erros[i+1]->getOcorrencia());
    }
    this->qtdErros--;
}
void Corretor::mostrarErros(){
    for (int i=0; i < this->qtdErros ;i++)
    {
        if (this->erros[i]->getOcorrencia()!= -1)
        cout<< i << " | " << this->erros[i]->getPalavra().getPalavra()<< " ( " << this->erros[i]->getOcorrencia()<< " )" <<endl; 
    }
}
void Corretor::listarErros()
{
    for(int i=0; i<this->texto.getContador(); i++)
    {
        try{
            
            //verifica se cada palavra esta na arvore
            if(!this->dicionario.getArvore()->consulta(this->texto.percorreTexto(i)))
            {
                //se nao tiver
                int j;
                int flag=0;
                for(j = 0; ((j < this->qtdErros) && (flag==0)); j++)
                {
                    //verifica se o erro ja existe
                    if(this->erros[j]->getPalavra().getPalavra()==this->texto.percorreTexto(i).getPalavra())
                    {
                        flag=1;
                        this->erros[j]->setOcorrencia(this->erros[j]->getOcorrencia()+1);
                    }
                }
                if(flag==0)
                {
                    //nao existe esse erro
                    if (this->erros[this->qtdErros] == NULL)
                        this->erros[this->qtdErros] = new Erros();

                    this->erros[this->qtdErros]->setPalavra(this->texto.percorreTexto(i));
                    this->erros[this->qtdErros]->setOcorrencia(1);
                    this->qtdErros++;
                }

            }
        }catch(Excecao i)
        {
            throw(i);
        }
    }
}

Palavra *Corretor::palavrasSemelhantes(Palavra p)
{
    int *posix = new int();   
   *posix=0;
   Palavra *vet = new Palavra[10000];
   this->dicionario.getArvore()->colocarSubArvoreEmVetor(this->dicionario.getArvore()->getRaiz(),p,vet,posix);
   for(int ai=0; ai<*posix;ai++)
   {
    cout << "("<<ai<<") "<<vet[ai].getPalavra()<<" | ";
  }
   delete posix;
   return(vet);
}
Texto *Corretor::apresentarContexto(Palavra p)
{
    int a;
    Texto *t =new Texto() ;
    a = this->texto.consultarPalavra(p);
    if(this->texto.getContador()-1==a)
    {
        try
        {
            t->adcLista(this->texto.percorreTexto(a-1).getPalavra());
        cout << "Palavra anterior: "<< this->texto.percorreTexto(a-1).getPalavra()<<endl;
        }catch(Excecao i)
        {
            throw(i);
        }
        return t;
    }
    if(0==a)
    {
        try
        {
            cout << "Palavra seguinte:" << this->texto.percorreTexto(a+1).getPalavra()<<endl;
            t->adcLista(this->texto.percorreTexto(a+1).getPalavra());
        }catch(Excecao i)
        {
            throw(i);
        }
        return t;
    }
    if(a!=-1)
    {
        try{
            
            t->adcLista(this->texto.percorreTexto(a-1).getPalavra());
            cout << "Palavra anterior: "<< this->texto.percorreTexto(a-1).getPalavra() <<" | Palavra seguinte:" << this->texto.percorreTexto(a+1).getPalavra()<<endl;
            t->adcLista(this->texto.percorreTexto(a+1).getPalavra());
        }catch(Excecao i)
        {
            throw(i);
        }
    }
    return t;
}

bool Corretor::adicionarPalavraDic(Palavra palavra){
    
        return (dicionario.getArvore()->insere(palavra));
}

bool Corretor::apresentarErro(Palavra palavra, Arvore *p){
    if(!p->consulta(palavra))
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
    try
    {
        this->texto.carregarTexto();
    }catch(Excecao i)
    {
        throw(i);
    }
    
}

int Corretor::corrigirPalavra(Palavra palavra){
    
    Palavra *aux = new Palavra[10000];
    try{
        aux = this->palavrasSemelhantes(palavra);
        if (aux[0].getPalavra()[0]=='\0')
            return (-1);
    }catch(Excecao i)
    {
        throw(Excecao(i));
    }
    try{
        string selecionada = this->selecionarPalavra(aux);
        if (selecionada == "")
                return 0;
       this->texto.alterarPalavra(palavra.getPalavra(), selecionada);
        delete aux;
    }catch(Excecao i)
    {
        throw(i);
    }
   return 1;
    
}

string Corretor::selecionarPalavra(Palavra *vet){
   int posicao;
   cout << endl << "Digite o número da palavra desejada para substituir o erro ('-1' para nao corrigir):";
   cin >> posicao;
   if (posicao==-1)
       return "";
   int tam;
   for(int i=0;i<10000;i++)
       if(vet[i].getPalavra()!="")
           tam=i+1;
   if (posicao>tam)
   {
       throw(Excecao(ErroDeMemoria));
   }
   string novaPalavra = vet[posicao - 1].getPalavra(); 
   
   return novaPalavra;
}

void Corretor::gravarTexto(string s)
{
    try
    {
        this->texto.gravarTexto(s);
    }catch(Excecao i)
    {
        throw(i);
    }
}

void Corretor::corrigirManualmente(Palavra p,string palavra)
{
    this->texto.alterarPalavra(p.getPalavra(),palavra);
}
Palavra Corretor::recuperaPalavra(int num)
{
    return this->erros[num]->getPalavra();
}