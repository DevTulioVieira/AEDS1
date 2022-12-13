#include <iostream>
#include <windows.h>
#include <fstream>
#include "lista.hpp"
//funçoes usadas
void limpar(){
    system("cls");
}
//menu
int menu(){
    int x;
    cout<<"BEM VINDO A LINHA DE ONIBUS INTERMUNICIPAL"<<endl;
    cout<<"1.Pesquisa sua viagem"<<endl;
    cout<<"2.Acesse o sistema"<<endl;
    cout<<"3.Sair"<<endl;
    cin>>x;
    limpar();
    return x;
}

int menu2(){
    int x;
    cout<<"||------------------------------||"<<endl;
    cout<<"||1.Adicionar nova linha.       ||"<<endl;
    cout<<"||2.Incluir uma parada.         ||"<<endl;
    cout<<"||3.Alterar uma parada.         ||"<<endl;
    cout<<"||4.Excluir uma parada.         ||"<<endl;
    cout<<"||5.Excluir Linha.              ||"<<endl;
    cout<<"||6.Mostrar todas as Linhas.    ||"<<endl;
    cout<<"||7.Mostrar Paradas.            ||"<<endl;
    cout<<"||8.Sair.                       ||"<<endl;
    cout<<"||------------------------------||"<<endl;
    cout<<"||Qual opcao deseja prosseguir: "; cin>>x;
    
    limpar();
    return x;
}
//void para login com senha
int login(){
    int senha;
    string log;
    limpar();
    cout<<"\t\tPAGINA DE ACESSO"<<endl;
    cout<<"LOGIN:   ";
    cin>>log;
    cout<<"SENHA:   ";
    cin>>senha;
    if(log=="Admin" && senha==1234){
        cout<<endl<<"Acesso permitido"<<endl;
        return 1;
    }
    cout<<endl<<"Acesso negado"<<endl; 
    return 0;
}

