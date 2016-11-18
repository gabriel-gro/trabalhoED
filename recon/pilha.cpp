/*
 Lista de Exercícios Avaliativa de Estrutura de Dados
 Professor joaguim Uchoa e Juliana Greghi
 Copyright 2016 by Gabriel Oliveira and Eduardo Lima
 recon.cpp - Contém o main e inserção de dados;
 pilha.cpp - Implementação da pilha junto com o método de verificação da linguagem;
 Conujnto.h - Header da classe pilha 
 Implementação do reconhecedor de uma sentença dentro de uma lingaugem;
*/

#include <iostream>
#include <cstdlib>
#include "pilha.h"

//construtor da excecao
excecao::excecao(TipoExcecao t){ //construtor da excecao
	tipo = t;
}

//Define a mensagem que vai ser entregue na excecao;
string excecao::msg(){
	stringstream stream;
	stream << endl << "Ocorreu um problema: ";
	switch (tipo){
		case DifCont:
			stream << endl << "A quantidade de caracteres A é diferente da quantidade de B";
			break;
		case ContZero:
			stream << endl << "Para que a sentença seja válida, é necessário que exista caracteres A e B.";
			break;
		case LinguagemInvalida:
			stream << endl << "A sentença não obdece a ordem dos caracteres! ";
			break;
	}
	stream << endl << "A sequencia de caracteres NÃO faz parte do conjunto de sentanças da linguagem!:(" << endl;
	return stream.str();
}

//Construtor da pilha
Pilha::Pilha(){
	top = NULL;
}

//Destrutor da pilha;
Pilha::~Pilha(){
	while(top != NULL){
		RemoveElemento();
	}
}

//Adiciona elementos na pilha
void Pilha::AdicionaElemento(char letra){
	noh* novo = new noh;
	novo->letra = letra;
	novo->proximo = top; 
	top = novo;
}


//Método para verificar se a sentença é valida
bool Pilha::VerificarValidade(int contA, int contB, int contC){ //Pega a quantidade de caracteres de A, B e C
	if (contA == contB and contA > 0 and contB > 0){ //Para q seja válida, a quantidade de caracteres de A deve ser igual a de B e maiores que zero
		noh* aux = top; //Cria um noh que irá percorrer a pilha conferindo a validade
		while(aux->letra == 'B'){ //Verifica enquanto a letra for B
			if (contC > 0 and aux->proximo->letra == 'A'){ //Se o contC for maior que 0, então existe C na pilha. Se o próximo elemento for A, teremos um erro.
				throw excecao(LinguagemInvalida); //Chama exceção
				return false; //Retorna que não é uma sentença válida
			}
			aux = aux->proximo; //Vai para o próximo da pilha;
		}
		if (contC > 0){  //Verifica se existe C dentro pilha
			while(aux->letra == 'C'){ //Vai percorrer todas as letras C do pilha;
				if (aux->proximo->letra == 'B'){ //Se em algum momento a próxima letra for B, teremos um erro.
					throw excecao(LinguagemInvalida); //Chama exceção
					return false; //retorna que não é uma sentença válida;
				}
				aux= aux->proximo; //vai pra o próximo;
			}
		}
		while (aux->letra == 'A'){ //Percorre todas as letras A da pilha
			if (aux->proximo == NULL){ //Se em algum momento chegar a NULL será considerada um sentença válida;
				return true;
			}else if (aux->proximo->letra == 'B' or aux->proximo->letra == 'C'){ //Se a próxima letra for B ou C, será considerada uma sentença inválida
				throw excecao(LinguagemInvalida); //Chama exceção
				return false; //Retorna falso
			}else{
			aux = aux->proximo; // vai para o próximo;
			}
		}
	}else{
		if (contA!=contB){ //Se a quantidade de caracteres A for diferente da quantidade de caracteres de B, será uma sentença inválida;
			throw excecao(DifCont); // chama exceção;
		}else if (contA == 0 or contB == 0){ //Se não existir caracter A nem B, será uma sentença inválida
			throw excecao(ContZero); //chama exceção;
		}
	}
	return false; //retorna falso se não cumpre as condições do IF na linha 62;
}

void Pilha::RemoveElemento(){ //método pra auxiliar no destrutor;
	top = top->proximo;
}
