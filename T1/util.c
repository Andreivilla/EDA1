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
        scanf("%d", &op);fflush(stdin);
        for(i=0; i<9;i++){
            if(opiscoes[i] == op)
                return (char) (op + 48);
        }
        printf("Opcao invalida\n");
    }    
}
void visualizar_tarefas(tarefa *lista){
    printf("|-----------------------------------------|\n");
    printf("|           TAREFAS CADASTRADAS           |\n");
    printf("|-----------------------------------------|\n");
    while(lista->prox != NULL){
        printf("|-----------------------------------------|\n");
        printf(" Tarefa: %s\n" ,lista->dados.nome);fflush(stdin);
        printf(" id: %d\n", lista->id);
        printf(" Inicio: %d/%d/%d - %d:%d\n", lista->dados.inicio.dia, lista->dados.inicio.mes, lista->dados.inicio.ano, lista->dados.inicio.hora, lista->dados.inicio.minuto);
        printf(" deadline: %d/%d/%d - %d:%d\n", lista->dados.deadline.dia, lista->dados.deadline.mes, lista->dados.deadline.ano, lista->dados.deadline.hora, lista->dados.deadline.minuto);
        printf(" Duracao: %d minutos\n", lista->dados.duracao);
        lista = lista->prox;
    }
    printf("|-----------------------------------------|\n"); 
}
void add_tarefa(tarefa *lista){
    int nid=0;
    while(lista->prox != NULL){
        nid = lista->id;
        lista = lista->prox;
    }
    printf("Tarefa: ");
    scanf("%s", lista->dados.nome);
    add_reg(&lista->dados);
    
    
    lista->id = nid+1;
    lista->prox = (tarefa*) malloc(sizeof(tarefa));
    lista = lista->prox;
    lista->prox = NULL;
}
void add_tempo(tempo *tmp){
    printf("Dia: ");
    scanf("%d", &tmp->dia);
    printf("Mes: ");
    scanf("%d", &tmp->mes);
    printf("Ano: ");
    scanf("%d", &tmp->ano);
    printf("Hora: ");
    scanf("%d", &tmp->hora);
    printf("Minuto: ");
    scanf("%d", &tmp->minuto);

}
void add_reg(reg *regis){
    printf("---Inicio---\n");
        add_tempo(&regis->inicio);
    printf("---Deadline---\n");
        add_tempo(&regis->deadline);
        
    regis->duracao = (60*regis->deadline.hora + regis->deadline.minuto) - (60*regis->inicio.hora + regis->inicio.minuto);

}
tarefa* remove_tarefa(tarefa *lista, int id){
    tarefa *aux1 = (tarefa*) malloc(sizeof(tarefa));
    tarefa *aux2 = (tarefa*) malloc(sizeof(tarefa));
    aux1 = lista;
    aux2 = lista->prox;
    if(aux1->id == id){
        return aux2;
    }else{
        while(aux2 != NULL && aux2->id != id){
            aux1 = aux2;
            aux2 = aux2->prox;
        }
        if(aux2 != NULL){
            aux1->prox = aux2->prox;
            free(aux2);
        }
        return lista;
    }
}

void editar_tarefa(tarefa *lista, int id){
    while(lista->id != id && lista->prox != NULL){
        lista = lista->prox;
    }
    printf("Tarefa: ");
    scanf("%s", lista->dados.nome);
    add_reg(&lista->dados);
}