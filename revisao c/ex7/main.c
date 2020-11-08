#include "util.h"

int main(int argc, char *argv[]){
    funcionario funcionarios[nFuncionarios];
    lerFuncionarios(funcionarios);  
    
    imprimirFuncionarios(funcionarios);

    printf("posicao maior salario: %d\n", maiorSalario(funcionarios));
    printf("posicao menor salario: %d\n", menorSalario(funcionarios));
    printf("media: %.2f\n", mediaSalario(funcionarios));
    return 0;
}
