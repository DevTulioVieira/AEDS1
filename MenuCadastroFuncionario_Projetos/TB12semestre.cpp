//bibliotecas ultilizadas
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>

# define MAXTAM 5//maximo de projetos

using namespace std;
//estruduras dos dados ultilizados, para lista encadedas.
typedef struct funcionarioLista{
    int codigo;
    char nome[100];
    char ende[100];
    int familia;
    int fp;
    struct funcionarioLista *prox;
}funcionario;//dos funcionarios estrutura

typedef struct Lista{
    funcionario *inicio;
    funcionario *fim;
}TLista;//lsita dos funcionarios

typedef struct PilhaLista{
    int codigo;
    int codi;
    char setor[100];
    int horas;
    struct PilhaLista *prox;
}Pilha;//dos projetos estrutura

typedef struct PPilha{
    Pilha *inicio;
    Pilha *fim;
}TPilha;//lista dos projetos ps: usei o nome pilha porq no inicio queria usa pilha, 
//ai decidie usa como lista mesmo, mais mantive o nome

void menu(){
    //menu
    cout<<"\n\n1-Adcionar funcionario\n";
    cout<<"2-Adcionar projeto\n";
    cout<<"3-Excluir projeto\n";
    cout<<"4-Exclui funcionario\n";
    cout<<"5-Consulta funciorio\n";
    cout<<"6-Salario funcionarios\n";
    cout<<"7-Sair\n";
}

void inicializapilha(TPilha *pilha){//inica lista projetos
    pilha->inicio=NULL;
    pilha->fim=NULL;
}

void inicializalista(TLista *lista){//inica lista funcionarios
    lista->inicio=NULL;
    lista->fim=NULL;
}

void insereprojeto(TPilha *pilha, int a){//para iserir projeto
    Pilha *novo;//pomteiro
    novo = new Pilha;//nova memoria para dados
    int x;

    cout<<"\n\t\t|||CADASTRO DE PROJETO|||\n";
    cout<<"\nInforme o codigo do projeto:       ";
    cin>>novo->codigo;
    cout<<"Informe as horas do projeto:       ";
    scanf("%d", &novo->horas);
    cin.ignore();
    cout<<"Informe o nome do projeto:         ";
    gets(novo->setor);
    novo->codi=a;
    novo->prox = NULL;//prox tem q se nulu, ja q insere independene da ordem

    if (pilha->inicio == NULL){//se for o primeiro elemento da lisata
        pilha->inicio = novo;
        pilha->fim = novo;
    }else{//se ja esive um elemento
        pilha->fim->prox=novo;//encadeamento
        pilha->fim=novo;
    }
    cout<<"\nAdcionado com sucesso\n";
}

void inserirfuncionario(TLista *lista){//mesma ideia do projeto T-T ksksks
    funcionario *novo;
    novo = new funcionario;

    cout<<"\t\t|||CADASTRO DE FUNCIONARIO|||\n";
    cout<<"Informe o codigo do funcionario:       ";
    scanf("%d", &novo->codigo);
    cin.ignore();
    cout<<"Informe o nome do funcionario:         ";
    gets(novo->nome);
    cout<<"Informe o endereco do funcionario:     ";
    gets(novo->ende);
    cout<<"Informe os familiares do funcionario:  ";
    scanf("%d", &novo->familia);
    novo->fp=0;

    novo->prox = NULL;

    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox=novo;//encadeamento
        lista->fim=novo;
    }
    cout<<"\nAdcionado com sucesso\n";
}

int  buscafuncionario(TLista *lista, TPilha *pilha, int a, int verdade){//busca um unico funcionario. 
    funcionario *aux;
    Pilha *ajuda;
    aux = lista->inicio;
    ajuda = pilha->inicio;

    int x=0, i=0;
    //essa e difente ksksk ela ja prepara os dados para inserir o projeto
    if(aux==NULL){
        cout<<"\nNenhum funcionario cadastrado!\n";
    }else{
        while(aux!= NULL){
            if(aux->codigo==a){//caso ache o funcionario retonra os dados dele
                cout<<"\n\nCodigo funcionario:      "<<aux->codigo;
                cout<<"\nNome funcionario:        "<<aux->nome;
                cout<<"\nEndereco funcionario:    "<<aux->ende;
                cout<<"\nFamiliares funcionario:  "<<aux->familia;
                x=1;//porq verdade some? e q se verdade for zero, eu so quero busca as informção, n adcionar projeto
                aux->fp+=verdade;//se o funcionario existir, ele adiciona a soma de um projeto
                if(aux->fp>MAXTAM){//caso ja tenha atinido o maximo de projeto
                    x=2;
                    aux->fp-=1;
                }
                i=0;
                while(ajuda!= NULL){//retorna os projetos ja trabalhados
                    if(ajuda->codi==aux->codigo){
                        cout<<"\n\nCodigo projeto: "<<ajuda->codigo;
                        cout<<"\tHoras projeto: "<<ajuda->horas;
                        cout<<"\tNome projeto: "<<ajuda->setor;
                        i=1;
                    }
                    ajuda = ajuda->prox;
                }
                if(i==0){
                    cout<<"\nNenhum projeto cadastrado!\n";//caso n trablhe em nenhum projeto
                }

            }
            aux = aux->prox;
        }
    }
    return x;//retorna se existi funcionario e se ka atingio o maximo deprojetos

}

