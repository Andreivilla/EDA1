#include "util.h"
int main(int agrc, char *argv[]){
    celula *lista;
    int tam, valor;
    while (1){
        switch (menu()){
            case '0':
                return 0;
                break;
            case '1':
                printf("Tamanho da lista: ");
                scanf("%d", &tam);fflush(stdin);
                lista = crialista(tam);
                break;
            case '2':
                printf("\n----PRINTA LISTA----\n");
                printLista(lista);
                printf("\n--------------------\n");
                break;
            case '3':
                /*printf("\n----TAMANHO DA LISTA----\n");
                printf("%d", lenLista(lista));
                printf("\n--------------------\n");*/
                break;
            case '4':
                /*printf("\n----POSICAO DO VALOR----\n");
                printf("Que valor procurar: ");
                scanf("%d", &valor);fflush(stdin);
                printf("%d", posiValor(lista, valor));
                printf("\n--------------------\n");*/
                break;
            case '5':
                /*printf("Digite um valor: ");
                scanf("%d", &valor);
                lista = addInicio(lista, valor);*/
                break;
            case '6':
                printf("Digite um valor: ");
                scanf("%d", &valor);fflush(stdin);
                addFinal(lista, valor);
                break;
            case '7':
                /*printf("Digite um valor: ");
                scanf("%d", &valor);fflush(stdin);
                lista = inserirOrdenado(lista, valor);*/
                break;
        }
    }
    return 0;
}