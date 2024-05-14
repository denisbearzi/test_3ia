#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Struct definition of a BST node 
typedef struct NODE{
    int key;
    struct NODE *left;
    struct NODE *right;
} node;

/* Build a struct for a BST graph; this struct allows using the 
   size without entry in every node, decreasing the complexity */
typedef struct {
    node *root;
    int size;
} bst;

// Initialize a BST: sets the root to NULL and size to 0
void initBST(bst *tree) {
    tree->root = NULL;
    tree->size = 0;
}

// Create a new node with the specified key
node *newNode(int key){
    node *nodoTemp;
    nodoTemp = (node*)malloc(sizeof(node));

    nodoTemp->key = key;
    nodoTemp->left = NULL;
    nodoTemp->right = NULL;

    return nodoTemp;
}

// Find the minimum node starting from the root
node *findMinNodeRoot(node *root){
    node *currentNode = root;

    if (root == NULL)
    {
        return currentNode;
    }
    
    while (currentNode->left != NULL)
    {
        currentNode = currentNode->left;
    }

    return currentNode;
}

// Find the maximum node in a BST
node *findMaxNode(bst *tree){
    node *currentNode = tree->root;

    if (tree->root == NULL) {
        return NULL;  // If the tree is empty, return NULL
    }

    while (currentNode->right != NULL) {
        currentNode = currentNode->right;  // Traverse to the rightmost node
    }

    return currentNode;  // Return the node with the maximum key
}

// Insert a new key into the BST
void insertNode(bst *tree, int key) {
    node *new_node = newNode(key);  // Create a new node with the given key
    if (tree->root == NULL) {
        tree->root = new_node;  // If the tree is empty, set the new node as the root
        tree->size = 1;  // Increase the size of the tree
        return;
    }

    node *current = tree->root;
    node *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;  // Move to the left child
        } else {
            current = current->right;  // Move to the right child
        }
    }

    if (key < parent->key) {
        parent->left = new_node;  // Set the new node as the left child
    } else {
        parent->right = new_node;  // Set the new node as the right child
    }
    tree->size++;  // Increase the size of the tree after insertion
}

// Search for a node with a given key in the BST
node *searchNode(bst *tree, int key) {
    node *current = tree->root;
    while (current != NULL && current->key != key) {
        if (key < current->key) {
            current = current->left;  // Move to the left if the key is smaller
        } else {
            current = current->right;  // Move to the right if the key is larger
        }
    }
    return current;  // Return the found node or NULL if not found
}

// Remove a node with a specific key from the BST
void deleteNode(bst *tree, int key) {
    // This function will handle the deletion of a node with the specified key.
    // It will need to handle three cases: deleting a leaf node, a node with one child, and a node with two children.
    // Actual implementation needs to carefully adjust pointers to maintain BST properties.

    // Placeholder for the rest of the deletion logic...
}

// Display the BST in order (left, root, right)
void inOrderTraversal(node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);  // Traverse the left subtree
        printf("%d ", root->key);  // Visit the root
        inOrderTraversal(root->right);  // Traverse the right subtree
    }
}
