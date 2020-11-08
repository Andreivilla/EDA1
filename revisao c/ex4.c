#include <stdio.h>
#define nValores 100
int main() {
    double vetValores[nValores];
    int i;
    scanf("%lf", &vetValores[0]);
    
    for(i=1; i<nValores; i++){
        vetValores[i] = vetValores[i-1]/2;
    }
    
    for(i=0; i<nValores; i++){
        printf("N[%d] = %.4lf\n", i, vetValores[i]);
    }
    return 0;
}
