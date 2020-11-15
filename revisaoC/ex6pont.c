#include <stdio.h>
typedef struct{
    int horas;
    int minutos;
}hm;
void converte(int, int*, int*);
int main() {
    int n;
    hm tempo;
    scanf("%d", &n);
    converte(n, &tempo.horas, &tempo.minutos);
    printf("%d\n",tempo.horas);
    printf("%d\n", tempo.minutos);
    return 0;
}
void converte(int n, int *horas, int *minutos){
    *horas=0;

    while(n>60){
        *horas++;
        n-=60;
    }
    *minutos = n;
}