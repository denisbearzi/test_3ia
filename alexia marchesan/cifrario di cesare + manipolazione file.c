#include <stdio.h>
#include <string.h>

void cifraStringa(char* stringa, int chiave) {
    int lunghezza = strlen(stringa);
    
    for (int i = 0; i < lunghezza; i++) {
        stringa[i] = stringa[i] + chiave;
    }
}


void decifraStringa(char* stringa, int chiave) {
    int lunghezza = strlen(stringa);
    
    for (int i = 0; i < lunghezza; i++) {
        stringa[i] = stringa[i] - chiave;
    }
}


void sceltaMenu(int scelta,int chiave,char* stringa){

    printf("Scegli cosa fare con la tua stringa: \n");

        printf("1 Cifra una stringa\n");
    
        printf("2 Decifra una stringa\n");

            scanf("%d", &scelta);
    
char fileManage(char currentChar,FILE *filePointer,char fileName[100]){
	
	printf("Enter the filename to open it: \n");
	scanf("%s", &fileName);
	
	filePointer = fopen(fileName, "r");
	
	if (filePointer == NULL){
		printf("Non esiste un file conquesto file, impossibile aprire! \n");
		exit (0);
		
	}
	currentChar = fgetc (filePointer);
	while (currentChar != EOF){
		printf("%c", currentChar);
		currentChar = fgetc (filePointer);
	}
	
	fclose(filePointer);
	return 0;
}
    switch(scelta) {
        
		fileManage(currentChar,filePointer,fileName,currentChar);
        
        case 1: 

                printf("Inserisci la stringa da cifrare: ");
                scanf("%s", stringa);
                printf("Inserisci la chiave di cifratura: ");
                scanf("%d", &chiave);
                
                cifraStringa(stringa, chiave);
                
                printf("Stringa cifrata: %s \n", stringa);

        break;

        case 2: 

                printf("Inserisci la stringa da decifrare: ");
                scanf("%s", stringa);
                printf("Inserisci la chiave di decifratura: ");
                scanf("%d", &chiave);
                
                decifraStringa(stringa, chiave);
                
                printf("Stringa decifrata: %s \n", stringa);

        break;

        default: 

                printf("Scelta non valida! \n");

        break;

    }

}



int main() {
    int scelta = 0;
    char stringa[100];
    int chiave;

    sceltaMenu(scelta,chiave,stringa);
}
    
