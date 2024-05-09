#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct{
    int ATK;
    int DEF;
    int HP;
}statistiche;

typedef struct{
    char nome[15];
    int danno;
    int riduzDifesa;
    int riduzDanno;
    int utilizzi;
    char info[100];
}mossa;

typedef struct{
    mossa move1;
    mossa move2;
    mossa move3;
    mossa move4;
    statistiche stats;
    char nomePersonaggio[25];
}personaggio;



void titolo(){
	FILE *filePointer;
	char character;

    filePointer = fopen("titolo.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    fclose(filePointer);
}

int gestioneSelezioneDifficolta(int selection){
do{
		printf("\nselezionare una difficolta: \n\n[1]facile\n[2]normale\n[3]difficile\n[4]molto difficile\n\n");
		scanf(" %d", &selection);
		
		if(selection > 4 || selection < 1){
			printf("\nerrore: selezione invalida");
		}
	}while (selection > 4 || selection < 1);
    system("CLS");
	return selection;
}

int gestioneSelezionePersonaggio(int selection){
do{
		printf("\nselezionare un personaggio: \n\n[1]cavaliere morgan (difensivo)\n[2]cavaliere giana (forte)\n\n");
		scanf(" %d", &selection);
		
		if(selection > 2 || selection < 1){
			printf("\nerrore: selezione invalida");
		}
	}while (selection > 2 || selection < 1);
    system("CLS");
	return selection;
}


void setupPersonaggio1(personaggio *giocatore){ //setup delle mosse, nome e statistiche del giocatore

    //nome
    strcpy(giocatore->nomePersonaggio, "il cavaliere Morgan");

    //prima mossa
    strcpy(giocatore->move1.nome, "spadata");
    giocatore->move1.danno = 15;
    giocatore->move1.riduzDanno = 0;
    giocatore->move1.riduzDifesa = 0;
    giocatore->move1.utilizzi = 20;
    strcpy(giocatore->move1.info, "danneggia il nemico");

    //seconda mossa
    strcpy(giocatore->move2.nome, "rompiarmatura");
    giocatore->move2.danno = 0;
    giocatore->move2.riduzDanno = 0;
    giocatore->move2.riduzDifesa = 2;
    giocatore->move2.utilizzi = 10;
    strcpy(giocatore->move2.info, "riduce la difesa di 2");

    //terza mossa
    strcpy(giocatore->move3.nome, "disarma");
    giocatore->move3.danno = 0;
    giocatore->move3.riduzDanno = 1;
    giocatore->move3.riduzDifesa = 0;
    giocatore->move3.utilizzi = 10;
    strcpy(giocatore->move3.info, "riduce l'attacco di 1");

    //quarta mossa
    strcpy(giocatore->move4.nome, "colpo d'elsa");
    giocatore->move4.danno = 5;
    giocatore->move4.riduzDanno = 0;
    giocatore->move4.riduzDifesa = 2;
    giocatore->move4.utilizzi = 2;
    strcpy(giocatore->move4.info, "danneggia il nemico e riduce la difesa di 2");

    //statistiche
    giocatore->stats.ATK = 5;
    giocatore->stats.DEF = 6;
    giocatore->stats.HP = 100;

    
}

void setupPersonaggio2(personaggio *giocatore){  //setup delle mosse, nome e statistiche del giocatore

    //nome
    strcpy(giocatore->nomePersonaggio, "la cavaliere Giana");

    //prima mossa
    strcpy(giocatore->move1.nome, "spadata");
    giocatore->move1.danno = 15;
    giocatore->move1.riduzDanno = 0;
    giocatore->move1.riduzDifesa = 0;
    giocatore->move1.utilizzi = 20;
    strcpy(giocatore->move1.info, "danneggia il nemico");

    //seconda mossa
    strcpy(giocatore->move2.nome, "rompiscudo");
    giocatore->move2.danno = 0;
    giocatore->move2.riduzDanno = 0;
    giocatore->move2.riduzDifesa = 1;
    giocatore->move2.utilizzi = 10;
    strcpy(giocatore->move2.info, "riduce la difesa di 1");

    //terza mossa
    strcpy(giocatore->move3.nome, "rompispada");
    giocatore->move3.danno = 0;
    giocatore->move3.riduzDanno = 2;
    giocatore->move3.riduzDifesa = 0;
    giocatore->move3.utilizzi = 10;
    strcpy(giocatore->move3.info, "riduce l'attacco di 2");

    //quarta mossa
    strcpy(giocatore->move4.nome, "amputazione");
    giocatore->move4.danno = 5;
    giocatore->move4.riduzDanno = 2;
    giocatore->move4.riduzDifesa = 0;
    giocatore->move4.utilizzi = 2;
    strcpy(giocatore->move4.info, "danneggia il nemico e riduce l'attacco di 2");


    //statistiche
    giocatore->stats.ATK = 6;
    giocatore->stats.DEF = 5;
    giocatore->stats.HP = 100;

    
}

//in base alla difficolta il nome del nemico sara scelto con uno switch
void setupNomeAI(char nomePersonaggio[], int difficolta){
    switch (difficolta){
    case 1:
        strcpy(nomePersonaggio, "il matto");
        break;

    case 2:
        strcpy(nomePersonaggio, "l'apprendista");
        break;

    case 3:
        strcpy(nomePersonaggio, "lo scudiero");
        break;

    case 4:
        strcpy(nomePersonaggio, "il generale");
        break;
    default:
        break;
    }
}


void setupAI(personaggio *AI, int difficolta){

    //prima mossa
    strcpy(AI->move1.nome, "fendente");
    AI->move1.danno = 15;
    AI->move1.riduzDanno = 0;
    AI->move1.riduzDifesa = 0;
    AI->move1.utilizzi = 20;

    //seconda mossa
    strcpy(AI->move2.nome, "distrai");
    AI->move2.danno = 0;
    AI->move2.riduzDanno = 0;
    AI->move2.riduzDifesa = 1;
    AI->move2.utilizzi = 10;

    //terza mossa
    strcpy(AI->move3.nome, "disarma");
    AI->move3.danno = 0;
    AI->move3.riduzDanno = 1;
    AI->move3.riduzDifesa = 0;
    AI->move3.utilizzi = 10;

    //quarta mossa
    strcpy(AI->move4.nome, "affondo");
    AI->move4.danno = 5;
    AI->move4.riduzDanno = 0;
    AI->move4.riduzDifesa = 2;
    AI->move4.utilizzi = 2;

    //statistiche
    AI->stats.ATK = 6;
    AI->stats.DEF = 6;
    AI->stats.HP = 100 + (difficolta * 5);

    //setup nome
    setupNomeAI(&AI->nomePersonaggio, difficolta);
}



void mostraVita(personaggio giocatore, personaggio AI){

    printf("\033[1;32m"); // imposto barra della vita verde
    printf("%s \nVita:", giocatore.nomePersonaggio);
    for(int i = 0; i < (giocatore.stats.HP / 10); i++){
        printf("#");
    }
    printf(" / %d \n", giocatore.stats.HP);

    printf("\033[1;31m"); //imposto barra della vita verde
    printf("%s \nVita:", AI.nomePersonaggio);
    for(int i = 0; i < (AI.stats.HP / 10); i++){
        printf("#");
    }
    printf(" / %d \n", AI.stats.HP);

    printf("\033[1;0m"); //riporto testo bianco
}

//stampo da file l'apetto del nemico
void aspettoNemico(){
	FILE *filePointer;
	char character;

    filePointer = fopen("nemico1.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    fclose(filePointer);

    

}

//animazione del nemico quando si fa male.
void nemicoDanno(){
	FILE *filePointer;
	char character;

    system("CLS");

    filePointer = fopen("nemico1.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    
    sleep(0.1);
    system("CLS");
    printf("\033[1;31m"); //imposto il colore rosso


    filePointer = fopen("nemico2.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    sleep(0.1);
    system("CLS");
    printf("\033[1;0m");  //riporto il colore al bianco originale

    filePointer = fopen("nemico1.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    sleep(0.1);

    fclose(filePointer);

}

//animazione del nemico quando si indebolisce.
void nemicoDebole(){
	FILE *filePointer;
	char character;

    system("CLS");

    printf("\033[1;33m"); //colore giallo

    filePointer = fopen("nemico_indebolito.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    
    sleep(0.3);
    printf("\033[1;0m"); //colore bianco


    fclose(filePointer);

}

//animazione del nemico quando attacca
void nemicoAttacco(){
	FILE *filePointer;
	char character;

    system("CLS");

    filePointer = fopen("nemico1.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    sleep(0.1);
    system("CLS");

    filePointer = fopen("nemico_attacco1.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    sleep(0.1);
    system("CLS");

    filePointer = fopen("nemico_attacco2.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    sleep(0.1);

    fclose(filePointer);
}

//selezione mosse durante una battaglia
int gestioneMosse(int selection, personaggio giocatore){
do{
		printf("\nselezionare una mossa: \n\n[1]%s: %s\n[2]%s: %s\n[3]%s: %s\n[4]%s: %s\n\n", 
        giocatore.move1.nome, giocatore.move1.info, 
        giocatore.move2.nome, giocatore.move2.info,
        giocatore.move3.nome, giocatore.move3.info,
        giocatore.move4.nome, giocatore.move4.info);
		scanf(" %d", &selection);
		
		if(selection > 4 || selection < 1){
			printf("\nerrore: Mossa invalida");
		}
	}while (selection > 4 || selection < 1);
	return selection;
}



void attaccoGiocatore(mossa *attacco, statistiche statsGiocatore, statistiche *statsNemico){
    //controllo se l'attacco non è esaurito
    if (attacco->utilizzi > 0){

        //calcolo danno di un attacco (usa la formula classica degli rpg)
        if(attacco->danno >= statsNemico->DEF ){
            statsNemico->HP -= (attacco->danno * 2) - statsNemico->DEF;
        } else{
            statsNemico->HP -= (attacco->danno * statsGiocatore.ATK) / statsNemico->DEF;
        }

        //per evitare che l'attacco vada nei negativi
        if(statsNemico->ATK > 1){
            statsNemico->ATK -= attacco->riduzDanno;
        } else{
            statsNemico->ATK = 1;
        }
        //per evitare che la difesa vada nei negativi
        if(statsNemico->DEF > 1){
            statsNemico->DEF -= attacco->riduzDifesa;
        } else{
            statsNemico->DEF = 1;
        }
        
        attacco->utilizzi -= 1;
        
    } else {
        printf("la mossa e' esaurita!\n");
    }

}

void attaccoAI(mossa *attacco, statistiche statsNemico, statistiche *statsGiocatore){
    if (attacco->utilizzi > 0){
        
        //calcolo danno di un attacco (usa la formula classica degli rpg)
        if(attacco->danno >= statsGiocatore->DEF ){
            statsGiocatore->HP -= (attacco->danno * 2) - statsGiocatore->DEF;
        } else{
            statsGiocatore->HP -= (attacco->danno * statsNemico.ATK) / statsGiocatore->DEF;
        }

        //per evitare che l'attacco vada nei negativi
        if(statsGiocatore->ATK > 1){
            statsGiocatore->ATK -= attacco->riduzDanno;
        } else{
            statsGiocatore->ATK = 1;
        }
        //per evitare che la difesa vada nei negativi
        if(statsGiocatore->DEF > 1){
            statsGiocatore->DEF -= attacco->riduzDifesa;
        } else{
            statsGiocatore->DEF = 1;
        }
        
        attacco->utilizzi -= 1;
        
    } else {
        printf("la mossa e' esaurita!\n");
    }

}



int gestioneAI(int selection, int difficolta, statistiche giocatoreStats, statistiche AIstats){
    
    srand(time(NULL));

    switch (difficolta){
    //molto facile sceglie attacchi a caso
    case 1:
        //numero casuale da 1 a 4
        selection = (rand() % 4) + 1;
        break;

    //facile attacchera e basta se la vita del giocatore e' sotto a 40 punti vita, altrimenti attachera a caso
    case 2:
        if(giocatoreStats.HP <= 40){
            selection = 1;
        } else {
            selection = (rand() % 4) + 1;
        }
        break;

    case 3:

        //prima di tutto decide se il giocatore è debole per essere attacato definitivamente

        if(giocatoreStats.HP <= 30 || giocatoreStats.DEF <= 1){
            selection = 1;
        } else {
            selection = (rand() % 4) + 1;
        }

        //poi controlla se lui è debvole e i suoi attacchi non faranno niente, se si allora toglie difesa al giocatore
        if(AIstats.ATK < giocatoreStats.DEF - 1){
            selection = 2;
        }
        //poi controlla se il giocatore e' forte e puo facilmente ucciderlo quindi decidera di diminuire l'attacco del giocatore
        if(AIstats.DEF < giocatoreStats.ATK - 2){
            selection = 3;
        }
        break;

    case 4: 
        // prima sceglie a caso
        selection = (rand() % 4) + 1;
        
        //poi controlla se è piu debole e i suoi attacchi non faranno niente, se si allora toglie difesa al giocatore
        if(AIstats.ATK < giocatoreStats.DEF - 1){
            selection = 2;
        } 

        //poi controlla se il giocatore e' forte e puo facilmente ucciderlo quindi decidera di diminuire l'attacco del giocatore
        if(AIstats.DEF < giocatoreStats.ATK - 2){
            selection = 3;
        }

        //poi controlla se: il giocatore è a poca vita, la difesa del giocatore è 1, se la propia vita è poca. se uno di questi è vero allora attachera e basta
        if(giocatoreStats.HP <= 40 || giocatoreStats.DEF <= 1 || AIstats.HP < 40){
            selection = 1;
        }

        break;

    default:
        break;
    }
    return selection;
}

void partitaVinta(){ //stampo lo schermo di Vittoria
	FILE *filePointer;
	char character;

    printf("\033[1;33m"); //colore giallo

    filePointer = fopen("trofeo.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    fclose(filePointer);

    printf("\nCongratulazioni hai vinto!\n\n l'applicazione si chiudera in 5 secondi");

    sleep(5);
}

void partitaPersa(){ //stampo lo schermo di GAME OVER
	FILE *filePointer;
	char character;

    printf("\033[1;31m"); //colore rosso

    filePointer = fopen("tomba.txt", "r");
	character = fgetc(filePointer); 
 	while (character != EOF) { 
        printf ("%c", character); 
      	character = fgetc(filePointer); 
    }

    fclose(filePointer);

    printf("\nChe peccato, hai perso...\n\n l'applicazione si chiudera in 5 secondi");

    sleep(5);
}

void battaglia(personaggio giocatore, personaggio AI, int difficolta){

    int selection = 0;
    int AIselection = 0;
    // loop battaglia finche uno dei due personaggi non raggiunge 0 HP
    do{
        aspettoNemico();  //stampo l'aspetto del nemico
        mostraVita(giocatore, AI); //stampo i punti vita e barra della vita
        do{
            
            selection = gestioneMosse(selection, giocatore);  //faccio scegliere al giocatore che mossa usare

            switch (selection){
            case 1:
                nemicoDanno(); //animazione d'attacco del giocatore
                
                printf("%s usa %s!\n\n", giocatore.nomePersonaggio, giocatore.move1.nome);
                attaccoGiocatore(&giocatore.move1, giocatore.stats, &AI.stats);
                
                sleep(1);
                
                break;

            case 2:
                nemicoDebole();  //animazione del nemico indebolito

                printf("%s usa %s!\n\n", giocatore.nomePersonaggio, giocatore.move2.nome);
                attaccoGiocatore(&giocatore.move2, giocatore.stats, &AI.stats);
                
                sleep(1);
                
                break;

            case 3:
                nemicoDebole(); //animazione del nemico indebolito

                printf("%s usa %s!\n\n", giocatore.nomePersonaggio, giocatore.move3.nome);
                attaccoGiocatore(&giocatore.move3, giocatore.stats, &AI.stats);
                
                sleep(1);
                
                break;

            case 4:
                nemicoDanno(); //animazione d'attacco del giocatore

                printf("%s usa %s!\n\n", giocatore.nomePersonaggio, giocatore.move4.nome);
                attaccoGiocatore(&giocatore.move4, giocatore.stats, &AI.stats);
                
                sleep(1);
                
                break;

            default:
                break;
            }

        } while (selection > 4 || selection < 1);

        if(AI.stats.HP > 0){
            AIselection = gestioneAI(AIselection, difficolta, giocatore.stats, AI.stats);
            switch (AIselection){

                case 1:
                    nemicoAttacco();  //animazione d'attacco del nemico

                    printf("Il nemico usa %s!\n\n", AI.move1.nome);
                    attaccoAI(&AI.move1, AI.stats, &giocatore.stats);

                    sleep(1);

                    break;
                case 2:
                    nemicoAttacco(); //animazione d'attacco del nemico

                    printf("Il nemico usa %s!\n\n", AI.move2.nome);
                    attaccoAI(&AI.move2, AI.stats, &giocatore.stats);

                    sleep(1);

                    break;
                case 3:
                    nemicoAttacco(); //animazione d'attacco del nemico

                    printf("Il nemico usa %s!\n\n", AI.move3.nome);
                    attaccoAI(&AI.move3, AI.stats, &giocatore.stats);

                    sleep(1);

                    break;
                case 4:
                    nemicoAttacco(); //animazione d'attacco del nemico

                    printf("Il nemico usa %s!\n\n", AI.move4.nome);
                    attaccoAI(&AI.move4, AI.stats, &giocatore.stats);
                    
                    sleep(1);
                    
                    break;
                default:

                    break;
            }
        }

        system("CLS");

    } while (giocatore.stats.HP > 0 && AI.stats.HP > 0);
    
    if (giocatore.stats.HP <= 0){
        partitaPersa();

    } else {
        partitaVinta();
    }
    

}


int main(){
    personaggio giocatore;
    personaggio AI;

    titolo();

    int difficolta = 0;
    difficolta = gestioneSelezioneDifficolta(difficolta);
    
    titolo();

    int selezionePersonaggio = 0;
    selezionePersonaggio = gestioneSelezionePersonaggio(selezionePersonaggio);
    switch (selezionePersonaggio){
    case 1:
        setupPersonaggio1(&giocatore);
        break;
    case 2:
        setupPersonaggio2(&giocatore);
        break;
    default:
        setupPersonaggio1(&giocatore);
        break;
    }
    
    setupAI(&AI, difficolta);

    battaglia(giocatore, AI, difficolta);
    
    return 0;
		
}