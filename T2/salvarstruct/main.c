#include<stdio.h>
#include<stdlib.h>
typedef struct s{
    int v3;
}s2;
typedef struct s2{
    int v1, v2;
    s2 v3;
}s;

s criaStruct(void);
void printStruct(s *vet, int tam);
void carregar(s *a, int tam);
void descarregar(s *a, int tam);

int main(int agrc, char *argv[]){
    int op, tamVet = 0;
    s *vets = (s*) malloc(sizeof(s));
    s *vetLer;

    printf("0- fechar\n");
    printf("1- definir struct\n");
    printf("2- Carregar struct\n");
    printf("3- Descarregar struct\n");
    printf("4- exbir struct\n");
    
    while(1){
        printf("Oq fzr?\n");
        scanf("%d", &op);
        switch(op){
        case 0:
            return 0;
            break;
        case 1:
            tamVet++;
            vets = (s*) realloc(vets, tamVet);
            vets[tamVet-1] = criaStruct();
            break;
        case 2:
            carregar(vets, tamVet);
            break;
        case 3:
            vetLer = (s*) malloc(sizeof(s)*tamVet);
            descarregar(vetLer, tamVet);
            printStruct(vetLer, tamVet);
            break;
        case 4:
            printStruct(vets, tamVet);
            break;
        default:
            printf("ERRO\n");
            break;
        }
    }
    return 0;
}
s criaStruct(void){
    s str;// = (s*) malloc(sizeof(s));
    printf("valor1: ");
    scanf("%d", &str.v1);
    printf("valor2: ");
    scanf("%d", &str.v2);
    printf("valor3: ");
    scanf("%d", &str.v3.v3);
    return str;    
}
void printStruct(s *vet, int tam){
    printf("print func: %d %d\n", vet[0].v1, vet[0].v2);
    for(int i = 0; i < tam; i++)
        printf("vet[%d]\nv1: %d\nv2: %d\nv3: %d\n", i, vet[i].v1, vet[i].v2, vet[i].v3.v3);    
}
void carregar(s *a, int tam){//carrega as structs no .bin
    int i;
    FILE *file = fopen("structs.bin", "wb");
    for(i=0; i<tam; i++)
        fwrite(&a[i], sizeof(s), 1, file);
    fclose(file);
}
void descarregar(s *a, int tam){//descarrega as strucs do .bin
    FILE *file = fopen("structs.bin", "rb");
    fread(a, sizeof(s), tam, file);
    fclose(file);
}