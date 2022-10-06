#include <iostream>

using namespace std;

typedef struct PILHA{
    int codigo[10];
    float distancia[10];
}Pilha;

void enchervetor(Pilha *vetor){
    int i;
    for(i=0; i<10; i++){
        cout<<"\nDigite um numero: ";
        cin>>vetor->distancia[i];
        vetor->codigo[i]=i;
    }
}

void mostra(Pilha *vetor){
    int i;
    for(i=0; i<10; i++){
        cout<<vetor->codigo[i]<<endl;
        cout<<vetor->distancia[i]<<endl;
    }
}

void ordena(Pilha *vetor){
    int i, j, aux, troca;
    for(i=0 ; i<10-1 ; i++)
        for(j=i+1 ; j<10 ; j++){
            aux=vetor->distancia[i];
            troca=vetor->codigo[i];

            if(vetor->distancia[j]>vetor->distancia[i]){
                vetor->distancia[i]=vetor->distancia[j];
                vetor->distancia[j] = aux;

                vetor->codigo[i]=vetor->codigo[j];
                vetor->codigo[j] = troca;
            }
        }

}

int main(){

    Pilha P1;
    cout<<"Enche pilha: \n";
    enchervetor(&P1);
    cout<<"Mostra: \n";
    mostra(&P1);
    cout<<"Ordena: \n";
    ordena(&P1);
    cout<<"Mostra: \n";
    mostra(&P1);

}