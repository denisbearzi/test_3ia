#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int capacity;
    int top;
} stack;

// New stack
stack* newStack (int capacity) {
    stack* tempStack = (stack*)malloc(sizeof(stack));
    tempStack->array = (int*)malloc(sizeof(int) * capacity); // quantità di memoria neccessaria al tipo di dato, noi moltiplichimo per la capacità (in input) dell'array 
    tempStack->top = -1; // top all'inizio è 0. O, mettiamo il top a meno e semplifichiamo l'algoritmo
    tempStack->capacity = capacity; // la variabile in input viene messo com puntatore
    return tempStack;
}

// Bool 
bool isEmpty (stack* myStack) {
    return (myStack->top == -1); // se è -1 allora lo stack è vuoto, capacity è una quantità, top è un indice.
}

bool isFull (stack* myStack) {
    return (myStack->top = myStack->capacity -1); 
}

// Push
bool push (stack* myStack, int value) {
    if (isFull(myStack)) { // se lo stack è pieno non si può più aggiungere nulla
        return false;
    }else{
        myStack->top++;
        myStack->array[myStack->top] = value;
        return true;
    }
}

// Pop: restituisce il valore nel top dello stack e lo "elimina" (modificando il top)
int pop (stack* myStack) {
    if (isEmpty(myStack)) {
        printf("The stack Is Full");
    }else{
        int value = 0;
        value = myStack->array[myStack->top];
        myStack->top--; // "elimina" l'ultimo elemento
        return value;
    }
}

// Peek
int peek (stack* myStack) {
    int value = 0;
    if (isEmpty(myStack)) {
        printf("The Stack Is Full");
    }else{
        value = myStack->array[myStack->top];
        return value;
    }
}
