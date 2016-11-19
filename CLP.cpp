/*
 Lista de Exercícios Avaliativa de Estrutura de Dados
 Professor joaguim Uchoa e Juliana Greghi
 Copyright 2016 by Gabriel Oliveira and Eduardo Lima
 Arquivo CLP 
 Implementacao de um arquivo binario de linguagem de programacao
*/

#include <iostream>
#include <fstream> 
#include <string.h>

using namespace std;

// Estrutura de um registro Tipo: LingProg
typedef struct{
    char nome[20];
    int anoCriacao;
    int ultimoAcesso;
    int versao;
    char autor[20];
    char tipo[12];
    bool ativo;
}LingProg;

LingProg novoDado(){
    LingProg novo;
    
    // Para contornar possiveis erros com cadeias de caracteres anteriores usei o cin.ignore();
    // Para pegar todo o conteudo daquela linha, com essa quantidade de caracteres usei o cin.getLine(char,int);
    
    // nome da linguagem
    cout << "|Nome: "; 
    cin.ignore();
    cin.getline(novo.nome, 20);  
    
    // Ano de criacao
    cout << "|Ano de Criacao: ";                       
    cin >> novo.anoCriacao;
    
    // Ultimo acceso que teve, para possiveis modificacoes
    cout << "|Ultimo Acesso: ";     
    cin >> novo.ultimoAcesso;
    
    // Versao atual
    cout << "|versao: ";            
    cin >> novo.versao;
    
    // Autor da linguagem
    cout << "|autor: ";             
    cin.ignore();
    cin.getline(novo.autor, 20);
    
    // Tipo;  exemplos: Funcional, lógica, imperativa, POO, etc...
    cout << "|Tipo: ";              
    cin.getline(novo.tipo, 12);
    
    novo.ativo = true;
    
    return novo;
}

void lingImprime(LingProg dados){
    cout << "\n|Nome: " << dados.nome << endl
         << "|Ano De Criacao: " << dados.anoCriacao << endl
         << "|Ultimo Acesso: " << dados.ultimoAcesso << endl
         << "|Versao: " << dados.versao << endl
         << "|Autor: " << dados.autor << endl
         << "|Tipo: " << dados.tipo << endl
         << "|Ativo: "<< dados.ativo << endl
         << endl;
}

class CLP{
    private:
        char nomeArq[20];
    public:
        CLP(const char nome[20]);
        bool arqExiste(const char nome[15]);
        int posInsercao();
        void inserir();
        void listar();
        void remove();
        void buscar();
        void transfere();
        unsigned int quantRegistros();
        void insereOrdem(LingProg dados);
};

// Criando um arquivo binario externo
CLP::CLP(const char nome[] = "dados.dat"){
    fstream arquivo;
    strcpy(nomeArq, nome);
    if(!arqExiste(nomeArq)){
        arquivo.open(nome, ios::binary | ios::out);
        arquivo.close();
    }
    arquivo.open(nome, ios::binary | ios::out | ios::in);
    arquivo.close();
}


// retorna tru caso ja exista, false caso precisa criar
bool CLP::arqExiste(const char nome[15]){
    fstream arquivo;
    arquivo.open(nome, ios::binary | ios::out | ios::in );
    if(arquivo)
        return 1;
    else
        return 0;
}

// funcao posInsercao, retorna um inteiro com a posicao de insercao
// A posicao pode ser um registro antigo inativo, ou a ultima posicao do arquivo
int CLP::posInsercao(){
    // Abre o arquivo no modo leitura E BINARIO
    fstream arquivo;
    arquivo.close();
    arquivo.open(nomeArq,ios::binary | ios::in);    
    
    // posicao de leitura no inicio arquivo  
    arquivo.seekg(0);
    
    // Variavel do tipo criado ( LingProg)
    LingProg elementos;
    
    // Variavel verificador de posicao                            
    int pos=0;
    // Percorre o arquivo verificando registros excluidos
    // Quando encontra um elemento excluido anteriormente ele para neste
    while(( arquivo.read((char *)&elementos, sizeof(LingProg)) ) and ( elementos.ativo ) ){
        ++pos;
    }
    
    // Fecha o arquivo
    arquivo.close();
    
    // Retorna a posicao 
    // Pos * sizeof(o tamanho de LingProg), para ter a posicao exata no arquivo
    return pos * int(sizeof(LingProg));
}

