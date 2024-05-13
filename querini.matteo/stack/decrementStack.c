#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"



int main(){

    int capacity = 0;
    int size = 0;


    printf("Inserisci la capacity dello stack: ");
    scanf("%d", &capacity);
    stack* stack = newStack(capacity);


    //riempio lo stack
    for(int i = 0; i < 3; i++){
    
        push(stack, i);
        size ++;
    }


    printf("Stack iniziale:");
    printStack(stack);


    int array[size];


    //faccio il pop dei valore e li salvo nell'array
    for(int i = 0; i < size; i++){
        
        array[i] = pop(stack);
    }


    for(int i = size - 2; i >= 0; i--){
        
        push(stack, array[i]);
    }

    //inserisco lultimo valore nella cima dello stack
    push(stack, array[size -1]);
    printStack(stack);

    return 0;
}