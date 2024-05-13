#include <stdio.h>

int main(){

     float num1 = 0, num2 = 0, risultante = 0;
     char operazione;

     printf("Digita un operatore fra i seguenti: +  -  *  /\n");
     scanf(" %c", &operazione);

     printf("Inserisci i due numeri che vuoi operare:");
     scanf("%f", &num1);
     scanf("%f", &num2);

    switch(operazione){

        case '+':
        risultante = num1 + num2;
        printf("Il risultante della somma fra %f e %f e' %f", num1, num2, risultante);
        break;

        case '-':
        risultante = num1 - num2;
        printf("Il risultante della sottrazione fra %f e %f e' %f", num1, num2, risultante);
        break;

        case '*':
        risultante = num1 * num2;
        printf("Il risultante della moltiplicazione fra %f e %f e' %f", num1, num2, risultante);
        break;
          
        case '/':
        if (num2 != 0){
            risultante = num1 / num2;
            printf("Il risultante della divizione fra %f e %f e' %f", num1, num2, risultante);
        } else {
            printf("Errore: %f non puo' essere 0.", num2);
        }
        break;

        default:
        printf("Mi dispiace, l'operatore inserito non è valido, prova a utilizzare uno dei seguenti: + - * /");
        break;
    }
return 0;
}