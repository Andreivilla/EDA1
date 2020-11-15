#include <stdio.h>
typedef struct{
    int horas;
    int minutos;
}hm;
hm converte(int);
int main() {
    int n;
    hm tempo;
    scanf("%d", &n);
    tempo = converte(n);
    printf("%d\n",tempo.horas);
    printf("%d\n", tempo.minutos);
    return 0;
}
hm converte(int n){
    hm tempo;
    tempo.horas=0;

    while(n>60){
        tempo.horas++;
        n-=60;
    }
    tempo.minutos=n;
    return tempo;
}