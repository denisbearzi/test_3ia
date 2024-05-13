#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"


int main(){

    int capacity1 = 0;
    int capacity2 = 0;
    int counter = 0;


    printf("Capacità primo stack: ");
    scanf("%d", &capacity1);

    printf("Capacità secondo stack: ");
    scanf("%d", &capacity2);


    stack* stack1 = newStack(capacity1);
    stack* stack2 = newStack(capacity2);


    //riempio lo stack
    for(int i = 0; i < 3; i++){
    
        push(stack1, i);
        counter++;
    }


    printf("Stack iniziale:");
    printStack(stack1);


    for(int i = 0; i < counter; i++){
        push(stack2, pop(stack1));
    }


    printf("Stack finale:");
    printStack(stack2);

    return 0;
}