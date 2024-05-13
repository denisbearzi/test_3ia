#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
	
	bst tempNode;
	node* root;
		
	inseretNode(root, 10);
	
	/*
	currentNode.root = newNode(50);
	currentNode.root -> left = newNode(25);
	currentNode.root -> right = newNode(75);
	currentNode.root -> left -> left = newNode(10);
	currentNode.root -> right -> right = newNode(100);
	currentNode.root -> left -> left -> left = newNode(0);
	currentNode.root -> right -> right -> right = newNode(120);
	*/
	
	
	printBst(root);
	
	return 0;
}
