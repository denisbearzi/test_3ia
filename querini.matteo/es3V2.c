#include <stdio.h>
#include <math.h>

int main(){

    int numero = 0;
    int valore;
    float  radice = 0;

    do{
        do{

            printf("Inserisci un numero(positivo) per calcolare la sua radice quadrata:");
            scanf("%d", &numero);

            while(numero < 0){

                printf("Errore, il numero inserito è negativo, inserisci un numero positivo:");
                scanf("%d", &numero);
            
            }
        } while (numero < 0);

        radice = sqrt(numero);
        printf("La radice quadrata di %d e' %f", numero, radice);

        printf("\nDigita un qualsiasi valore per calcolare una ulteriore radice e 0 per terminare:");
        scanf("%d", &valore);


    
        printf("Grazie per aver utilizzato questo programma, arrivederci");

return 0;

}