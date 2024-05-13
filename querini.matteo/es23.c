#include <stdio.h>
#include <string.h>

typedef struct{
    int giorno;
    int mese;
    int anno;
}data;


typedef struct{
    char nome[100];
    char cognome[100];
    data compleanno;
}persona;

typedef struct{
    persona contatti[100];
    int dimensioneRubrica;
}rubrica;

void choiceMenu(){
    int choice = 0;
    do{
        printf("Digita una operazione da fare:");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4){
            printf("Errore, riprova:");
        }
    } while (choice < 1 || choice > 4);
}

void newContact(persona rubrica[], int dimensioneRubrica){

    int dimensioneRubrica = 0;

    printf("Inserisci la dimensione della rubrica:");
    scanf("%d", &dimensioneRubrica);
    
    persona rubtica[dimensioneRubrica];

    for (int i = 0; i < dimensioneRubrica; i++) {

        printf("Inserisci nome: ");
        scanf("%s", rubrica[i].nome);

        printf("Inserisci cogninome: ");
        scanf("%s", rubrica[i].cogniome);

        printf("Inserisci la data di nascita: ");
        scanf("%d/%d/%d", rubrica[i].data.giorno, rubrica[i].data.mese, rubrica[i].data.anno);
    }
}

void searchContact(persona rubrica[], int dimensioneRubrica){

    char nome[100];
    printf("Inserisci il nome da cercare nella rubrica:");
    scanf("%s", nome);

    for (int i = 0; i < dimensioneRubrica; i++){
        if (strcmp(nome, rubrica[i].nome) == 0){
            printf("Il contatto:\nnome:%s\ncogniome:%s\ncompleanno:%s/%s/%s\n", rubrica[i].nome, rubrica[i].cognome, rubrica[i].data.giorno, rubrica[i].data.mese, rubrica[i].data.anno,);
        } else{
            printf("Il contatto non è stato trovato nella rubrica.");
        }
        
        
    }
    
}

void printAddressBook(persona rubrica[], int dimensioneRubrica) {
    for (int i = 0; i < dimensioneRubrica; i++){
        printf("Il contatto %d:\nnome:%s\ncognome:%s\ncompleanno:%s/%s/%s\n", i, rubrica[i].nome, rubrica[i].cognome, rubrica[i].data.giorno, rubrica[i].data.mese, rubrica[i].data.anno);
    }
}

int main(){
    
    int choice;
    choiceMenu();

    switch (choice){

    case 1:
        newContact(rubrica, dimensioneRubrica);
        break;

    case 2:
        searchContact(rubrica, dimensioneRubrica);
        break;

    case 3:
        printAddressBook(rubrica, dimensioneRubrica);
        break;
    
    default:
        printf("Arrivederci.");
        break;
    }
return 0;
}