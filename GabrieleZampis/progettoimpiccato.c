#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int main() {
	//zampis gabriele 2a progetto di informatica impiccato da consegnare entro il 7/06/23
	/*Creare un software che simula il gioco dell�impiccato. Dobbiamo adottare
alcuni accorgimenti per semplificare il programma. Stabilire un numero
massimo di tentativi sbagliati possibili per indovinare la parola. La parola da
ricercare pu� essere inserita a programma senza chiedere l�inserimento
all�utente. Inoltre, stabiliamo che la parola da cercare sia tutta in minuscolo e
anche le lettere che verranno inserire sono tutte in minuscolo. Non sar�
possibile inserire la parola completa ma bisogna inserire lettera per lettera*/
//in questo programma c� qualche modifica dal principale, la pi� incisiva � il fatto che una volta finito si pu�
//reiniziare il gioco premendo 1
	//il codice sar� diviso in vari settori, per permettermi di non perdermi tra le linee di codice 
    //pertanto creer� dei settori divisi da dei commenti specifici per specificare bene il settore
    printf("\n");
    printf("BENVENUTO AL GIOCO DELL IMPICCATO!!");
    printf("\n");
    printf("\nATTENZIONE, la parola nascosta NON contiene lettere maiuscole\n");
	printf("\npertanto, tutte le lettere maiuscole inserite verranno convertite in minuscole\n");
	printf("\ni caratteri inseriti oltre alle lettere verranno contati come errore\n");
	printf("\nhai 10 tentativi per indovinare la parola\n");
	int num;
	num=1;
	//inizializzo una variabile chiamata round come output per vedere il numero della partita
	int round;
	round=0;
	while(num==1){
    // fopen per aprile  il file di testo
    FILE* file = fopen("parole.txt", "r");
    //spazio variabili
    int i;
    int numerodelleparole;
    numerodelleparole=0;
    srand(time(NULL));
    int colonna;
    int lunghezza;
    round=round+1;
    //nascosta sar� l'incognita che va trovata 
    char nascosta[20];
    //chiuso lo spazio per le variabili
    while (fgets(nascosta, 20, file) != NULL) {
        numerodelleparole=numerodelleparole+1; 
    }
    //scelgo una parola casuale partendo dal selezionare una colonna casuale del file da cui questultimo prenda la 
    // parola in quella determinata riga(se ci sono pi� parola in uns colonna il programma non funziona)
	colonna = rand() % numerodelleparole;
	//la funzione fseek imposta l'indicatore di posizione nel file
    fseek(file, 0, SEEK_SET);
    for ( i = 0; i < colonna; i++) {
        fgets(nascosta, 20, file);
    }
    nascosta[strlen(nascosta)-2] = '\0'; 
    char parola[20];
    int tentativi;
    tentativi = strlen(nascosta);
    int conteggio;
    conteggio = 0;
    int meno;
    printf("\n");
    printf("%d%c ROUND\n\n",round,167);
    for( i = 0; i < strlen(nascosta); i++)
    {
    	parola[i] = 95;
    	printf("%c ",parola[i]);
	}
    int ctentativi;
    ctentativi=0;
    printf("\n");
	for(ctentativi = 10; ctentativi > 0; ctentativi--)
	{
        printf("\nTentativi rimanenti: %d\n", ctentativi);
		printf("\n");
	    char inserimento;
		scanf(" %c", &inserimento);
		//funzione che trasforma le lettere maiuscole in minuscole 
		inserimento=tolower(inserimento);
		printf("\n");
    meno=0;
		//apertura spazio for per controllare tutte le lettere
		for( i = 0; i < strlen(nascosta); i++)
		{
			if(inserimento==nascosta[i])
			{   
			  parola[i]=inserimento;
		      printf("%c ", inserimento);
			  conteggio++;	
			  meno++;
			}
			else {
				printf("%c ",parola[i]);
			}	
		}
		//controllo in if per vedere se la parola era giusta e quindi di conseguenza non togliere tentativi
		if(meno>0)
		{
			ctentativi=ctentativi+1;
			printf("\n");
			printf("\nbravo, hai indovinato la lettera!\n");
		}
		else{
			printf("\n");
			printf("\npurtroppo hai sbagliato, ritenta!\n");
		}
	//controllo per vedere se la parola � stata indovinata senza stamparla per comodit� dopo
	if(conteggio==strlen(nascosta))
	{
	break;	
	}
	}
	//uso questo if per dire se si ha vinto o perso
	if(conteggio==strlen(nascosta))
	{	
		printf("\nComplimenti, hai vinto! la parola era %s.\n",nascosta); 
	}
	else {
		printf("\nPurtroppo hai perso, la parola era %s.\n",nascosta);
		 }
	printf("\nse vuoi fare un altro round digita 1, se invece vuoi terminare la sessione, digita qualsiasi altro numero.\n");
	printf("\n");
	scanf("%d", &num);	
}
printf("\nhai digitato un numero diverso da 1, pertanto il programma %c ora terminato.\n",138);
	return 0;
}
