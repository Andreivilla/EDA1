#include<stdlib.h>
#include<stdio.h>

typedef struct reg{
    int conteudo;
    struct reg *prox;
    struct reg *ant;
    
}celula;
char menu();
celula* crialista(int);
void printLista(celula*);

/*int lenLista(celula*);
int posiValor(celula *lista, int valor);
celula* addInicio(celula *lista, int valor);
*/
void addFinal(celula *lista, int valor);
/*
void addmeio(celula *lista, int posicao, int valor);
celula* inserirOrdenado(celula *lista, int valor);*/