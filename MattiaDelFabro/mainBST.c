#include "BST.h"

int main(){
    bst newTree;
    initBST(&newTree);
    insert(&newTree, 10);

    for (int i = 11; i < 20; i++)
    {
        insert(&newTree, i);
    }
    
    printBSTPreorder(&newTree);
    deleteValueBST(&newTree, 19);
    printf("\n");
    printBSTPreorder(&newTree);
    printf("\n");
    
    int value = 0;
    printf("%d", SommaBSTtow(newTree.root));


    return 0;

}