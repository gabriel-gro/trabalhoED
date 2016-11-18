/*
 Lista de Exercícios Avaliativa de Estrutura de Dados
 Professor joaguim Uchoa e Juliana Greghi
 Copyright 2016 by Gabriel Oliveira and Eduardo Lima
 recon.cpp - Contém o main e inserção de dados;
 pilha.cpp - Implementação da pilha junto com o método de verificação da linguagem;
 Conujnto.h - Header da classe pilha 
 Implementação do reconhecedor de uma sentença dentro de uma lingaugem;
*/

#ifndef PILHA_H
#define PILHA_H 1
#include <sstream>
#include <string>

using namespace std;

enum TipoExcecao{DifCont, ContZero, LinguagemInvalida}; //Define os tipos de excecoes;

//Declara a classe exceção
class excecao{
private:
	TipoExcecao tipo;
public:
	excecao(TipoExcecao t);
	string msg();
};

//Declara a classe pilha;
class noh{
friend class Pilha;
private:
	char letra;
	noh* proximo;
};

class Pilha{
private:
	noh* top;
public:
	Pilha(); //Construtor da pilha
	~Pilha(); //Desctrutor da pilha
	void AdicionaElemento(char letra); //Método para adicionar noh's na prilha
	bool VerificarValidade(int contA, int contB, int contC); //Método para verificar a validade da linguagem
	void RemoveElemento(); //Método para remover elementos (usado no destrutor);
};

#endif
