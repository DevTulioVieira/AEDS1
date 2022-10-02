#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

typedef struct Casado{
    char nome[30];
    char sexo;
    int idade;
};

typedef struct Solteiro{
    char nome[30];
    char sexo;
    int idade;
};

int main(){
    char nome[30];
    char sexo;
    int idade, i, q,Tcasado=0, Tsolteiro=0;
    char Escivil;

    cout<<"Digite a quantidade de pessoas para serem cadastradas: \n";
    cin>>q;

    Casado casados[q];
    Solteiro solteiros[q];

    for(i=0; i<q; i++){
        cout<<"Digite o nome: \n";
        cin.ignore();
        cin.getline(nome, 30);
        cout<<"Digite o sexo: \n";
        cin>>sexo;
        cout<<"Digite a idade: \n";
        cin>>idade;
        cout<<"Digite o estado civil: \n";
        cin>>Escivil;
        cin.ignore();
        if(Escivil=='C' || Escivil=='c'){
            strcpy(casados[Tcasado].nome, nome);
            casados[Tcasado].sexo = sexo;
            casados[Tcasado].idade = idade;
            Tcasado++;
        }
        else{if(Escivil=='S' || Escivil=='s'){
            strcpy(solteiros[Tsolteiro].nome, nome);
            solteiros[Tsolteiro].sexo = sexo;
            solteiros[Tsolteiro].idade = idade;
            Tsolteiro++;
        }
        }
    }

    int TotalHomens=0, TotalMulheres=0;

    for(i=0; i<Tsolteiro; i++){
        cout<<"Solteiro: "<<solteiros[i].nome<<"\n";
        if(solteiros[i].sexo=='M' || solteiros[i].sexo=='m'){
            TotalHomens++;
        }
        if(solteiros[i].sexo=='F' || solteiros[i].sexo=='f'){
            TotalMulheres++;
        }
    }
    cout<<"Total Solteiros: "<< TotalHomens << "\nTotal Solteiras: "<< TotalMulheres<<"\n";

    for(i=0; i<Tcasado; i++){
        cout<<"Casado: \n";
        cout << casados[i].nome;
    }
    cout<<"Total de Casados: "<< Tcasado;
}