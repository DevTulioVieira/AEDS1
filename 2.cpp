#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    FILE *arq;
    int x=1, result;
    char nome[100];
    char num[100];
    // char str="\t";

    arq = fopen("Planilha.xls", "wt");

    if(arq == NULL){
        cout<<"Erro ao abrir arquivo!";
    }else{
        fputs("Nome\tNumero\n", arq);
        while(x!=2){
            cout<<"\nInsina um nome: ";
            cin.ignore();
            cin.getline(nome, 100);
            fputs(nome, arq);
            cout<<"\nInsira o telefone:(Somente numeros) ";
            cin.getline(num, 100);
            fputs("\t", arq);
            fputs(num, arq);
            fputs("\n", arq);
            cout<<"\n1. Insiri novo dado: ";
            cout<<"\n2. sair:             \n";
            cin>>x;
            system("cls");
        }
    }
    
    fclose(arq);
}