#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct{
    char nome[20];
    int anoCriacao;
    int ultimoAcesso;
    int versao;
    char autor[20];
    char tipo[12];

}LingProg;

class CLP{
    private:
        fstream clp;
    public:
        CLP(const char nomeArq[]);
        ~CLP();
        //inserir(LingProg);
        //remove(LingProg);
        //listar();
        //buscar();
        //transfere( CLP clp02 , opcao);
};

CLP::CLP(const char nomeArq[] = "arqLinguagens.txt"){
    clp.open(nomeArq);
}

CLP::~CLP(){
    clp.close();
}

        
int main(){
    string nome;
    cout << "digite o nome do arquivo a ser aberto/criado" << endl;
    cin >> nome;
    
    CLP 
    
    system ("pause");
    return 0;
}