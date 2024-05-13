#include <stdio.h>
#include <stdlib.h>


void quickSort(int array[], int l, int r){

    if(l < r){

        int pivotIndex = partition(array, l, r);

        quickSort(array, l, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, r);
    }
}


int partition(int array[], int l, int r){

    int pivot = array[r];
    int i = l - 1;

    for(int j = l; j <= r; j++){

        if(array[j] < pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[r]);

    return i + 1;
}
