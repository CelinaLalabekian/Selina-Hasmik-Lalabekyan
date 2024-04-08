#include <stdio.h> 
#include <stdlib.h> 
 
// Structure for a node 
struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev; 
}; 
 
// Function to create a new node 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->next = NULL; 
    newNode->prev = NULL; 
    return newNode; 
} 
 
// Function to insert a node at the end of the list 
void insertAtEnd(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
 
// Function to delete a node by value 
void deleteNode(struct Node** head, int key) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = *head; 
    struct Node* prev = NULL; 
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("Node with value %d not found\n", key); 
        return; 
    } 
    if (temp == *head) { 
        *head = temp->next; 
    } else { 
        prev->next = temp->next; 
    } 
    if (temp->next != NULL) { 
        temp->next->prev = prev; 
    } 
    free(temp); 
    printf("Node with value %d deleted successfully\n", key); 
} 
 
// Function to print the list 
void printList(struct Node* head) { 
    printf("List: "); 
    while (head != NULL) { 
        printf("%d ", head->data); 
        head = head->next; 
    } 
    printf("\n"); 
} 
 
// Function to free memory allocated for the list 
void freeList(struct Node** head) { 
    struct Node* temp; 
    while (*head != NULL) { 
        temp = *head; 
        *head = (*head)->next; 
        free(temp); 
    } 
} 
 
int main() { 
    struct Node* head = NULL; 
 
    // Inserting elements into the list 
    insertAtEnd(&head, 10); 
    insertAtEnd(&head, 20); 
    insertAtEnd(&head, 30); 
    insertAtEnd(&head, 40); 
    insertAtEnd(&head, 50); 
 
    // Printing the list 
    printList(head); 
 
    // Deleting a node 
    deleteNode(&head, 30); 
 
    // Printing the list after deletion 
    printList(head); 
 
    // Freeing memory 
    freeList(&head); 
 
    return 0; 
}