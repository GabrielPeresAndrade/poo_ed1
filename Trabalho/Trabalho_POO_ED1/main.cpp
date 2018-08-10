/* File:   main.cpp
 * Author: Gabriel Peres
 * Created on 8 de Maio de 2018, 22:48
 */
#include <iostream>
#include <cstdlib>
#include "Corretor.h"

using namespace std;

int main(int argc, char** argv) 
{
    int opc;
    int num;
    int num2;
    char r;
    
    Corretor *c = new Corretor();
    cout << "******BEM VINDO A SAMUEL'S DRIFT******" << endl << endl<< "******TRABALHO INTEGRADO P00 ED******"<< endl<< endl;
    cout << "Digite o nome do Arquivo contendo o Dicionario (\"Dic.txt\"):"<< endl <<"-";
    string nome;
    cin >> nome;
    try{
        c->nomeArquivo(nome);
        cout << "Carregando..."<< endl;
        c->getDicionario().lerArquivo(c->getDicionario().getRaiz());
        cout << "Carregado com Sucesso"<< endl;
        cout << "Digite o nome do Arquivo do Texto (\"exemplo.txt\")"<< endl <<"-";
        cin >> nome;
        c->nomeTexto(nome);
        cout << "Carregando..."<< endl;
        c->carregarTexto();
        cout << "Carregado com Sucesso"<< endl<<endl; 
    }catch(Excecao i)
    {
        i.Msg();
        return (0);
    }
    while(1)
    {   
        r=getchar();
        r=getchar();
        c->listarErros();
        cout << "Os Erros encontrados no seu arquivo foram: "<<endl<<"Num | Palavra (Ocorrencia)"<<endl;
        c->mostrarErros();
        cout << "O que gostaria de fazer:" << endl<<"(1) Adicionar Palavra ao Dicionario"<<endl<<"(2) Ignorar um Erro"<<endl<<"(3) Corrigir Manualmente"<<endl<<"(4) Mostrar Palavras Semelhantes"<<endl<<"(5) Apresentar Contexto de uma Palavra"<<endl<<"(6) Gravar no Texto e Sair"<<endl<<"-";
        try
        {
            cin >> opc;
            switch(opc)
            {
           
                case 1:
                    cout << "Digite o numero da Palavra"<<endl<<"-";
                    cin>> num;
                    if(c->adicionarPalavraDic(c->recuperaPalavra(num))==1)
                    {
                        //adicionou
                        cout << "add";
                        c->ignorarErro(num);
                    }
                    else
                    {
                        //nao adicionou
                        cout << "nao add";
                    }
                    break;
                case 2:
                    cout << "Digite o numero da Palavra"<<endl<<"-";
                    cin>> num;
                    c->ignorarErro(num);
                    break;
                case 3:
                    cout << "Digite o numero da Palavra"<<endl<<"-";
                    cin>> num;
                    cout << "Digite a correção"<<endl<<"-";
                    cin>> nome;
                    c->corrigirManualmente(c->recuperaPalavra(num),nome);
                    c->ignorarErro(num);
                    break;
                case 4:
                    cout << "Digite o numero da Palavra"<<endl<<"-";
                    cin>> num;
                    if (c->corrigirPalavra(c->recuperaPalavra(num))==1)
                    {
                        c->ignorarErro(num);
                    }
                    break;
                case 5:
                    cout << "Digite o numero da Palavra"<<endl<<"-";
                    cin>> num;
                    c->apresentarContexto(c->recuperaPalavra(num));
                    break;      
                case 6:
                    cout << "Digite o nome do Texto para Gravar o Texto"<<endl<<"-";
                    cin>> nome;
                    c->gravarTexto(nome);
                    cout << "BYE BYE"<<endl;
                    return(0);
                    break;
            }
        }catch(Excecao i)
        {
            i.Msg();
            return (0);
        }
    }
    return(0);
}
