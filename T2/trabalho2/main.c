#include"util.h"
int main(int agrc, char *argv[]){
    int id;
    tarefa *lista_tarefas = NULL;

    lista_tarefas = (tarefa*) malloc(sizeof(tarefa));
    lista_tarefas->id = 0;
    lista_tarefas->prox = NULL;
    while(1){
        switch (menu()){
            case '1'://INCLUIR NOVA TAREFA
                add_tarefa(lista_tarefas);
                break;
            case '2'://VISUALIZAR TAREFAS CADASTRADAS
                visualizar_tarefas(lista_tarefas);
                break;
            case '3'://EXCLUIR TAREFA
                printf("ID da tarefa qu deseja remover: ");
                scanf("%d", &id);                
                lista_tarefas = remove_tarefa(lista_tarefas, id);
                break;
            case '4'://EDITAR TAREFA
                printf("ID da tarefa qu deseja editar: ");
                scanf("%d", &id);
                editar_tarefa(lista_tarefas, id);
                break;
            case '5'://CARREGAR ARQUIVO DE TAREFAS
                carregar_arquivo(lista_tarefas);
                break;
            case '6'://GERAR ARQUIVO DE TAREFAS
                salvar(lista_tarefas);
                printf("\n--arquivos baixados--\n");
                break;
            case '7'://COMPUTAR AGENDA DO DIA
                printf("...\n");
                break;
            case '8'://SALVARA AGENDA DO DIA
                printf("...\n");
                break;
            case '0'://SAIR
                return 0;
                break;            
            default:
                break;
        }
    }
    return 0;
}