int  remover(TLista *lista){//remover funcionario q n trablha em projeto
    funcionario *anterior, *atual;
    int x=1;
    
    if(lista->inicio == NULL){
        cout<<"lista vazia!\n";//se lista vazia n vai remover nada
    }else{
        anterior = lista->inicio;
        atual = lista->inicio;
        while(atual!=NULL){//vai percore a lista
            if(atual->fp==0){//caso ele n trablhe
                x=0;
                if(atual == lista->inicio){
                    lista->inicio = lista->inicio->prox;
                    free(atual);//exluir se for o primeiro
                    break;
                }else{
                    if(atual==lista->fim){
                        lista->fim =anterior;//se for o ultimo mantem o encadeamento garante q o fim tenha valor null
                    }
                    //refaz encadeamento
                    anterior->prox = atual->prox;
                    free(atual);//remover o funcionario
                    break;
                }
            }else{//se nao acha ele vai pro proximo
                anterior=atual;
                atual = atual->prox;
            }
        }
        
    }
    return x;//se ele remover ele retorna 0, dizendo q removel alguem
}

void buscafun(TLista *lista, TPilha *pilha){//busca normal, aqui vai busca todos os funcionarios e projeto
    funcionario *aux;
    Pilha *ajuda, *ini;
    aux = lista->inicio;
    ajuda = pilha->inicio;
    ini = pilha->inicio;//salva o dado do primeiro projeto

    int x=0;

    if(aux==NULL){
        cout<<"Nenhum funcionario cadastrado!\n";//se n tive funcionario
    }else{
        while(aux!= NULL){
            cout<<"\n\nCodigo funcionario:      "<<aux->codigo;
            cout<<"\nNome funcionario:        "<<aux->nome;
            cout<<"\nEndereco funcionario:    "<<aux->ende;
            cout<<"\nFamiliares funcionario:  "<<aux->familia;
            x=0;
            ajuda = ini;//garante q vai busca todos os projetos do funcionario, isso me deu dor cabeça sskksks
            while(ajuda!= NULL){//imagino q o metodo q usei nao seja o mais eficiente, mais foi oq conseguie fazer
                if(ajuda->codi==aux->codigo){//codi e o valor igual ao funcionario mostrando q o proejto e dele
                    cout<<"\nCodigo projeto: "<<ajuda->codigo;
                    cout<<"\tHoras projeto: "<<ajuda->horas;
                    cout<<"\tNome projeto:     "<<ajuda->setor;
                    x=1;
                }
                ajuda = ajuda->prox;
            }
            if(x==0){
                cout<<"\nNenhum projeto cadastrado!\n";//se n tive projeto
            }
            aux = aux->prox;//vai buscando todos os funcionarios
        }
    }
}

int  removerprojeto(TPilha *pilha, int a){//remover projeto escolhido
    
    Pilha *anterior, *atual;//mesmo esquema do funcionario 
    int x=1;
    
    if(pilha->inicio == NULL){
        cout<<"Nenhum projeto!\n";//se lista vazia n vai remover nada
    }else{
        anterior = pilha->inicio;
        atual = pilha->inicio;
        while(atual!=NULL){//vai percore a lista
            if(atual->codigo==a){//caso ele n trablhe
                x=0;
                if(atual == pilha->inicio){
                    pilha->inicio = pilha->inicio->prox;
                    free(atual);//exluir se for o primeiro
                    break;
                }else{
                    if(atual==pilha->fim){
                        pilha->fim =anterior;//se for o ultimo mantem o encadeamento garante q o fim tenha valor null
                    }
                    //refaz encadeamento
                    anterior->prox = atual->prox;
                    free(atual);//remover o funcionario
                    break;
                }
            }else{//se nao acha ele vai pro proximo
                anterior=atual;
                atual = atual->prox;
            }
        }
        
    }
    return x;//se ele remover ele retorna 0, dizendo q removel alguem
}

