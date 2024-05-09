#include <stdio.h>
#include "stack.h"

bool willContinue(){
	
	int risposta = 0;
	do{
		printf("vuoi fare un Push\n 1 = si \n2 = no");
		scanf("%d", &risposta);
	if(risposta == 1 || risposta == 0){
		
		if(risposta == 1){
		
			return true;
			
		}else if( risposta == 0){
			
			return false;
			
		}
			
	}	
	}while(risposta != 0);
	
	
}

void swapTop(stack* stack1,stack* stack2){
	
	tempVal = stack2 -> array[stack-> top];
	stack2 -> array[stack2 -> top] = stack1 -> array[stack1 -> top];
	stack1 -> array[stack1 -> top] = tempVal;
	
}

stringStack swap(stringStack stack,int top,int bottom){
	
	char temp = stack -> array[bottom];
	stack -> array[bottom] = stack -> array [top];
	stack -> array[top] = temp;
	
	return stack
}

void invertiStringStack(StringStack* stack){
	
	int t = stack -> top;
	 for(int i = 0;i != t || i==t-1; i ++){
	 	
	 	swap(stack,i,t);
	 	t--;
	 	
	 }
	
}












int main(){
	
	int capacity = 0;
	
	printf("Inserisci la grandezza che vuoi che abbia il tuo stack");
	scanf("%d", &capacity);

	stack stack = newStack(capacity);
	
	while(willContinue){
		printf("inserisci il valore da mettere nello stack");
		scanf("%d", &value);
		push(stack,value);
	}
		
		
	
}
