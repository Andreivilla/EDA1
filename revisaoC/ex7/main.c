#include "util.h"

int main(int argc, char *argv[])
{
    funcionario funcionarios[80];
    int posicao, nFuncionarios = 1;

    //funcionarios = malloc(nFuncionarios * sizeof(funcionario));
    while (1){
        switch (menu())
        {
        case '1':
            printf("Quantos funcionarios adicionar: \n");
            scanf("%d", &nFuncionarios);fflush(stdin);
            //funcionarios = realloc(funcionarios, nFuncionarios);
            printf("%d\n", (int)(sizeof(funcionarios)/sizeof(funcionarios[0])));
            lerFuncionarios(funcionarios);
            break;
        case '2':
            imprimirFuncionarios(funcionarios);
            break;
        case '3':
            printf("Qual usuario imprimir: ");
            scanf("%d", &posicao);fflush(stdin);
            imprimirFuncionario(funcionarios, posicao);
            break;
        case '4':
            printf("Posiaco maior salario: %d\n", maiorSalario(funcionarios));
            break;
        case '5':
            printf("Posiaco menor salario: %d\n", menorSalario(funcionarios));
            break;
        case '6':
            printf("Media do salario: %f\n", mediaSalario(funcionarios));
            break;
        case '7':
            incluirFuncionario(funcionarios);
            break;
        case '8':
            printf("Qual posicao remover: ");
            scanf("%d", &posicao);fflush(stdin);
            removerFuncionario(funcionarios, posicao);
            break;
        case '0':
            return 0;
            break;
        }
    }
}