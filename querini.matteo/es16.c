#include <stdio.h>

void Matrix(int matrice[][3], int righeMatrice, int colonneMatrice) {
    for (int i = 0; i < righeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            matrice[i][j] = 0;
        }
    }
}

int mediaCorniceMatrice(int matrice[][3], int righeMatrice, int colonneMatrice) {
    float result = 0;

    for (int i = 0; i < righeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            if (i == 0 || i == righeMatrice - 1 || j == 0 || j == colonneMatrice - 1) {
                matrice[i][j] = 0;
            } else {
                result += matrice[i][j];
            }
        }
    }

    return result;
}

int main() {
    int colonneMatrice = 3;
    int righeMatrice = 5;
    int matrice[5][3];

    Matrix(matrice, righeMatrice, colonneMatrice);

    for (int i = 0; i < righeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            matrice[i][j] = i + j;
        }
    }

    printf("Matrice:\n");
    for (int i = 0; i < righeMatrice; i++) {
        for (int j = 0; j < colonneMatrice; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    float result = mediaCorniceMatrice(matrice, righeMatrice, colonneMatrice);
    printf("La media dei valori nella cornice della matrice è: %.2f\n", result);

    return 0;
}