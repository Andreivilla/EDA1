#include<stdlib.h>
#include<stdio.h>
//é uma lista q tu só mexe no topo
typedef struct NO no;
struct lista {
    float info;
    no* prox;
};
typedef struct pilha Pilha;
struct pilha {
    no* topo;
};

//aloca e marca o topo sem botar valores
Pilha* pilha_cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

//cria novo no q aponta prono do topo e dps aponta o topo pra esse no
void push (Pilha* p, float v){
    no* n = (no*) malloc(sizeof(no));
    n->info = v;
    n->prox = p->topo;
    p->topo = n;
}

float pop (Pilha* p, int *controle){ 
    Lista* t;
    float v;
    if (pilha_vazia(p)) {
        *controle = 0;
        return (0);
    }
    t = p->topo;
    v = t->info;
    p->topo = t->prox;
    *controle = 1;
    free(t);
    return v;
}