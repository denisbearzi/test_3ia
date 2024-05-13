#include <stdio.h>

void inizializzaMatrice(int sizeRows, int sizeCollons, int matrice[sizeRows][sizeCollons]){
    for (int i = 0; i < sizeRows; i++) {
        for (int j = 0; j < sizeCollons; j++){
            matrice[i][j] = 0;
        }
    }
}

void stampaCornice(int sizeRows, int sizeCollons, int matrice[sizeRows][sizeCollons]){
    for (int i = 0; i < sizeRows; i++) {
        for (int j = 0; j < sizeCollons; j++) {
            if (i == 0 || i == sizeRows - 1 || j == 0 || j == sizeCollons - 1){
                matrice[i][j] = 1;
            }
        }
    }
}

void stampaMatrice(int sizeRows, int sizeCollons, int matrice[sizeRows][sizeCollons]){
    for (int i = 0; i < sizeRows; i++) {
        for (int j = 0; j < sizeCollons; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int sizeRows = 0;
    int sizeCollons = 0;

    printf("Inserisci il numero di righe: ");
    scanf("%d", &sizeRows);

    printf("Inserisci il numero di colonne: ");
    scanf("%d", &sizeCollons);

    int matrice[sizeRows][sizeCollons];

    inizializzaMatrice(sizeRows, sizeCollons, matrice);
    stampaCornice(sizeRows, sizeCollons, matrice);
    stampaMatrice(sizeRows, sizeCollons, matrice);

    return 0;
}