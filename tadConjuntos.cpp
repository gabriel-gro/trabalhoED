#include <iostream>
#include <cstdlib>

using namespace std;

class Conjunto{
private:
	int tamVetor; //Tamanho do vetor (10 por padrão)
	int* elementos; //"Vetor" de elementos
	int qntElementos; //Quantidade de elementos válidos no vetor.
public:
	Conjunto(); //Construtor.
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

//Contrutor.
Conjunto::Conjunto(){
	tamVetor = 10;
	elementos = new int[tamVetor];
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
	}else if (Cheio()){
		cout << "Conjunto cheio!" << endl;
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
	}else{
		cout << "Elemento não está no conjunto!" << endl;
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
Conjunto& Conjunto::operator+(const Conjunto B){
	Conjunto* result = new Conjunto;
	for (int i = 0; i < this->qntElementos; i++){
		result->AdicionaElemento(this->elementos[i]);
	}
	for (int i = 0; i < B.qntElementos; i++){
		result->AdicionaElemento(B.elementos[i]);
	}
	return *result;
}

//Retorna a intersecao de dois conjuntos;
Conjunto& Conjunto::operator-(const Conjunto B){
	Conjunto* result = new Conjunto;
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
Conjunto& Conjunto::operator*(const Conjunto B){
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

//Breve explanação do programa
void introducao(){
	cout << "|---------------------------------------------|" << endl;
	cout << "|                 Introducao                  |" << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "Neste programa voce ira trabalhar com os conjuntos A, B e C (Por hora estão vazios!)(O conjunto cabe 10 elementos!) \n\n. Voce pode adicionar e remover elementos e fazer operacoes descritas no menu!" << endl; 
}

//Menu principal do programa
int menuPrincipal(){
	cout << "|---------------------------------------------|" << endl;
	cout << "|                    MENU                     |" << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "|Digte o numero da opcao desejada:            |" << endl;
	cout << "|1 - Adicionar elemento em algum conjunto     |" << endl;
	cout << "|2 - Remover elemento do algum Conjunto       |" << endl;
	cout << "|3 - Verificar se existe elemento no Conjunto |" << endl;
	cout << "|4 - Verificar tamanho atual do Conjunto      |" << endl;
	cout << "|5 - Imprimir  Conjunto                       |" << endl;
	cout << "|6 - Imprimir Uniao de dois Conjuntos         |" << endl;
	cout << "|7 - Imprimir a intersecao de dois Conjuntos  |" << endl;
	cout << "|8 - Imprimir a diferenca de dois Conjuntos   |" << endl;
	cout << "|0 - Sair do programa                         |" << endl;
	cout << "----------------------------------------------|" << endl;
	int opcao;
	cin >> opcao;
	return opcao;
}

// **************** SUB-MENUS DERIVADOS DO MENU PRINCIPAL ***************************;

int menuAdicionarElementos(){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     1 - Adicionar elemento em algum conjunto     |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "|Em qual conjunto você deseja adicionar elementos ?|" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                    |" << endl;
    cout << "|2 - Conjunto B                                    |" << endl;
    cout << "|3 - Conjunto C                                    |" << endl;
    cout << "|0 - Sair desse menu                               |" << endl;
    cout << "|--------------------------------------------------|" << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

int menuRemoverElementos(){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     2 - Remover elemento em algum conjunto       |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "|Em qual conjunto você deseja remover elementos ?  |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                    |" << endl;
    cout << "|2 - Conjunto B                                    |" << endl;
    cout << "|3 - Conjunto C                                    |" << endl;
    cout << "|0 - Sair desse menu                               |" << endl;
    cout << "|--------------------------------------------------|" << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

int menuVerificaElementos(){
	cout << "|------------------------------------------------------|" << endl;
	cout << "|3 - Verificar se o elemento existe em algum conjunto  |" << endl;
	cout << "|------------------------------------------------------|" << endl; 
	cout << "|Em qual conjunto você deseja verificar a existencia de|" << endl;
	cout << "|elementos?                                            |" << endl;                                           
	cout << "|------------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                        |" << endl;
    cout << "|2 - Conjunto B                                        |" << endl;
    cout << "|3 - Conjunto C                                        |" << endl;
    cout << "|0 - Sair desse menu                                   |" << endl;
    cout << "|------------------------------------------------------|" << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

int menuTamanhoConjunto(){
	cout << "|----------------------------------------------------- |" << endl;
	cout << "|      4 - Verificar tamanho atual do Conjunto         |" << endl;
	cout << "|------------------------------------------------------|" << endl; 
	cout << "|Qual conjunto você deseja verificar o tamanho?        |" << endl;                            
	cout << "|------------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                        |" << endl;
    cout << "|2 - Conjunto B                                        |" << endl;
    cout << "|3 - Conjunto C                                        |" << endl;
    cout << "|0 - Sair desse menu                                   |" << endl;
    cout << "|------------------------------------------------------|" << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

int menuImpressao(){
	cout << "|----------------------------------------------------- |" << endl;
	cout << "|               5 - Imprimir Conjunto                  |" << endl;
	cout << "|------------------------------------------------------|" << endl; 
	cout << "|Qual conjunto você deseja imprimir?                   |" << endl;                            
	cout << "|------------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                        |" << endl;
    cout << "|2 - Conjunto B                                        |" << endl;
    cout << "|3 - Conjunto C                                        |" << endl;
    cout << "|0 - Sair desse menu                                   |" << endl;
    cout << "|------------------------------------------------------|" << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

void menuUniaoElementos(Conjunto A, Conjunto B, Conjunto C){
	cout << "|-----------------------------------------------------------|" << endl;
	cout << "|         6 - Imprimir a Uniao de dois Conjuntos            |" << endl;
	cout << "|-----------------------------------------------------------|" << endl; 
	cout << "|Digite os numeros dos dois conjuntos que voce deseja unir: |" << endl;
	cout << "|-----------------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                             |" << endl;
    cout << "|2 - Conjunto B                                             |" << endl;
    cout << "|3 - Conjunto C                                             |" << endl;
    cout << "|0 - Sair desse menu                                        |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
   int op1, op2;
    cin >> op1 >> op2;
    Conjunto S;
    if (op1 == 1 and op2 == 2){
    	S = A+B;
    	cout << "UNIÃO = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 1 and op2 == 3){
    	S = A+C;
    	cout << "UNIÃO = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 2 and op2 == 1){
   		S = B+A;
    	cout << "UNIÃO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 2 and op2 == 3){
   		S = B+C;
    	cout << "UNIÃO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 3 and op2 == 1){
   		S = C+A;
    	cout << "UNIÃO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 3 and op2 == 2){
   		S = C+B;
    	cout << "UNIÃO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 0 or op2 == 0){
    	return;
   	}else{
   		cout << "Opcao Invalida" << endl;
   	}
   	return;
}

void menuIntersecaoElementos(Conjunto A, Conjunto B, Conjunto C){
	cout << "|-----------------------------------------------------------------------|" << endl;
	cout << "|              6 - Imprimir a intersecao de dois Conjuntos              |" << endl;
	cout << "|-----------------------------------------------------------------------|" << endl; 
	cout << "|Digite os numeros dos dois conjuntos que voce deseja ver a intersecao: |" << endl;
	cout << "|-----------------------------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                                         |" << endl;
    cout << "|2 - Conjunto B                                                         |" << endl;
    cout << "|3 - Conjunto C                                                         |" << endl;
    cout << "|0 - Sair desse menu                                                    |" << endl;
    cout << "|-----------------------------------------------------------------------|" << endl;
   int op1, op2;
    cin >> op1 >> op2;
    if (op1 == 1 and op2 == 2){
    	Conjunto S = A-B;
    	cout << "INTERSECAO = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 1 and op2 == 3){
    	Conjunto S = A-C;
    	cout << "INTERSECAO = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 2 and op2 == 1){
   		Conjunto S = B-A;
    	cout << "INTERSECAO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 2 and op2 == 3){
   		Conjunto S = B-C;
    	cout << "INTERSECAO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 3 and op2 == 1){
   		Conjunto S = C-A;
    	cout << "INTERSECAO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 3 and op2 == 2){
   		Conjunto S = C-B;
    	cout << "INTERSECAO = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 0 or op2 == 0){
    	return;
   	}else{
   		cout << "Opção invalida" << endl;
   	}
   	return;
}

void menuDiferencaElementos(Conjunto A, Conjunto B, Conjunto C){
	cout << "|-----------------------------------------------------------------------|" << endl;
	cout << "|              6 - Imprimir a diferenca de dois Conjuntos               |" << endl;
	cout << "|-----------------------------------------------------------------------|" << endl; 
	cout << "|Digite os numeros dos dois conjuntos que voce deseja ver a diferenca : |" << endl;
	cout << "|-----------------------------------------------------------------------|" << endl; 
	cout << "|1 - Conjunto A                                                         |" << endl;
    cout << "|2 - Conjunto B                                                         |" << endl;
    cout << "|3 - Conjunto C                                                         |" << endl;
    cout << "|0 - Sair desse menu                                                    |" << endl;
    cout << "|-----------------------------------------------------------------------|" << endl;
   int op1, op2;
    cin >> op1 >> op2;
    if (op1 == 1 and op2 == 2){
    	Conjunto S = A*B;
    	cout << "DIFERENCA = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 1 and op2 == 3){
    	Conjunto S = A*C;
    	cout << "DIFERENCA = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 2 and op2 == 1){
   		Conjunto S = B*A;
    	cout << "DIFERENCA = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 2 and op2 == 3){
   		Conjunto S = B*C;
    	cout << "DIFERENCA = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 3 and op2 == 1){
   		Conjunto S = C*A;
    	cout << "DIFERENCA = ";
    	S.ImprimeConjunto();
    	cout << endl;
   	}else if (op1 == 3 and op2 == 2){
   		Conjunto S = C*B;
    	cout << "DIFERENCA = ";
    	S.ImprimeConjunto();
    	cout << endl;
    }else if (op1 == 0 or op2 == 0){
    	return;
   	}else{
   		cout << "Opção invalida" << endl;
   	}
   	return;
}

// ***************** FUNÇÕES INDIVIDUAIS DOS SUB-MENUS VOLTADA PARA CADA CONJUNTO ***********************

void menuAdicionarElementosA(Conjunto* A){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     1 - Adicionando elementos no conjunto A      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para adicionar no conjunto A     |" << endl;
	cout << "| Para sair, adicione o elemento -999              |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		A->AdicionaElemento(elemento);
		cin >> elemento;
	}
}

void menuAdicionarElementosB(Conjunto* B){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     2 - Adicionando elementos no conjunto B      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para adicionar no conjunto B     |" << endl;
	cout << "| Para sair, adicione o elemento -999              |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		B->AdicionaElemento(elemento);
		cin >> elemento;
	}
}

void menuAdicionarElementosC(Conjunto* C){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     3 - Adicionando elementos no conjunto C      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para adicionar no conjunto C     |" << endl;
	cout << "| Para sair, adicione o elemento -999              |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		C->AdicionaElemento(elemento);
		cin >> elemento;
	}
}

void menuRemoverElementosA(Conjunto* A){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     1 - Adicionando elementos no conjunto A      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para remover no conjunto A       |" << endl;
	cout << "| Para sair, remova o elemento -999                |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		A->RemoveElemento(elemento);
		cin >> elemento;
	}
}

void menuRemoverElementosB(Conjunto* B){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     2 - Adicionando elementos no conjunto B      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para remover no conjunto B       |" << endl;
	cout << "| Para sair, remova o elemento -999                |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		B->RemoveElemento(elemento);
		cin >> elemento;
	}
}

void menuRemoverElementosC(Conjunto* C){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     3 - Adicionando elementos no conjunto C      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para remover no conjunto C       |" << endl;
	cout << "| Para sair, remova o elemento -999                |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		C->RemoveElemento(elemento);
		cin >> elemento;
	}
}

void menuVerificaElemenntosA(Conjunto* A){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     1 - Verificando elementos no conjunto A      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para verificar no conjunto A se  |" << endl;
	cout << "| ele existe no conjunto.                          |" << endl;
	cout << "| Para sair, adicione o elemento -999              |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		if(A->VerificaExistencia(elemento))
			cout << "O ELEMENTO EXISTE EM A" << endl;
		else
			cout << "O ELEMENTO NAO EXISTE EM A" << endl;
		cin >> elemento;
	}
}

void menuVerificaElemenntosB(Conjunto* B){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     2 - Verificando elementos no conjunto B      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para verificar no conjunto B se  |" << endl;
	cout << "| ele existe no conjunto.                          |" << endl;
	cout << "| Para sair, adicione o elemento -999              |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		if(B->VerificaExistencia(elemento))
			cout << "O ELEMENTO EXISTE EM B" << endl;
		else
			cout << "O ELEMENTO NAO EXISTE EM B" << endl;
		cin >> elemento;
	}
}

void menuVerificaElemenntosC(Conjunto* C){
	cout << "|--------------------------------------------------|" << endl;
	cout << "|     3 - Verificando elementos no conjunto C      |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	cout << "| Digite o numero para verificar no conjunto C se  |" << endl;
	cout << "| ele existe no conjunto.                          |" << endl;
	cout << "| Para sair, adicione o elemento -999              |" << endl;
	cout << "|--------------------------------------------------|" << endl; 
	int elemento;
	cin >> elemento;
	while (elemento != -999){
		if(C->VerificaExistencia(elemento))
			cout << "O ELEMENTO EXISTE EM C" << endl;
		else
			cout << "O ELEMENTO NAO EXISTE EM C" << endl;
		cin >> elemento;
	}
}

void menuTamanhoConjuntoA(Conjunto* A){
	cout << "|----------------------------------------------------|" << endl;
	cout << "|            1 - Tamanho do conjunto A               |" << endl;
	cout << "|----------------------------------------------------|" << endl; 
	cout << " O tamanho do conjunto A é " << A->TamanhoConjunto() << endl << endl;
}

void menuTamanhoConjuntoB(Conjunto* B){
	cout << "|----------------------------------------------------|" << endl;
	cout << "|            2 - Tamanho do conjunto B               |" << endl;
	cout << "|----------------------------------------------------|" << endl; 
	cout << " O tamanho do conjunto B é " << B->TamanhoConjunto() << endl << endl;
}

void menuTamanhoConjuntoC(Conjunto* C){
	cout << "|----------------------------------------------------|" << endl;
	cout << "|            3 - Tamanho do conjunto C               |" << endl;
	cout << "|----------------------------------------------------|" << endl; 
	cout << " O tamanho do conjunto C é " << C->TamanhoConjunto() << endl << endl;
}

void menuImpressaoA(Conjunto* A){
	cout << "|----------------------------------------------------|" << endl;
	cout << "|            1 - Imprimindo o conjunto A             |" << endl;
	cout << "|----------------------------------------------------|" << endl; 
	cout << " *** "; 
	A->ImprimeConjunto();
	cout << " *** " << endl;
}

void menuImpressaoB(Conjunto* B){
	cout << "|----------------------------------------------------|" << endl;
	cout << "|            2 - Imprimindo o conjunto B             |" << endl;
	cout << "|----------------------------------------------------|" << endl; 
	cout << " *** "; 
	B->ImprimeConjunto();
	cout << " *** " << endl;
}

void menuImpressaoC(Conjunto* C){
	cout << "|----------------------------------------------------|" << endl;
	cout << "|            3 - Imprimindo o conjunto C             |" << endl;
	cout << "|----------------------------------------------------|" << endl; 
	cout << " *** "; 
	C->ImprimeConjunto();
	cout << " *** " << endl;
}




int main(){
	introducao(); // Chama a introdução para o usuário;
	Conjunto A, B, C; //Cria três conjuntos para o usuário modificar;
	int op;
	do{
		op = menuPrincipal(); // Chama o menu principal
		switch(op){
			case 0: // Sai do programa;
				break;
			case 1: // Adiciona Elementos
				int opAdicionar;
				do{
					opAdicionar = menuAdicionarElementos();
					switch(opAdicionar){  //Escolhe em qual conjunto vai adicionar
						case 0:
							break;
						case 1:
							menuAdicionarElementosA(&A);
							break;
						case 2:
							menuAdicionarElementosB(&B);
							break;
						case 3:
							menuAdicionarElementosC(&C);
							break;
						default:
							cout << "Por favor, digite um numero que esteja dentro das opcoes disponiveis!!" << endl;
							break;
					}
				}while(opAdicionar != 0);	
				break;
			case 2: //Remover elementos
				int opRemover;
				do{
					opRemover = menuRemoverElementos();
					switch(opRemover){ //Escolhe em qual conjunto vai remover;
						case 0:
							break;
						case 1:
							menuRemoverElementosA(&A);
							break;
						case 2:
							menuRemoverElementosB(&B);
							break;
						case 3:
							menuRemoverElementosC(&C);
							break;
						default:
							cout << "Por favor, digite um numero que esteja dentro das opcoes disponiveis!!" << endl;
							break;
					}
				}while(opAdicionar != 0);	
				break;
			case 3: //Verifica se tal elemento existe no conjunto
				int opVerifica;
				do{
					opVerifica = menuVerificaElementos();
					switch(opVerifica){ //Escolhe em qual conjunto vai verificar;
						case 0:
							break;
						case 1:
							menuVerificaElemenntosA(&A);
							break;
						case 2:
							menuVerificaElemenntosB(&B);
							break;
						case 3:
							menuVerificaElemenntosC(&C);
							break;
						default:
							cout << "Por favor, digite um numero que esteja dentro das opcoes disponiveis!!" << endl;
							break;
					}
				}while(opAdicionar != 0);	
				break;
			case 4: //Opção para retornar o tamanho
				int opTamanho;
				do{
					opTamanho = menuTamanhoConjunto();
					switch(opTamanho){ //Escolhe qual conjunto quer ver o tamanho;
						case 0:
							break;
						case 1:
							menuTamanhoConjuntoA(&A);
							break;
						case 2:
							menuTamanhoConjuntoB(&B);
							break;
						case 3:
							menuTamanhoConjuntoC(&C);
							break;
						default:
							cout << "Por favor, digite um numero que esteja dentro das opcoes disponiveis!!" << endl;
							break;
					}
				}while(opTamanho != 0);	
				break;
			case 5: //Opção para imprimir o conjunto
				int opImpressao;
				do{
					opImpressao = menuImpressao();
					switch(opImpressao){ // Escolhe qual conjunto vai imprimir;
						case 0:
							break;
						case 1:
							menuImpressaoA(&A);
							break;
						case 2:
							menuImpressaoB(&B);
							break;
						case 3:
							menuImpressaoC(&C);
							break;
						default:
							cout << "Por favor, digite um numero que esteja dentro das opcoes disponiveis!!" << endl;
							break;
					}
				}while(opImpressao != 0);	
				break;
			case 6: //Realiza a união de elementos
				menuUniaoElementos(A,B,C);
				break;
			case 7: //Realiza a intersecao de elementos
				menuIntersecaoElementos(A,B,C);
				break;
			case 8: //Realiza a diferenca de elementos
				menuDiferencaElementos(A,B,C);
				break;
			default:
				cout << "Por favor, digite um numero que esteja dentro das opcoes disponiveis!!" << endl;
				break;
		}
	}while (op!= 0);
	return 0;
}	
	
