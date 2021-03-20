#include<stdio.h>
#include<stdlib.h>

struct no {
    float info;
    struct no* prox;
};
typedef struct no No;
struct pilha {
    No* prim;
};
typedef struct pilha Pilha;

int menu();
Pilha* criaPilha(void);
No* insereInicio(No* l, float v);
No* ret_ini (No* l);
void printaPilha(Pilha *p);
void push (Pilha*, float);
/*void push (Pilha*, float);
float pop (Pilha*, int*);*/