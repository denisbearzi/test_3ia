# include <stdio.h>

void vector(int size, int array[]){

    printf("Inserisci i valori del vettore:\n");

    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

}


int copiaVector(int size, int array[], int destinazione[]){

    for (int i = 0; i < size; i++){

        destinazione[i] = array[i];

    }
    
}


int main(){

    printf("Inserisci la dimansione del vettore:");

    int size = 0;
    scanf("%d", &size);

    int array[size];
    vector(size, array);

    int arrayDestinazione[size];
    copiaVector(size, array, arrayDestinazione);

    printf("Il vettore copiato e': ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arrayDestinazione[i]);
    }

    return 0;
}