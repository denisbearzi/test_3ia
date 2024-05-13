#include <stdio.h>

int main(){
   int inputvalore = 0;
   int inputsomma = 0;
   int inputnumeri = 0;

    do{
        do{
        printf("Inserisci un valore(positivo) per calcolare la somma di tutti i numeri interi che lo precedono:");
        scanf("%d", &inputvalore);

        while (inputvalore <= 0){
            printf("Il valore inserito non e' valido perche' e' minore di 0, inserisci un altro valore:");
            scanf("%d", &inputvalore);
        }        

    } while (inputvalore < 0);

        for(inputnumeri = 1; inputnumeri <= inputvalore; inputnumeri++){
            inputsomma = inputsomma + inputnumeri;
        }
        printf("\nLa somma di tutti i valori prima di %d e':%d", inputvalore, inputsomma);
        printf("\nDigita un qualsiasi valore per eseguire un ulteriore operazione e 0 per terminare:");
        scanf("%d", &inputvalore);

    } while (inputvalore != 0);
        printf("Grazie per aver usato questo programma, arrivederci.");
    

return 0;
}