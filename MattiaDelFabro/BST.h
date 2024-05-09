#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//struct def of a BST node 
typedef struct NODE{
    int key;
    struct NODE *left;
    struct NODE *right;
}node;

/*build a struct for a BST graph, this struct allow using the 
size whiout entery in every node, decresting the complexity*/
typedef struct{
    node * root;
    int size;
}bst;

void initBST(bst *tree) {
    tree->root = NULL;
    tree->size = 0;
}


node * newNode(int key){
    node * nodoTemp;
    nodoTemp =(node*)malloc(sizeof(node));

    nodoTemp->key = key;
    nodoTemp->left = NULL;
    nodoTemp->right = NULL;

    return nodoTemp;
}

//find min node in BST
node *findMinNodeRoot(node *root){
    node *currentNode = root;

    if (root == NULL)
    {
        return currentNode;
    }
    
    while (currentNode->left != NULL)
    {

        currentNode= currentNode->left;

    }

    return currentNode;
    
}

//find max node in BST
node *findMaxNode(bst *tree){
    node *currentNode = tree->root;

    if (tree == NULL)
    {
        return currentNode;
    }
    
    while (currentNode->right != NULL)
    {

        currentNode= currentNode->right;

    }

    return currentNode;
    
}

//find max value in bst
int findMaxValue(bst *tree){
    node * MaxValue = findMaxNode(tree);

    return MaxValue->key;

}

//find min value in bst
int findMinValue(bst *tree){
    node * MinValue = findMaxNode(tree);

    return MinValue->key;

}
//order
void printNodeOrder(node *root){
    if (root != NULL)
    {
        printNodeOrder(root->left);
        printf("%d ", root->key);
        printNodeOrder(root->right);
        
    }

}

void printBSTOrder(bst * tree){
    printNodeOrder(tree->root);

}

//preorder
void printNodePreorder(node *root){
    if (root != NULL)
    {
        printf("%d ", root->key);
        printNodePreorder(root->left);
        printNodePreorder(root->right);
    }

}

void printBSTPreorder(bst * tree){
    printNodePreorder(tree->root);

}

//postorder
void printNodePostorder(node *root){
    if (root != NULL)
    {
        printNodePostorder(root->left);
        printNodePostorder(root->right);
        printf("%d ", root->key);
    }

}

void printBSTPostorder(bst * tree){
    printNodePostorder(tree->root);

}

node * insertNode(node * root, int key){
    if(root == NULL){

        return newNode(key); 
    }

    if(key < root->key){
        root->left = insertNode(root->left, key);
    }else{
        root->right = insertNode(root->right, key);
    }

    return root; //ricostruzione del nodo
}

void insert(bst *tree, int valueToInsert){
    tree->root = insertNode(tree->root, valueToInsert);

}

// Funzione per cercare un valore nel BST
node* search(node* root, int value) {
    if (root == NULL || root->key == value){ //caso base
        return root;
    }
    if (value < root->key){ //ricerca nell albero sinistro
        return search(root->left, value);
    }else{ //ricerca nell albero destro
        return search(root->right, value);
    }
}


node * successor(node *root){
    return findMinNodeRoot(root->right);
}

//funzione di delete(se elimini la root, cerchi il successore n più vicino alla radice locato nella foglia più a sinistra del sottoalbero destro)
node* deleteNode(node * root, int key){

    if(root == NULL){
        return NULL;
    }

    if(key < root->key){   //il nodo contine il valore ci spostiamo a sinistra o a destra 
        root->left = deleteNode(root->left, key); //caso minore
        return root;
    }else if(key > root->right->key){
        root->right = deleteNode(root->right, key); //caso maggiore
        return root;
    }
    //questa parte di codice viene eseguito solo se viene effettivamente trovato il nodo da eliminare
    if(root->left == NULL){
        node * right = root->right;
        free(root);
        return right;
    }  

    if(root->right == NULL){
        node * left = root->left;
        free(root);
        return left;
    }
    node * succ = successor(root);
    root->key = succ->key;
    free(succ);
    return root;

}

node* deleteNodeAlternative(node * root, int key){
    node * succ;
    
    if (root == NULL) //caso base 
    {
        return NULL;
    }

    if(root->left == NULL && root->right==NULL){//caso 1: leaf
        free(root);
        return root;
    }

    if(key < root->key){ //cerca il nodo da eliminare
        deleteNodeAlternative(root->left,key); //search in left tree 
    }else if(key > root->key){
        deleteNodeAlternative(root->right,key); //search into right tree
    }else{
        //caso 2 e 3 se il nodo da eliminare è stato trovato
        succ = successor(root);
        root->key = succ->key;
        deleteNodeAlternative(root->left, succ->key);
    }
    

    return root;
     
}

void deleteValueBST(bst *tree, int key){
    deleteNode(tree->root, key);
}

int sommaBST(node * root, int value){
    if(root != NULL){
    value = value + sommaBST(root->left, value);
    value = value + sommaBST(root->right, value);

    return root->key + value;
    }

    return 0;
}

int SommaBSTtow(node * root){
    if (root != NULL){
        return root->key + SommaBSTtow(root->left) + SommaBSTtow(root->right);
    }

    return 0;
}


int SommaBSTtowIterative( node* root) {
    int sum = 0;
    node* current = root;
    node* prev = NULL;

    while (current != NULL) {
        if (current->left == NULL) {
            sum += current->key;
            current = current->right;
        } else {
            prev = current->left;
            while (prev->right != NULL && prev->right != current) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = NULL;
                sum += current->key;
                current = current->right;
            }
        }
    }

    return sum;
}

void printNodeOrderIterative(node* root) {
    if (root == NULL)
        return;

    node* currentNode = root;
    node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->left == NULL) {
            //in asssenza di valori sinistri si stampa l'albero destro
            printf("%d ", currentNode->key);
            currentNode = currentNode->right;
        } else {
            //ricerca del predecessore
            prevNode = currentNode->left;
            while (prevNode->right != NULL && prevNode->right != currentNode)
                prevNode = prevNode->right;

            if (prevNode->right == NULL) {
                prevNode->right = currentNode;
                currentNode = currentNode->left;
            } else {
                prevNode->right = NULL;
                printf("%d ", currentNode->key);
                currentNode = currentNode->right;
            }
        }
    }
}
