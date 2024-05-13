#include <stdio.h>

void matrice0(int rigeMatrice, int colonneMatrice, int matrix[][colonneMatrice]){
    int rows = 0;
    int collons = 0;

    for (int i = rows; i < rigeMatrice; i++) {
        for (int j = collons; j < colonneMatrice; j++) {
            matrix[i][j] = ' ';

            if (j < colonneMatrice || i < rigeMatrice ){
                matrix[i][j] = 0;
            }
            rows += 1;
            collons += 1;
        }
    }
}

int main() {
    int rigeMatrice, colonneMatrice;

    printf("Inserisci il numero di righe: ");
    scanf("%d", &rigeMatrice);

    printf("Inserisci il numero di colonne: ");
    scanf("%d", &colonneMatrice);

    int matrix[rigeMatrice][colonneMatrice];
    
    matrice0(rigeMatrice, colonneMatrice, matrix);

    // Stampiamo la matrice risultante
    for (int i = 0; i < rigeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}