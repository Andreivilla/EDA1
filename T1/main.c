#include"util.h"
int main(int agrc, char *argv[]){
    int id;
    tarefa *lista_tarefas = NULL;
    
    lista_tarefas = (tarefa*) malloc(sizeof(tarefa));
    lista_tarefas->id = 0;
    lista_tarefas->prox = NULL;
    
    while(1){
        switch (menu()){
            case '1':
                add_tarefa(lista_tarefas);
                break;
            case '2':
                visualizar_tarefas(lista_tarefas);
                break;
            case '3':
                printf("ID da tarefa qu deseja remover: ");
                scanf("%d", &id);                
                lista_tarefas = remove_tarefa(lista_tarefas, id);
                break;
            case '4':
                printf("ID da tarefa qu deseja editar: ");
                scanf("%d", &id);
                editar_tarefa(lista_tarefas, id);
                break;
            case '5':
                printf("...\n");
                break;
            case '6':
                printf("...\n");
                break;
            case '7':
                printf("...\n");
                break;
            case '8':
                printf("...\n");
                break;
            case '0':
                return 0;
                break;            
            default:
                break;
        }
    }
    return 0;
}