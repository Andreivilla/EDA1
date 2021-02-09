#include"util.h"
int main(int agrc, char *argv[]){
    tarefa *fila1 = NULL;//, *fila2, *fila3;
    tarefa *teste = (tarefa*) malloc(sizeof(tarefa));

    scanf("%[^\n]", teste->nome);fflush(stdin);
    int tam, Nlista = 0;
    while(1){
        switch (menu()){
            case '1':
                /*printf("lista inserir: ");
                scanf("%d", &Nlista);
                printf("Tamanho da lista: ");
                scanf("%d", &tam);fflush(stdin);*/
                tam = 3; Nlista = 1; 
                if(Nlista == 1)
                    fila1 = criar_fila(tam);
                /*else if(Nlista == 2)
                    fila2 = criar_fila(tam);
                else if(Nlista)
                    fila2 = criar_fila(tam);
                else
                    printf("Lista não existe");*/
                break;
            case '2':
                printf("\n|----------------FILA 1-----------------|\n");
                print_filas(fila1);
                /*printf("\n|----------------FILA 2-----------------|\n");
                print_filas(fila2);
                printf("\n|----------------FILA 3-----------------|\n");
                print_filas(fila3);*/
                break;
            case '3':
                inserir_no(fila1, teste);
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