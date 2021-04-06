#include"util.h"
int main(int agrc, char *argv[]){
    int id;
    tarefa *lista_tarefas = (tarefa*) malloc(sizeof(tarefa));
    tarefa *lista_tarefas_dia ;
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
                printf("\n--arquivos baixados--\n");
                break;
            case '6'://GERAR ARQUIVO DE TAREFAS
                salvar(lista_tarefas, 1);
                printf("\n--arquivos salvos--\n");
                break;
            case '7'://COMPUTAR AGENDA DO DIA
                    //cria lista de tarefas do dia
                    lista_tarefas_dia = agenda_do_dia(lista_tarefas);
                    //ordena tarefaz em ordem de deadline
                    lista_tarefas_dia = mergeSort(lista_tarefas_dia);
                    //otimiza
                    lista_tarefas_dia = otimiza(lista_tarefas_dia);
                    visualizar_tarefas(lista_tarefas_dia);
                break;
            case '8'://SALVARA AGENDA DO DIA
                salvar(lista_tarefas_dia, 2);
                printf("--arquivos salvos--\n");
                
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