#include <stdio.h>

int main(){

    int scelta_menu = 0;
    int scelta_operazione = 0;
    int numero = 0;
    int valore = 0;
    int numero = 0;
    int moltiplicatore = 0;
    int risultato = 0;
    int valorefinale = 0;
    int inputvalore = 0;
    int inputsomma = 0;
    int inputnumeri = 0;
    float inoutnum1 = 0;
    float inputnum2 = 0;
    float risultante = 0;
    char operazione;

    do{
        printf("\n[1] Costrutti iterativi\n[2] Costrutti di selezione\n[3] Esci\nInserisci uno dei numeri fra parentesi:");
        scanf("%d", &scelta_menu);

        switch (scelta_menu){

        case 1:

        do{
            printf("\n[1] Somma dei primi N numeri interi\n[2] Tabellina di un numero\n[3] Torna al menu precedente\n");
            scanf("%d", &scelta_operazione);
            switch (scelta_operazione)
            {
            case 1:
                printf("Hai deciso di fare la somma dei primi N numeri interi\n");
                            do {
                                printf("Inserisci un valore (positivo) per calcolare la somma di tutti i numeri interi che lo precedono:");
                                scanf("%d", &inputvalore);

                                while (inputvalore <= 0) {
                                    printf("Il valore inserito non e' valido perche' e' minore di 0, inserisci un altro valore:");
                                    scanf("%d", &inputvalore);
                                }

                                inputsomma = 0;
                                for (inputnumeri = 1; inputnumeri <= inputvalore; inputnumeri++) {
                                    inputsomma = inputsomma + inputnumeri;
                                }
                                printf("\nLa somma di tutti i valori prima di %d e': %d", inputvalore, inputsomma);
                                printf("\nDigita un qualsiasi valore per eseguire un ulteriore operazione e 0 per terminare:");
                                scanf("%d", &valorefinale);
                            } while (valorefinale != 0);
                break;
            
            case 2:

                printf("Hai deciso di fare la tabellina di un N numero\n");
                            do {
                                printf("Inserisci un numero intero per sapere la sua tabellina:");
                                scanf("%d", &Numero);

                                printf("La tabellina del %d e':\n", Numero);

                                for (moltiplicatore = 1; moltiplicatore <= 10; moltiplicatore++) {
                                    risultante = Numero * moltiplicatore;
                                    printf("%d x %d = %.2f\n", Numero, moltiplicatore, risultante);
                                }

                                printf("\nDigita 0 per terminare il programma o un altro valore per ripeterlo:");
                                scanf("%d", &valorefinale);
                            } while (valorefinale != 0);
                break;

            case 3:

                printf("Hai deciso di tornare al menu precedente.\n");
                break;

            default:

            printf("\nSelezione non valida, riprova:");

                break;
            }

        } while (scelta_operazione != 3);
        
            break;
        
            
        case 2:

            do{
                printf("\n[1] Numero pari o dispari\n[2] Calcolatrice\n[3] Torna al menu precedente\n");
                scanf("%d", &scelta_operazione);

                switch (scelta_operazione){


                case 1:
                
                    do {
		                printf("Hai scelto di sapere se un numero N e' pari o dispari\nInserisci un numero per sapere se e' pari o dispari:");
                        scanf("%f", &numero);

                        if (numero % 2 == 0) {
                            printf("Il numero %f e' pari\n", numero);
                        } else {
                            printf("Il numero %f e' dispari\n", numero);
                        }
        
		                printf("\nDigita 0 per terminare il programma o un altro valore per ripeterlo:");
		                scanf("%d", &valore);
                    } while (valore != 0);
                        
                    break;


                    printf("Hai scelto di usare la calcolatrice\n");
                case 2:
                
                    do{
                        printf("Digita un operatore fra i seguenti: +  -  *  /\n");
                        scanf(" %c", &operazione);

                        printf("Inserisci i due numeri che vuoi operare:");
                        scanf("%f", &inputnum1);

                        switch(operazione){

                            case '+':
                            scanf("%f", &inputnum2);
                            risultante = inputnum1 + inputnum2;
                            printf("Il risultante della somma fra %f e %f e' %f", inputnum1, inputnum2, risultante);
                            break;

                            case '-':
                            scanf("%f", &inputnum2);
                            risultante = inputnum1 - inputnum2;
                            printf("Il risultante della sottrazione fra %f e %f e' %f", inputnum1, inputnum2, risultante);
                            break;

                            case '*':
                            scanf("%f", &inputnum2);
                            risultante = inputnum1 * inputnum2;
                            printf("Il risultante della moltiplicazione fra %f e %f e' %f", inputnum1, inputnum2, risultante);
                            break;
          
                            case '/':
                                do{
                                    printf("Inserisci il secondo numero (deve essere maggiore di zero): ");
                                    scanf("%f", &inputnum2);
                                    if (inputnum2 <= 0){
                                        printf("\nIl numeor inserito e' uguale a zero, inserisci dinuovo il secondo valore facendo attenzione che sia diverso da 0:");
                                        scanf("%f", &inputnum2);
                                    }
                                } while (inputnum2 <= 0);
                                    risultante = inputnum1 / inputnum2;
                                    printf("Il risultante della divizione fra %f e %f e' %f", inputnum1, inputnum2, risultante);
                            break;

                            default:
                            printf("Mi dispiace, l'operatore inserito non è valido, prova a utilizzare uno dei seguenti: + - * /");
                            break;
                        }
                        printf("\nDigita un qualsiasi valore per eseguire un ulteriore operazione e 0 per terminare:");
                        scanf("%d", &valore);
                        } while (valore != 0);
                            printf("\nGrazie per aver utilizzato questo programma, arrivederci");
                    break;
                    
                case 3:

                    printf("Hai scelto di tornare al menu precedente\n");

                    break;

                default:
                printf("L'operatore non è valido, riprova");
                    break;
                }
            } while (scelta_operazione != 0);
            
            break;

        case 3:
            printf("Arrivederci.");
            break;

        default:
            break;
        }
    }while (scelta != 3);
        return 0;
}