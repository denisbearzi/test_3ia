#include <stdio.h>

int main() {
    int matrice[5][5];
    int valore1 = 0;
    int valore2 = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrice[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        matrice[valore1][valore2] = 1;
        valore1 += 1;
        valore2 += 1;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}