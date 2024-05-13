#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void comparaStringa(){

    bool valoreBooleanoT = true;
    bool valoreBooleanoF = false;

    char stringa1[200];
    printf("Inserisci la prima stringa:");
    scanf("%s", stringa1);
    
    char stringa2[200];
    printf("Inserisci la seconda stringa:");
    scanf("%s", stringa2);

    if (strcmp(stringa1, stringa2) == 0) {
        printf("Il valore booleano è: %s\n", valoreBooleanoT ? "true" : "false");
    } else {
        printf("Il valore booleano è: %s\n", valoreBooleanoF ? "true" : "false");
    }
}

void lunghezzaStringa(){

    int k = 0;
    char stringa[100];
    printf("Inserisci la stringa:");
    scanf("%s", stringa);

    for (int i = 0; stringa[i] != '\0'; i++){
        k++;
    }
     printf("La dimensione della stringa è %d\n", k);
}

void concatStringhe(){

    int i = 0;
    int k = 0;

    char stringa1[100];
    printf("Inserisci la prima stringa:");
    scanf("%s", stringa1);
    
    char stringa2[100];
    printf("Inserisci la seconda stringa:");
    scanf("%s", stringa2);

    char stringa3[200];

   for (int i = 0; stringa1[i] != '\0'; i++){
    stringa3[i] = stringa1[i];
   }

   for (int k = 0; stringa2[k] != '\0'; k++){
    stringa3[i] = stringa2[k];
   }

    stringa3[i + k] = '\0';
    printf("La stringa concatenata è: %s\n", stringa3);

}

int main(){

    int choice = 0;
    do{
        printf(" 1. Calcola lunghezza\n 2. Compara stringhe\n 3. Unisci stringhe\n 4. Esci\n Digita una operazione da fare:");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4){
            printf("Errore\n");
        }
        
    } while (choice < 1 || choice > 4);
    

    switch (choice){

    case 1:
        comparaStringa();
        break;
    
    case 2:
        lunghezzaStringa();
        break;

    case 3:
        concatStringhe();
        break;
    
    default:
        printf("Arrivederci.");
        break;
    }
return 0;
}