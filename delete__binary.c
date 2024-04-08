#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct Node { 
    int key; 
    struct Node *left, *right; 
} Node; 
 
// Function to create a new BST node 
Node* newNode(int item) { 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
 
// Function to insert a new node with a given key in BST 
Node* insert(Node* root, int key) { 
    if (root == NULL) return newNode(key); 
 
    if (key < root->key) 
        root->left = insert(root->left, key); 
    else if (key > root->key) 
        root->right = insert(root->right, key); 
 
    return root; 
} 
 
// Function to find the node with minimum key value in a subtree 
Node* minValueNode(Node* node) { 
    Node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 
 
// Function to delete the node with given key from BST 
Node* deleteNode(Node* root, int key) { 
    if (root == NULL) return root; 
 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else { 
        // Node with only one child or no child 
        if (root->left == NULL) { 
            Node* temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
 
        // Node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* temp = minValueNode(root->right); 
 
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
 
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
 
// Function to search a given key in BST 
Node* search(Node* root, int key) { 
    if (root == NULL || root->key == key) 
        return root; 
 
    if (root->key < key) 
        return search(root->right, key); 
 
    return search(root->left, key); 
} 
 
// Function to perform inorder traversal of BST 
void inorder(Node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
 
int main() { 
    Node* root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
 
    printf("Inorder traversal of the BST: "); 
    inorder(root); 
    printf("\n"); 
 
    printf("Deleting 20 from the BST\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified BST: "); 
    inorder(root); 
    printf("\n"); 
 
    return 0; 
}