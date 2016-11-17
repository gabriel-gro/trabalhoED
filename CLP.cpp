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

typedef struct{
    char nome[20];
    int anoCriacao;
    int ultimoAcesso;
    int versao;
    char autor[20];
    char tipo[12];
    bool ativo;
}LingProg;

int menu();
void inserir();
void remove();
void listar();
void buscar();
//CLP* transfere(CLP clp02 , opcao);
int posInsercao();


int main()
{
    int op;
    do{
        op = menu();
        switch(op){
            case 0:
                break;
            case 1:
                inserir();
                break;
            case 2:
                remove();
                break;
            case 3:
                listar();
                break;
            case 4:
                buscar();
                break;
            default:
                cout << "| Escolha uma opcao valida" << endl;
                break;
        }
    }while(op != 0);
    
    
    return 0;
}

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
  
// Insercao sera feita aparti do controle de posicao posIncercao()
void inserir(){
    
    // criando uma variavel do tipo LingProg para inserir no arquivo
    LingProg novo;
    
    //Abrindo arquivo em modo binario, leitura e escrita
    fstream arquivo("dados.dat", ios::binary | ios::in | ios::out );      
    
    
    // Testa se ocorreu erro na abertura
    if(!arquivo){                      
        cerr << "| Arquivo não pode ser aberto para gravacao" << endl;
        return;
    }
    
    // Atribuindo valores ao arquivo, por struct LingProg (linguagem de programacao)
    
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
    
    novo.ativo = true;
    
    // Setando posicao de escrita na posicao de insercao
    // posInsercao seta posicao no primeiro inativo, ou por ultimo
    arquivo.seekp(posInsercao());
    
    // Escrita em arquivo binario, mandando a referencia do obj e o tamanho
    arquivo.write((const char *)&novo, sizeof(LingProg));    
    cout << "|-------------------------------------------------------|" << endl;
    
    // Fechar arquivo
    arquivo.close();                
}

//  Impressao dos dados do arquivo
void listar(){
    // Abertura do arquivo em modo binario e leitura 
    ifstream arquivo("dados.dat",ios::binary);
    
    // Posicao de leitura no inicio  
    arquivo.seekg(0);
    
    
    LingProg dados;
    
    // Teste para continuar rodando enquanto tiver registro do ttamanho LingProg
    while(arquivo.read((char *)&dados, sizeof(LingProg))){                  
        // Para imprimir somente os dados ativos
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
void remove(){
    LingProg dado;
                                                          
    // Abrindo o arquivo em modo: Binario, leitura e escrita
    fstream arquivo("dados.dat", ios::binary | ios::in | ios::out);     

    // Modificando posicao do ponteiro de leitura e escrita
    arquivo.seekg(0);
    arquivo.seekp(0);
    
    // variavel a ser pesquisada
    char nome[20];                                                      
    cout << "Digite o nome da Linguagem a ser removida" <<endl;
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
void buscar(){
    //Variavel dado para percorrer o arquivo procurando o registro
    LingProg dado;
    
    // Abertura do arquivo para leitura, em modo binario
    ifstream arquivo("dados.dat", ios::binary);
    
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
        cout << "|Nome: " << dado.nome << endl
             << "|Ano De Criacao: " << dado.anoCriacao << endl
             << "|Ultimo Acesso: " << dado.ultimoAcesso << endl
             << "|Versao: " << dado.versao << endl
             << "|Autor: " << dado.autor << endl
             << "|Tipo: " << dado.tipo << endl
             << endl; 
    }
    // Mensagem caso nao encontre a linguagem buscada
    else
        cout <<"|" << nome <<" nao foi encontrada" << endl;
}

// funcao posInsercao, retorna um inteiro com a posicao de insercao
// A posicao pode ser um registro antigo inativo, ou a ultima posicao do arquivo
int posInsercao(){
    // Abre o arquivo no modo leitura E BINARIO
    ifstream arquivo("dados.dat",ios::binary);    
    
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