void diminuir(TLista *lista, int a){//diminui o numero maximo de projeto ja cadastrado
    funcionario *aux;
    aux = lista->inicio;

    while(aux!= NULL){
        if(aux->codigo==a){
            aux->fp-=1;//diminui em 1 quando excluido o projeto para cadastramento de um novo
        }
        aux = aux->prox;
    }

}

void salario(TLista *lista, TPilha *pilha){//vamos ver salrio iruu
    funcionario *aux;
    Pilha *ajuda, *ini;//mesmo esquema do void q mostra todos os funcionario, so q esse tem o calculo do salario
    aux = lista->inicio;
    ajuda = pilha->inicio;
    ini = pilha->inicio;//salva o dado do primeiro projeto

    int x=0;
    float h=0, ht=0, sb=0, dn=0, di=0, sl=0, f=0;//variaveis para calcula o salarioi

    if(aux==NULL){
        cout<<"Nenhum funcionario cadastrado!\n";//se n tive funcionario
    }else{
        while(aux!= NULL){
            cout<<"\n\t\t\tSALARIO\n";
            cout<<"\n\nCodigo funcionario:      "<<aux->codigo;
            cout<<"\nNome funcionario:        "<<aux->nome;
            cout<<"\nEndereco funcionario:    "<<aux->ende;
            cout<<"\nFamiliares funcionario:  "<<aux->familia;
            x=0;
            f+=aux->familia;
            ajuda = ini;//garante q vai busca todos os projetos do funcionario, isso me deu dor cabeça sskksks
            while(ajuda!= NULL){//imagino q o metodo q usei nao seja o mais eficiente, mais foi oq conseguie fazer
                if(ajuda->codi==aux->codigo){//codi e o valor igual ao funcionario mostrando q o proejto e dele
                    cout<<"\nCodigo projeto: "<<ajuda->codigo;
                    cout<<"\tHoras projeto: "<<ajuda->horas;
                    cout<<"\tNome projeto:     "<<ajuda->setor;
                    ht+=ajuda->horas;//calcula hora
                    x=1;
                }
                ajuda = ajuda->prox;
            }
            if(x==0){
                cout<<"\nNenhum projeto cadastrado!\n";//se n tive projeto
            }
            h=ht*45;//calculos do salrio
            f=f*35;
            sb=h+f;
            di=sb*0.085;
            dn=sb*0.15;
            sl=sb-di-dn;
            
            cout<<"\n\nHoras totais:    "<<ht<<" horas";
            cout<<"\nSalario bruto:   "<<sb<<" reais";
            cout<<"\nDesconto INSS:   "<<di<<" reais";
            cout<<"\nDesconto IR:     "<<dn<<" reais";
            cout<<"\nSalario liquido: "<<sl<<" reais";
            //reseta os valores para calcula os novos salarios, seria ideal ter um variavel com o preço?
            //mais iria da muito trabalho sem tempo, assim ta bom. q fica atualizado.
            ht=0;
            h=0;
            f=0;
            sb=0;
            di=0;
            dn=0;
            sl=0;

            aux = aux->prox;//vai buscando todos os funcionarios
        }
    }



}

void salvar(TLista *lista, TPilha *pilha){
    ofstream arq;
    funcionario *aux;
    Pilha *ajuda;
    char x='+';
    // int max=1;
    // int max1=0;
    aux = lista->inicio;
    ajuda = pilha->inicio;
    arq.open("funcionario.bin", ios::binary | ios::out);
    
    cout<<"Salvando dados.. aguarde"<<endl;

    if(arq.is_open()){

        while(aux!=NULL){
            if(aux->prox!=NULL){
                x='!';
            }
            arq.write((char*)&x,sizeof(x));
            arq.write((char*)&aux->codigo,sizeof(aux->codigo));
            arq.write((char*)&aux->nome,sizeof(aux->nome));
            arq.write((char*)&aux->ende,sizeof(aux->ende));
            arq.write((char*)&aux->familia,sizeof(aux->familia));
            arq.write((char*)&aux->fp,sizeof(aux->fp));
            aux = aux->prox;
            
             
        }
        
        x='-';
        while(ajuda!= NULL){
            if(aux->prox!=NULL){
                x='!';
            }
            arq.write((char*)&x,sizeof(x));
            arq.write((char*)&ajuda->codigo,sizeof(ajuda->codigo));
            arq.write((char*)&ajuda->codi,sizeof(ajuda->codi));
            arq.write((char*)&ajuda->horas,sizeof(ajuda->horas));
            arq.write((char*)&ajuda->setor,sizeof(ajuda->setor));
            ajuda = ajuda->prox;
            // max1++;
        }
        // arq.write((char*)&max1,sizeof(max1));
        cout<<"salvo com secesso!"<<endl;
        arq.close();
    }else{
        cout<<"Erro ao abrir arquivo"<<endl;
    }
    
}

