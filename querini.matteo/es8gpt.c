#include <stdio.h>

int main() {
    int scelta_menu, scelta_operazione;
    int numero, inputvalore, inputsomma, inputnumeri, Numero, moltiplicatore, valorefinale;
    float numero2, num1, num2, risultante;
    char operazione;

    do {
        printf("[1] Costrutti iterativi\n[2] Costrutti di selezione\n[3] Esci\nInserisci uno dei numeri fra parentesi:");
        scanf("%d", &scelta_menu);

        switch (scelta_menu) {
            case 1:
                do {
                    printf("\n[1] Somma dei primi N numeri interi\n[2] Tabellina di un numero\n[3] Torna al menu precedente\n");
                    scanf("%d", &scelta_operazione);

                    switch (scelta_operazione) {
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
                            printf("Hai scelto di tornare al menu precedente");
                            break;

                        default:
                            printf("Selezione non valida. Riprova.\n");
                            break;
                    }
                } while (scelta_operazione != 3);
                break;

            case 2:
                do {
                    printf("\n[1] Numero pari o dispari\n[2] Calcolatrice\n[3] Torna al menu precedente\n");
                    scanf("%d", &scelta_operazione);

                    switch (scelta_operazione) {
                        case 1:
                            printf("Hai scelto di sapere se un numero N e' pari o dispari\nInserisci un numero per sapere se e' pari o dispari:");
                            scanf("%f", &numero2);

                            if ((int)numero2 % 2 == 0) {
                                printf("Il numero %.2f e' pari\n", numero2);
                            } else {
                                printf("Il numero %.2f e' dispari\n", numero2);
                            }
                            break;

                        case 2:
                            printf("Hai scelto di usare la calcolatrice\n");
                            do {
                                printf("Digita un operatore fra i seguenti: +  -  *  /\n");
                                scanf(" %c", &operazione);

                                printf("Inserisci i due numeri che vuoi operare:\n");
                                scanf("%f %f", &num1, &num2);

                                switch (operazione) {
                                    case '+':
                                        risultante = num1 + num2;
                                        printf("Il risultato della somma fra %.2f e %.2f e': %.2f\n", num1, num2, risultante);
                                        break;

                                    case '-':
                                        risultante = num1 - num2;
                                        printf("Il risultato della sottrazione fra %.2f e %.2f e': %.2f\n", num1, num2, risultante);
                                        break;

                                    case '*':
                                        risultante = num1 * num2;
                                        printf("Il risultato della moltiplicazione fra %.2f e %.2f e': %.2f\n", num1, num2, risultante);
                                        break;

                                    case '/':
                                        if (num2 != 0) {
                                            risultante = num1 / num2;
                                            printf("Il risultato della divisione fra %.2f e %.2f e': %.2f\n", num1, num2, risultante);
                                        } else {
                                            printf("Impossibile dividere per zero.\n");
                                        }
                                        break;

                                    default:
                                        printf("Operatore non valido. Riprova.\n");
                                        break;
                                }

                                printf("Digita 0 per terminare la calcolatrice o un altro valore per continuare:\n");
                                scanf("%d", &valorefinale);
                            } while (valorefinale != 0);
                            break;

                        case 3:
                            printf("Hai scelto di tornare al menu precedente");
                            break;

                        default:
                            printf("Selezione non valida. Riprova.\n");
                            break;
                    }
                } while (scelta_operazione != 3);
                break;

            case 3:
                printf("Arrivederci!");
                break;

            default:
                printf("Selezione non valida. Riprova.\n");
                break;
        }
    } while (scelta_menu != 3);

    return 0;
}