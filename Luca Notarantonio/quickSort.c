#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int l, int r){
    int pivot = array[r];
    int i = l - 1;

    for(int j = l; j <= r; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[r]);

    return i + 1;
}

void quickSort(int array[], int l, int r){
    if(l < r){
        int pivot = partition(array, l, r);
        quickSort(array, l, pivot-1); 
        quickSort(array, pivot + 1, r);
    }
}

void merge(int array[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  // Copia i dati negli array di supporto L ed R
  for (i = 0; i < n1; i++) {
    L[i] = array[l + i];
  }

  for (j = 0; j < n2; j++) {
    R[j] = array[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int l, int r){
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);

    merge(array, l, m, r);
  }
}

int binarySearch(int array[], int l , int r, int key){
    while(l <= r){
        int m = l + (r - r) / 2;

        if(array[m] == key){
            return m;
        }
        if(array[m] > key){
            r = m - 1;
        }else{
            l = m +1;
        }
    }
    return -1;
}
/*
node *buildNode(contatto newContatto){
	node *nodeTemp;
	nodeTemp = malloc(sizeof(node));
	nodeTemp->contatto = newContatto;
	nodeTemp->next = NULL;

	return nodeTemp;
}

node *getLastNode(node *head){
	node *lastNode = head;
	while(lastNode != NULL && lastNode->next != NULL){
		lastNode = lastNode->next;
	}
	return lastNode;
}

node *append(node *head, contatto newContatto){
    if(head == NULL){
        head = buildNode(newContatto);
    }else{
	node *lastNode;
	lastNode = getLastNode(head);

	lastNode->next = buildNode(newContatto);
    }
    return head;
}

void deleteNodeAt(node *head, int key){
    node *nodeToDelete = head;
    node *previousNode;

    for(int i = 0; i < key && nodeToDelete != NULL; i++){
        previousNode = nodeToDelete;
        nodeToDelete = nodeToDelete->next;  
    }

    if(nodeToDelete != NULL){
        previousNode->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

void printList(node *head) {
    while (head != NULL) {
        printf("%s -> ", head->contatto.nome);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(node *head){
    node *currentNode = head;
    node *nextNode;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}
*/
//(-(-(-(-(-(-(-(-(-(-(-(-(-(-(-(-(-(-(-(-(--)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)
/*
int main(){
    int array[] = {2, 10, 5, 12, 7};

    for(int i = 0; i < 5; i++){
        printf(" [%d]", array[i]);
    }
    printf("\n");

    quickSort(array, 0, 5);

    for(int i = 0; i < 5; i++){
        printf(" [%d]", array[i]);
    }
    printf("\n");
}
*/