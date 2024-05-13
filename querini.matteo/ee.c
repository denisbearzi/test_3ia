#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void bubbleSortMED (int n, double array[]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1-i; j++){
			if(array[j]>array[i]){
				double temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}			
		}
		
	}
}

int main() {
    static int array[SIZE];
    int i, j, temp;
    double times[100];

    
    srand(time(NULL)); 
    
    for (i = 0; i < 100; i++) {
        
        for (j = 0; j < SIZE; j++){
            array[j] = rand() % 1000;

        }

        clock_t start = clock();
        bubbleSort(array, SIZE);
        clock_t end = clock();
        
        double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        times[i] = time_spent;
    }

    bubbleSortMED(100, times);

    printf("La mediana è: %lf secondi.\n", times[50]);

return 0;
}