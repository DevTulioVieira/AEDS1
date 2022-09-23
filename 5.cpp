#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream> 

using namespace std;

int main(){

    FILE *arq;
    char *str;
    int soma=0, aux=1, i;
    char linha[80];
    stringstream sst;

    ifstream fin("preco.txt"); 

    if(arq == NULL){
        cout<<"Erro ao abrir arquivo!";
    }else{
       while(fin){
            fin.getline(linha, 80);
            if(aux==2){
                sst<<linha<<endl;
                sst>>i;
                soma+=i;
                aux=1;
            }else{
                aux=2;
            }
       }
    }
    cout<<soma;

}