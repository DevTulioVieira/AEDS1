#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;
//struct usada para armazenagem de dados
typedef struct listaHospital{
    int numero;
    int paciente;
    int medico;
    int curados;
    struct listaHospital*prox;
}hospital;

typedef struct listaH{
    hospital *inicio;
}HospitalLista;

typedef struct listaMedico{
    int crm;
    char nome[100];
    char area[100];
    struct listaMedico*prox;
}medico;

typedef struct listaM{
    medico *inicio;
    medico *fim;
}MedicoLista;

typedef struct listaPaciente{
    int idade;
    int a;
    char nome[100];
    char endereco[100];
    struct listaPaciente*prox;
}paciente;

typedef struct listaPaci{
    paciente *inicio;
    paciente *fim;
}pacienteList;

typedef struct listaFila{
    int item;
    struct listaFila*prox;
}fila;

typedef struct listaF{
    fila *inicio;
    fila *fim;
    int tamanho;
}FilaLista;

//iniciando as listas
void iniciohospital(HospitalLista *lista){
    lista->inicio=NULL;
}

void inicioMedico(MedicoLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}

void iniciopaciente(pacienteList *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
}

void iniciofila(FilaLista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->tamanho=0;
}
//menu
void menu(){
    system("cls");
    cout<<"-------------------------"<<endl;
    cout<<"|1.Registros            |"<<endl;
    cout<<"|2.Cadastro de doutores |"<<endl;
    cout<<"|3.Novo Atendimento     |"<<endl;
    cout<<"|4.Medicos Do hospital  |"<<endl;
    cout<<"|5.Ordem para atender   |"<<endl;
    cout<<"|6.Iniciar atendimento  |"<<endl;
    cout<<"|7.sair                 |"<<endl;
    cout<<"-------------------------"<<endl;
}
//traiagem com 18perguntas
int triagem(){

    char a;
    system("cls");
    cout<<"Informe os sitomas do paciente"<<endl;
    cout<<"Comprometimento da via aerea?s/n:       ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Respiracao ineficaz?s/n:                ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Choque?s/n:                             ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Não responde a etimulos?s/n:            ";
    cin>>a;
    if(a=='s')
        return 0;
    cout<<"Em convulsão?s/n:                       ";
    cin>>a;
    if(a=='s')
        return 0;

    cout<<"Dor severa?s/n:                         ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Grande hemorragia incontrolavel?s/n:    ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Alteracao do estado de conciencia?s/n:  ";
    cin>>a;
    if(a=='s')
        return 1;
    cout<<"temperatura maior ou igual a 39°C?s/n:  ";

    cin>>a;
    if(a=='s')
        return 1;
    cout<<"Trauma craniano severo?s/n:             ";
    cin>>a;
    if(a=='s')
        return 1;

    cout<<"Dor moderada?s/n:                       ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Pequena hemorragia incontrolavel?s/n:  ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"vomito persistente?s/n:                ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Temperatura entre 38°C e 39°C?s/n:     ";
    cin>>a;
    if(a=='s')
        return 2;
    cout<<"Idoso ou gravida?s/n:                  ";
    cin>>a;
    if(a=='s')
        return 2;

    cout<<"Dor leve?s/n:                          ";
    cin>>a;
    if(a=='s')
        return 3;
    cout<<"Nauseas?s/n:                           ";
    cin>>a;
    if(a=='s')
        return 3;
    cout<<"Temperatura?s/n:                       ";
    cin>>a;
    if(a=='s')
        return 3;

    return 4;
}
//cadastros de medico
void cadastromedico(MedicoLista *lista, int x){//cadastro de medico
    medico *novo;
    novo = new medico;

    if(x>5){
        cout<<"Favor emcaminha a outra cidade o medico"<<endl;
        abort;
    }
    cout<<"\n\t\tCADASTRO DE PDOUTORES"<<endl;
    cout<<"\nInforme o numero CRM:       ";
    cin>>novo->crm;
    cin.ignore();
    cout<<"Informe o nome do doutor:   ";
    gets(novo->nome);
    cout<<"Informe a area de atuacao:  ";
    gets(novo->area);
    novo->prox = NULL;

    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    cout<<"Doutor cadastrado!"<<endl;
    Sleep(1000);
    system("cls");
}
//cadastros de paciente
void cadastropaciente(pacienteList *lista, int x){
    paciente *novo;
    novo = new paciente;

    cout<<"\n\t\tCADASTRO DE PACIENTE"<<endl;
    cin.ignore();
    cout<<"Informe o nome do paciente:           ";
    gets(novo->nome);
    cout<<"Informe o enderecoreco:               ";
    gets(novo->endereco);
    cout<<"Informe a idade:                      ";
    cin>>novo->idade;

    novo->a=x;

    novo->prox = NULL;

    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    cout<<"Dados salvo"<<endl;
    Sleep(2000);
    system("cls");
}
//cadastros de fila
void cadastrofila(FilaLista *lista, int x){
    fila *novo, *aux, *anterior;
    novo = new fila;
    novo->prox = NULL;
    novo->item=x;
    aux = lista->inicio;

    if (lista->inicio==NULL){
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho=1;
    }else{
        anterior=aux;
        lista->tamanho++;
        while(aux!=NULL){
            if(novo->item<aux->item){
                if(aux==lista->inicio){
                    novo->prox=lista->inicio;
                    lista->inicio=novo;
                }else{
                    novo->prox=anterior->prox;
                    anterior->prox=novo;
                }
                break;
            }
            if(aux==lista->fim){
                aux->prox=novo;
                lista->fim=novo;
                novo->prox = NULL;
            }
            anterior=aux;
            aux=aux->prox;
        }
    }
    cout<<"Cadastro completo"<<endl;
    Sleep(1000);
    system("cls");
}
//Quando alguem é chamado para se atendido
int atentido(FilaLista *lista){
    fila *aux;
    int x;
    aux = lista->inicio;

    if(lista->inicio==NULL){
        cout<<"Sem pacientes para atenderecor"<<endl;
        return 10;
    }else{
        cout<<"Paciente foi atendido"<<endl;
        x=aux->item;
        lista->inicio = lista->inicio->prox;
        free(aux);
        lista->tamanho--;
    }
    return x;
}
//funçao q atualiza os dados sempre
int atualiza(HospitalLista *lista, int x){
    hospital *aux;
    aux=lista->inicio;

    if(x==1){
        if(aux->numero<5){
            aux->numero++;
            aux->medico++;
            return aux->numero;
        }
    }
    if(x==2){
        aux->paciente++;
    }
    if(x==3){
        if(aux->medico>0 && aux->paciente>0){
            aux->medico--;
            aux->paciente--;
            return 1;
        }
    }
    if(x==4){
        aux->curados++;
        aux->medico++;
    }
    if(x==5){
        if(aux->paciente>0){
            return 1;
        }
    }

    return 0;
}
//mostra os medicos
void medicolista(MedicoLista *lista){
    medico *aux;
    aux = lista->inicio;
    system("cls");
    if(aux==NULL){
        cout<<"\nNenhum medico cadastrado!\n";
    }else{
        cout<<"\t\tDOUTORES"<<endl<<endl;
        while(aux!= NULL){
            cout<<"CRM:    "<<aux->crm<<endl;
            cout<<"Nome:   "<<aux->nome<<endl;
            cout<<"Area:   "<<aux->area<<endl<<endl;
            aux = aux->prox;
        }
    }
    system("pause");
    system("cls");  
}
//mostra a fila
void filalista(FilaLista *lista){
    fila *aux;
    aux = lista->inicio;
    system("cls");
    if(aux==NULL){
        cout<<"\nNenhum paciente para atenderecor!\n";
    }else{
        while(aux!= NULL){
            cout<<"Ordem de pioridade: "<<aux->item;
            aux = aux->prox;
        }
    }
    cout<<endl;
    system("pause");
    system("cls");
    
}
//mostra os dados hospitalar
void hospitallista(HospitalLista *lista){
    hospital *aux;
    aux=lista->inicio;

    system("cls");
    cout<<"\nTotal de medicos:     "<<aux->numero;
    cout<<"\nMedicos disponiveis:  "<<aux->medico;
    cout<<"\nTotal de pacientes:   "<<aux->paciente;
    cout<<"\npacientes curados:    "<<aux->curados<<"\n";
    system("pause");
}
//mostra o nivel de pioridade
void ordem(int x){
    system("cls");
    if(x==0){
        cout<<"Nivel vermelho: 60 segundos";
    }else{
        if(x==1){
            cout<<"Nivel laranja: 50 segundos";
        }else{
            if(x==2){
                cout<<"Nivel amarelo: 40 segundos";
            }else{
                if(x==3){
                    cout<<"Nivel verde: 30 segundos";
                }else{
                    cout<<"Nivel azul: 20 segundos";
                }
            }
        }
    }
    Sleep(1000);
    system("cls");
}
//o tempo de antendimento e definido aqui
int segundo(int x){
    if(x==0){
        return 60;
    }else{
        if(x==1){
            return 50;
        }else{
            if(x==2){
                return 40;
            }else{
                if(x==3){
                    return 30;
                }else{
                    return 20;
                }
            }
        }
    }
}
//salva dados hospitalar
void salvarhospital(HospitalLista *lista){
    hospital *aux;
    aux = lista->inicio;

    ofstream outFile;
    outFile.open("dados.txt", ios::out); // abre o arquivo para escrita
    if (!outFile){ 
        cout<<"Arquivo saida.txt nao pode ser aberto"<<endl;
        abort();
    }

    if(aux==NULL){
        cout<<"\nNenhum dado encontrado!\n";
    }else{
        while(aux!= NULL){
            outFile<<aux->curados<<" "<<aux->medico<<" "<<aux->numero<<" "<<aux->paciente<< "\n";
            aux=aux->prox;
        }
    }
    outFile.close();
    cout<<"Dados Salvos!"<<endl;
    Sleep(2000);
    system("cls");
}
//puxa os dados hospitalar
void carregarhospital(HospitalLista *lista){
    hospital *novo;
    novo = new hospital;
    novo->prox = NULL;

    ifstream inFile;
    inFile.open("dados.txt", ios::in);
    if (!inFile){ 
        cout<<"Arquivo saida.txt nao pode ser aberto"<<endl;
        abort();
    }

    while(inFile>> novo->curados >>novo->medico>>novo->numero>>novo->paciente){      
        if (lista->inicio==NULL){
            lista->inicio=novo;   
        }
        novo = new hospital;
        novo->prox = NULL;
    }
    cout<<"Dados do hospital carregados com suceso!"<<endl;
}
//salva os dados medicos
void salvar(MedicoLista *lista){
    medico *aux;
    aux = lista->inicio;

    ofstream outFile;
    outFile.open("medico.txt", ios::out); // abre o arquivo para escrita
    if (!outFile){ 
        cout<<"Arquivo saida.txt nao pode ser aberto"<<endl;
        abort();
    }

    if(aux==NULL){
        cout<<"\nNenhum medico cadastrado!\n";
    }else{
        while(aux!= NULL){
            outFile<<aux->nome<<" "<<aux->area<<" "<<aux->crm<< "\n";
            aux = aux->prox;
        }
    }
    outFile.close();
    cout<<"Dados Salvos!"<<endl;
    Sleep(2000);
    system("cls");
}
//puxa os dados medicos
int carregar(MedicoLista *lista){
    medico *novo;
    novo = new medico;
    novo->prox = NULL;
    int x=0;
    ifstream inFile;
    inFile.open("medico.txt", ios::in);
    if (!inFile){ 
        cout<<"Arquivo saida.txt nao pode ser aberto"<<endl;
        abort();
    }

    while(inFile>>novo->nome>>novo->area>>novo->crm){      
        if (lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
        }else{
            lista->fim->prox=novo;
            lista->fim=novo;
        }
        x++;
        novo = new medico;
        novo->prox = NULL;
    }
    cout<<"Dados dos medicos carregados com suceso!"<<endl;
    return x;
}

