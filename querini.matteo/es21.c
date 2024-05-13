#include <stdio.h>
#include <string.h>


int cifraStringa(char stringa[], int keyMittente){
    for (int i = stringa; i < stringa; i++){
        stringa[i] += key;
    }
    
}


void decifraStringa(char stringa[], int keyDestinatario){
    for (int i = stringa; i < stringa; i++){
        stringa[i] -= keyDestinatario;
        printf("La parola cifrata e': %s", stringa[i]);
    }
}


int main(){

    char stringa[100];
    int keyMittente = 0;
    int keyDestinatario = 0;
    int choice = 0;
    printf("1. Cifra stringa\n2. Decifra stringa\n3. Esci\nSegli una operazione da fare:");
    scanf("%d", &choice);

    switch (choice){

    case 1:

        printf("Inserisci una stringa che vuoi cifrare:");
        scanf("%s", stringa);

        printf("Inserisci una chiave:");
        scanf("%d", &keyMittente);

        cifraStringa();
        break;

    case 2:

        printf("Inserisci una chiave:");
        scanf("%d", &keyDestinatario);

        decifraStringa();
        break;
    
    default:
        printf("Arrivederci.")
        break;
    }

return 0;
}