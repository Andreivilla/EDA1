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
                scanf("%d", &tam);
                lista = crialista(tam);
                break;
            case '2':
                printf("\n----PRINTA LISTA----\n");
                printLista(lista);
                printf("\n--------------------\n");
                break;
            case '3':
                printf("\n----TAMANHO DA LISTA----\n");
                printf("%d", nLista(lista));
                printf("\n--------------------\n");
                break;
            case '4':
                printf("\n----POSICAO DO VALOR----\n");
                printf("Que valor procurar: ");
                scanf("%d", &valor);
                printf("%d", posiValor(lista, valor));
                printf("\n--------------------\n");
                break;
            case '5':
                lista = addInicio(lista);
                break;
            case '6':
                addFinal(lista);
                break;
            case '7':
                addOrdenado(lista);
                break;
        }
    }
    return 0;
}