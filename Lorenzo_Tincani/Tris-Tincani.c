#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

// funzione per pulire il terminale ogni volta che si richiama
void pulisciTerminale() {
    system("cls"); 
}

void stampaScacchiera(char scacchiera[3][3]) {
    pulisciTerminale();

    // titolo 

    printf("\033[1;33m                 _____   _____   _____   _____  \033[0m\n");
    printf("\033[1;33m                |_   _| | __  | |     | |   __| \033[0m\n");
    printf("\033[1;33m                  | |   |    -  |-   -| |__   | \033[0m\n");
    printf("\033[1;33m                  |_|   |__|__| |_____| |_____| \033[0m\n\n");


    // stampa della scacchiera  
    printf("\033[1;32m  0 1 2\n\033[0m");
    for (int i = 0; i < 3; i++) {
        printf("\033[1;32m%d\033[0m ", i);
        for (int j = 0; j < 3; j++) {
            if (scacchiera[i][j] == 'X') {
                printf("\033[1;31mX\033[0m ");
            } else if (scacchiera[i][j] == 'O') {
                printf("\033[1;34mO\033[0m ");
            } else {
                printf("%c ", scacchiera[i][j]);
            }
        }
        printf("\n");
    }
}

// controllo vincita in linea e in diagonale 
int controllaVincita(char simbolo, char scacchiera[3][3]) {
    for (int i = 0; i < 3; i++) {

        // verifica in verticale e orizzontale
        if ((scacchiera[i][0] == simbolo && scacchiera[i][1] == simbolo && scacchiera[i][2] == simbolo) ||
            (scacchiera[0][i] == simbolo && scacchiera[1][i] == simbolo && scacchiera[2][i] == simbolo)) {
            return 1;
        }
    }

    // verifica in diagonale
    if ((scacchiera[0][0] == simbolo && scacchiera[1][1] == simbolo && scacchiera[2][2] == simbolo) ||
        (scacchiera[0][2] == simbolo && scacchiera[1][1] == simbolo && scacchiera[2][0] == simbolo)) {
        return 1;
    }

    return 0;
}

// funzione per controllare se il gioco finisce con la parita'
int controllaParita(char scacchiera[3][3]) { 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (scacchiera[i][j] == ' ') { // controllo se ci sono ancora spazi vuoti
                return 0;
            }
        }
    }
    return 1;
}


// funzione per l'easter egg
void matrix(int righe, int colonne) {
    int matrice[righe][colonne];

    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = rand() % 2; // generazione randomica di 0 e 1
        }
    }

    // stampa della matrice
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("\033[1;32m %d \033[0m", matrice[i][j]);
            fflush(stdout);
            usleep(0); // tempo di attesa
        }
    }
}

int main() {

    do { 

        char scacchiera[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        int riga, colonna;
        char player = 'X';

        do {

            stampaScacchiera(scacchiera);
            fflush(stdout);
            usleep(5000);

            // Inserire righe e colonne 
            printf("\n\nGiocatore %c, inserisci la tua mossa (riga e colonna, es. 0 1 2): \n", player); 
            printf("Riga: ");
            char inputRiga[3];
            scanf("%s", inputRiga);

            printf("Colonna: ");
            char inputColonna[3];
            scanf("%s", inputColonna);

            // combinazione per attivare l'easter egg
            if (strcmp(inputRiga, "TR") == 0 && strcmp(inputColonna, "IS") == 0) { 
                matrix(500, 500); 
                return 0;
            }

            sscanf(inputRiga, "%d", &riga);
            sscanf(inputColonna, "%d", &colonna);

            // controllo se utente ha messo valori tra 0 e 2
            if (riga >= 0 && riga < 3 && colonna >= 0 && colonna < 3 && scacchiera[riga][colonna] == ' ') {
                pulisciTerminale();
                scacchiera[riga][colonna] = player;

                if (controllaVincita(player, scacchiera)) {
                    stampaScacchiera(scacchiera);
                    printf("\nIl giocatore %c ha vinto!\n", player);
                    break;
                }

                if (controllaParita(scacchiera)) {
                    stampaScacchiera(scacchiera);
                    printf("Pari!\n");
                    break;
                }

                // cambio del giocatore
                if (player == 'X') {
                    player = 'O';
                } else {
                    player = 'X';
                }
            } else {
                printf("Mossa non valida. Riprova.\n");
            }
        } while (1);

        // richiesta se fare una altra parita o di uscire
        printf("Scrivi ' si ' per fare un altra partita oppure scrivi qualsiasi cosa per uscire dal gioco: ");
        char risposta[3];
        scanf("%s", risposta);

        if (strcmp(risposta, "si") != 0 ) { 
            break;
        }

    } while (1);

    printf("Arrivederci!\n");

    return 0;
}