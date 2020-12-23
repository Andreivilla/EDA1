#include<stdio.h>
#include<stdlib.h>
//ex4
typedef struct reg{
    int matricula;
    char nome[100];
    float media;
    struct reg *prox;
}celula;
float media_geral(celula *lista){
    int countAlunos=0;
    float somaMedia=0;
    float mediaTurma;
    
    while(lista->prox != NULL){
        somaMedia += lista->media;
        countAlunos++;
        lista = lista->prox;
    }    
    mediaTurma = (float) somaMedia/countAlunos;
    return mediaTurma;
}
void maiores_media_geral(celula *lista, float mediaGeral){
    printf("\n--------------------------\n");
    printf("\nmedias maiores que a media geral\n");    
    while(lista->prox != NULL){
        if(lista->media > mediaGeral){        
        //printf("Aluno: %s\n", lista->nome);
        printf("Matricula: %d\n", lista->matricula);
        printf("Media: %.2f\n", lista->media);        
        lista = lista->prox;
        }
    }
    printf("\n--------------------------\n");
}

//func cria lista
celula* crialista(int tam){
    int i;
    celula *no, *lista = NULL;
    no = (celula*) malloc(sizeof(celula));
    lista = no;
    if(no == NULL){
        printf("erro de alocacao\n");
    }else{
        for(i=0; i<tam; i++){
            printf("\n------%d-----\n", i);
            printf("matricula: ");
            scanf("%d", &no->matricula);fflush(stdin);
            printf("Media: ");
            scanf("%f", &no->media);fflush(stdin);
            no->prox = (celula*) malloc(sizeof(celula));
            no = no->prox;
        }
    }
    no->prox = NULL;    
    return lista;
}
//printa lista
void printLista(celula *lista){
    printf("\n----------------printa lista----------------\n");
    while(lista->prox != NULL){
        printf("matricula: %d\n", lista->matricula);
        printf("media: %f\n", lista->media);
        lista = lista->prox;
    }    
}
//ex5
celula* inicio(celula *lista, int posi){
    celula *temp = (celula*) malloc(sizeof(celula));
    celula *percorre;
    int i;
    percorre = lista;
    for(i=0; i<posi; i++){
        percorre = percorre->prox;
    }
    temp->matricula = percorre->matricula;
    temp->media = percorre->media;
    temp->prox = lista;
    temp->nome = percorre->nome;
    for(i=0; i<posi-1; i++){
        lista = lista->prox;
    }
    lista->prox = lista->prox->prox;
    return temp;
}




//main para testes
int main(int agrc, char *argv[]){
    int tam;
    celula *lista;
    scanf("%d", &tam);fflush(stdin);
    lista = crialista(tam);
    printLista(lista);
    lista = inicio(lista, 2);
    //printf("\nMedia geral: %.2f\n", media_geral(lista));
    //maiores_media_geral(lista, media_geral(lista));
    printLista(lista);
    return 0;
}