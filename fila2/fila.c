/*reame
funções do menu  
1- adiciona valores nas filas individualmente
2- visualizar os valores nas filas
3- executa a passagem de arguivos de uma vila para outra confomre a prioridade
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct no No;
    struct no {
    float info;
    No* prox;
};

typedef struct fila Fila;
    struct fila {
    No* ini;
    No* fim;
};

int menu();
Fila *criar_fila(void);
void insere_fila(Fila*, float);
float retira_fila(Fila*);
void add_no(Fila*);
void print_filas(Fila*);
void executar(Fila*, Fila*, Fila*);

int main(int agrc, char *argv[]){
    Fila *fila1= criar_fila();
    Fila *fila2 = criar_fila();
    Fila *fila3 = criar_fila();
    int Nlista = 0;

    while(1){
        switch(menu()){
            case 1:
                printf("Qual a prioridade adicionar(1,2,3): ");
                scanf("%d", &Nlista);
                switch(Nlista){
                case 1:
                    add_no(fila1);
                break;
                case 2:
                    add_no(fila2);
                break;
                case 3:
                    add_no(fila3);
                break;
                default:
                    printf("--- Opcao invalida ---\n");
                    break;
                }
                break;
            case 2:
                printf("\n|----------------FILA 1-----------------|\n");
                print_filas(fila1);
                printf("\n|----------------FILA 2-----------------|\n");
                print_filas(fila2);
                printf("\n|----------------FILA 3-----------------|\n");
                print_filas(fila3);
                break;
            case 3:
                executar(fila1, fila2, fila3);
                break;
            case 0:
                return 0;
                break;            
            default:
                break;
        }
    }
    return 0;
}
int menu(){
    int opiscoes[9] = {0, 1, 2, 3};
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
        for(i=0; i<4;i++){
            if(opiscoes[i] == op)
                return op;
        }
        printf("Opcao invalida\n");
    }    
}
Fila *criar_fila(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void insere_fila(Fila* f, float n){
    No* novo = (No*) malloc(sizeof(No));
    novo->info = n;
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