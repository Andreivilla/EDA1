#include <stdio.h>
#define lin 12
#define col 12
int main() {
    float M[lin][col];
    float soma = 0;
    char op;
    int i, j;

    scanf("%c", &op);

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            scanf("%f", &M[i][j]);
        }
    }

    for(i=0; i<lin; i++){
        for(j=i+1; j<col; j++){
            soma += M[i][j];
        }
    }

    if(op == 'S')
        printf("%f\n", soma);
    else if(op == 'M')
        printf("%f\n", soma/(((lin*col)-lin)/2));

    return 0;
}