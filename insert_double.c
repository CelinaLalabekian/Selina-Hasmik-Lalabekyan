#include <stdio.h> 
#include <stdlib.h> 
 
// Define structure for a node in the doubly linked list 
typedef struct Node { 
    int data; 
    struct Node* prev; 
    struct Node* next; 
} Node; 
 
// Function to create a new node 
Node* createNode(int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed.\n"); 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = NULL; 
    return newNode; 
} 
 
// Function to insert a new node at the beginning of the doubly linked list 
Node* insertAtBeginning(Node* head, int data) { 
    Node* newNode = createNode(data); 
    if (head == NULL) { 
        return newNode; 
    } 
    head->prev = newNode; 
    newNode->next = head; 
    return newNode; 
} 
 
// Function to print the doubly linked list 
void printList(Node* head) { 
    printf("Doubly Linked List: "); 
    while (head != NULL) { 
        printf("%d ", head->data); 
        head = head->next; 
    } 
    printf("\n"); 
} 
 
int main() { 
    Node* head = NULL; 
 
    // Inserting elements at the beginning 
    head = insertAtBeginning(head, 3); 
    head = insertAtBeginning(head, 5); 
    head = insertAtBeginning(head, 7