/*
 Lista de Exercícios Avaliativa de Estrutura de Dados
 Professor joaguim Uchoa e Juliana Greghi
 Copyright 2016 by Gabriel Oliveira and Eduardo Lima
 CLPmain.cpp - Contém o main e inserção de dados;
 CLP.cpp - Implementação do CLP com uma estrutura para facilitar a insercao de um novo registro
 CLP.h - Header da classe pilha 
 Implementação de um cadastro de linguagens de programacao(C.L.P);
*/

#include <iostream>
#include <cstdlib>
#include "CLP.h"

using namespace std;

// Introducao, para o usuario ficar ciente do programa
void intro(){
    cout << "|-------------------------------------------------------|" << endl
         << "|      PROGRAMA PARA CADASTRO E ARMAZENAMENTO DE        |" << endl
         << "|              LINGUAGENS DE PROGRAMACAO                |" << endl
         << "|-------------------------------------------------------|" << endl
         << "| Digite o nome do arquivo de linguagens de programacao |" << endl
         << "|  Se o nomo nao existir, sera criado um novo arquivo   |" << endl
         << "|  Lembresse de colocar a extensao no nome do arquivo   |" << endl
         << "|          Ver arquivos na pasta do programa ?          |" << endl
         << "|                [1] - SIM | [0] - NAO                  |" << endl
         << "| > ";
         int op;
         cin >> op;
         if(op==1) system("dir") ;
         cout << "\n| Ditige o nome do arquivo: ";
         
         
}


// Menu para informar as opcoes ao usuario
int menu(){
    int op;
    cout << "|-------------------------------------------------------|" << endl
         << "|                         MENU                          |" << endl   
         << "|-------------------------------------------------------|" << endl
         << "|[1] - Inserir nova linguagem                           |" << endl
         << "|[2] - remover                                          |" << endl
         << "|[3] - listar                                           |" << endl
         << "|[4] - buscar linguagem                                 |" << endl
         << "|[5] - listar registros de outro arquivo                |" << endl
         << "|[6] - Transferir dados para um aruivo ordenado         |" << endl
         << "|[7] - Deletar todos dados desse registro               |" << endl
         << "|[8] - Quntidade de registros existentes neste arquivo  |" << endl
         << "|[9] - Ver nome de arquivos externos na pasta           |" << endl
         << "|[0] - SAIR                                             |" << endl
         << "|-------------------------------------------------------|" << endl; 
    cout << "|> ";
    cin >> op;
    
    // retorna um inteiro informando a opcao escolhida
    return op;
} 

int main(){
    // Introducao
    intro();
    
    // Usuario digita o nome do arquivo a ser criado, lembrando de exstencao
    string nome;
    cin >> nome;
    cout << "|-------------------------------------------------------|" << endl;
    
    // Variavel da classe CLP;
    CLP cadastro(nome.c_str());
    
    int op; 
    do{
        op = menu();
        switch(op){
            case 0:
                break;
            case 1:
                    cout << "| - Inserir -" << endl;
                    cadastro.inserir();
                break;
            case 2:
                cout << "| - Remover -" << endl;
                cadastro.remove();
                break;
            case 3:
                cout << "| - Listar -" << endl;
                cadastro.listar();
                break;
            case 4:
                cout << "| - Buscar -" << endl;
                cadastro.buscar();
                break;
            case 5:
                cout << "| - Listar registros de um arquivo externo -\n";
                cout << "| Digite o nome do arquivo externo:\n>";
                cin >> nome;
                cadastro.listar(nome.c_str());
                break;
            case 6:
                cout << "| - Transferir dados -" << endl;
                cadastro.transfere();
                break;
            case 7:
                cout << "| - Deletar todos reregistros desse arquivo -\n"
                     << "| Tem certeza disso? [1] - NAO | [2] - SIM\n";
                cin >> op;
                if(op==2) cadastro.deletar();
                break;
            case 8:
                cout << "| Existem "<< cadastro.quantRegistros()
                     << " registros neste arquivo \n";
                break;
            case 9:
                system("dir");
                cout << endl;
                break;
            default:
                cout << "| - Escolha uma opcao valida -" << endl;
                break;
        }
    }while(op != 0);
    
    return 0;
}
