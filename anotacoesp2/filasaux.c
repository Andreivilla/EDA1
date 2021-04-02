#include<stdlib.h>
#include<stdio.h>
//estrutura com axiliar
typedef struct no No;
struct no {
    char info;// carro 'c' caminhão com vacinas 'v'
    No* prox;
};
typedef struct fila Fila;
struct fila {
    No* ini;//linkar no inicio
    No* fim;//linkar no fim
};

//cria fila mas não aloca valores
Fila* fila_cria (void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;//inicio e fim não apontam pra nada
    return f;
}

//insele no final da fila
void fila_insere (Fila* f, char v){
    No* novo = (No*) malloc(sizeof(No));
    novo->info = v;
    novo->prox = NULL;
    if (f->fim != NULL)//verifica se não esta vazio e adiciona
        f->fim->prox = novo;
    else // se for apneas um elemento
        f->ini = novo;
        f->fim = novo;
}

char fila_retira (Fila* f){
    No* t;
    float v;
    if (f == NULL){
        printf("Fila vazia.\n");
        return(1);
    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL)//se não tem inicio 
        f->fim = NULL;// não tem fim
    free(t);
    return v;
}
void movimentaAté(Fila *f, No *c){
    No *ini = f->ini;
    Fila *escape1 = fila_cria();
    Fila *escape2 = fila_cria();
    while(c->info = ini->info){
        

    }
    
}