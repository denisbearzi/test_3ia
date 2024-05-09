#include<stdlib.h>
#include<stdio.h>
typedef struct Node{
	int key;
	struct Node*left;
	struct Node*right;
}node;


typedef struct{
	node*root;
}bst;

node*newNode(int value){
	node*tempNode;
	tempNode=(node *)malloc(sizeof(node));
	tempNode->key=value;
	tempNode->left=NULL;
	tempNode->right=NULL;
	return tempNode;
}

node*minNode(bst*tree){
	node*currentNode;
	currentNode=tree->root;
	while(currentNode->left != NULL){
		currentNode=currentNode->left;
	}
	return currentNode;
}

int valoreMin(bst*tree){
		node*nodeMin = minNode(tree);
		return nodeMin->key;
}

node*maxNode(bst*tree){
	node*currentNode;
	currentNode=tree->root;
	while(currentNode->right != NULL){
		currentNode=currentNode->right;
	}
	return currentNode;
}

int valoreMax(bst*tree){
		node*nodeMax = maxNode(tree);
		return nodeMax->key;
	}
	
void printNode(node*root){
	if(root != NULL){
		printf("%d ", root->key);
		printNode(root->left);
		printNode(root->right);
	}
} 

void printBST(bst*tree){
	printNode(tree->root);
}
	
node*instertNode(node*root, int value){
	if(root == NULL){
		return newNode(value);
	}
	if(value < root->key){
		root->left=instertNode(root->left, value);
	}else{
		root->right=instertNode(root->right, value);
	}
	return root;
}
	
void insert(bst*tree, int value){
	tree-> root = instertNode(tree->root, value);
}

node*minNodeSuccessor(node*root){
	node*currentNode;
	currentNode=root;
	while(currentNode->left != NULL){
		currentNode=currentNode->left;
	}
	return currentNode;
}
node*successor(node*root){
	return minNodeSuccessor(root->right);
}

node*deleteNodeEasy(node*root, int value){
	node*succ;
	if(root == NULL){  //caso base
		return NULL;
	}
	if(root->left == NULL && root->right == NULL){ //caso 1: foglia
		free(root);
	}
	if(value < root->key){ //cerca nodo da eliminare
		deleteNodeEasy(root->left, value); //cerca nel sottoalbero radicato nel figlio sinistro
	}else if(value > root->key){
		deleteNodeEasy(root->right, value);	 //cerca nel sottoalbero radicato nel figlio destro
	}else{
		
	//Nodo da eliminare trovato
	//caso 2 e 3
	succ = successor(root);
	root->key = succ->key;
	deleteNodeEasy(root->left, succ->key);
	}
}
	
void deleteBST(bst*tree, int key){
	deleteNodeEasy(tree->root, key);
}

int main(){
retrun 0;
}

