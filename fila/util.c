#include"util.h"
char menu(){
    int opiscoes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int op;
    int i;
    fflush(stdin);
    printf("|-----------------------------------------|\n");
    printf("|        CADASTRO DE TAREFAS              |\n");
    printf("|_________________________________________|\n");
    printf("|           MENU DE OPCOES                |\n");
    printf("|-----------------------------------------|\n");
    printf("| 1 - CRIAR FILAS                         |\n");
    printf("| 2 - VISUALIZAR FILAS                    |\n");
    printf("| 3 - EXECUTAR PROGRAMAS                  |\n");
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
tarefa *criar_fila(int tam){
    tarefa *fila, *no;
    int i;
    no = (tarefa*) malloc(sizeof(tarefa));
    fila = no;
    for(i=0; i<tam; i++){
        printf("Digite a tarefa: ");
        scanf("%[^\n]", no->nome);fflush(stdin);
        no->prox = (tarefa*) malloc(sizeof(tarefa));
        no = no->prox;
    }
    no->prox = NULL;
    return fila;
}
void print_filas(tarefa *fila){
    if(fila != NULL){
        while(fila->prox != NULL){
            printf("%s\n", fila->nome);
            fila = fila->prox;
        }
    }
}