// Insercao sera feita aparti do controle de posicao posIncercao()
void CLP::inserir(){
    fstream arquivo;
    // criando uma variavel do tipo LingProg para inserir no arquivo
    LingProg novo;
    
    novo = novoDado();
    
    //Abrindo arquivo em modo binario, leitura e escrita
    arquivo.open(nomeArq, ios::binary | ios::in | ios::out ); 
        
    // Testa se ocorreu erro na abertura
    if(!arquivo){                      
        cerr << "| Arquivo não pode ser aberto para gravacao" << endl;
        return;
    }
    
    // Atribuindo valores ao arquivo, por struct LingProg (linguagem de programacao)
    
    // Setando posicao de escrita na posicao de insercao
    // posInsercao seta posicao no primeiro inativo, ou por ultimo
    arquivo.seekp(posInsercao());
    
    // Escrita em arquivo binario, mandando a referencia do obj e o tamanho
    arquivo.write((const char *)&novo, sizeof(LingProg));    
    cout << "|-------------------------------------------------------|" << endl;
    
    // Fechar arquivo
    arquivo.close();                
}

// Impressao dos dados do arquivo
void CLP::listar(){
    fstream arquivo;
    //Abertura do arquivo em modo binario e leitura 
    arquivo.close();
    arquivo.open(nomeArq,ios::binary | ios::in);
    
     //Posicao de leitura no inicio  
    arquivo.seekg(0);
    
    
    LingProg dados;
    
     //Teste para continuar rodando enquanto tiver registro do ttamanho LingProg
    while(arquivo.read((char *)&dados, sizeof(LingProg))){                  
         //Para imprimir somente os dados ativos
        //if(dados.ativo){                                                
            cout << "|Nome: " << dados.nome << endl
                 << "|Ano De Criacao: " << dados.anoCriacao << endl
                 << "|Ultimo Acesso: " << dados.ultimoAcesso << endl
                 << "|Versao: " << dados.versao << endl
                 << "|Autor: " << dados.autor << endl
                 << "|Tipo: " << dados.tipo << endl
                 << "|Ativo: "<< dados.ativo << endl
                 << endl; 
        //}
    }
}

  
  
// Remocao de um dado do arquivo por nome da linguagem
void CLP::remove(){
    LingProg dado;
    fstream arquivo;                                                      
    // Abrindo o arquivo em modo: Binario, leitura e escrita
    arquivo.open(nomeArq, ios::binary | ios::in | ios::out);     

    // Modificando posicao do ponteiro de leitura e escrita
    arquivo.seekg(0);
    arquivo.seekp(0);
    
    // variavel a ser pesquisada
    char nome[20];                                                      
    cout << "| Digite o nome da Linguagem a ser removida" <<endl;
    cin.ignore();
    cout << "|> ";
    cin.getline(nome, 20);
    
    // Percorrendo o arquivo para encontrar a linguagem (nome)
    int pos = 0;
    while((arquivo.read((char *)&dado, sizeof(LingProg))) and !(strcmp(dado.nome, nome) == 0)){
        ++pos;
    }
    
    // Se encontrou no arquivo uma linguagem chmada 'Nome', desativo ela
    if((strcmp(dado.nome, nome) == 0) and (dado.ativo)){
        dado.ativo = false;
        arquivo.seekp(pos * sizeof(LingProg));
        arquivo.write((const char *)&dado, sizeof(LingProg));
    }
    // Senao informo o usuario que nao foi encontrada
    else
        cout << "| Linguagem nao foi encontrada" << endl;
    
    // Fecha arquivo
    arquivo.close();
}

// Busca uma linguagem ja cadastrada
void CLP::buscar(){
    //Variavel dado para percorrer o arquivo procurando o registro
    LingProg dado;
    
    // Abertura do arquivo para leitura, em modo binario
    ifstream arquivo(nomeArq, ios::binary);
    
    // Ponteiro de leitura no inicio
    arquivo.seekg(0);
    
    // Linguagem a ser procurada
    char nome[20];
    cout << "| Digite o nome da Linguagem a ser procurada" <<endl;
    cin.ignore();
    cout << "|> ";
    cin.getline(nome, 20);
    
    // Procurando a linguagem especifica
    int pos=0;
    while((arquivo.read((char *)&dado, sizeof(LingProg))) and !(strcmp(dado.nome, nome) == 0)){
        ++pos;
    }
    // Teste se os registro daquela posicao é o procurado e se esta ativo
    if((strcmp(dado.nome, nome) == 0) and (dado.ativo)){
        lingImprime(dado); 
    }
    // Mensagem caso nao encontre a linguagem buscada
    else
        cout <<"|" << nome <<" nao foi encontrada" << endl;
}

