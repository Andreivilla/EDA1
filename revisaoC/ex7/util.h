#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[40];
    float salario;
}funcionario;

int len(funcionario*);
int maiorSalario(funcionario *);
int menorSalario(funcionario *);
float mediaSalario(funcionario *);
void imprimirFuncionario(funcionario*, int);
void imprimirFuncionarios(funcionario *);
void lerFuncionario(funcionario*, int);
void lerFuncionarios(funcionario *);
char menu();
void incluirFuncionario(funcionario *);
void removerFuncionario(funcionario *, int);