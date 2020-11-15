#include"util.h"
int len(funcionario *vetor){
    printf("len: %d\n", (int)(sizeof(vetor)/sizeof(vetor[0])));
    return (int)(sizeof(vetor)/sizeof(vetor[0]));
}
//retornar a posição do vetor que armazena o funcionário de maior salário;
int maiorSalario(funcionario *listaFuncionarios){
    int nFuncionarios = len(listaFuncionarios);
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
    int nFuncionarios = len(listaFuncionarios);
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
void imprimirFuncionario(funcionario *func, int posicao){
    printf("Nome: %s\n", func[posicao].nome);
    printf("Salario: %.2f\n", func[posicao].salario);
}
//retornar a média dos salários dos funcionários
float mediaSalario(funcionario *listaFuncionarios){
    int nFuncionarios = len(listaFuncionarios);
    int i;
    float somaSalario=0;
    for(i=0; i<nFuncionarios;i++)
        somaSalario += listaFuncionarios[i].salario;
    return somaSalario/nFuncionarios;
}
//imprimir os dados de todos os funcionários
void imprimirFuncionarios(funcionario *listaFuncionarios){
    int nFuncionarios = len(listaFuncionarios);
    int i;
    for(i=0; i<nFuncionarios; i++){
        imprimirFuncionario(listaFuncionarios, i);
    }
}
void lerFuncionario(funcionario *listaFuncionarios, int posicao){
        scanf("%s", listaFuncionarios[posicao].nome);fflush(stdin);
        scanf("%f", &listaFuncionarios[posicao].salario);fflush(stdin);
}
void lerFuncionarios(funcionario *listaFuncionarios){
    int nFuncionarios = len(listaFuncionarios);
    int i;
    printf("%d\n", nFuncionarios);
    for(i=0; i<nFuncionarios; i++){
        scanf("%s", listaFuncionarios[i].nome);fflush(stdin);
        scanf("%f", &listaFuncionarios[i].salario);fflush(stdin);
    }
}
void incluirFuncionario(funcionario *listaFuncionarios){
    int nFuncionarios = len(listaFuncionarios);
    funcionario *vetAux;
    int i;
    nFuncionarios++;
    vetAux = malloc((nFuncionarios)*sizeof(funcionario));
    
    for (i = 0; i <nFuncionarios; i++){
        vetAux[i] = listaFuncionarios[i];
        if(i==(nFuncionarios-1))
            lerFuncionario(vetAux, i);
    }    
    realloc(listaFuncionarios, nFuncionarios);
    listaFuncionarios = vetAux;
    free(vetAux);
    nFuncionarios--;
}
void removerFuncionario(funcionario *listaFuncionarios, int posicao){
    int nFuncionarios = len(listaFuncionarios);
    funcionario *vetAux;
    int i,j=0;
    vetAux = malloc((nFuncionarios-1)*sizeof(funcionario));
    
    for (i = 0; i <nFuncionarios; i++){
        if(i == posicao){
            j++;
            continue; 
        }
        vetAux[i] = listaFuncionarios[j];
        j++;
    }    
    realloc(listaFuncionarios, nFuncionarios);
    listaFuncionarios = vetAux;
    free(vetAux);
    nFuncionarios--;
}
char menu(){
    char *vetop = "012345678";
	char op;
    int i;
    while(1){       
        printf("\n---- Menu de opcoes ----\n");
        printf("1 - inserir valores\n");
        printf("2 - imprimir valores\n");
        printf("3 - imprimir funcionario da opicao\n");
        printf("4 - retornar posicao do maior salario\n");
        printf("5 - retornar posicao do menor salario\n");
        printf("6 - Media dos salarios\n");
        printf("7 - incluir funcionarios\n");
        printf("8 - remover um funcionario\n");
        printf("0 - sair\n");
        scanf("%c", &op);fflush(stdin);
        for(i=0; i<9; i++){
            if(vetop[i] == op)
                return op;
        }
        printf("\n----Opicao invalida----\n\n");
    }

}