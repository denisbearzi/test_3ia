#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}node;



typedef struct{
	node* root;
}bst;




//versione iterativa
node* minNode(node* root){
	
	node* currentNode = root;
	
	while(currentNode -> left != NULL){
		
		currentNode = currentNode -> left;
	}
	return currentNode;
}



node* min(bst* tree){
	minNode(tree -> root);
}


node* successor(node* root){
	return minNode(root -> right);
}



node* delateNode(node* root, int key){
	
	
	node* succ;
	
	
	//caso base
	if(root == NULL){
		
		return NULL;
	}
	
	
	//caso 1: foglia
	if(root -> left == NULL && root -> right == NULL){
		
		free(root);
	}
	
	
	//cerca il nodo da eliminare
	if(key < root -> key){
		
		
		//cerca nel sottoalbero sx
		delateNode(root -> left, key);
	} else if(key > root -> key){
		
		
		//cerca nel sottoalbero dx
		delateNode(root -> right, key);
	} else{
	
	
	//caso 2 e 3: 
	succ = successor(root);
	root -> key = succ -> key;
	delateNode(root -> left, succ -> key);
	}
}




void delate(bst tree, int key){
	delateNode(tree.root, key);
}



node* newNode(int key){
	node* tempNode;
	tempNode = (node*)malloc(sizeof(node));
	
	tempNode -> left = NULL;
	tempNode -> key = key;
	tempNode -> right = NULL;

	return tempNode;
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



void printBst(node* root){
	if(root != NULL){
		printBst(root -> left);
		printf("&d ", root -> key);
		printBst(root -> right);
	}
}



node* nodeSearch(node* root, int key){
	node* currentNode = root;

	if(currentNode -> key == key){

		return currentNode;
	}
	
	if(currentNode -> key > key){

		currentNode = currentNode -> left;
		return nodeSearch(currentNode, key);

	} else {

		currentNode = currentNode -> right;
		return nodeSearch(currentNode, key);
	}
}



node* treeSearch(bst* tree, int key){
	nodeSearch(tree -> root, key);
}
