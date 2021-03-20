#include"util.h"
int main(int agrc, char *argv[]){
    Pilha *p = criaPilha();
    //2 4 3 1
    push(p, 2);
    push(p, 4);
    push(p, 3);
    push(p, 1);
    while(1){
        switch(menu()){
            case 1:
                printaPilha(p);
                break;
            case 2:
                
                printf("2\n");
                break;
            case 0:
                printf("0\n");
                return 0;
                break;            
            default:
                break;
        }
    }
    return 0;
}
