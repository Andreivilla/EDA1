#include<stdio.h>
#include<math.h>

int main(void) {
    int valor, nNotas, i;
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};

    scanf("%d", &valor);

    for(i=0; i<7; i++){
        if(valor >= notas[i]){
            nNotas = floor(valor/notas[i]);
            valor = valor%notas[i];
            printf("%d nota(s) de R$ %d,00\n", nNotas, notas[i]);
        }else{
            printf("0 nota(s) de R$ %d,00\n", notas[i]);
        }
    }

    return 0;
}