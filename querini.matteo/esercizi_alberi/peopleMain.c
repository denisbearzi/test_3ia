#include <stdio.h>
#include <stdlib.h>
#include "peopleFunction.h"



int main(){


    rubrica myRubrica;
    myRubrica.root = NULL;
    persona* root;


    int choice = 0;


    char nome[100];
    char cognome[100];
    int eta = 0;
    int id = 0;
    int cellulare[10];


    while(choice == 0){

        printf("1. Crea una nuova persona\n");
        printf("2. Inserisci una nuova persona\n");
        printf("3. Stampa la rubrica\n");
        printf("4. Cerca una persona\n");
        printf("5. Elimina una persona\n");
        printf("6. Trova la persona piu' giovane\n");
        printf("7. Trova il successore di una persona\n");

        printf("Digita una operazione d eseguire:");
        scanf("%d", &choice);

        switch (choice){

        case 1:

            printf("Inserisci i dati della persona:\n");
            printf(">nome:");
            scanf("%s", nome);
            printf(">cognome:");
            scanf("%s", cognome);
            printf(">eta:");
            scanf("%d", &eta);
            printf(">cellulare:");
            scanf("%d", &cellulare);

            newPerson(nome, cognome, eta, id, cellulare);
        break;

        case 2:

            printf("Inserisci i dati della persona:\n");
            printf(">nome:");
            scanf("%s", nome);
            printf(">cognome:");
            scanf("%s", cognome);
            printf(">eta:");
            scanf("%d", &eta);
            printf(">cellulare:");
            scanf("%d", &cellulare);

            insertPerson(root, nome, cognome, eta, id, cellulare);
        break;

        case 3:
            printRubrica(root);
        break;

        case 4:
            printf("Inserisci l'id della persona da cercare:");
            scanf("%d", &id);
            searchPeople(root, id);
        break;

        case 5:
            printf("Inserisci l'id della persona da eliminare:");
            scanf("%d", &id);
            delatePerson(root, id);
        break;

        case 6:
            minPerson(root);
           // printRubrica(currentPerson);
        break;

        case 7:
            successor(root);
        break;
    
        default:
            printf("Arrivederci.");
        break;
        }

        printf("Digita zero se vuoi continuare a eseguire operazioni, un altro numero per uscire:");
        scanf("%d", &choice);
    }
    
    return 0;
}