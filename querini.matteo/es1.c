a.#include <stdio.h>

int main(){
	
	int num = 0;
	
	printf(">Inserisci un numero per verificare se e' positivo o negativo:");
	scanf("%d", &num);
	
	if(num >= 0){
		
		printf(">Il numero %d e' risultato positivo.", num);
		
	} else {
		
		printf(">Il numero %d e' risultato negativo.", num);
		
	}
		
	return 0;
}