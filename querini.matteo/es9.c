#include <stdio.h>
#include <math.h>

void valore_assoluto(){

    float valore;
    float risultato;

    printf("Inxserisci un valore per calcolare il suo valore assoluto:");
    scanf("%f", &valore);

     if (valore > 0){
        printf("Il valore assoluto di %f e' %f", valore, valore);
     } else if (valore < 0){
        risultato = valore * -1;
        printf("Il valore assoluto di %f e' %f", valore, risultato);
     }
}

void potenza(){

    float base;
    float esponente;
    float risultato;

    printf("Inseriscu un numero per calcolare la sua potenza:");
    scanf("%f", &base);
    printf("Ora inserisci il suo esponente:");
    scanf("%f", &esponente);

    risultato = pow(base, esponente);

    printf("La potenza del numero %f elevato alla %f e' %f", base, esponente, risultato);


}


void fattoriale(){

    int inputnum1;
    float risultato = 1;

    do{
        printf("Inserisci un numero per calcolare il suo fattoriale:");
        scanf("%d", &inputnum1);
        if (inputnum1 < 0){
            printf("Non e' possibile calcolare il fattoriale di un numero negativo, riprova:");
            scanf("%d", &inputnum1);
        }
        
    } while (inputnum1 < 0);

    if (inputnum1 == 0 || inputnum1 == 1){
        printf("Il suop fattoriale e' 1");
    } else if (inputnum1 != 0 || inputnum1 != 1){
        for (int i = 1; i <= inputnum1; i++){
            risultato = risultato * i;
        }
        printf("Il fattoriale di %d e' %f", inputnum1, risultato);
    }
}


int main(){

int riesecuzione;
int scelta_operazione;

do{
    printf("1. Valore assoluto\n2. Potenza\n3. Fattoriale\n4. Esci\nDigita una operazione:");
    scanf("%d", &scelta_operazione);
    if (scelta_operazione < 1 || scelta_operazione > 4){
        printf("Il numerol inxerito non e' v<òido, riprova:");
        scanf("%d", &scelta_operazione);
    }
    
} while (scelta_operazione < 1 || scelta_operazione > 4);

do{
    switch (scelta_operazione){

case 1:
    valore_assoluto();
    break;


case 2:
    potenza();
    break;


case 3:
    fattoriale();
    break;


case 4:
    printf("Arrivederci!");
    break;


default:
    break;
}

printf("Digita 0 per terminare, un altro valore per rieseguire il codice:");
scanf("%d", riesecuzione);

} while (riesecuzione != 0);

return 0;
}