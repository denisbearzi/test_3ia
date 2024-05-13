# include <stdio.h>

int main(){

    int array[5];
    int somma = 0;

    printf("inserisci i 5 numeri da sommare:");

    for (int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < 5; i++) {
        somma += array[i];
    }
    printf("La somma degli elementi è %d\n", somma);

return 0;

}