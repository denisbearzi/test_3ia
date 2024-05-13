#include <stdio.h>

void matrice0(int rigeMatrice, int colonneMatrice, int matrix[][colonneMatrice]) {
    int valore = 1;
    int rigaInizio = 0;
    int rigaFine = rigeMatrice - 1;
    int colonnaInizio = 0;
    int colonnaFine = colonneMatrice - 1;

    while (rigaInizio <= rigaFine && colonnaInizio <= colonnaFine) {
        for (int col = colonnaInizio; col <= colonnaFine; col++) {
            matrix[rigaInizio][col] = valore++;
        }
        rigaInizio++;

        for (int row = rigaInizio; row <= rigaFine; row++) {
            matrix[row][colonnaFine] = valore++;
        }
        colonnaFine--;

        if (rigaInizio <= rigaFine) {
            for (int col = colonnaFine; col >= colonnaInizio; col--) {
                matrix[rigaFine][col] = valore++;
            }
            rigaFine--;
        }

        if (colonnaInizio <= colonnaFine) {
            for (int row = rigaFine; row >= rigaInizio; row--) {
                matrix[row][colonnaInizio] = valore = 2;
            }
            colonnaInizio++;
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

