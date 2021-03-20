#include"util.h"
int menu(){
    int op;
    int i;
    printf("|_________________________________________|\n");
    printf("|           MENU DE OPCOES                |\n");
    printf("|-----------------------------------------|\n");
    printf("| 1 - VISUALIZAR PILHAS                   |\n");
    printf("| 2 - EXECUTAR PROGRAMAS                  |\n");
    printf("| 0 - SAIR                                |\n");
    printf("|-----------------------------------------|\n");
    
    
    while (1){
        scanf("%d", &op);
        for(i=0; i<3;i++){
            if(op == i)
                return op;
        }
        printf("Opcao invalida\n");
    }    
}
Pilha* criaPilha(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}
No* insereInicio(No* l, float v){
    No* p = (No*) malloc(sizeof(No));
    
    p->info = v;
    p->prox = l;
    return p;
}
No* ret_ini (No* l){
    No* p = l->prox;
    free(l);
    return p;
}
void printaPilha(Pilha *p){
    No *n = p->prim;
    printf("insere inicio: %f\n", p->prim->info);
    while(n != NULL){
        printf("%.2f\n", n->info);
        n = n->prox;
    }    
}
void push (Pilha* p, float v){
    p->prim = insereInicio(p->prim,v);
}
/*float pop (Pilha* p){
    float v;
    if (vazia(p)) {
    printf("Pilha vazia.\n");
    exit(1); // aborta programa
}
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}*/