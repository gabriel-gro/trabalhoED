#include <iostream>

using namespace std;

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
	Pilha();
	~Pilha();
	void AdicionaElemento(char letra);
	bool VerificarValidade(int contA, int contB, int contC);
	void ImprimePilha();
	void RemoveElemento();
	bool Vazio();

};

Pilha::Pilha(){
	top = NULL;
}

Pilha::~Pilha(){
	while(top != NULL){
		RemoveElemento();
	}
}

void Pilha::AdicionaElemento(char letra){
	noh* novo = new noh;
	novo->letra = letra;
	novo->proximo = top; 
	top = novo;
}

bool Pilha::VerificarValidade(int contA, int contB, int contC){
	if (contA == contB and contA > 0 and contB > 0){
		noh* aux = top;
		while(aux->letra == 'B'){
			if (contC > 0 and aux->proximo->letra == 'A'){
				return false;
			}
			aux = aux->proximo;
		}
		if (contC > 0){
			while(aux->letra == 'C'){
				if (aux->proximo->letra == 'B'){
					return false;
				}
				aux= aux->proximo;
			}
		}
		while (aux->letra == 'A'){
			if (aux->proximo == NULL){
				return true;
			}else if (aux->proximo->letra == 'B' or aux->proximo->letra == 'C'){
				return false;
			}else{
			aux = aux->proximo;
			}
		}
	}
	return false;
}

void Pilha::ImprimePilha(){
	noh* aux = top;
	while (aux != NULL){
		cout << aux->letra << " ";
		aux = aux->proximo;	
	}
	cout << endl;
}

void Pilha::RemoveElemento(){
	top = top->proximo;
}

bool Pilha::Vazio(){
	return (top == NULL);
}



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