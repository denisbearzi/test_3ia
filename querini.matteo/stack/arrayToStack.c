#include <stdio.h>
#include "funzioni.h"



int main(){

    int size = 10;
    int array[size];
    int capacity;


    printf("Inserisci la capacity dello stack: ");
    scanf("%d", &capacity);
    stack* stack = newStack(capacity);


    printf("Inserisci i valori dell'array:");


    for(int i = 0; i < size ;i++){

        printf("Inserisci il %d valore: \n", i + 1);
        scanf("%d", &array[i]);
    }
    

    for(int i = 0; i < size ;i++){

        push(stack, array[i]);
    }


    printStack(stack);


    return 0;
}