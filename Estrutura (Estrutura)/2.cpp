#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
 
using namespace std;

typedef struct registo{
  string marca;
  int ano;
  float preco;
};


int main() {
  float preco;
  registo car[5];
  int i;

  for (i=0; i < 5; i++){
    cout<<"Digite a marca: \n";
    cin>>car[i].marca;
    cout<<"Digite o ano: \n";
    cin>>car[i].ano;
    cout<<"Digite o preço: \n";
    cin>>car[i].preco;
  }
  
  cout<<"Digite o preço desejado: \n";
  cin>>preco;

  for (i=0; i<= 5; i++){
    if (preco>=car[i].preco){
      cout<<"Marca: "<<car[i].marca<<"\n";
      cout<<"Ano: "<<car[i].ano<<"\n";
      cout<<"Preço: "<<car[i].preco<<"\n";
    }
  }
}