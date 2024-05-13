#include <stdio.h>

int main(){

    int I=0;

    for(I=0; I <= 10; I++){

        if(I == 3){
            printf("#");
        } else {
            printf("0");
        }

        if(I == 7){
            printf("#");
        } else {
            printf("0");
        }
       
    }
    return 0;
}