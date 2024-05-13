#include <stdio.h>

int main(){
     int N = 0, I = 0, risultato = 0;

     printf("Inserisci un numero intero per sapere la sua tebellina:");
     scanf("%d", &N);

    printf("La tabellina del %d e':\n", N);

     for(I = 1; I <= 10; I++){
        risultato = N * I;
        printf("Il valore %d moltiplicato per %d e':%d\n", N, I, risultato);
     }

    return 0;
}