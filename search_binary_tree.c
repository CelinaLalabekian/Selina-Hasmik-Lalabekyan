#include <stdio.h> 
#include <stdlib.h> 
 
// Structure for each node of the binary search tree 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
 
// Function to create a new node 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
// Function to insert a new node into the BST 
struct Node* insert(struct Node* root, int data) { 
    if (root == NULL) 
        return createNode(data); 
     
    if (data < root->data) 
        root->left = insert(root->left, data); 
    else if (data > root->data) 
        root->right = insert(root->right, data); 
     
    return root; 
} 
 
// Function to search for a value in the BST 
struct Node* search(struct Node* root, int key) { 
    if (root == NULL || root->data == key) 
        return root; 
     
    if (key < root->data) 
        return search(root->left, key); 
     
    return search(root->right, key); 
} 
 
// Function to print the inorder traversal of the BST (for testing) 
void inorderTraversal(struct Node* root) { 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("%d ", root->data); 
        inorderTraversal(root->right); 
    } 
} 
 
int main() { 
    struct Node* root = NULL; 
 
    // Inserting some elements into the BST 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
 
    // Printing the inorder traversal of the BST (to verify) 
    printf("Inorder traversal of the BST: "); 
    inorderTraversal(root); 
    printf("\n"); 
 
    // Searching for a value in the BST 
    int key = 60; 
    struct Node* result = search(root, key); 
    if (result != NULL) 
        printf("%d is found in the BST.\n", key); 
    else 
        printf("%d is not found in the BST.\n", key); 
 
    return 0; 
}