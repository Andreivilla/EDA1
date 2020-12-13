#include "util.h"
char menu(){
    char *vetop = "012345678";
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
        //printf("7 - incluir funcionarios\n");
        //printf("8 - remover um funcionario\n");
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
    int i;
    celula *no, *lista = NULL;
    no = (celula*) malloc(sizeof(celula));
    lista = no;
    if(no == NULL){
        printf("erro de alocacao");
    }else{
        for(i=0; i<tam; i++){
            //no->conteudo = 0;
            printf("valor %d: ", i);
            scanf("%d", &no->conteudo);
            no->prox = (celula*) malloc(sizeof(celula));
            no = no->prox;
        }
    }
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
int nLista(celula *lista){
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
celula* addInicio(celula *lista){
    celula *add;
    add = (celula*) malloc(sizeof(celula));
    printf("Digite um valor: ");
    scanf("%d", &add->conteudo);
    add->prox = lista;
    return add;
}
void addFinal(celula *lista){
    while(lista->prox != NULL){
        printf("%d\n", lista->conteudo);
        if(lista->prox == NULL)
            lista->prox = (celula*) malloc(sizeof(celula));
        else
            lista = lista->prox;
    }
    
    printf("Digite um valor: ");
    scanf("%d", &lista->conteudo);
    printf("conteudo fora: %d\n", lista->conteudo);
    lista->prox = (celula*) malloc(sizeof(celula));
    lista = lista->prox;
    lista->prox = NULL;
}
void addOrdenado(celula *lista){
    int i, posicao;
    celula *novo = (celula*) malloc(sizeof(celula));
    celula *aux = (celula*) malloc(sizeof(celula));

    printf("qual posicao adicionar(0-n)? ");
    scanf("%d", &posicao);
    printf("Inserir Valor: ");
    scanf("%d", &novo->conteudo);

    for(i=0; i<posicao-1; i++){
        lista = lista->prox;
    }
    aux = lista->prox;
    lista->prox = novo;
    novo->prox = aux;
    printf("%d\n", lista->conteudo);
}