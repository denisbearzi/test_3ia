#include <stdio.h>

typedef struct {
    int giorno;
    char mese[100];
    int anno;
} DataDiNascita;


typedef struct {
    char nome[100];
    char cognome[100];
    DataDiNascita dataDiNascita;
} Persona;

int main() {
    
    Persona p1;

    printf("Inserisci il nome della persona da salvare: ");
    scanf("%s", p1.nome);

    printf("Inserisci il cognome della persona da salvare: ");
    scanf("%s", p1.cognome);

    printf("Inserisci il giorno di nascita della persona da salvare: ");
    scanf("%d", &p1.dataDiNascita.giorno);

    printf("Inserisci il mese di nascita della persona da salvare: ");
    scanf("%s", p1.dataDiNascita.mese);

    printf("Inserisci l'anno di nascita della persona da salvare: ");
    scanf("%d", &p1.dataDiNascita.anno);

    printf("Rubrica:\nNome:%s\nCogniome:%s\nData di nascita:%d/%s/%d",p1.nome, p1.cogninome, p1.dataDiNascita.giorno, p1.dataDiNascita.mese, p1.dataDiNascita.anno)
return 0;
}