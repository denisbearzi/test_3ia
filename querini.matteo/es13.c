#include <stdio.h>

void condizioneValore(int matrice[][2], int righeMatrice, int colonneMatrice, int valore) {
    int trovato = 0;

    for (int i = 0; i < righeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            if (matrice[i][j] == valore) {
                printf("Il valore %d si trova all'interno della matrice.\n", valore);
                trovato = 1;
                return;
            }
        }
    }

    if (!trovato) {
        printf("Il valore %d non si trova all'interno della matrice.\n", valore);
    }
}

void cicliMatrix(int matrice[][2], int rigeMatrice, int colonneMatrice) {
    for (int i = 0; i < rigeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            int inputNum;
            printf("Inserisci un numero all'interno della matrice: ");
            scanf("%d", &inputNum);
            matrice[i][j] = inputNum;
        }
    }
}

int main() {
    int colonneMatrice = 2;
    int righeMatrice = 3;
    int matrice[righeMatrice][colonneMatrice];

    cicliMatrix(matrice, righeMatrice, colonneMatrice);

    int valore;
    printf("Inserisci un valore per verificare se è presente nella matrice: ");
    scanf("%d", &valore);
    condizioneValore(matrice, righeMatrice, colonneMatrice, valore);

    return 0;
}