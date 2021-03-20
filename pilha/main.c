#include"util.h"
int main(int agrc, char *argv[]){
    
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
