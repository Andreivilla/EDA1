#include "util.h"
char menu(){
    char *vetop = "01234567";
	char op;
    int i;
    while(1){       
        printf("\n---- Menu de opcoes ----\n");
        printf("1 - inserir n nos\n");
        printf("2 - imprimir lista\n");
        printf("3 - contar n valores da lista\n");
        printf("4 - encontrar valor na lista\n");
        printf("5 - inserir valor no inicio da lista\n");
        printf("6 - inserir valor no final da lista\n");
        printf("7 - inserir valor ordenado na lista\n");
        printf("0 - sair\n");

        scanf("%c", &op);fflush(stdin);
        for(i=0; i<9; i++){
            if(vetop[i] == op)
                return op;
        }
        printf("\n----Opicao invalida----\n\n");
    }
}
celula* crialista(int tam){
    int i, valor;
    celula *no, *lista = NULL;
    no = (celula*) malloc(sizeof(celula));
    lista = no;
    if(no == NULL){
        printf("erro de alocacao");
    }else{
        printf("valor: ");
        scanf("%d", &no->conteudo);fflush(stdin);
        no->prox = (celula*) malloc(sizeof(celula));
        no->ant = (celula*) malloc(sizeof(celula));
        no = no->prox;
    }
    for(i=0; i<tam;i++){
        printf("Digite um valor: ");
        scanf("%d", &valor);fflush(stdin);
        addFinal(lista, valor);
    }
    no->ant = NULL;
    no->prox = NULL;
    return lista;
}
void printLista(celula *lista){
    int count = 0;
    while(lista->prox != NULL){
        printf("valor %d: %d\n", count, (lista->conteudo));
        count++;
        lista = lista->prox;
    }
}
/*
int lenLista(celula *lista){
    int count=0;
    while(lista->prox != NULL){
        count++;
        lista = lista->prox;
    }
    return count;    
}
int posiValor(celula *lista, int valor){
    int posicao = -1;
    int count=0;
    while(lista->prox != NULL){
        if(valor == lista->conteudo){
            posicao = count;
            break;
        }
        lista = lista->prox;
        count++;
    }
    if(posicao != -1)
        return posicao;
    else
        printf("\nlista nao possui o valor\n");
    
    return -1;
}
celula* addInicio(celula *lista, int valor){
    celula *add;
    add = (celula*) malloc(sizeof(celula));
    add->conteudo = valor;
    add->prox = lista;
    return add;
}*/
void addFinal(celula *lista, int valor){
    celula *p = (celula*) malloc(sizeof(celula));
    
    while(lista->prox != NULL){
        if(lista->prox == NULL)
            lista->prox = (celula*) malloc(sizeof(celula));
            lista->ant = p;
        else{
            lista = lista->prox;            
        }
    }
    lista->conteudo = valor;
    lista->prox = (celula*) malloc(sizeof(celula));
    lista = lista->prox;
    lista->prox = NULL;
}
/*
void addmeio(celula *lista, int posicao, int valor){
    int i;
    celula *novo = (celula*) malloc(sizeof(celula));
    celula *aux = (celula*) malloc(sizeof(celula));

    novo->conteudo = valor;
    for(i=0; i<posicao; i++){
        lista = lista->prox;
    }
    aux = lista->prox;
    lista->prox = novo;
    novo->prox = aux;
}
celula* inserirOrdenado(celula *lista, int valor){
    int posi = 0;
    celula *posicao = (celula*) malloc(sizeof(celula));
    posicao = lista;
    while(posicao->prox != NULL){
        if(posicao->prox->conteudo > valor){
            break;
        }
        posicao = posicao->prox;
        posi++;
    }
    if(posi == 0){
        lista = addInicio(lista, valor);
        printLista(lista);
    }else if(posi == lenLista(lista)-1){
        addFinal(lista, valor);
    }else{
        addmeio(lista, posi, valor);
    }
    return lista;
}*/