#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void riempimentoArray(int n, int array[n]){
	
	srand(time(NULL));
	
	for(int i = 0; i <n; i++){
		
		array[i]=rand() % 10;
		
	}
	
	
	
}

void insertionSortIterativo(int n, int array[n]){
	
	int value = 0;
	int j = 0;
	
	for(int i = 1; i<n; i++){
		
		value = array[i];
		
		j = i-1;
		
		while(j>= 0 && array[j]>value){
			
			array[j+1] = array[j];
			
			j = j-1;
			
			
		}
		
		array[j+1] = value;
		
	}
	
	
}

void stampaArray(int n, int array[n]){
	
	for(int i = 0; i<n; i++){
		
		printf("%d", array[i]);
			
		
	}
	
	
}

int main(){
	
	
	int n = 0;
	
	scanf("%d", &n);
	
	int array[n];
	
	riempimentoArray(n, array);
	
	insertionSortIterativo(n, array);
	
	stampaArray(n, array);
}
