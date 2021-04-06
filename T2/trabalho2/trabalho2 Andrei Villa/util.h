#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;    
}tempo;

typedef struct{
    char nome[100];
    int duracao;
    tempo inicio;
    tempo deadline;
}reg;

typedef struct x{
    int id;
    reg dados;
    struct x *prox;
}tarefa;

char menu();
void visualizar_tarefas(tarefa *lista);
void add_tarefa(tarefa*);
void add_tempo(tempo*);
void add_reg(reg*);
tarefa* remove_tarefa(tarefa *lista, int id);
void editar_tarefa(tarefa *lista, int id);
int verifica_data(int dia, int mes, int ano, int hora, int minuto);
tarefa *agenda_do_dia(tarefa *lista);

//arquivos
void carregar_arquivo(tarefa *lista);
void ler_linha(tarefa *t, FILE *fl);
void salvar_linha(tarefa *t, FILE *fl);
void salvar(tarefa *lista, int);


//mergesort
tarefa *merge(tarefa *e, tarefa *d);
tarefa *split(tarefa *l);
tarefa *mergeSort(tarefa *l);

//otimiza
tarefa *otimiza(tarefa *lista);

//apagar 
void printa_tarefa(tarefa *t);



