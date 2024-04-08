#include <stdio.h> 
#include <stdlib.h> 
 
// Define the structure of a node 
typedef struct Node { 
    int data; 
    struct Node *left; 
    struct Node *right; 
} Node; 
 
// Function to create a new node 
Node* createNode(int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
 
// Function to insert a new node into BST 
Node* insert(Node* root, int data) { 
    // If the tree is empty, return a new node 
    if (root == NULL) { 
        return createNode(data); 
    } 
 
    // Otherwise, recur down the tree 
    if (data < root->data) { 
        root->left = insert(root->left, data); 
    } else if (data > root->data) { 
        root->right = insert(root->right, data); 
    } 
 
    // return the unchanged node pointer 
    return root; 
} 
 
// Function to print BST in inorder traversal 
void inorderTraversal(Node* root) { 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("%d ", root->data); 
        inorderTraversal(root->right); 
    } 
} 
 
int main() { 
    Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
 
    printf("Inorder traversal of the BST: "); 
    inorderTraversal(root); 
    printf("\n"); 
 
    return 0; 
}