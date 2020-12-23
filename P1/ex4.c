//ex4
typedef struct reg{
    int matricula;
    char nome[100];
    float media;
    struct reg *prox;
}celula;
float media_geral(celula *lista){
    int countAlunos=0;
    float somaMedia=0;
    float mediaTurma;
    
    while(lista->prox != NULL){
        somaMedia += lista->media;
        countAlunos++;
        lista = lista->prox;
    }    
    mediaTurma = (float) somaMedia/countAlunos;
    return mediaTurma;
}
void maiores_media_geral(celula *lista, float mediaGeral){
    printf("\n--------------------------\n");
    printf("\nmedias maiores que a media geral\n");    
    while(lista->prox != NULL){
        if(lista->media > mediaGeral){        
        printf("Aluno: %s\n", lista->nome);
        printf("Matricula: %d\n", lista->matricula);
        printf("Media: %.2f\n", lista->media);        
        lista = lista->prox;
        }
    }
    printf("\n--------------------------\n");
}