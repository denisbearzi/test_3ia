#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct{
	int *array;
	int capacity;
	int top;
} stack;



stack* newStack(int capacity){
	stack* myStack = (stack*) malloc(sizeof(stack));
	myStack -> array = (int*) malloc(sizeof(int) * capacity);
	myStack -> top = -1;
	myStack -> capacity = capacity;
	
	return myStack;
}



bool isEmpty(stack* myStack){
	return myStack -> top == -1;
}



bool isFull(stack* myStack){
	return myStack -> top == myStack -> capacity -1;
}



bool push(stack* myStack, int value){
	
	if(isFull(myStack)){
		
		return false;
		
	} else {
		
		myStack -> top ++;
		myStack -> array[myStack -> top] = value;
		return true;
		
	}
}



int pop(stack* myStack){
	
		int value = 0;
		value = myStack -> array[myStack -> top];
		myStack -> top--;
		
		return value;
}



int peek(stack* myStack){
	
	int value = 0;
	value = myStack -> array[myStack -> top];
	return value;
}



void printStack(stack* myStack) {
    for (int i = myStack->top; i >= 0; i--) {
        printf("%d ", myStack->array[i]);
    }
    printf("\n");
}



void swapFirstValueStack(stack* stack1, stack* stack2) {
    int temp1 = pop(stack1);
    int temp2 = pop(stack2);
    push(stack1, temp2);
    push(stack2, temp1);
}