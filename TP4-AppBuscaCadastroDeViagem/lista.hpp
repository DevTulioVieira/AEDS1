#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

using namespace std;


typedef struct linhaLista{
    int codigo;
    int num;
    char nome[100];
    struct paradaLista *primeiro;
    struct linhaLista *prox;
}linha;

typedef struct LinhaLista{
    linha *inicio;
    linha *fim;
}LLista;

typedef struct paradaLista{
    int codigo;
    double valorP;
    string horaP;
    char local[100];
    struct paradaLista *prox, *ant;
}parada;

typedef struct ParadaLista{
}PLista;

void limpar();

int menu();

int menu2();

int login();

void inicializarLinha(LLista *lista);

int inserirLinha(LLista *lis, PLista *lista);

void deletaLinha(LLista *lista, int cod);

void mostralinha(LLista *lista);

void inserirParada(LLista *lis, PLista *lista, int x, int local);

void mostraParada(LLista *lis, PLista *lista, int x);

void alteraParada(LLista *lis, PLista *lista, int x, int local);

void removerParada(LLista *lis, PLista *lista, int x, int local);

void procuraViagem(LLista *lis, PLista *lista, string saida, string destino);

#endif