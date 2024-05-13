#include <stdio.h>
#include <math.h>

int main(){

    int numero = 0;
    float  radice = 0;

        printf("Inserisci un numero(positivo) per calcolare la sua radice quadrata:");
        scanf("%d", &numero);

        if (numero < 0){

            printf("Errore, il numero inserito è negativo, inserisci un numero positivo:");

        } else {

            radice = sqrt(numero);
            printf("La radice quadrata di %d e' %f", numero, radice);

        }

    return 0;
    
}