#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stack>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

int main(){
    int opcao, acesso, var, ajuda, local;
    string saida, destino;
    char palavra;

    LLista L1;
    PLista P1;
    //inicializa lista
    inicializarLinha(&L1);

    for(;;){//menu de operaçõe
        opcao=menu();//menu para busca ou altera
        switch (opcao){
        case 1:
            cout<<"Digite o local de partida: ";
            cin>>saida;
            cout<<"Digite o local destino:    ";
            cin>>destino;
            procuraViagem(&L1, &P1, saida, destino);
            break;
        case 2:
            acesso=login();
            if(acesso==0){
                break;
            }
            var=0;
            while(var!=8){
                limpar();
                var=menu2();
                switch (var){//menu proprio de operções do admin
                    case 1:
                        ajuda=inserirLinha(&L1, &P1);
                        ini:
                        system("pause");
                        limpar();
                        cout<<"Incluir parada:(s/n): ";
                        cin>>palavra;
                        if(palavra=='s'){
                            limpar();
                            mostraParada(&L1, &P1, ajuda);
                            cout<<"Digite a posicao desejada: ";
                            cin>>local;
                            inserirParada(&L1, &P1, ajuda, local);
                            goto ini;
                        }
                        limpar();
                    break;
                    case 2:
                        cout<<"Insira o codigo da linha: ";
                        cin>>ajuda;
                        inic:
                        cout<<"Incluir parada:(s/n): ";
                        cin>>palavra;
                        if(palavra=='s'){
                            limpar();
                            mostraParada(&L1, &P1, ajuda);
                            cout<<"Digite a posicao desejada: ";
                            cin>>local;
                            inserirParada(&L1, &P1, ajuda, local);
                            system("pause");
                            limpar();
                            goto inic;
                        }
                        system("pause");
                        limpar();
                    break;

                    case 3:
                        cout<<"Insira o codigo da linha: ";
                        cin>>ajuda;
                        mostraParada(&L1, &P1, ajuda);
                        cout<<"Digite a posicao desejada: ";
                        cin>>local;
                        alteraParada(&L1, &P1, ajuda, local);
                        system("pause");
                    break;

                    case 4:
                        cout<<"Insira o codigo da linha: ";
                        cin>>ajuda;
                        mostraParada(&L1, &P1, ajuda);
                        cout<<"Digite a posicao desejada: ";
                        cin>>local;
                        removerParada(&L1, &P1, ajuda, local);
                        system("pause");
                    break;

                    case 5:
                        limpar();
                        mostralinha(&L1);
                        cout<<"Digite o codigo da linha: ";
                        cin>>ajuda;
                        deletaLinha(&L1, ajuda);
                        system("pause");
                    break;

                    case 6:
                        limpar();
                        mostralinha(&L1);
                        system("pause");
                    break;

                    case 7:
                        limpar();
                        cout<<"Insira o codigo da linha: ";
                        cin>>ajuda;
                        mostraParada(&L1, &P1, ajuda);
                        system("pause");
                    break;

                    case 8:
                        var=8;
                    break;
                }
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}