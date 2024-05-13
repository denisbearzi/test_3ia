#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioniListaPersone.h"

int main(){
	
    char nome[100];
    char cognome[100];
    int eta = 0;
    int id = 0;
    
    char newNome[100];
    char newCognome[100];
    int newEta = 0;
    int newId = 0;

    int result = 0;
    int key = 0;

    person *head;

    //datidi una persona persona
    printf("\nInserisci il nome: ");
    scanf("%s", nome);

    printf("\nInserisci il cogniome: ");
    scanf("%s", cognome);

    printf("\nInserisci l'eta: ");
    scanf("%d", &eta);

    printf("\nInserisci l'id: ");
    scanf("%d", &id);


    head = buildPerson(nome, cognome, eta, id);

    printf("Inserisci un nuovo contatto alla lista:\n");

    printf("\nInserisci il nome: ");
    scanf("%s", newNome);

    printf("\nInserisci il cognome: ");
    scanf("%s", newCognome);

    printf("\nInserisci l'eta: ");
    scanf("%d", &newEta);

    printf("\nInserisci l'id: ");
    scanf("%d", &newId);
    

    append(&head, newNome, newCognome, newEta, newId);

    printList(head);

    printf("\nInserisci l'id della persona da eliminate della lista:");
    scanf("%d", &key);

    deletePerson(&head, key);

    printList(head);

    printf("\nInserisci l'id della persona da cercare nella lista:");
    scanf("%d", &key);

    result = binarySearch(head, key);

    if (result == -1){

        printf("Il valore %d non è presente nella lista.\n", key);

    }else{

        printf("Il valore %d è stato trovato alla posizione %d.\n", key, result);
        
    }

    return 0;
}