#include<stdio.h>
#include<stdlib.h>

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

int menu();
Fila *criar_fila(void);
void insere_fila(Fila*, float);
float retira_fila(Fila*);
void add_no(Fila*);
void print_filas(Fila*);
void executar(Fila*, Fila*, Fila*);