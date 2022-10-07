#include <iostream>//bibliotecas
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stack>
//https://github.com/CachorroLouco7/Algoritmos-e-Estruturas-de-Dados-AEDS-/upload/Eita!Tem-tudo-aqui-ksksksk/CadastrodePedido
#define MAXTAM 10
#define MAX_ENTREGA 7

using namespace std;
//strruct dos pedidos em lista
typedef struct PedidoLista{
    int codigo;
    int produto[MAXTAM];
    double total;
    float distancia; 
    struct PedidoLista *prox;
}pedido;

typedef struct Lista{
    pedido *inicio;
    pedido *fim;
}TLista;

typedef struct PILHA{//estrutura para guarda os valor de codigo e distancia
    int codigo[10];
    float distancia[10];
}Pilha;
//struduta da pilha de entrega
typedef struct tipoElemento{
    int codigo;
    int distancia;
    struct tipoElemento *prox;
}TElemento;

typedef struct pPilha{
    TElemento *topo;
    int tamanho;
}TPilha;
//menu
void menu(){
    cout<<"\n-----------------------"<<endl;
    cout<<"| 1.Novo pedido       |"<<endl;
    cout<<"| 2.Lista pedidos     |"<<endl;
    cout<<"| 3.Cardapio          |"<<endl;
    cout<<"| 4.Busca pedido      |"<<endl;
    cout<<"| 5.Lista entrega     |"<<endl;
    cout<<"| 6.Pedido entregue   |"<<endl;
    cout<<"| 7.Sair              |"<<endl;
    cout<<"-----------------------"<<endl;
}
//cardapio
void cardapio(){
    system("cls");
    cout<<"\n-----------------------------"<<endl;
    cout<<"| 1.Arroz ............ 10.5 |"<<endl;
    cout<<"| 2.Hamburgue ........ 20.9 |"<<endl;
    cout<<"| 3.Batata Frita ..... 30.1 |"<<endl;
    cout<<"| 4.Sopa Legumes ..... 12.2 |"<<endl;
    cout<<"| 5.Pao de Alho ...... 8.65 |"<<endl;
    cout<<"| 6.Picanha .......... 54.9 |"<<endl;
    cout<<"| 7.Sushi ............ 26.6 |"<<endl;
    cout<<"----------------------------"<<endl;
}
//tabela de preço ksks
double dinheiro(int codigo){
    int i;
    double tabela[]={10.5, 20.9, 30.1, 12.2, 8.65, 54.9, 26.6};
    string produto[]={"Arroz","Hamburgue","Batata Frita","Sopa Legumes","Pao de Alho","Picanha","Sushi"};
    
    for(i=0; i<(MAXTAM+1); i++){
        if((codigo-1)==i){
            cout<<tabela[i]<<"    "<<produto[i]<<endl;
            return tabela[i];
            break;
        }
    }
}
//incializa plha
void inicializarpilha(TPilha *pi){
    pi->topo=NULL;
    pi->tamanho=0;
}
//inicializa lista
void inicializarlista(TLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}
//inseir produto
void insirirpedido(TLista *lista, int *cod){
    pedido *novo;
    novo = new pedido;
    int i;
    system("cls");
    cardapio();
    cout<<"\t\t|||NOVO PEDIDO|||\n";
    novo->codigo=*cod;
    *cod=*cod + 1;
    cout<<"\nInsira distancia(m): ";
    cin>>novo->distancia;
    novo->total=0;
    cout<<"\nDigite (-1) quando estive terminado os pedidos"<<endl;//aceitara ate 10 ou quando digita -1
    cout<<"Insira o codigo do(s) pedido(s): "<<endl;
    for(i=0; i<MAXTAM; i++){//por favor sempre insira um produto antes de finaliza a compra
        cin>>novo->produto[i];//sempre deve caddrasta um pedido para evitar erro
        if(novo->produto[i]==-1){
            break;
        }
        cout<<"Adcionado!"<<endl;
    }

    novo->prox = NULL;
    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    cout<<"\nPedido efetuado com sucesso\n";
}
//lista os pedidos
void listapedido(TLista *lista){
    pedido *aux;
    aux = lista->inicio;
    float preco;
    int i=0, a;

    system("cls");
    
    if(aux==NULL){
        cout<<"\nNenhum pedido cadastro\n";
    }else{
        while(aux!= NULL){
            a=0;
            cout<<"\n\nCodigo pedido:  "<<aux->codigo;
            cout<<"\nDistancia:    "<<aux->distancia;
            cout<<"\nProdutos:\n";
            for(i=0; i<MAXTAM; i++){
                if(aux->produto[i]==-1){
                    break;
                }
                preco=dinheiro(aux->produto[i]);//vai la na tablea d epeço epega o preço do produto
                if(aux->total==0){//se igual a zero ele vai entender que ainda n somou o total, o total sempre e zero
                    a=1;
                }
                if(a==1){
                    aux->total+=preco;//se ja tive somado ele soma de novo é ignora
                }
            }
            
            cout<<"\nTotal:  "<<aux->total<<endl;
            
            aux = aux->prox;
        }
    }
}
//remove da lsita o pedido entregue
void remove(TLista *lista, int cod){
    pedido *anterior, *atual;
    
    if(lista->inicio == NULL){
        cout<<"\nNenhum Pedido cadastrado\n";
    }else{
        anterior = lista->inicio;
        atual = lista->inicio;
        while(atual!=NULL){
            if(atual->codigo==cod){
                if(atual == lista->inicio){
                    lista->inicio = lista->inicio->prox;
                    free(atual);
                    break;
                }else{
                    if(atual==lista->fim){
                        lista->fim =anterior;
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

}
//busca um unico pedido
void buscapedido(TLista *lista){
    pedido *aux;
    aux = lista->inicio;
    float preco;
    int x=0, i=0, opcao, a=0;
    system("cls");
    if(aux==NULL){
        cout<<"\nNenhum pedido cadastro\n";
    }else{
        cout<<"Insira o codigo do pedido: ";
        cin>>opcao;
        while(aux!= NULL){
            if(aux->codigo==opcao){
                cout<<"\n\nCodigo pedido:  "<<aux->codigo;
                cout<<"\nDistancia:      "<<aux->distancia;
                cout<<"\nProdutos:\n";
                for(i=0; i<MAXTAM; i++){
                    if(aux->produto[i]==-1){
                        break;
                    }
                    preco=dinheiro(aux->produto[i]);//ira busca o preço
                    if(aux->total==0){// se n tive sido somado, a ideia e q se o cliente quiser sabe o preço ele vai somar,
                        a=1;//porq se n tivesse imprimido a lista antes ele n somaria, entao vai sempre somar o antes d einforma
                    }
                    if(a==1){
                        aux->total+=preco;
                    }
                }
                
                cout<<"\nTotal:  "<<aux->total<<endl;
                x=0;
            }
            aux = aux->prox;
        }
    }
}

void listaentrega(Pilha *vetor, TLista *lista, int tam){
    pedido *aux;
    aux = lista->inicio;
    int i;

    system("cls");
    if(aux==NULL){
        cout<<"\nNenhum pedido cadastro para entrega\n";//ele vai nostra os pedidos sendo q o de baixo q sera entregue
    }else{
        for(i=0; i<tam; i++){
            if(aux!= NULL){
                vetor->distancia[i]=aux->distancia;
                vetor->codigo[i]=aux->codigo;
                aux = aux->prox;
            }else{
                break;
            }
        }
    }
}

void ordena(Pilha *vetor, int tam){//ele ordena os valopr de disntacia para joga na pilha
    int i, j, aux, troca;
    for(i=0 ; i<tam-1 ; i++){
        for(j=i+1 ; j<tam ; j++){
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
}

void push(Pilha *vetor, TPilha *pi, int tam){//insere na pilha ja oprdenado para entrega
    int i;

    for(i=0; i<tam; i++){
        TElemento *novo;
        novo = new TElemento;
        novo->codigo=vetor->codigo[i];
        novo->distancia=vetor->distancia[i];

        novo->prox=NULL;
        if(pi->topo = NULL){
            pi->topo =novo;
        }else{
            novo->prox= pi->topo;
            pi->topo = novo;
        }
    }
}

void mostra(Pilha *vetor, int tam){//mostra a pilha o codigo e distancia
    int i;

    if(tam>0){
        cout<<"Sequencia de codigo dos produtos a se entregue:\n";
        for(i=tam ; i>0 ; i--){
            cout<<vetor->codigo[i]<<"  Distancia: "<<vetor->distancia[i]<<endl;
        }
    }
}
//retira da pilha apara entrega
int pop(TPilha *pi){
    TElemento *aux;
    int x=-1;
    if(pi->topo==NULL){
        cout<<"\nVazio!\n";
    }else{
        x = pi->topo->codigo;
        aux = pi->topo;
        pi->topo = pi->topo->prox;
        pi->tamanho--;
        free(aux);
    }
    return x;
}

int main(){
    int x, a, codigo=1, cod, tamanho=0;//funcoes basica
    
    TLista L1;
    Pilha P1;
    TPilha TP1;

    inicializarlista(&L1);
    inicializarpilha(&TP1);

    for(;;){//deixa ifinito
        menu();
        cin>>x;
    
        switch(x){
            case 1:
                insirirpedido(&L1, &codigo);//codigo e aumentando um sempre ksksks
                tamanho++;
                system("pause");
                system("cls");
            break;

            case 2:
                listapedido(&L1);
                system("pause");
                system("cls");
            break;

            case 3:
                cardapio();
                system("pause");
                system("cls");
            break;

            case 4:
                buscapedido(&L1);
                system("pause");
                system("cls");
            break;

            case 5:
                listaentrega(&P1, &L1, tamanho);//aqui serao passado para o vetor os codigo e distancia dos pedidos
                ordena(&P1, tamanho);//ira ordena pela disntacia, sendo do maior para menor, ja q na pilha o maior deve se inserido primeiro
                push(&P1, &TP1, tamanho);//ira inseri na pilha do maior pro menor
                mostra(&P1, tamanho);//mostra a orddem de entrega, com o menor numero em cima ksks
                system("pause");
                system("cls");
            break;

            case 6:
                listaentrega(&P1, &L1, tamanho);
                ordena(&P1, tamanho);
                push(&P1, &TP1, tamanho);
                system("cls");//se tentar remover sem atualiza a lista da errado por isso ele e feita antes de remover um intem
                cod=pop(&TP1);//retorna o codigo do pedido enviado, se retorna -1 que dizer q n tinha nenhum pedido
                remove(&L1,cod);//remove na lista pelo codigo
                system("cls");
                if(cod!=-1){//se diferente de menos q dizer q removel
                    cout<<"\nPedido Entregue!\n";
                    tamanho--;//diminuir o tamanho ksks
                    system("pause");
                    system("cls");
                }
                
            break;

            case 7:
            exit(0);//acabou?
            break;
        }
    }

}
