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
arvore *criaArvore(void){
    return NULL;
}
nodo* arv_cria (int c, nodo* sae, nodo* sad){
    nodo* p=(nodo*)malloc(sizeof(nodo));
    if(p==NULL) exit(1);
    p->conteudo = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}