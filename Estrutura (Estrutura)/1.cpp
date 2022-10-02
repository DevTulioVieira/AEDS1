#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
 
using namespace std;

typedef struct registro{
  char Nome[100];
  int idade;
  char sex;
  string cpf;
  string data;
  int codigo;
  string cargo;
  float salario;
};


int main(){
  registro func;
  cout<<"Digite seu nome: \n";
  cin.getline(func.Nome, 100);
  cout<<"Digite sua idade: \n";
  cin>>func.idade;
  cout<<"Digite seu sexo: \n";
  cin>>func.sex;
  cout<<"Digite seu CPF: \n";
  cin>>func.cpf;
  cout<<"Digite sua data de nascimento: \n";
  cin>>func.data;
  cout<<"Digite seu código do setor: \n";
  cin>>func.codigo;
  cout<<"Digite seu cargo: \n";
  cin>>func.cargo;
  cout<<"Digite seu salário: \n";
  cin>>func.salario;

  cout<<"Nome: \n"<<func.Nome;
  cout<<"Idade: \n"<<func.idade;
  cout<<"Sexo: \n"<<func.sex;
  cout<<"CPF: \n"<<func.cpf;
  cout<<"Data de nascimento: \n"<<func.data;
  cout<<"Código: \n"<<func.codigo;
  cout<<"Cargo: \n"<<func.cargo;
  cout<<"Salario: \n"<<func.salario;
}