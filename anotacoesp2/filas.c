#include<stdlib.h>
#include<stdio.h>
//estruturas
typedef struct no No;
struct no {
float info;
    No* prox;
};
typedef struct fila Fila;
struct fila {
    No* ini;
    No* fim;
};

//Retira elemento do inicio
No * retira_inicio(No *l, float *valor){
No *p;
if(l==NULL){//nada para retirar
    return(l);
}
else{
    p=l->prox;//aponta pra dpsde l
    *valor=l->info;
    free(l);
    return(p);
    }
}
//