#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int agrc, char *argv[]){
    struct tm *local;
    time_t t;
    t = time(NULL);
    local=localtime(&t);

    int dia=local->tm_mday;
    int mes=local->tm_mon+1;
    int ano=local->tm_year+1900;

    printf("Data do Sistema: %d/%d/%d\n",dia,mes,ano);
    
    return 0;
}