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
         << "|   Lembresse de colocar a extensao no nome do arquivo  |" << endl
         << "| > ";
}


// Menu para informar as opcoes ao usuario
int menu(){
    int op;
    cout << "|-------------------------------------------------------|" << endl
         << "|                         MENU                          |" << endl   
         << "|-------------------------------------------------------|" << endl
         << "|[1] - Inserir nova l                                         |" << endl
         << "|[2] - remover                                          |" << endl
         << "|[3] - listar                                           |" << endl
         << "|[4] - buscar linguagem                                 |" << endl
         << "|[5] - Transferir dados para um aruivo ordenado         |" << endl
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
    char nome[20];
    cin.getline(nome,20);
    cout << "|-------------------------------------------------------|" << endl;
    
    // Variavel da classe CLP;
    CLP cadastro(nome);
    //cfd
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
                cout << "| - Transferir dados -" << endl;
                cadastro.transfere();
                break;
            default:
                cout << "| - Escolha uma opcao valida -" << endl;
                break;
        }
    }while(op != 0);
    
    return 0;
}
