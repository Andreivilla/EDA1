#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int info;
    struct lista *proximo;
}lista;

lista *criarElemento(int info);
void inserirFim(lista **listaTotal, lista *elemento);
void printaLista(lista**);
void inserirInicio(lista **listaTotal, lista *elemento);
void carregar(lista **a);
void descarregar(lista **a);

int main(int agrc, char *argv[]){    
    lista *list = NULL, *list1 = NULL;
    //lista *ele;
    int op, inf;
    
    printf("definir valor raiz: ");
            scanf("%d", &inf);
    inserirInicio(&list, criarElemento(inf));

    printf("0- fechar\n");
    printf("1- definir struct\n");
    printf("2- Carregar struct\n");
    printf("3- Descarregar struct\n");
    printf("4- exbir struct\n");
    
    while(1){
        printf("Oq fzr?\n");
        scanf("%d", &op);
        switch(op){
        case 0:
            return 0;
            break;
        case 1:
            printf("Valor inserir: ");
            scanf("%d", &inf);
            inserirFim(&list, criarElemento(inf));
            break;
        case 2:
            carregar(&list);
            break;
        case 3:
            descarregar(&list1);
            printaLista(list1);
            break;
        case 4:
            printf("\n---Structs---\n");
            printaLista(&list);
            printf("\n-------------\n");
            break;
        default:
            printf("ERRO\n");
            break;
        }
    }
    return 0;
}
lista *criarElemento(int info){
    lista *no = (lista*) malloc(sizeof (lista));
    if (no == NULL)
        return NULL;
    no->info = info;
    no->proximo = NULL;
    return no;
}
void inserirFim(lista **listaTotal, lista *elemento){
    lista *elementoAuxiliar;
    elementoAuxiliar = *listaTotal;
    /* Percorre a lista ateh encontrar o ultimo elemento */
    while (elementoAuxiliar->proximo != NULL){
        elementoAuxiliar = (lista *) elementoAuxiliar->proximo;
    }
    
        elementoAuxiliar->proximo = (struct lista *) elemento;
}
void printaLista(lista **listaTotal){
    lista *elementoAuxiliar;
    elementoAuxiliar = *listaTotal;
    /* Percorre a lista ateh encontrar o ultimo elemento */
    while (elementoAuxiliar->proximo != NULL){
        printf("%d ", elementoAuxiliar->info);
        elementoAuxiliar = (lista *) elementoAuxiliar->proximo;
    }
    printf("\n");
}
void inserirInicio(lista **listaTotal, lista *elemento){
    if(*listaTotal == NULL){
        *listaTotal = elemento;
    }
    else{
        elemento->proximo =(struct lista *) *listaTotal;
        *listaTotal = elemento;
    }
} 
/*void inserirInicio(lista **listaTotal, lista *elemento){
    if(*listaTotal == NULL){
        *listaTotal = elemento;
    }
    else{
        elemento->proximo =(struct lista *) *listaTotal;
        *listaTotal = elemento;
    }
}*/

void carregar(lista **a){//carrega as structs no .bin
    lista *elementoAuxiliar;
    elementoAuxiliar = *a;
    FILE *file = fopen("structs.bin", "wb");
    while(elementoAuxiliar->proximo != NULL){
        fwrite(&elementoAuxiliar, sizeof(lista), 1, file);
    }        
    fclose(file);
}
void descarregar(lista **a){//descarrega as strucs do .bin
    lista *elementoAuxiliar;
    elementoAuxiliar = *a;
    int count = 0;
    while(elementoAuxiliar->proximo != NULL){
        count++;
    }  
    FILE *file = fopen("structs.bin", "rb");
    fread(a, sizeof(lista), count, file);
    fclose(file);
}