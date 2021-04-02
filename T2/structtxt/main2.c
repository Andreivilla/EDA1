#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fl = fopen("test.txt", "r");
    int a, b;
    char c[40];
    //fscanf(fl, "%d, %s %d/", &a, c, &b);
    fscanf(fl, "%d, ", &a);
    fscanf(fl, "%[^,]s ", c);
    fscanf(fl, ", %d", &b);
    printf("n: %d-%s-%d", a, c, b);
}