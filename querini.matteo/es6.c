#include <stdio.h>

int main(){
   int num = 0, I = 0, somma = 0;

    printf("Inserisci un valore(positivo) per calcolare la somma di tutti i numeri interi che lo precedono:");
    scanf("%d", &num);

   for(I = 0; I <= num; I++){
        somma = somma + I;
   }
    printf("La somma di tutti i valori prima di %d e':%d", num, somma);

return 0;
}