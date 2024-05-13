// Sqrt di un numero in input, il numero deve essere positivo.

#include <stdio.h>
#include <math.h>

int main() {
    
    // Parte dichiarativa
    int inputNum = 0;
    float result = 0;
    
    // Input
    do{
        printf("Inserisci un numero: ");
        scanf("%d", &inputNum);
        
        // Messaggio di errore
        if(inputNum < 0){
            printf("Non e' possibile calcolare la radice quadrata di un numero negativo, riprova.\n\n");
        }
        
    } while (inputNum < 0);
    
    // Calcoli
    result = sqrt(inputNum);
    
    // Output
    printf("La radice quadrata di %d e' %f", inputNum, result);
    
    return 0;
}