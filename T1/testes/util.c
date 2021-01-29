#include"util.h"
char menu(){
    char *opiscoes = "012345678";
    char op;
    int i;
    fflush(stdin);
    printf("|-----------------------------------------|\n");
    printf("|        CADASTRO DE TAREFAS              |\n");
    printf("|_________________________________________|\n");
    printf("|           MENU DE OPCOES                |\n");
    printf("|-----------------------------------------|\n");
    printf("| 1 -INCLUIR NOVA TAREFA                  |\n");
    printf("| 2 -VISUALIZAR TAREFAS CADASTRADAS       |\n");
    printf("| 3 -EXCLUIR TAREFA                       |\n");
    printf("| 4 -EDITAR TAREFA                        |\n");
    printf("| 5 -CARREGAR ARQUIVO DE TAREFAS          |\n");
    printf("| 6 -GERAR ARQUIVO DE TAREFAS             |\n");
    printf("| 7 -COMPUTAR AGENDA DO DIA               |\n");
    printf("| 8 -SALVARA AGENDA DO DIA                |\n");
    printf("| 0 -SAIR                                 |\n");
    printf("|-----------------------------------------|\n");
    
    while (1){
        scanf("%c", &op);fflush(stdin);
        for(i=0; i<10;i++){
            if(opiscoes[i] == op)
                return op;
        }
        printf("Opcao invalida\n");
    }
    
}