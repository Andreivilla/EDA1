#include"util.h"
//retornar a posição do vetor que armazena o funcionário de maior salário;
int maiorSalario(funcionario *listaFuncionarios){
    int i, posicaoMaiorSalario;
    float valorMaiorSalario;

    for(i=0; i<nFuncionarios; i++){
        if(listaFuncionarios[i].salario > valorMaiorSalario || i==0){
            valorMaiorSalario = listaFuncionarios[i].salario;
            posicaoMaiorSalario = i;
        }
    }
    return posicaoMaiorSalario;
}
//retornar a posição do vetor que armazena o funcionário de menor salário; 
int menorSalario(funcionario *listaFuncionarios){
    int i, posicaoMenorSalario;
    float valorMenorSalario;

    for(i=0; i<nFuncionarios; i++){
        if(listaFuncionarios[i].salario < valorMenorSalario || i==0){
            valorMenorSalario = listaFuncionarios[i].salario;
            posicaoMenorSalario = i;
        }
    }
    return posicaoMenorSalario;
}
//imprimir os dados de um funcionário de acordo com sua posição no vetor;
void imprimirFuncionario(funcionario func){
    printf("Nome: %s\n", func.nome);
    printf("Salario: %.2f\n", func.salario);
}
//retornar a média dos salários dos funcionários
float mediaSalario(funcionario *listaFuncionarios){
    int i;
    float somaSalario=0;
    for(i=0; i<nFuncionarios;i++)
        somaSalario += listaFuncionarios[i].salario;
    return somaSalario/nFuncionarios;
}
//imprimir os dados de todos os funcionários
void imprimirFuncionarios(funcionario *listaFuncionarios){
    int i;
    for(i=0; i<nFuncionarios; i++){
        imprimirFuncionario(listaFuncionarios[i]);
    }
}
void lerFuncionarios(funcionario *listaFuncionarios){
    int i;
    for(i=0; i<nFuncionarios; i++){
        scanf("%s", listaFuncionarios[i].nome);fflush(stdin);
        scanf("%f", &listaFuncionarios[i].salario);fflush(stdin);
    }
}