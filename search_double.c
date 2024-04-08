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
        printf("Memory allocation failed.\n"); 
        exit(1); 
    } 
    newNode->data = data; 
    newNode->next = NULL; 
    newNode->prev = NULL; 
    return newNode; 
} 
 
// Function to insert a node at the beginning of the list 
void insertAtBeginning(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    if (*head == NULL) { 
        *head = newNode; 
    } else { 
        newNode->next = *head; 
        (*head)->prev = newNode; 
        *head = newNode; 
    } 
} 
 
// Function to search for a given value in the list 
struct Node* search(struct Node* head, int key) { 
    struct Node* current = head; 
    while (current != NULL) { 
        if (current->data == key) { 
            return current; 
        } 
        current = current->next; 
    } 
    return NULL; // Return NULL if key is not found 
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
 
// Main function 
int main() { 
    struct Node* head = NULL; 
     
    // Insert some elements at the beginning 
    insertAtBeginning(&head, 10); 
    insertAtBeginning(&head, 20); 
    insertAtBeginning(&head, 30); 
     
    // Print the list 
    printList(head); 
     
    // Search for a value 
    int searchValue = 20; 
    struct Node* result = search(head, searchValue); 
    if (result != NULL) { 
        printf("%d found in the list.\n", searchValue); 
    } else { 
        printf("%d not found in the list.\n", searchValue); 
    } 
 
    // Free memory 
    while (head != NULL) { 
        struct Node* temp = head; 
        head = head->next; 
        free(temp); 
    } 
     
    return 0; 
}