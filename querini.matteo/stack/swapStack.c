#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"


int main(){

    int capacity1 = 0;
    int capacity2 = 0;


    printf("Capacità primo stack: ");
    scanf("%d", &capacity1);

    printf("Capacità secondo stack: ");
    scanf("%d", &capacity2);


    stack* stack1 = newStack(capacity1);
    stack* stack2 = newStack(capacity2);


    push(stack1, 1);
    push(stack1, 1);
    push(stack1, 1);


    push(stack2, 2);
    push(stack2, 2);
    push(stack2, 2);


    swapFirstValueStack(stack1, stack2);


    printf("Elementi del primo stack: ");
    printStack(stack1);

    printf("Elementi del secondo stack: ");
    printStack(stack2);

    return 0;
}