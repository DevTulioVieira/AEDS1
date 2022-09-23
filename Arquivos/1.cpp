#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main(){
    FILE *arq;
    int result;
    char str[50];

    cout<<"Informe o nome do arquivo: ";
    cin>>str;

    arq = fopen(str, "rt");

    if(arq == NULL){
        cout<<"Erro ao abrir arquivo!";
    }else{
        cout<<"Arquivo aberto com sucesso";
    }
}

