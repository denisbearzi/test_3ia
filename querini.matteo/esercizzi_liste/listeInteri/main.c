#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
	
    int valoreMain = 0;
    int inputValue = 0;
    int result = 0;
    int value = 0;
    int key = 0;

    node *head;

    printf("Inserisci un valore:");
    scanf("%d", &valoreMain);

    head = buildNode(valoreMain);

    printf("Inserisci un nuovo valore da inserire alla fine della lista:");
    scanf("%d", &inputValue);

    append(head, inputValue);

    printList(head);

    printf("\nInserisci un nuovo valore da eliminare della lista:");
    scanf("%d", &key);

    deleteNode(&head, key);

    printList(head);

    printf("\nInserisci un valore da cercare nella lista:");
    scanf("%d", &value);

    result = binarySearch(head, value);

    if (result == -1){

        printf("Il valore %d non è presente nella lista.\n", value);

    }else{

        printf("Il valore %d è stato trovato alla posizione %d.\n", value, result);
        
    }

    return 0;
}