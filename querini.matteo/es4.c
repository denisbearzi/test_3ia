#include <stdio.h>
#include <math.h>

int main() {

    int numero = 0;
    float radice = 0;

    printf("Inserisci un numero (positivo) per calcolare la sua radice quadrata: ");

    scanf("%d", &numero);

    while (numero < 0) {
        printf("Il numero inserito è negativo, inserisci un numero positivo: ");
        scanf("%d", &numero);
    }

    radice = sqrt(numero);

    printf("La radice quadrata di %d è %f\n", numero, radice);

    return 0;
}