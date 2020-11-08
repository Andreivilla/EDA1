#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[40];
    float salario;
}funcionario;
#define nFuncionarios 6
int maiorSalario(funcionario *);
int menorSalario(funcionario *);
float mediaSalario(funcionario *);
void imprimirFuncionario(funcionario);
void imprimirFuncionarios(funcionario *);
void lerFuncionarios(funcionario *);