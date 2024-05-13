#include <stdio.h>
#include <string.h>

void getDomain(){

    int k = 0;
    char stringaDominio[100];
    char stringaUrl[100];
    printf("Inserisci la stringa:");
    scanf("%s", stringaUrl);

    for (int i = 0; stringaUrl[i] != '.'; i++){
        k++;
    }
    strcat(stringaDominio, stringaUrl + k);
    printf("%s\n", stringaDominio);
}


void subString(){

    int indice1 = 0;
    int indice2 = 0;
    char stringa[100];
    char stringaFinale[100];

    printf("Inserisci la stringa:");
    scanf("%s", stringa);
    gets(stringa);

    printf("Inserisci gli indici:");
    scanf("%d", indice1);
    scanf("%d", indice2);

    for (int i = indice1; i <= indice2; i++){
    }

    printf("Sottostringa: %s\n", stringaFinale);
}

int main() {
    int choice = 0;
    do {
        printf(" 1. Stampa dominio\n 2. Parte della stringa\n 3. Esci\n Digita un'operazione da fare: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Errore\n");
        }

    } while (choice < 1 || choice > 3);

    switch (choice) {
        case 1:
            getDomain();
            break;

        case 2:
            subString();
            break;

        default:
            printf("Arrivederci.\n");
            break;
    }

    return 0;
}