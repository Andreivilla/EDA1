#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[40];
    float salario;
}funcionario;

int maiorSalario(funcionario *, int);
int menorSalario(funcionario *, int);
float mediaSalario(funcionario *, int);
void imprimirFuncionario(funcionario*, int);
void imprimirFuncionarios(funcionario *, int);
void lerFuncionario(funcionario*, int);
void lerFuncionarios(funcionario *, int);
char menu();
void incluirFuncionario(funcionario *, int*);
void removerFuncionario(funcionario *, int, int*);

int main(int argc, char *argv[])
{
    funcionario *funcionarios;
    int posicao, nFuncionarios = 1;
    while (1){
        switch (menu()){
        case '1':
            printf("Quantos funcionarios adicionar: ");
            scanf("%d", &nFuncionarios);fflush(stdin);
            funcionarios = malloc(nFuncionarios * sizeof(funcionario));
            lerFuncionarios(funcionarios, nFuncionarios);
            break;
        case '2':
            imprimirFuncionarios(funcionarios, nFuncionarios);
            break;
        case '3':
            printf("Qual usuario imprimir: ");
            scanf("%d", &posicao);fflush(stdin);
            imprimirFuncionario(funcionarios, posicao);
            break;
        case '4':
            printf("Posiaco maior salario: %d\n", maiorSalario(funcionarios, nFuncionarios));
            break;
        case '5':
            printf("Posiaco menor salario: %d\n", menorSalario(funcionarios, nFuncionarios));
            break;
        case '6':
            printf("Media do salario: %f\n", mediaSalario(funcionarios, nFuncionarios));
            break;
        case '7':
            incluirFuncionario(funcionarios, &nFuncionarios);
            break;
        case '8':
            printf("Qual posicao remover: ");
            scanf("%d", &posicao);fflush(stdin);
            removerFuncionario(funcionarios, posicao, &nFuncionarios);
            break;
        case '0':
            return 0;
            break;
        }
    }
}

//retornar a posição do vetor que armazena o funcionário de maior salário;
int maiorSalario(funcionario *listaFuncionarios, int nFuncionarios){
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
int menorSalario(funcionario *listaFuncionarios, int nFuncionarios){
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
float mediaSalario(funcionario *listaFuncionarios, int nFuncionarios){
    int i;
    float somaSalario=0;
    for(i=0; i<nFuncionarios;i++)
        somaSalario += listaFuncionarios[i].salario;
    return somaSalario/nFuncionarios;
}
//imprimir os dados de todos os funcionários
void imprimirFuncionarios(funcionario *listaFuncionarios, int nFuncionarios){
    int i;
    for(i=0; i<nFuncionarios; i++){
        imprimirFuncionario(listaFuncionarios, i);
    }
}
void lerFuncionario(funcionario *listaFuncionarios, int posicao){
    printf("funcionario %d: \n", posicao+1);
    printf("Nome: ");
    scanf("%s", listaFuncionarios[posicao].nome);fflush(stdin);
    printf("Salario: ");
    scanf("%f", &listaFuncionarios[posicao].salario);fflush(stdin);
}
void lerFuncionarios(funcionario *listaFuncionarios, int nFuncionarios){
    int i;
    for(i=0; i<nFuncionarios; i++){
        lerFuncionario(listaFuncionarios, i);
    }
}
void incluirFuncionario(funcionario *listaFuncionarios, int *nFuncionarios){
    funcionario *vetAux;
    int i;
    *nFuncionarios = *nFuncionarios + 1;
    vetAux = malloc((*nFuncionarios)*sizeof(funcionario));
    
    for (i = 0; i <*nFuncionarios; i++){
        vetAux[i] = listaFuncionarios[i];
        if(i==(*nFuncionarios-1))
            lerFuncionario(vetAux, i);
    }    
    realloc(listaFuncionarios, *nFuncionarios);
    for (i = 0; i <*nFuncionarios; i++)
        listaFuncionarios[i] = vetAux[i];
}
void removerFuncionario(funcionario *listaFuncionarios, int posicao, int *nFuncionarios){
    funcionario *vetAux;
    int i,j=0;
    vetAux = malloc((*nFuncionarios)*sizeof(funcionario));
    
    for (i = 0; i <*nFuncionarios; i++){
        if(i == posicao){
            j++;
            continue; 
        }
        vetAux[i] = listaFuncionarios[j];
        j++;
    }    
    realloc(listaFuncionarios, *nFuncionarios-1);
    for (i = 0; i <*nFuncionarios-1; i++)
        listaFuncionarios[i] = vetAux[i];
    *nFuncionarios = *nFuncionarios-1;
}
char menu(){
    char *vetop = "012345678";
	char op;
    int i;
    while(1){       
        printf("\n---- Menu de opcoes ----\n");
        printf("1 - inserir funcionarios\n");
        printf("2 - imprimir funcionarios\n");
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