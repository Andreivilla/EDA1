#include<stdlib.h>
#include<stdio.h>

typedef struct reg{
    int conteudo;
    struct reg *prox;
}celula;
char menu();
celula* crialista(int);
void printLista(celula*);
int nLista(celula*);
int posiValor(celula *lista, int valor);
celula* addInicio(celula *lista);
void addFinal(celula *lista);
void addOrdenado(celula *lista);