#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//extern int globalId;



typedef struct Persona{

	char nome[100];
	char cognome[100];
	int eta;
	int id;
	int cellulare[10];

	struct Persona* left;
	struct Persona* right;

}persona;



typedef struct{
	persona* root;
}rubrica;




//versione iterativa
persona* minPerson(persona* root){
	
	persona* currentPerson = root;
	
	while(currentPerson -> left != NULL){
		
		currentPerson = currentPerson -> left;
	}
	return currentPerson;
}



persona* min(rubrica* tree){
	minPerson(tree -> root);
}


persona* successor(persona* root){
	return minPerson(root -> right);
}



persona* delatePerson(persona* root, int id){
	
	
	persona* succ;
	
	
	//caso base
	if(root == NULL){
		
		return NULL;
	}
	
	
	//caso 1: foglia
	if(root -> left == NULL && root -> right == NULL){
		
		free(root);
	}
	
	
	//cerca il nodo da eliminare
	if(id < root -> id){
		
		
		//cerca nel sottoalbero sx
		delatePerson(root -> left, id);
	} else if(root -> right, id){
		
		
		//cerca nel sottoalbero dx
		delatePerson(root -> right, id);
	} else{
	
	
	//caso 2 e 3: 
	succ = successor(root);
	root -> id = succ -> id;
	delatePerson(root -> left, succ -> id);
	}
}




void delate(rubrica tree, int id){
	delatePerson(tree.root, id);
}



persona* newPerson(char nome[], char cognome[], int eta, int id, int cellulare[]){
	persona* tempPerson;
	tempPerson = (persona*)malloc(sizeof(persona));
	
	id++;

	tempPerson -> left = NULL;
	tempPerson -> right = NULL;
	strcpy(tempPerson -> nome, nome);
	strcpy(tempPerson -> cognome, cognome);
	tempPerson -> eta = eta;
	tempPerson -> id = id;

	for (int i = 0; i < 10; i++){

    	tempPerson->cellulare[i] = cellulare[i];
    }

	return tempPerson;
}



persona* insertPerson(persona* root, char nome[], char cognome[], int eta, int id,  int cellulare[]){
	
	if(root == NULL){
		return newPerson(nome, cognome, eta, id, cellulare);
	}
	
	if(eta <= root -> eta){
		
		root -> left = insertPerson(root -> left, nome, cognome, eta, id,  cellulare);
		
	} else {
		
		root -> right = insertPerson(root -> right, nome, cognome, eta, id, cellulare);
	}
	return root;
}



void insert(rubrica* tree, char nome[], char cognome[], int eta, int id, int cellulare[]){
	insertPerson(tree -> root, nome, cognome, eta, id, cellulare);
}



void printRubrica(persona* root){


    if (root != NULL){



        // visita il sottoalbero sinistro
        printRubrica(root->left);



        // stampa i dettagli della persona
        printf("Nome: %s\n", root->nome);
        printf("Cognome: %s\n", root->cognome);
        printf("Età: %d\n", root->eta);
        printf("ID: %d\n", root->id);
        printf("Cellulare: ");



        //stampa l'array cellulare
        for (int i = 0; i < 10 && root->cellulare[i] != 0; i++){

            printf("%d ", root->cellulare[i]);
        }

        printf("\n");

        // visita il sottoalbero destro
        printRubrica(root->right);
    }
}



persona* searchPeople(persona* root, int id){
	persona* currentPerson = root;

	if(currentPerson -> id == id){

		return currentPerson;
	}
	
	if(currentPerson -> id > id){

		currentPerson = currentPerson -> left;
		return searchPeople(currentPerson, id);

	} else {

		currentPerson = currentPerson -> right;
		return searchPeople(currentPerson, id);
	}
	printRubrica(currentPerson);
}


persona* searchPersona(rubrica* tree, int id){
	searchPeople(tree -> root, id);
}
