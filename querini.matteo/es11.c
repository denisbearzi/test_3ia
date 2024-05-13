# include <stdio.h>

int main(){

    int array[5];
    int findNumber;

    printf("inserisci i 5 numeri:");

    for (int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    printf("Inserisci un numero da vercare fra quelli inseriti:");
    scanf("%d", findNumber);

    for (int i = 0; i < 5; i++){

        if (findNumber == array[i]){

            printf("Il valore %d si trova in posizione %d.", findNumber, i);

        } else {

            printf("Il valore %d si trova nel vettore", findNumber);
        }
        
        
    }

return 0;

}