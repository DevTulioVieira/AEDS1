#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
 
using namespace std;

typedef struct registro{
  char titulo[30];
  char categoria[15];
  char autor[20];
  char editora[15];
  int numPag, ano;
};


int main(){
  registro livro[5];
  int i;

  for(i=0; i<5; i++){
    cout<<"Digite o título: \n";
    cin.getline(livro[i].titulo, 30);
    cout<<"Digite a categoria: \n";
    cin.ignore();
    cin.getline(livro[i].categoria, 15);
    // cout<<"Digite o autor: \n";
    // cin.ignore();
    // cin.getline(livro[i].autor, 20);
    // cout<<"Digite a editora: \n";
    // cin.ignore();
    // cin.getline(livro[i].editora, 15);
    // cout<<"Digite a quantidade de páginas: \n";
    // cin>>livro[i].numPag;
    // cout<<"Digite o ano: \n";
    // cin>>livro[i].ano;
  }
  
  cout<<"Digite o titulo do livro: \n";
  cin.ignore();
  cin.getline(livro[5].titulo, 30);

  for(i=0; i<5; i++){
    if(strcmp(livro[i].titulo, livro[5].titulo)==0){
      cout<<"Titulo: "<<livro[i].titulo<<"\n";
      cout<<"Categoria: "<<livro[i].categoria<<"\n";
      cout<<"Autor: "<<livro[i].autor<<"\n";
      cout<<"Editora: "<<livro[i].editora<<"\n";
      cout<<"Quantidade de páginas: "<<livro[i].numPag<<"\n";
      cout<<"Ano: "<<livro[i].ano<<"\n";
    }
  }
}
