/*
 Lista de Exercícios Avaliativa de Estrutura de Dados
 Professor joaguim Uchoa e Juliana Greghi
 Copyright 2016 by Gabriel Oliveira and Eduardo Lima
 tadConjuntos.cpp - Contém o main e funções para o menu;
 Conjunto.cpp - Implementação dos métodos da classe Conjunto;
 Conujnto.h - Header da classe Conjunto; 
 Implementação da estrutura de dados do tipo conjunto(Set);
*/


#include <iostream>
#include <cstdlib>
#include "Conjunto.h"

using namespace std;

excecao::excecao(TipoExcecao t, int l){
	tipo = t;
	linha = l;
}

string excecao::msg(){
	stringstream stream;
	stream << "Ocorreu um problema: ";
	switch(tipo){
		case opConjuntoVazio:
			stream << "Você tentou realizar uma operação com um conjunto vazio ";
			break;
		case conjuntoCheio:
			stream << "Você está tentando adicionar elementos em um conjunto que está cheio! ";
			break;
	}
	return stream.str();
 }

//Contrutor.
Conjunto::Conjunto(){
	tamVetor = 10;
	elementos = new int[tamVetor];
	qntElementos = 0;
}

Conjunto::Conjunto(int tamVet){
	tamVetor = tamVet;
	elementos = new int[tamVet];
	qntElementos = 0;
}
//Construtor de cópia
Conjunto::Conjunto(const Conjunto &conj){
	tamVetor = conj.tamVetor;
	qntElementos = conj.qntElementos;
	elementos = new int[tamVetor];
	for (int i = 0; i < tamVetor; ++i){
		elementos[i] = conj.elementos[i];
	}
}

//Destrutor
Conjunto::~Conjunto(){
	delete[] elementos;
	tamVetor = 0;
	qntElementos = 0;
}

//Verifica se o elemento existe no conjunto;
bool Conjunto::VerificaExistencia (int elemento){
	for (int i = 0; i < qntElementos ; i++){
		if (elementos[i] == elemento)
			return true;
	}
	return false;
}
  
//Adiciona elemento no conjunto;
void Conjunto::AdicionaElemento (int elemento){
	if (VerificaExistencia(elemento)){
		return;
	}else if (Cheio()){
		throw excecao(conjuntoCheio,__LINE__);
	}else{
		elementos[qntElementos] = elemento;
		qntElementos++;
	}
}

//Remove elemento do conjunto
void Conjunto::RemoveElemento (int elemento){
	if (VerificaExistencia(elemento)){
		for (int i = 0; i < qntElementos; i++){
			if (elemento == elementos[i]){
				elementos[i] = 0;
				int pos = i;
				while (pos != qntElementos){
					int aux = elementos[pos];
					elementos[pos] = elementos[pos+1];
					elementos[pos+1] = aux;
					pos++;
				}
				qntElementos--;
			}
		}
	}
}

//Retorna o tamanho do conjunto;		
int Conjunto::TamanhoConjunto(){
	return qntElementos;
}

//Imprime o conjunto;
void Conjunto::ImprimeConjunto(){
	if (!Vazio()){
		for (int i = 0; i < qntElementos; i++){
			cout << elementos[i] << " ";
		}
	}
}

//Verifica se o conjunto esta vazio
bool Conjunto::Vazio(){
	return (qntElementos == 0);
}

//Verifica se o conjunto esa cheio
bool Conjunto::Cheio(){
	return (qntElementos == tamVetor);
}

//Retorna a união de dois conjuntos;
Conjunto& Conjunto::operator+(Conjunto B){
	Conjunto* result = new Conjunto;
	if (Vazio() or B.Vazio()){
		throw excecao(opConjuntoVazio,__LINE__);
	}
	for (int i = 0; i < this->qntElementos; i++){
		result->AdicionaElemento(this->elementos[i]);
	}
	for (int i = 0; i < B.qntElementos; i++){
		result->AdicionaElemento(B.elementos[i]);
	}
	return *result;
}

//Retorna a intersecao de dois conjuntos;
Conjunto& Conjunto::operator-( Conjunto B){
	Conjunto* result = new Conjunto;
	if (Vazio() or B.Vazio()){
		throw excecao(opConjuntoVazio,__LINE__);
	}
	for (int i = 0; i < this->qntElementos; i++){
		for (int j = 0; j < B.qntElementos; j++){
			if (this->elementos[i] == B.elementos[j]){
				result->AdicionaElemento(this->elementos[i]);
			}
		}
	}
	return *result;
}

//Retorna a diferenca de dois conjuntos;
Conjunto& Conjunto::operator*(Conjunto B){
	Conjunto* result = new Conjunto;
	if (Vazio() or B.Vazio()){
		throw excecao(opConjuntoVazio,__LINE__);
	}
	for (int i = 0; i < this->qntElementos; i++){
		bool existe = false;
		for (int j = 0; j < B.qntElementos ; j++){
			if (this->elementos[i] == B.elementos[j]){
				existe = true;
			}
		}
		if (!existe){
			result->AdicionaElemento(this->elementos[i]);
		}
	}
	return *result;
}