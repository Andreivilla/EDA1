#include"util.h"
char menu(){
    int opiscoes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int op;
    int i;
    printf("|_________________________________________|\n");
    printf("|           MENU DE OPCOES                |\n");
    printf("|-----------------------------------------|\n");
    printf("| 1 - ADICIONAR VALOR                     |\n");
    printf("| 2 - VISUALIZAR FILAS                    |\n");
    printf("| 3 - EXECUTAR PROGRAMAS                  |\n");
    printf("| 0 - SAIR                                |\n");
    printf("|-----------------------------------------|\n");
    
    
    while (1){
        scanf("%d", &op);fflush(stdin);
        for(i=0; i<9;i++){
            if(opiscoes[i] == op)
                return (char) (op + 48);
        }
        printf("Opcao invalida\n");
    }    
}
Fila *criar_fila(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void insere_fila(Fila* f, float v){
    No* novo = (No*) malloc(sizeof(No));
    novo->info = v;
    novo->prox = NULL;
    if(f->fim != NULL) 
        f->fim->prox = novo;
    else
        f->ini = novo;
    f->fim = novo;
}

float retira_fila(Fila* f){
    No* t;
    float v;
    if(f == NULL){
        printf("Fila vazia.\n");
        return(1);
    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if(f->ini == NULL)
        f->fim = NULL;
    free(t);
    return v;
}
void add_no(Fila* f){
    float n;
    while(1){
        printf("Qual valor adicionar(-1 para parar): ");
        scanf("%f", &n);
        if(n == -1)
            break;                
        insere_fila(f, n);
    }    
}

void print_filas(Fila *f){
    No *fila = f->ini;
    if(fila == NULL){
        printf("ERRO: lista vazia\n");
    }else{
        while(fila->prox != NULL){
            printf("%2.2f\n", fila->info);
            fila = fila->prox;
        }
        fila = f->fim;
        printf("%2.2f\n", fila->info);        
    }
}
void executar(Fila *f1, Fila *f2, Fila *f3){
    float aux;    
    while(f3->ini != NULL){
        aux = retira_fila(f3);
        insere_fila(f2, aux);
    }
    while(f2->ini != NULL){
        aux = retira_fila(f2);
        insere_fila(f1, aux);
    }    
}