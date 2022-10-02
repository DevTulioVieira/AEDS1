#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

typedef struct Pessoa{
    char nome[30];
    char endereco[50];
    char telefone[10];
};

int main(){
    int i, j;
    Pessoa pes[5], aux[1];

    for(i=0; i<5; i++){
        cout << "Digite o nome: \n";
        cin >> pes[i].nome;
        cout << "Digite o endereco: \n";
        cin >> pes[i].endereco;
        cout << "Digite o telefone: \n";
        cin >> pes[i].telefone;
    }

    Pessoa aux1;

    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if(strcmp(pes[j + 1].nome, pes[j].nome)<0){
                aux1 = pes[j];
                pes[j] = pes[j+1];
                pes[j+1] = aux1;
            }
        }
    }

    for(i=0; i<5; i++){
        cout <<"Nome: " << pes[i].nome<<"\n";
        cout <<"Endereco: " << pes[i].endereco<<"\n";
        cout <<"Telefone:" << pes[i].telefone<<"\n";
    }
}
