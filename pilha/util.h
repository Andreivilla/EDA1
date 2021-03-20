#include<stdio.h>
#include<stdlib.h>

typedef struct reg nodo;
struct reg{
    int conteudo;
    nodo *esq;
    nodo *dir;
};
typedef nodo *arvore;
arvore *criaArvore(void);