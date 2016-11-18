#ifndef CONJUNTO_H
#define CONJUNTO_H 1

#include <string>
#include <sstream>

using namespace std;

enum TipoExcecao {opConjuntoVazio,conjuntoCheio};

class excecao{
private:
	TipoExcecao tipo;
	int linha;
public:	
	excecao(TipoExcecao t, int l);
	string msg();
};


class Conjunto{
private:
	int tamVetor; //Tamanho do vetor (10 por padrão)
	int* elementos; //"Vetor" de elementos
	int qntElementos; //Quantidade de elementos válidos no vetor.
public:
	Conjunto(); //Construtor.
	Conjunto(int tamvet);
	Conjunto(const Conjunto &conj); //Construtor de cópia
	~Conjunto(); // Destrutor
	//Funções obrigatórias
	bool VerificaExistencia(int elemento); //Verifica se o elemento existe no Conjunto
	void AdicionaElemento(int elemento); //Adiciona um elemento ao Conjunto
	void RemoveElemento(int elemento); //Remove Elemento do Conjunto
	int TamanhoConjunto(); //Retorna o tamanho do Conjunto
	void ImprimeConjunto(); //Imprime o Conjunto
	Conjunto& operator+(const Conjunto B); //Realiza a União dos conjuntos
	Conjunto& operator-(const Conjunto B); //Realiza a Instersecao de conjuntos
	Conjunto& operator*(const Conjunto B); //Realiza a Diferenca de Conjuntos
	//Funções extras
	bool Vazio(); //Vefifica se está cheio
	bool Cheio(); //Verifica se está vazio


};

#endif