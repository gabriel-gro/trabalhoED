#include <iostream>

using namespace std;

class Conjunto{
private:
	int tamVetor;
	int* elementos;
	int qntElementos;
public:
	Conjunto(int tamVet = 10);
	~Conjunto();
	//Funções obrigatórias
	bool VerificaExistencia(int elemento);
	void AdicionaElemento(int elemento);
	void RemoveElemento(int elemento);
	int TamanhoConjunto();
	void ImprimeConjunto();
	Conjunto& operator+(Conjunto B);
	Conjunto& operator-(Conjunto B);
	Conjunto& operator*(Conjunto B);
	//Funções extras
	bool Vazio();
	bool Cheio();
};

Conjunto::Conjunto(int tamVet){
	tamVetor = tamVet;
	elementos = new int[tamVetor];
	qntElementos = 0;
}

Conjunto::~Conjunto(){
	delete[] elementos;
	tamVetor = 0;
	qntElementos = 0;
}

bool Conjunto::VerificaExistencia (int elemento){
	for (int i = 0; i < qntElementos ; i++){
		if (elementos[i] == elemento)
			return true;
	}
	return false;
}

void Conjunto::AdicionaElemento (int elemento){
	if (VerificaExistencia(elemento)){
		// cout << "Elemento já existe! \nConjunto não modificado \n";
	}else if (Cheio()){
		cout << "Conjunto cheio!" << endl;
	}else{
		// cout << "Inserindo elemento " << elemento << " na posicao: " << qntElementos << endl;
		elementos[qntElementos] = elemento;
		qntElementos++;
	}
}

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
	}else{
		cout << "Elemento não está no conjunto!" << endl;
	}
}
		


int Conjunto::TamanhoConjunto(){
	return qntElementos;
}

void Conjunto::ImprimeConjunto(){
	if (!Vazio()){
		for (int i = 0; i < qntElementos; i++){
			cout << elementos[i] << " ";
		}
		cout << endl;
	}
}

bool Conjunto::Vazio(){
	return (qntElementos == 0);
}

bool Conjunto::Cheio(){
	return (qntElementos == tamVetor);
}

Conjunto& Conjunto::operator+(Conjunto B){
	Conjunto* result = new Conjunto;
	for (int i = 0; i < this->qntElementos; i++){
		result->AdicionaElemento(this->elementos[i]);
	}
	for (int i = 0; i < B.qntElementos; i++){
		result->AdicionaElemento(B.elementos[i]);
	}
	return *result;
}

Conjunto& Conjunto::operator-(Conjunto B){
	Conjunto* result = new Conjunto;
	for (int i = 0; i < this->qntElementos; i++){
		for (int j = i; j < B.qntElementos; j++){
			if (this->elementos[i] == B.elementos[j]){
				result->AdicionaElemento(this->elementos[i]);
			}
		}
	}
	return *result;
}

Conjunto& Conjunto::operator*(Conjunto B){
	Conjunto* result = new Conjunto;
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
	

int main(){
	Conjunto A,B;
	A.AdicionaElemento(1);
	A.AdicionaElemento(2);
	A.AdicionaElemento(3);
	A.AdicionaElemento(4);
	A.AdicionaElemento(3);
	A.ImprimeConjunto();
	A.RemoveElemento(2);
	A.ImprimeConjunto();
	cout << A.TamanhoConjunto() << endl;
	/*B.AdicionaElemento(3);
	B.AdicionaElemento(4);
	B.AdicionaElemento(5);
	B.ImprimeConjunto();
	cout << A.VerificaExistencia(2) << endl;
	cout << B.VerificaExistencia(1) << endl;
	cout << A.TamanhoConjunto() << endl;
	cout << B.TamanhoConjunto() << endl;
	/*Conjunto Uniao = A + B; 
	cout << "IMPRIMINDO UNIAO" << endl;
	Uniao.ImprimeConjunto();
	Conjunto Inter = A - B;
	cout << "IMPRIMINDO INTER" << endl;
	Inter.ImprimeConjunto();
	Conjunto Diferenca = A * B;
	cout << "IMPRIMINDO DIF" << endl;
	Diferenca.ImprimeConjunto();*/
	return 0;
}
	
	
	



