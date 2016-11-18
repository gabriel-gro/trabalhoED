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
#include "pilha.h"

using namespace std;

void introducao(){ // Introdução para auxiliar o usuário;
	cout << "------------------------------------------" << endl;
	cout << "               INTRODUÇÃO                 " << endl;
	cout << "------------------------------------------" << endl;
	cout << "* Esse programa irá verificar a validade de uma lingaugem." << endl;
	cout << "* Para essa lingaugem ser considerada valida ela deve: " << endl;
	cout << "   -Seguir a ordem de inserção A-C-B" << endl;
	cout << "   -Quantidade de caracteres de A deve ser igual a de B" << endl;
	cout << "   -A Quantidade de caracteres de A e B deve ser maiores que zero" << endl;
	cout << "   -A quantodade de caracteres de C dever maior OU IGUAL a zero!" << endl;
}


int main(){
	introducao(); //chama introdução
	int verificador; //Verificador que será usado no final para o usuário reiniciar ou sair do programa
	do{
		cout << endl << endl;
		cout << "Digite um conjunto de letras para realizar a verificação: " << endl;
		cout << "Para parar o programa, digite qualquer letra diferente de A,B e C " << endl << endl;
		char letra;
		cin >> letra;
		Pilha rec; //Cria a pilha;
		int contA=0,contB=0,contC=0; //Contadores pra auxiliar na verificação da linguagem posteriormente
		while (letra == 'A' or letra == 'B' or letra == 'C'){ //Incrementa o contador das letras;
			if (letra == 'A')
				contA++;
			else if (letra == 'B')
				contB++;
			else
				contC++;
			rec.AdicionaElemento(letra); //Adiciona a letra; 
			cin >> letra; //Pede a nova letra
		}
		try{
			if (rec.VerificarValidade(contA,contB,contC)){ //Retorna a validade da sentença
				cout << endl << endl;
				cout << "A sequencia de caracteres faz parte do conjunto de sentenças da lingaugem!:) " << endl;
			}
		}catch (excecao e){ //Pega qualquer exceção que tenha ocorrido dentro do método;
			cerr << e.msg() << endl;
		}
		cout << endl << endl;
		//Verifica se o usuário quer continuar no programa o sair dele;
		cout << "Se deseja sair do programa, digite 0." << endl;
		cout << "Se deseja fazer outra verificação, digite qualquer número." << endl;
		cin >> verificador;
	}while(verificador!=0);

	return 0;

}