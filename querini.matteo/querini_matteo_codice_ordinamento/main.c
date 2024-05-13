#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

#define MAX_SIZE 1000000



double misurazioneTempo(double array[], int num, int choice){
    clock_t tempoInizio = clock();

    //algoritmo da misurare
    switch (choice){

        case 1:
            bubbleSort(array, num);
            break;

        case 2:
            insertionSort(array, num);
            break;

        case 3:
            selectionSort(array, num);
            break;

        case 4:
            mergeSort(array, 0, num - 1);
            break;

        case 5:
            quickSort(array, 0, num - 1);
            break;

        
        default:
            printf("Algoritmo non valido.\n");
            exit(1);
    }

    clock_t tempoFine = clock();

    //calcola il tempo in millisecondi
    double tempoTrascorso = ((double)(tempoFine - tempoInizio)) / CLOCKS_PER_SEC * 1000;
    return tempoTrascorso;
}

int main(){

    int choice;
    int num;
    int scelta;
    int tempoImpiegato;
    double tempi[100];

    printf("1) Bubble Sort\n2) Insertion Sort\n3) Selection Sort\n4) Merge Sort\n5) Quick Sort\n");
    printf("Scegli l'algoritmo di ordinamento da misurare:\n");

    scanf("%d", &choice);


    printf("1) 100\n2) 1000\n3) 10000\n4) 100000\n5) 1000000\n");
    printf("Scegli la dimensione dell'array:\n");

    scanf("%d", &scelta);
    
    switch (scelta){

        case 1:
            num = 100;
            break;

        case 2:
            num = 1000;
            break;

        case 3:
            num = 10000;
            break;

        case 4:
            num = 100000;
            break;

        case 5:
            num = 1000000;
            break;

        default:
            printf("Scelta non valida.\n");
    }


    for (int i = 0; i < 100; i++){

        static double array[MAX_SIZE];

        for (int j = 0; j < num; j++){
            array[j] = rand() % 1000;
        }

        tempoImpiegato = misurazioneTempo(array, num, choice);
    }

    for (int i = 0; i < 100; i++){
        static double array[MAX_SIZE];

        for (int j = 0; j < num; j++){
            array[j] = rand() % 1000;
        }

        double tempoImpiegato = misurazioneTempo(array, num, choice);
        tempi[i] = tempoImpiegato;
    }

    selectionSort(tempi, 100);


    double mediana;
    if (100 % 2 == 0){
        mediana = (tempi[100 / 2 - 1] + tempi[100 / 2]) / 2.0;
    } else {
        mediana = tempi[100 / 2];
    }

    printf("Mediana: %.2f ms\n", mediana);

    return 0;
}
