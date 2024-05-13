#include <stdio.h>

int main(){

    int valore;
    float num1 = 0;
    float num2 = 0;
    float risultante = 0;
    char operazione;

    do{
        printf("Digita un operatore fra i seguenti: +  -  *  /\n");
        scanf(" %c", &operazione);

        printf("Inserisci i due numeri che vuoi operare:");
        scanf("%f", &num1);

        switch(operazione){

            case '+':
            scanf("%f", &num2);
            risultante = num1 + num2;
            printf("Il risultante della somma fra %f e %f e' %f", num1, num2, risultante);
            break;

            case '-':
            scanf("%f", &num2);
            risultante = num1 - num2;
            printf("Il risultante della sottrazione fra %f e %f e' %f", num1, num2, risultante);
            break;

            case '*':
            scanf("%f", &num2);
            risultante = num1 * num2;
            printf("Il risultante della moltiplicazione fra %f e %f e' %f", num1, num2, risultante);
            break;
          
            case '/':
                do{
                    printf("Inserisci il secondo numero (deve essere maggiore di zero): ");
                    scanf("%f", &num2);
                    if (num2 <= 0){
                        printf("\nIl numeor inserito e' uguale a zero, inserisci dinuovo il secondo valore facendo attenzione che sia diverso da 0:");
                        scanf("%f", &num2);
                    }
                } while (num2 <= 0);
                    risultante = num1 / num2;
                    printf("Il risultante della divizione fra %f e %f e' %f", num1, num2, risultante);
            break;

            default:
            printf("Mi dispiace, l'operatore inserito non è valido, prova a utilizzare uno dei seguenti: + - * /");
            break;
        }
        printf("\nDigita un qualsiasi valore per eseguire un ulteriore operazione e 0 per terminare:");
        scanf("%d", &valore);
    } while (valore != 0);
        printf("\nGrazie per aver utilizzato questo programma, arrivederci");

return 0;
}