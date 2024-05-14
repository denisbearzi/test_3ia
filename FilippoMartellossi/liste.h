// Define a structure for a node in a singly linked list
typedef struct Node {
    int value;               // Value held by the node
    struct Node *next;       // Pointer to the next node
} node;

// Function to create a new node with a given value
node *buildNode(int inputValue) {
    node *nodeTemp;          // Temporary node pointer
    nodeTemp = malloc(sizeof(node));  // Allocate memory for the new node
    nodeTemp->value = inputValue;      // Set the value of the new node
    nodeTemp->next = NULL;             // Initialize the next pointer to NULL
    return nodeTemp;                   // Return the newly created node
}

// Function to print the elements of the list iteratively
void printListIterativo(node *head) {
    node *currentNode = head;   // Start from the head of the list

    // Iterate through the list until the current node is NULL
    while(currentNode != NULL) {
        printf("%d ", currentNode->value);  // Print the value of the current node
        currentNode = currentNode->next;    // Move to the next node
    }
}

// Function to get the last node of the list
node *getLastNode(node *head) {
    node *lastNode = head;    // Start from the head of the list

    // Traverse the list until the next pointer of the current node is NULL
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;    // Move to the next node
    }

    return lastNode;   // Return the last node
}

// Function to append a new node with a given value to the end of the list
void append(int inputValue, node *head) {
    node *newLastNode = getLastNode(head);    // Get the last node of the list
    newLastNode->next = buildNode(inputValue);  // Create a new node and append it to the list
}

// Function to sort the list using bubble sort algorithm
void bubbleSort(node *head) {
    int swapped;
    node *currentNode;
    node *lastSortedNode = NULL;

    if (head == NULL)
        return;

    // Iterate through the list until no more swaps are needed
    do {
        swapped = 0;                // Flag to check if any swap occurs in this pass
        currentNode = head;

        // Iterate through the unsorted part of the list
        while (currentNode->next != lastSortedNode) {
            // Swap adjacent elements if they are in the wrong order
            if (currentNode->value > currentNode->next->value) {
                int temp = currentNode->value;
                currentNode->value = currentNode->next->value;
                currentNode->next->value = temp;
                swapped = 1;    // Set swapped flag to true
            }
            currentNode = currentNode->next;    // Move to the next node
        }
        lastSortedNode = currentNode;   // Mark the last sorted node
    } while (swapped);   // Repeat until no more swaps occur
}

// Function to perform binary search on the sorted list
int binarySearch(node *head, int value) {
    int position = 0;         // Position of the element found
    node *currentNode = head; // Start from the head of the list
    int low = 0;              // Low index for binary search
    int high = 0;             // High index for binary search

    // Calculate the number of nodes in the list
    while (currentNode != NULL) {
        high++;               // Increment the high index
        currentNode = currentNode->next;  // Move to the next node
    }

    high -= 1;   // Adjust the high index

    // Perform binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate the mid index

        // Traverse to the middle node of the list
        currentNode = head;
        int i;
        for (i = 0; i < mid; ++i) {
            currentNode = currentNode->next;  // Move to the next node
        }

        // Check if the value is found at the middle node
        if (currentNode->value == value)
            return mid;  // Return the position of the value

        // Update the low and high indices based on the comparison with the value
        if (currentNode->value < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;   // Return -1 if the value is not found in the list
}

// Function to delete a node with a given value from the list
void deleteNode(node **head, int key){
    node *temp = *head;    // Temporary pointer to traverse the list
    node *prev = NULL;     // Pointer to the previous node

    // If the key is found at the head of the list
    if (temp != NULL && temp->value == key) {
        *head = temp->next;  // Update the head pointer
        free(temp);          // Free the memory of the deleted node
        return;
    }

    // Traverse the list to find the node with the given key
    while (temp != NULL && temp->value != key) {
        prev = temp;        // Update the previous pointer
        temp = temp->next;  // Move to the next node
    }

    // If the key is not found in the list
    if (temp == NULL)
        return;

    // Update the links to remove the node from the list
    prev->next = temp->next;
    free(temp);   // Free the memory of the deleted node
}

// Function to delete the node at a given position in the list
void deleteNodeAt(node **head, int position){
    if (*head == NULL)
        return;

    node *temp = *head;   // Temporary pointer to traverse the list

    // If the node to be deleted is the head node
    if (position == 0) {
        *head = temp->next;  // Update the head pointer
        free(temp);          // Free the memory of the deleted node
        return;
    }
    
    // Traverse the list to find the node at the given position
    int i;
    for (i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If the position is out of range or the node is not found
    if (temp == NULL || temp->next == NULL)
        return;

    // Update the links to remove the node from the list
    node *next = temp->next->next;
    free(temp->next);     // Free the memory of the deleted node
    temp->next = next;
}
