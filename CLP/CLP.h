/*
 Lista de Exercícios Avaliativa de Estrutura de Dados
 Professor joaguim Uchoa e Juliana Greghi
 Copyright 2016 by Gabriel Oliveira and Eduardo Lima
 CLPmain.cpp - Contém o main e inserção de dados;
 CLP.cpp - Implementação do CLP com uma estrutura para facilitar a insercao de um novo registro
 CLP.h - Header da classe pilha 
 Implementação de um cadastro de linguagens de programacao(C.L.P);
*/

#ifndef CLP_H
#define CLP_H 1

#include <iostream>
#include <sstream> 
#include <string>

using namespace std;

enum TipoExcecao{arqOff}; //Define os tipos de excecoes;

//Declara a classe exceção
class excecao{
private:
    TipoExcecao tipo;
public:
    excecao(TipoExcecao t);
    string msg();
};

// Estrutura de um registro Tipo: LingProg
typedef struct{
    char nome[20];
    int anoCriacao;
    int ultimoAcesso;
    int versao;
    char autor[20];
    char tipo[12];
    bool ativo;
}LingProg;

// Declara a classe CLP
class CLP{
    private:
        char nomeArq[20];                               // Nome arquivo a ser trabalhado
    public:
        CLP(const char nome[20]);                       // Construtor da classe
        bool arqExiste(const char nome[15]);            // Verificao se existe o arquivo com o nome especificado
        int posInsercao();                              // Verifica e retorna a posicao de insercao
        void inserir();                                 // Insercao de um novo registro
        void listar();                                  // Listagem de todos registro no arquivo(nomeArq)
        void listar(const char nome[20]);               // Listar todos registros de um arquivo externo
        void remove();                                  // Remover = Indicar que um registro nao esta mais ativo
        void buscar();                                  // Busca um registro pelo nome
        void transfere();                               // Transfere todos registro desse arquivo para outro de modo ordenado
        unsigned int quantRegistros();                  // Me indica a quantidade de registros, ativos, contidos no arquivo
        void insereOrdem(LingProg dados, int op);       // Insere um novo registro no arquivo de modo ordenado
        void deletar();                                 // Deleta todos dados de um arquivo
        
};

#endif
