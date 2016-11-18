#include <iostream>
#include <cstdlib>
#include "pilha.h"

using namespace std;

int main(){
	cout << "Digite um conjunto de Letras para realizar a verificação: " << endl;
	char letra;
	cin >> letra;
	Pilha rec;
	int contA=0,contB=0,contC=0;
	while (letra == 'A' or letra == 'B' or letra == 'C'){
		if (letra == 'A')
			contA++;
		else if (letra == 'B')
			contB++;
		else
			contC++;
		rec.AdicionaElemento(letra);
		cin >> letra;
	}
	
	if (rec.VerificarValidade(contA,contB,contC)){
		cout << "Válido" << endl;
	}else{
		cout << "Inválido" << endl;
	}

	return 0;

}