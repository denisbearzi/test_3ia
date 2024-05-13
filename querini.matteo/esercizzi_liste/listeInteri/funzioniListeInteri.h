

typedef struct Node{

    int value;  
    struct Node *next;  

} node;


node *buildNode(int inputValue){

    node *nodeTemp;
    nodeTemp = malloc(sizeof(node));

    nodeTemp -> value = inputValue; 
    nodeTemp -> next = NULL;

    return nodeTemp;
}

void printList(node *head){

    node *currentNode = head;  

    while(currentNode != NULL){

        printf("%d ", currentNode->value);  
        currentNode = currentNode->next;  
    }
}

node *getLastNode(node *head){

    node *lastNode = head;

    while (lastNode->next != NULL){

        lastNode = lastNode->next;  
    }

    return lastNode;
}


void append(node *head, int inputValue){

    node *newLastNode = getLastNode(head);
    newLastNode->next = buildNode(inputValue);  
}


int binarySearch(node *head, int value){

    int position = 0;
	int low = 0;
    int high = 0;

    node *currentNode = head;

   
    while (currentNode != NULL){

        high++;
        currentNode = currentNode->next;
    }

    high -= 1;

    while (low <= high){

        int mid = low + (high - low) / 2;

        
        currentNode = head;

        for (int i = 0; i < mid; ++i){

            currentNode = currentNode->next;
        }

        if (currentNode->value == value){
            return mid;  
		}

        if (currentNode->value < value){

            low = mid + 1;

        }else{

            high = mid - 1;
    	}
    }

    return -1;  
}


void deleteNode(node **head, int key){

    node *temp = *head;
    node *prev = NULL;

    if (temp != NULL && temp -> value == key){

        *head = temp -> next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != key){

        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL){
        return;
	}

    prev -> next = temp -> next;
    free(temp);
}


void deleteNodeAt(node **head, int position){
    if (*head == NULL){
        return;
	}

    node *temp = *head;

    if (position == 0){

        *head = temp->next;
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

    node *next = temp -> next -> next;

    free(temp -> next);
    temp -> next = next;
}