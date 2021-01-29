#include<stdio.h>
#include<stdlib.h>
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

typedef struct{
    int id;
    reg dados;
}Tarefa;


char menu();