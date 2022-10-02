#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

typedef struct Filme
{
    char titulo[30];
    char genero[30];
    int duracao;
    int ano;
};

void Comedia(Filme filmes[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(filmes[i].genero, "Comedia") == 0)
        {
            cout << filmes[i].titulo << endl;
        }
    }
}

int main()
{
    Filme filmes[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Digite o titulo: ";
        cin.getline(filmes[i].titulo, 30);
        cout << "Digite o genero: ";
        cin.getline(filmes[i].genero, 30);
        cout << "Digite a duracao: ";
        cin >> filmes[i].duracao;
        cout << "Digite o ano: ";
        cin >> filmes[i].ano;
        cin.ignore();
    }

    Comedia(filmes);

    return 0;
}