int main(){
    int opcao, a, x, aux;//variasveis usadas
    char espera;
    int tempo[5];
    int num[5];
    int medi[5];
    int livre[5];
    //criar um variavel paras as listas
    MedicoLista L1;
    pacienteList P1;
    FilaLista F1;
    HospitalLista H1;
    //inicia as listas
    inicioMedico(&L1);
    iniciopaciente(&P1);
    iniciofila(&F1);
    iniciohospital(&H1);
    //carrega os dados
    carregar(&L1);
    carregarhospital(&H1);
    Sleep(2000);
    
    for(;;){
        menu();
        cout<<"opcao: ";
        cin>>opcao;
        switch (opcao){
        case 1:
            hospitallista(&H1);//mostra a lista
        break;

        case 2:
            aux=atualiza(&H1, 1);//verifica a disponibilidade para adcionar medicos
            cadastromedico(&L1, aux);
            if(aux!=0){
                salvar(&L1);
            } 
        break;

        case 3:
            inicio:
            a=triagem();//faz a triagem
            ordem(a);//diz o nivel do paciente
            cadastropaciente(&P1, a);//cadastra o paciente
            atualiza(&H1, 2);//adciona um paciente para atende
            cadastrofila(&F1, a);//defini a ordem de chamada
            cout<<"Paciente esperando(s/n)?";
            cin>>espera;
            if(espera=='s' || espera=='S'){
                goto inicio;
            }      
        break;

        case 4:
            medicolista(&L1); //mostra medicos  
        break;

        case 5:
            filalista(&F1);//mostra fila dizendo quais a ordem de prioridade
        break;

        case 6:
            system("cls");
            x=atualiza(&H1, 5);//se medico disponivel e tem paciente para atender
            while(x==1){
                time_t t1 = time(NULL);//maximo de 5 medicos
                time_t t2 = time(NULL);//
                time_t t3 = time(NULL);
                time_t t4 = time(NULL);
                time_t t5 = time(NULL);
                tem:
                if(medi[0]==0){
                    aux=atualiza(&H1, 3);//se tem medico e paciente começa atender
                    if(aux==1){//inicia aqui se verdade em cima, caso ingnora entendendo q n tem paciente nem emdico
                        num[0]=atentido(&F1);
                        tempo[0]=segundo(num[0]);
                        livre[0]=0;//para mostra que esta atendendo ainda
                    }else{
                        livre[0]=1;
                    }
                    medi[0]=1;
                }else{
                    if(livre[0]==0){
                        time_t t11 = time(NULL);
                        if(difftime(t11, t1)>tempo[0]){//ver se o tempo para atendimento passou
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            medi[0]=0;
                            livre[0]=1;
                            time_t t1 = time(NULL);
                            goto tem;
                        }
                    }
                }

                if(medi[1]==0){
                    aux=atualiza(&H1, 3);
                    if(aux==1){
                        num[1]=atentido(&F1);
                        tempo[1]=segundo(num[1]);
                        livre[1]=0;
                    }else{
                        livre[1]=1;
                    }
                    medi[1]=1;
                }else{
                    if(livre[1]==0){
                        time_t t22 = time(NULL);
                        if(difftime(t22, t2)>tempo[1]){
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            medi[1]=0;
                            livre[1]=1;
                            time_t t2 = time(NULL);
                            goto tem;
                        }
                    }
                }

                 if(medi[2]==0){
                    aux=atualiza(&H1, 3);
                    if(aux==1){
                        num[2]=atentido(&F1);
                        tempo[2]=segundo(num[2]);
                        livre[2]=0;
                    }else{
                        livre[2]=1;
                    }
                    medi[2]=1;
                }else{
                    if(livre[2]==0){
                        time_t t33 = time(NULL);
                        if(difftime(t33, t3)>tempo[2]){
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            medi[2]=0;
                            livre[2]=1;
                            time_t t3 = time(NULL);
                            goto tem;
                        }
                    }
                }

                 if(medi[3]==0){
                    aux=atualiza(&H1, 3);
                    if(aux==1){
                        num[3]=atentido(&F1);
                        tempo[3]=segundo(num[3]);
                        livre[3]=0;
                    }else{
                        livre[3]=1;
                    }
                    medi[3]=1;
                }else{
                    if(livre[3]==0){
                        time_t t44 = time(NULL);
                        if(difftime(t44, t4)>tempo[3]){
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            medi[3]=0;
                            livre[3]=1;
                            time_t t4 = time(NULL);
                            goto tem;
                        }
                    }
                }

                 if(medi[4]==0){
                    aux=atualiza(&H1, 3);
                    if(aux==1){
                        num[4]=atentido(&F1);
                        tempo[4]=segundo(num[4]);
                        livre[4]=0;
                    }else{
                        livre[4]=1;
                    }
                    medi[4]=1;
                }else{
                    if(livre[4]==0){
                        time_t t55 = time(NULL);
                        if(difftime(t55, t5)>tempo[4]){
                            cout<<"Paciente atendido!"<<endl;
                            atualiza(&H1, 4);
                            medi[4]=0;
                            livre[4]=1;
                            time_t t5 = time(NULL);
                            goto tem;
                        }
                    }
                }

                if(livre[0]==0 || livre[1]==0 || livre[2]==0 || livre[3]==0 || livre[4]==0){//se estive alguem atendido epera acaba todos
                    goto tem;
                }
                x=atualiza(&H1, 5);//confere se realmente atendeu todos
            }
            
            medi[0]=0; medi[1]=0; medi[2]=0; medi[3]=0; medi[4]=0;//reseta as variaveis para futura atendimento
            cout<<"Todos os pacientes foram curados"<<endl;
            system("pause");
        break;

        case 7:
            salvar(&L1);   //salva dados
            salvarhospital(&H1);
            exit(0);   
        break;
        }
    }
}