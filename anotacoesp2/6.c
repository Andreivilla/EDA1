#include<stdlib.h>
#include<stdio.h>

//função da questão outras são auxioliares
void movimentaAté(Fila *f, No *c){
    No *ini = f->ini;
    char aux;
    Fila *escape1 = pilha_cria();
    Fila *escape2 = pilha_cria();
    
    //while retira veiculos da frente do caminhão (cracter 'v')
    printf("Carros entram no escape: \n");
    while(c->info = ini->info){
        aux = fila_retira;
        printf("Carro entra no escape 1\n");
        push(escape1, aux);
    }
    printf("Caminhão passa no fiscal\n");
    //while retira carros do escape um e passa para o 2
    printf("Carros mudam de escape: \n");
    while(escape1 != NULL){
        printf("Carro entra no escape 2\n");
        aux = pop(escape1,1);
        push(escape2, aux);
    }
    //carros saem do segundo escapeevão para o fiscal
    while(escape2 != NULL){
        printf("carro sai do escape dois e passa para o fiscal\n");
        pop(escape2);
    }
    
}

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
typedef struct pilha Pilha;
struct pilha {
    No* topo;
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

/*------------------------------------------*/
//aloca e marca o topo sem botar valores
Pilha* pilha_cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

//cria novo no q aponta prono do topo e dps aponta o topo pra esse no
void push (Pilha* p, char v){
    No* n = (No*) malloc(sizeof(No));
    n->info = v;
    n->prox = p->topo;
    p->topo = n;
}

char pop (Pilha* p, int *controle){ 
    No* t;
    char v;
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

