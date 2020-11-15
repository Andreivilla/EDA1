#include<stdio.h>
#include<stdlib.h>
void troca(int *a,int *b);
int main(int agrc, char *agrv[]){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    troca(&a,&b);
    printf("a: %d\n", a);
    printf("b: %d", b);
}
void troca(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}