void carregardados(TLista *lista, TPilha *pilha){
    ifstream arq;
    funcionario *aux, *novo;
    novo = new funcionario;
    Pilha *ajuda;
    char intereger='+';
    char x;
    int max;
    aux = lista->inicio;
    ajuda = pilha->inicio;
    arq.open("funcionario.bin", ios::binary | ios::in);
    
    cout<<"Carregando... aguarde"<<endl;

    if(arq.is_open()){
        arq.read((char*)&x,sizeof(x));
        cout<<x;
        while(intereger==x){
            arq.read((char*)&novo->codigo,sizeof(novo->codigo));
            arq.read((char*)&novo->nome,sizeof(novo->nome));
            arq.read((char*)&novo->ende,sizeof(novo->ende));
            arq.read((char*)&novo->familia,sizeof(novo->familia));
            arq.read((char*)&novo->fp,sizeof(novo->fp));
            arq.read((char*)&x,sizeof(x));
            cout<<x;
            if (lista->inicio == NULL){
                lista->inicio = novo;
                lista->fim = novo;
            }else{
                lista->fim->prox=novo;//encadeamento
                lista->fim=novo;
            }
            
        }
        intereger='-';
        while(intereger==x){
            arq.read((char*)&ajuda->codigo,sizeof(ajuda->codigo));
            arq.read((char*)&ajuda->codi,sizeof(ajuda->codi));
            arq.read((char*)&ajuda->horas,sizeof(ajuda->horas));
            arq.read((char*)&ajuda->setor,sizeof(ajuda->setor));
            ajuda = ajuda->prox;
            arq.read((char*)&x,sizeof(x));
        }
        cout<<"carregado com secesso!"<<endl;
        arq.close();
    }else{
        cout<<"Erro ao abrir arquivo"<<endl;
    }

}

int main(){ 
    int x=0, a, b=0, verdade=1, opcao, remo=0, pexcluir=0;
    string linha;
    //minhas listas
    TLista L1;
    TPilha P1;
    
    fstream arquivo;

    inicializalista(&L1);
    inicializapilha(&P1);
    
    // carregararquivo(&L1, &P1);
    carregardados(&L1, &P1);//
    
    for(;;){//deixa ifinito ate sair kakakakakak
        menu();
        cin>>x;
    
        switch(x){
            case 1:
            inserirfuncionario(&L1);//envia o endereço da lista
            system("pause");
            system("cls");
            break;

            case 2:          
            cout<<"\nInsira o codigo do funcionario: ";
            cin>>a;
            system("cls");
            verdade=1;
            b=buscafuncionario(&L1, &P1, a, verdade); //vai enviar o codigo de busca, se acha retorna 1
            if(b==1){//caso ache o funcionario, insere o projeto
                insereprojeto(&P1, a);
            }else{
                if(b==2){//caso ja tenha 5 projetos, ele informa
                    cout<<"\no funcionario ja esta em 5 projetos!\n";
                }else{
                    cout<<"Nao foi encontrado funcionario!\n";
                }
            }
            system("pause");
            system("cls");
            break;

            case 3:
            cout<<"\nInsira o codigo do funcionario: ";
            cin>>a;
            verdade=0;
            b=buscafuncionario(&L1, &P1, a, verdade);
            if(b==1 || b==2){
                cout<<"\nDigite o codigo do projeto: ";
                cin>>opcao;
                pexcluir=removerprojeto(&P1, opcao);
                if(pexcluir==0){
                    cout<<"Removido com sucesso!\n";
                    diminuir(&L1, a);
                }else{
                    cout<<"Nao foi possivel localiar o projeto!\n";
                }
            }
            system("pause");
            system("cls");
            break;

            case 4:
            while(remo==0){//fiz um laço, pois, n conseguie fazer ele repetir na função infelismente
                remo=remover(&L1);//enquanto remover um, repete o codigo ate n conseguri remover nenhum
            }
            system("pause");
            system("cls");
            break;

            case 5:
            system("cls");
            buscafun(&L1, &P1);//busca todos os funcionarios com seu projetos
            break;

            case 6:
            system("cls");
            cout<<"\n\t\t\tCONTRA-CHEQUE\n";
            salario(&L1, &P1);
            cout<<"\n";
            system("pause");
            system("cls");
            break;

            case 7:
            // salvar(&L1, &P1);
            salvar(&L1, &P1);
            exit(0);//fecha ksksksk
        }
    }

return 0;//retorna 0 kskskskkskskskskskskskskkskskskskskksksksksksksksksk

}