void CLP::transfere(){
    CLP novoReg("dadosOrdenados.dat");
    
    fstream arquivo("dados.dat", ios::binary | ios::in);
    arquivo.seekg(0);
    arquivo.seekp(0);
    LingProg dados;
    while(arquivo.read((char *)&dados, sizeof(LingProg))){
        //lingImprime(dados);
        novoReg.insereOrdem(dados);
        //cout << "reg inserido" << endl;
        //cout << arquivo.tellg() << endl;
    }
    
    arquivo.close();
}

void CLP::insereOrdem(LingProg dados){//LingProg dados){
   
    
    fstream arq(nomeArq, ios::binary | ios::in | ios::out);

    LingProg dados2;
    arq.seekp(0);
    arq.seekg(0);
    int posInserir=0;

    while(arq.read((char *)&dados2, sizeof(LingProg)) and (dados.anoCriacao > dados2.anoCriacao)){
        ++posInserir;
    }
    if(!arq){
        cout << "erro\n";
        arq.clear();
    }
    else{
        for (int i = quantRegistros(); i > posInserir ; --i){
            arq.seekg((i-1) * sizeof(LingProg));
            arq.read((char *)&dados2, sizeof(LingProg));
            arq.seekp(i * sizeof(LingProg));
            arq.write((const char *)&dados2, sizeof(LingProg));
        }
    }
    arq.seekp(posInserir * sizeof(LingProg));
    arq.write((const char *)&dados, sizeof(LingProg));
    arq.close();
}

// utilizada para testes, pode se conseguir pos total com quantRegistro * sizeof(LingProg)
unsigned int CLP::quantRegistros(){
    LingProg dado;
    ifstream arq(nomeArq, ios::binary);
    arq.seekg(0);
    int quant=0;
    while(arq.read((char *)&dado, sizeof(LingProg))){
        if(dado.ativo)
            ++quant;
    }
    return quant;
}

//---------------------------------------MAIN-----------------------------------
int menu();

int main()
{
    cout << "|-------------------------------------------------------|" << endl
         << "|      Programa para cadastro e armazenamento de        |" << endl
         << "|              Linguagens de programacao                |" << endl
         << "|-------------------------------------------------------|" << endl;
    CLP cadastro("dadosOrdenados.dat");
    
    int op;
    do{
        op = menu();
        switch(op){
            case 0:
                break;
            case 1:
                cout << "| - Inserir -" << endl;
                cadastro.inserir();
                break;
            case 2:
                cout << "| - Remover -" << endl;
                cadastro.remove();
                break;
            case 3:
                cout << "| - Listar -" << endl;
                cadastro.listar();
                break;
            case 4:
                cout << "| - Buscar -" << endl;
                
                
                cadastro.buscar();
                break;
            case 5:
                //LingProg dados;
                //dados = novoDado();
                //cadastro.insereOrdem(dados); // por enquanto imprime quanti total de registros
                cadastro.transfere();
                break;
            default:
                cout << "| Escolha uma opcao valida" << endl;
                break;
        }
    }while(op != 0);
    
    
    return 0;
};

// Menu para informar as opcoes ao usuario
int menu(){
    int op;
    cout << "|-------------------------------------------------------|" << endl
         << "|                         MENU                          |" << endl   
         << "|-------------------------------------------------------|" << endl
         << "|[1] - Inserir                                          |" << endl
         << "|[2] - remover                                          |" << endl
         << "|[3] - listar                                           |" << endl
         << "|[4] - buscar                                           |" << endl
         << "|[5] - Transferir                                       |" << endl
         << "|[0] - SAIR                                             |" << endl
         << "|-------------------------------------------------------|" << endl; 
    cout << "|> ";
    cin >> op;
    
    // retorna um inteiro informando a opcao escolhida
    return op;
} 
  
