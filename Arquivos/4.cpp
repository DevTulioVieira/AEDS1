#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

int main(){
    FILE *arq;
    int x=0, i, j, nu, aux=0, cancela=0;
    char* num;
    string nome="";

    srand(time(0));

    arq = fopen("PlanilhaMatriz.xls", "wt");

    if(arq == NULL){
        cout<<"Erro ao abrir arquivo!";
    }else{
        while(cancela==0){
            cout<<"\ntamanho da matriz: ";
            cin>>i;
            aux=i-1;
            while(x<(i*i)){
                
                nu=rand()%100;
                nome=nome+to_string(nu);
                num = &nome[0];
                fputs(num, arq);
                fputs("\t", arq);
                if(aux==0){
                    fputs("\n", arq);
                    aux=i;
                }
                aux--;
                nome="";
                x++;
            }
            cancela=1;
        }
    }
    
    fclose(arq);
}