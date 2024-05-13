#include <stdio.h>

int main(){
   int numero;
   int moltiplicatore;
   int risultato;
   int valorefinale;

   do{
      printf("Inserisci un numero intero per sapere la sua tebellina:");
      scanf("%d", &numero);

      printf("La tabellina del %d e':", numero);

     for(moltiplicatore = 1; moltiplicatore <= 10; moltiplicatore++){
        risultato = numero * moltiplicatore;
        printf("Il valore %d moltiplicato per %d e':%d\n", numero, moltiplicatore, risultato);
     }

    printf("\nDigita 0 per terminare il programa o un altro valore per ripeterlo:");
    scanf("%d", &valorefinale);

   } while (valorefinale != 0);
   printf("Grazie per aver utilizzato questo programma, arrivederci");

    return 0;
}