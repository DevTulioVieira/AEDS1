#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>

using namespace std;

typedef struct Endereco{
    char rua[30];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char cep[30];
};

typedef struct Cadastro{
    char nome[30];
    Endereco endereco;
    float salario;
    char identidade[15];
    char cpf[15];
    char estadoCivil[8];
    char telefone[15];
    int idade;
    char sexo;
};

int main(){
    Cadastro cadastrar[2];
    int maior_idade, i;
    char maior[30];
    char identidade[15];
    for(i=0; i<2; i++){
        cout<<"Digite o nome: \n";
        cin.getline(cadastrar[i].nome, 30);
        cout<<"Digite a rua: \n";
        cin.getline(cadastrar[i].endereco.rua, 30);
        cout<<"Digite o bairro: \n";
        cin.getline(cadastrar[i].endereco.bairro, 30);
        cout<<"Digite a cidade: \n";
        cin.getline(cadastrar[i].endereco.cidade, 30);
        cout<<"Digite o estado: \n";
        cin.getline(cadastrar[i].endereco.estado, 30);
        cout<<"Digite o CEP: \n";
        cin.getline(cadastrar[i].endereco.cep, 30);
        cout<<"Digite o salario: \n";
        cin>>cadastrar[i].salario;
        cin.ignore();
        cout<<"Digite a identidade: \n";
        cin.getline(cadastrar[i].identidade, 15);
        cout<<"Digite o CPF: \n";
        cin.getline(cadastrar[i].cpf, 15);
        cout<<"Digite o Estado Civil: \n";
        cin.getline(cadastrar[i].estadoCivil, 15);
        cout<<"Digite o telefone: \n";
        cin.getline(cadastrar[i].telefone, 15);
        cout<<"Digite a idade: \n";
        cin>>cadastrar[i].idade;
        cout<<"Digite o sexo: \n";
        cin>>cadastrar[i].sexo;
        cin.ignore();
    }

    cin.getline(identidade, 15);

    maior_idade = cadastrar[0].idade;

    for(i=0; i<2; i++){
        if(cadastrar[i].idade>maior_idade){
            maior_idade = cadastrar[i].idade;
            cout<<"O maior idade é: ";
            strcpy(maior, cadastrar[i].nome);
        }
        if (cadastrar[i].sexo=='m' || cadastrar[i].sexo=='M'){
            cout<<"Sexo Masculino: ";
            cout<<cadastrar[i].nome<<"\n";
        }
        if (cadastrar[i].salario>1212.0){
            cout<<"O que tem um salario maior que 1212,00: ";
            cout<<cadastrar[i].nome<<"\n";
        }
        if (strcmp(cadastrar[i].identidade, identidade)==0){
            cout<<"Identidade igual: ";
            cout<<cadastrar[i].nome<<"\n";
        }
    }
    cout<<maior;
}