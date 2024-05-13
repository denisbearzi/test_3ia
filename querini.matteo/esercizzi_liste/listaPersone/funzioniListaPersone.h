

typedef struct Person{

    char nome[100];
    char cognome[100];
    int eta;
    int id;
    struct Person *next;  

} person;


person *buildPerson(char inputNome[], char inputCognome[], int inputEta, int inputId){

    person *personTemp;
    personTemp = malloc(sizeof(person));

    strcpy(personTemp->nome, inputNome);
    strcpy(personTemp->cognome, inputCognome);
    personTemp -> eta = inputEta;
    personTemp -> id = inputId; 
    personTemp -> next = NULL;

    return personTemp;
}

void printList(person *head){

    person *currentPerson = head;  

    while(currentPerson != NULL){

        printf("\n %s\n ", currentPerson -> nome);
        printf("%s\n ", currentPerson -> cognome);
        printf("%d\n ", currentPerson -> eta);
        printf("%d\n ", currentPerson -> id);  
        currentPerson = currentPerson -> next;  
    }
}

person *getLastPerson(person **head){

    person *lastPerson = *head;

    while (lastPerson -> next != NULL){

        lastPerson = lastPerson -> next;  
    }

    return lastPerson;
}


void append(person **head, char inputNome[], char inputCogniome[], int inputId, int inputEta){

    person *newLastPerson = getLastPerson(head);
    newLastPerson -> next = buildPerson(inputNome, inputCogniome, inputId, inputEta);  
}


int binarySearch(person *head, int key){

    int position = 0;
	int low = 0;
    int high = 0;

    person *currentPerson = head;

   
    while (currentPerson != NULL){

        high++;
        currentPerson = currentPerson->next;
    }

    high -= 1;

    while (low <= high){

        int mid = low + (high - low) / 2;

        
        currentPerson = head;

        for (int i = 0; i < mid; ++i){

            currentPerson = currentPerson->next;
        }

        if (currentPerson -> id == key){
            return mid;  
		}

        if (currentPerson -> id < key){

            low = mid + 1;

        }else{

            high = mid - 1;
    	}
    }

    return -1;  
}


void deletePerson(person **head, int key){

    person *temp = *head;
    person *prev = NULL;

    if (temp != NULL && temp -> id == key){

        *head = temp -> next;
        free(temp);
        return;
    }

    while (temp != NULL && temp -> id != key){

        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL){
        return;
	}

    prev -> next = temp -> next;
    free(temp);
}


void deletePersonAt(person **head, int position){

    if (*head == NULL){
        return;
	}

    person *temp = *head;

    if (position == 0){

        *head = temp -> next;
        free(temp);
        return;
    }

	int i;

    for (i = 0; temp != NULL && i < position - 1; i++){
        temp = temp->next;
	}


    if (temp == NULL || temp->next == NULL){
        return;
	}

    person *next = temp -> next -> next;

    free(temp -> next);
    temp -> next = next;
}