#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <bitset>
#include <string>

using namespace std;

string binario(int a){
    string str;
    while (a != 0){
        str+=(a%2==0 ? "0" : "1" );
        a /= 2;
    }
    return str;
}

int main(){

    FILE *arq;
    int x=0, a;
    char* num;
    string nome;


    arq = fopen("teste.txt", "wt");

    if(arq == NULL){
        cout<<"Erro ao abrir arquivo!";
    }else{
        while(x<10){

            cout<<"Insira o numero: ";
            cin>>a;
            nome=binario(a);
            num = &nome[0]; // É só isso?
            fputs(num, arq);
            fputs("\n", arq);

            x++;
        }
    }

    fclose(arq);
}