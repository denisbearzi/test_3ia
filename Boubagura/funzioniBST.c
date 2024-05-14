#include<stdlib.h>  // Including the standard library header file for memory allocation and other utility functions
#include<stdio.h>   // Including the standard I/O header file for input and output operations

// Defining a structure for a binary tree node
typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
} node;

// Defining a structure for a binary search tree
typedef struct {
    node* root;
} bst;

// Function to create a new node
node* newNode(int value) {
    node* tempNode;
    tempNode = (node *)malloc(sizeof(node));  // Allocating memory for a new node
    tempNode->key = value;  // Setting the value of the new node
    tempNode->left = NULL;   // Initializing left child pointer to NULL
    tempNode->right = NULL;  // Initializing right child pointer to NULL
    return tempNode;  // Returning the newly created node
}

// Function to find the node with the minimum value in the tree
node* minNode(bst* tree) {
    node* currentNode;
    currentNode = tree->root;  // Starting from the root node
    while (currentNode->left != NULL) {  // Traverse to the leftmost node
        currentNode = currentNode->left;
    }
    return currentNode;  // Returning the node with minimum value
}

// Function to get the minimum value in the tree
int minValue(bst* tree) {
    node* nodeMin = minNode(tree);  // Finding the node with minimum value
    return nodeMin->key;  // Returning the minimum value
}

// Function to find the node with the maximum value in the tree
node* maxNode(bst* tree) {
    node* currentNode;
    currentNode = tree->root;  // Starting from the root node
    while (currentNode->right != NULL) {  // Traverse to the rightmost node
        currentNode = currentNode->right;
    }
    return currentNode;  // Returning the node with maximum value
}

// Function to get the maximum value in the tree
int maxValue(bst* tree) {
    node* nodeMax = maxNode(tree);  // Finding the node with maximum value
    return nodeMax->key;  // Returning the maximum value
}

// Function to recursively print nodes in pre-order traversal
void printNode(node* root) {
    if (root != NULL) {  // If the node exists
        printf("%d ", root->key);  // Print the key of the node
        printNode(root->left);     // Recursively print left subtree
        printNode(root->right);    // Recursively print right subtree
    }
}

// Function to print the entire binary search tree
void printBST(bst* tree) {
    printNode(tree->root);  // Starting pre-order traversal from the root node
}

// Function to recursively insert a node with given value into the tree
node* insertNode(node* root, int value) {
    if (root == NULL) {  // If the tree is empty
        return newNode(value);  // Create a new node with the given value
    }
    if (value < root->key) {  // If the value is less than the key of the current node
        root->left = insertNode(root->left, value);  // Insert into the left subtree
    } else {  // If the value is greater than or equal to the key of the current node
        root->right = insertNode(root->right, value);  // Insert into the right subtree
    }
    return root;  // Returning the modified root node
}

// Function to insert a value into the binary search tree
void insert(bst* tree, int value) {
    tree->root = insertNode(tree->root, value);  // Calling the recursive insert function
}

// Function to find the minimum node in the right subtree
node* minNodeSuccessor(node* root) {
    node* currentNode;
    currentNode = root;  // Starting from the current node
    while (currentNode->left != NULL) {  // Traverse to the leftmost node
        currentNode = currentNode->left;
    }
    return currentNode;  // Returning the minimum node
}

// Function to find the successor of a given node
node* successor(node* root) {
    return minNodeSuccessor(root->right);  // Finding the minimum node in the right subtree
}

// Function to delete a node with given value from the tree
node* deleteNodeEasy(node* root, int value) {
    node* succ;
    if (root == NULL) {  // Base case: empty tree
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {  // Case 1: leaf node
        free(root);  // Freeing memory for the leaf node
    }
    if (value < root->key) {  // If the value is less than the key of the current node
        deleteNodeEasy(root->left, value);  // Recursively delete in the left subtree
    } else if (value > root->key) {  // If the value is greater than the key of the current node
        deleteNodeEasy(root->right, value);  // Recursively delete in the right subtree
    } else {
        // Node to be deleted found
        // Case 2 and 3
        succ = successor(root);  // Finding the successor node
        root->key = succ->key;  // Replacing the key of the node to be deleted with the successor key
        deleteNodeEasy(root->left, succ->key);  // Recursively delete the successor node
    }
}

// Function to delete a node with given key from the tree
void deleteBST(bst* tree, int key) {
    deleteNodeEasy(tree->root, key);  // Calling the delete function
}

// Main function
int main() {
    return 0;  // Exiting the program
}
