#include <iostream>
#include <cstdlib>
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
//LingProg buscar();
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
            default:
                cout << "Escolha uma opcao valida" << endl;
                break;
        }
    }while(op != 0);
    
    
    system("pause");
    return 0;
}

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
    cin >> op;
    return op;
}   

void inserir(){
    LingProg novo;                                              // criando uma variavel do tipo LingProg para atribuir no arquivo
    // Abrindo arquivo em modo de leitura
    fstream arquivo("dados.dat", ios::binary | ios::in | ios::out );      //Abrindo arquivo ( modo binario, falando que so se pode acrecentar ) ios::binary|ios::append
        
    
    if(!arquivo){                   // Testa se arquivo contem erro    
        cerr << "arquivo não pode ser aberto para gravacao" << endl;
        return;
    }
    // Atribuindo valores a struct LingProg (linguagem de programacao)
    cout << "|Nome: ";              // nome da linguagem
    cin.ignore();
    cin.getline(novo.nome, 20);     // para pegar todo o conteudo daquela linha, com essa quantidade de caracteres 
    
    cout << "|Ano de Criacao: ";    // Ano de criacao                   // para contornar possiveis erros com caracteres anteriores
    cin >> novo.anoCriacao;
    
    cout << "|Ultimo Acesso: ";     // Ultimo acceso que teve, para possiveis modificacoes
    cin >> novo.ultimoAcesso;
    
    cout << "|versao: ";            // Versao atual
    cin >> novo.versao;
    
    cout << "|autor: ";             // Autor da linguagem
    cin.ignore();
    cin.getline(novo.autor, 20);
    
    cout << "|Tipo: ";              // Tipo;  exemplos: Funcional, lógica, imperativa, POO, etc...
    cin.getline(novo.tipo, 12);     // perde o 1º caracter da linha ao inserir
    
    novo.ativo = true;
    
    arquivo.seekp(posInsercao());
    arquivo.write((const char *)&novo, sizeof(LingProg));    // Escrita em arquivo binario, mandando a referencia do obj e o tamanho
    cout << "|-------------------------------------------------------|" << endl;
    
    arquivo.close();                //fechando o arquivo que foi aberto
}

void listar(){
    ifstream arquivo("dados.dat",ios::binary);
    arquivo.seekg(0);
    LingProg dados;
    
    while(arquivo.read((char *)&dados, sizeof(LingProg))){
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

void remove(){
    LingProg dado;
    fstream arquivo("dados.dat", ios::binary | ios::in | ios::out);
    arquivo.seekg(0);
    arquivo.seekp(0);
    
    char nome[20];
    cout << "Digite o nome da Linguagem a ser removida" <<endl;
    cin.ignore();
    cin.getline(nome, 20);
    
    int pos = 0;
    while(arquivo.read((char *)&dado, sizeof(LingProg))){
        if(strcmp(dado.nome, nome) == 0)
            break;
        ++pos;
    }
    if((strcmp(dado.nome, nome) == 0) and (dado.ativo)){
        dado.ativo = false;
        arquivo.seekp(pos * sizeof(LingProg));
        arquivo.write((const char *)&dado, sizeof(LingProg));
    }
    else
        cout << "Linguagem nao foi encontrada" << endl;
    arquivo.close();
}

//void buscar(){
    //LingProg dado;
    
    //ifstream arquivo("dados.dat", ios::binary);
    //arquivo.seekg(0);
    //char nome[20];
    //cout << "Digite o nome da Linguagem a ser removida" <<endl;
    //cin.ignore();
    //cin.getline(nome, 20);
    
    //int pos = 0;
    //while(arquivo.read((char *)&dado, sizeof(LingProg))){
        //if(strcmp(dado.nome, nome) == 0){
            //cout << "|Nome: " << dado.nome << endl
                 //<< "|Ano De Criacao: " << dado.anoCriacao << endl
                 //<< "|Ultimo Acesso: " << dado.ultimoAcesso << endl
                 //<< "|Versao: " << dado.versao << endl
                 //<< "|Autor: " << dado.autor << endl
                 //<< "|Tipo: " << dado.tipo << endl
                 //<< endl; 
        //}
        //++pos;
    //}
    
//}



// quando implementar se registro ta ativo ou nao

int posInsercao(){
        
    ifstream arquivo("dados.dat",ios::binary);      // Abre o arquivo no modo leitura
    arquivo.seekg(0);                               // posicao de leitura no inicio arquivo
    
    LingProg elementos;                             // Variavel do tipo criado ( LingProg)
    int pos=0;                                      // Variavel verificador de posicao
    
    while(arquivo.read((char *)&elementos, sizeof(LingProg))){
        if(!elementos.ativo){                        //  quando encontra um elemento excluido anteriormente
            break;
        }
    ++pos;
    }
    arquivo.close();
    return pos * int(sizeof(LingProg));
}











