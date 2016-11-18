#ifndef PILHA_H
#define PILHA_H 1

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

#endif