void inicializarLinha(LLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}
//cria uma linha
int inserirLinha(LLista *lis, PLista *lista){
    linha *novinho;
    novinho = new linha;

    cout<<"\n\t\t|||CADASTRO DE LINHA|||\n";
    cout<<"\nInforme o numero da linha:        ";
    cin>>novinho->codigo;
    cin.ignore();
    cout<<"Informe o nome da passagem:       ";
    gets(novinho->nome);
    novinho->num=2;
    novinho->prox = NULL;
    
    if(lis->inicio == NULL){
        lis->inicio = novinho;
        lis->fim = novinho;
    }else{
        lis->fim->prox=novinho;
        lis->fim=novinho;
    }
    cout<<"\nAdicionado com sucesso\n";//lista encadeada simples
    system("pause");
    limpar();

    parada *novo, *aux;
    novo = new parada;
    cout<<"Cidade de Saida"<<endl;
    cout<<"\nInforme a hora de saida:            ";
    cin>>novo->horaP;
    cout<<"Informe o valor da passagem:        ";
    cin>>novo->valorP;
    cin.ignore();
    cout<<"Informe o nome da cidade de saida:  ";
    gets(novo->local);
    novo->codigo=novinho->codigo;
    novinho->primeiro=novo;//para saber onde começa a lista duplamente
    
    aux = new parada;

    cout<<"\nCidade destino"<<endl;
    cout<<"Informe a hora de saida:            ";
    cin>>aux->horaP;
    aux->valorP=novo->valorP;
    cin.ignore();
    cout<<"Informe o nome da cidade de saida:  ";
    gets(aux->local);
    aux->codigo=novinho->codigo;
    novo->prox=aux;
    novo->ant=aux;
    aux->prox=novo;
    aux->ant=novo;

    cout<<"Cadastrada!"<<endl;//sempre seram cadastradas 2 cidadde obrigatriamente, afinal precisa de 2 locai para viaja
    return novinho->codigo;
}
//excluir uma linha
void deletaLinha(LLista *lista, int cod){
    linha *anterior, *atual;
    int x=0;

    if(lista->inicio == NULL){
        cout<<"lista vazia!\n";
    }else{
        anterior = lista->inicio;
        atual = lista->inicio;
        while(atual!=NULL){
            if(atual->codigo==cod){
                x=1;
                if(atual->num==0){//para caso n ter nenhuma parada
                    lista->inicio=NULL;
                    atual->codigo=NULL;
                    free(atual);
                    break;
                }
                if(atual == lista->inicio){
                    lista->inicio = lista->inicio->prox;
                    atual->codigo=NULL;
                    free(atual);
                    break;
                }else{
                    if(atual==lista->fim){
                        lista->fim = anterior;
                    }
                    
                    anterior->prox = atual->prox;
                    free(atual);
                    break;
                }
            }else{
                anterior=atual;
                atual = atual->prox;
            }
        }
    }
    if(x==0)
        cout<<"Codigo Invalido!"<<endl;
    else  
        cout<<"Linha deletada"<<endl;  
}
//mostra as linhas de onibus
void mostralinha(LLista *lista){
    linha *aux;
    aux=lista->inicio;
    
    if(lista->inicio==NULL){
        cout<<"Lista vazia!"<<endl;
    }else{
        cout<<"codigo  nome: "<<endl;
        while(aux!=NULL){
            cout<<aux->codigo<<"        "<<aux->nome<<endl;
            aux = aux->prox;
        }
    }
}
//adciona uma nova paradda
void inserirParada(LLista *lis, PLista *lista, int x, int local){
    parada *novo, *aux;
    linha *proc;
    int i=2;
    proc=lis->inicio;
    if(lis->inicio==NULL){
        cout<<"Vazia"<<endl;
    }else{
        while(proc!=NULL){
            if(proc->codigo==x){
                aux=proc->primeiro;//busca a linha q sera mudada a parada
                break;
            }
            proc = proc->prox;
        }
    }

    novo = new parada;

    cout<<"Nova Parada"<<endl;
    cout<<"\nInforme a hora de saida:            ";
    cin>>novo->horaP;
    cout<<"Informe o valor da passagem:        ";
    cin>>novo->valorP;
    cin.ignore();
    cout<<"Informe o nome da parada:           ";
    gets(novo->local);
    //ele vai adcionar no local q se encontra a parada, e subir todos um nivel, se estive no 1. o 1 sera jogado no segundo
    if(proc->num==0){//caso seja adcionado uma unica parada
        novo->prox=novo;
        novo->ant=novo;
        proc->num++;
        proc->primeiro=novo;
    }else{
    if(local==1){//se adcionado na posicao 1
        proc->num++;
        aux->ant->valorP+=novo->valorP;
        novo->prox=aux;
        novo->ant=aux->ant;
        aux->ant->prox=novo;
        aux->ant=novo;
        proc->primeiro=novo;
    }else{
        if(local>proc->num){//se adcionado no final-se tive ate o codigo 3, deve se pedir par ainsiri no 4, par adciona no ultimo
            proc->num++;
            aux=aux->ant;
            cout<<"Insira o valor atualizado da passagem da cidade "<<aux->local<<" para "<<novo->local<<": ";
            cin>>aux->valorP;
            novo->prox=aux->prox;
            novo->ant=aux;
            aux->prox->ant=novo;
            aux->prox=novo;
        }else{
            aux=aux->prox;
            aqui:
            if(i==local){//se adcionado no meio
                proc->num++;
                cout<<"Insira o valor atualizado da passagem da cidade "<<aux->ant->local<<" para "<<novo->local<<": ";
                cin>>aux->ant->valorP;
                novo->prox=aux;
                novo->ant=aux->ant;
                aux->ant->prox=novo;
                aux->ant=novo;
            }else{
                aux=aux->prox;
                i++;
                goto aqui;
            }
            
        }
    }
    }
   
    cout<<"Cadastrada!"<<endl;
}
//mostra paradas
void mostraParada(LLista *lis, PLista *lista, int x){
    parada *aux, *ajuda;
    linha *proc;
    int i=2;
    proc=lis->inicio;

    if(proc==NULL){
        cout<<"Vazia"<<endl;
        return;
    }else{
        while(proc!=NULL){
            if(proc->codigo==x){
                ajuda=proc->primeiro;
                break;
            }
            if(proc->prox==NULL){
                break;
            }
            proc = proc->prox;
        }
    }
    
    if(proc->num>0 && proc->codigo==x){
    cout<<"Cidade Saida:    "<<ajuda->local<<endl;
    cout<<"Cidade Destino:  "<<ajuda->prox->local<<endl;
    cout<<"Horario:         "<<ajuda->horaP<<endl;
    cout<<"Valor:           "<<ajuda->valorP<<endl;
    cout<<"Codigo:          "<<1<<endl<<endl;
    ajuda=ajuda->prox;
    while(ajuda!=proc->primeiro){
        cout<<"Cidade Saida:    "<<ajuda->local<<endl;
        cout<<"Cidade Destino:  "<<ajuda->prox->local<<endl;
        cout<<"Horario:         "<<ajuda->horaP<<endl;
        cout<<"Valor:           "<<ajuda->valorP<<endl;
        cout<<"Codigo:          "<<i<<endl<<endl;
        ajuda=ajuda->prox;
        i++;
    }
    }else{
        cout<<"Nenhuma parada encontra!"<<endl;
    }
}
//altera os dados de uma parada informada
void alteraParada(LLista *lis, PLista *lista, int x, int local){
    parada *aux;
    linha *proc;
    int i=2;
    char resposta;

    proc=lis->inicio;
    if(lis->inicio==NULL){
        cout<<"Vazia"<<endl;
    }else{
        while(proc!=NULL){
            if(proc->codigo==x){
                aux=proc->primeiro;
                break;
            }
            proc = proc->prox;
        }
    }

    if(local==1){    
    }else{
        if(proc->num==local){
            aux=aux->ant;
        }else{
            aux=aux->prox;
            ali:
            if(i==local){
            }else{
                aux=aux->prox;
                i++;
                goto ali;
            }
        }
    }
    cout<<"responda (s/n):"<<endl;
    cout<<"Altera nome? Nome atual: "<<aux->local<<endl;
    cin>>resposta;
    if(resposta=='s'){
        cin.ignore();
        cout<<"Novo nome: ";
        gets(aux->local);
    }
    cout<<"Altera hora? Hora atual: "<<aux->horaP<<endl;
    cin>>resposta;
    if(resposta=='s'){
        cout<<"Nova hora: ";
        cin>>aux->horaP;
    }
    cout<<"Altera valor? valor atual: "<<aux->valorP<<endl;
    cin>>resposta;
    if(resposta=='s'){
        cout<<"Novo valor: ";
        cin>>aux->valorP;
    }
   
    cout<<"Alterado!"<<endl;
}
//remover uma parada dada sua posição
void removerParada(LLista *lis, PLista *lista, int x, int local){
    parada *aux;
    linha *proc;
    int i=2;
    char resposta;

    proc=lis->inicio;
    if(lis->inicio==NULL){
        cout<<"Vazia"<<endl;
    }else{
        while(proc!=NULL){
            if(proc->codigo==x){
                aux=proc->primeiro;
                break;
            }
            proc = proc->prox;
        }
    }

    if(local==1 && proc->num==0){
        cout<<"Nenhuma parada cadastrada!"<<endl;
        return;
    }

    if(local==1){
        proc->num--;
        proc->primeiro=aux->prox;
        aux->prox->ant=aux->ant;
        aux->ant->prox=aux->prox;
        free(aux);
        if(proc->num==0){
            proc->primeiro=NULL;
        } 
    }else{
        if(proc->num==local){
            proc->num--;
            aux=aux->ant;
            aux->prox->ant=aux->ant;
            aux->ant->prox=aux->prox;
            free(aux);  
        }else{
            aux=aux->prox;
            ali:
            if(i==local){
                aux->prox->ant=aux->ant;
                aux->ant->prox=aux->prox;
                proc->num--;
                free(aux); 
            }else{
                aux=aux->prox;
                i++;
                goto ali;
            }
        }
    }
    cout<<"Excluido!"<<endl;
}
//procura uma viagem dados os dados de partida, em todas as linhas é as retona
void procuraViagem(LLista *lis, PLista *lista, string saida, string destino){
    linha *proc;
    parada *aux, *inicio, *help;
    proc=lis->inicio;
    double soma;
    int vdd=0, troca;

    if(lis->inicio==NULL){
        cout<<"Vazia"<<endl;
    }else{
        while(proc!=NULL){
            aux=proc->primeiro;
            soma=0;
            troca=0;
            vdd=0;
            help=aux->ant;
            while(aux!=help){
                if(troca==0){
                    help=aux;
                    troca=1;
                }
                if(aux->local==saida){
                    inicio=aux;
                    soma=aux->valorP;
                    aux=aux->prox;
                    while(aux!=proc->primeiro){ 
                        if(aux->local==destino){
                            cout<<"Saida:   "<<inicio->local<<endl;
                            cout<<"Chegada: "<<aux->local<<endl;
                            cout<<"Hora:    "<<inicio->horaP<<endl;
                            cout<<"Valor:   "<<soma<<endl<<endl;
                            vdd=1;
                            break;
                        }
                        soma+=aux->valorP;
                        aux=aux->prox;
                    }
                    if(vdd==0){
                        aux=inicio;
                        soma=aux->ant->valorP;
                        aux=aux->ant;
                        while(aux!=proc->primeiro->ant){ 
                            if(aux->local==destino){
                                cout<<"Saida:   "<<inicio->local<<endl;
                                cout<<"Chegada: "<<aux->local<<endl;
                                cout<<"Hora:    "<<inicio->horaP<<endl;
                                cout<<"Valor:   "<<soma<<endl<<endl;
                                break;
                            }
                            soma+=aux->valorP;
                            aux=aux->ant;
                        }
                    }
                }else{
                    aux=aux->prox;
                }     
            }
            proc = proc->prox;
        }
    }
}
