#include<stdio.h>
#include<stdlib.h>

typedef struct x{
    char nome[100];
    struct x *prox;
}tarefa;

char menu();
tarefa *criar_fila(int tam);
void print_filas(tarefa *fila);
void inserir_no(tarefa *fila, tarefa *inserir);