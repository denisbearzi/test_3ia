#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
}node;



node* newNode(int key){
	node* tempNode;
	tempNode = (node*)malloc(sizeof(node));
	
	tempNode -> left = NULL;
	tempNode -> key = key;
	tempNode -> right = NULL;
}



node* insertNode(node* root, int key){
	
	if(root == NULL){
		return newNode(key);
	}
	
	if(key <= root -> key){
		
		root -> left = insertNode(root -> left, key);
		
	} else {
		
		root -> right = insertNode(root -> right, key);
	}
	return root;
}



void insert(bst* tree, int key){
	insertNode(tree -> root, key);
}



void printOrder(Node* root){

    Node* current = root;
    Node* preNode;

    while (current != NULL){

        if (current->left == NULL){

            printf("%d ", current->key);
            current = current->right;

        } else {
            
            preNode = current->left;

            while (preNode->right != NULL && preNode->right != current){

                preNode = preNode->right;
            }

            if (preNode->right == NULL){

                preNode->right = current;
                current = current->left; 

            } else {
                
                preNode->right = NULL;
                printf("%d ", current->key);
                current = current->right;
            }
        }
    }
}



int somma(Node* root){

    int somma;
    Node* current = root;

    while (current != NULL){

        if (current->left == NULL){

            somma += current->value; 
            current = current->right; 

        } else {
            
            Node* predecessor = current->left;

            while (predecessor->right != NULL && predecessor->right != current){

                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL){

                predecessor->right = current; 
                current = current->left; 

            } else {

                predecessor->right = NULL;
                somma += current->value;
                current = current->right;
            }
        }
    }

    return somma;
}



int main() {

    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);

    printOrder(root);
    printf("\n");

    int sommaTotale = somma(root);
    printf("Somma totale degli elementi nell'albero: %d\n", sommaTotale);

    return 0;
}