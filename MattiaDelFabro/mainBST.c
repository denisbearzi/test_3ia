#include "BST.h" // Include the header file for the binary search tree (BST) functions and definitions

int main() {
    bst newTree; // Declare a variable of type 'bst' to represent the new binary search tree
    initBST(&newTree); // Initialize the binary search tree 'newTree'
    insert(&newTree, 10); // Insert the value 10 into the binary search tree

    for (int i = 11; i < 20; i++) { // Loop from 11 to 19
        insert(&newTree, i); // Insert each value into the binary search tree
    }
    
    printBSTPreorder(&newTree); // Print the binary search tree in pre-order traversal
    deleteValueBST(&newTree, 19); // Delete the value 19 from the binary search tree
    printf("\n"); // Print a newline character for better readability
    printBSTPreorder(&newTree); // Print the binary search tree in pre-order traversal again
    printf("\n"); // Print a newline character for better readability
    
    int value = 0; // Declare an integer variable 'value' and initialize it to 0
    printf("%d", SommaBSTtow(newTree.root)); // Calculate and print the sum of all values in the binary search tree using the 'SommaBSTtow' function

    return 0; // Return 0 to indicate successful execution of the program
}
