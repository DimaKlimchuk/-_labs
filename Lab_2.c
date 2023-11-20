#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
struct Node {
    char** data; // Array of strings
    struct Node* next; // Pointer to the next node
};

// Function to create a new node with given data
struct Node* createNode(char** dataArray) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Calculate the number of strings in the array
    int numStrings = 0;
    while (dataArray[numStrings] != NULL) {
        numStrings++;
    }

    newNode->data = (char**)malloc((numStrings + 1) * sizeof(char*)); // +1 for the NULL terminator
    if (newNode->data == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numStrings; i++) {
        newNode->data[i] = _strdup(dataArray[i]);
        if (newNode->data[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Set the last element of the array to NULL to indicate the end
    newNode->data[numStrings] = NULL;

    newNode->next = NULL;

    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        // Print each string in the array
        for (int i = 0; current->data[i] != NULL; i++) {
            printf("%s ", current->data[i]);
        }
        printf("\n");

        current = current->next;
    }
}

// Function to free the memory used by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        // Free each string in the array
        for (int i = 0; current->data[i] != NULL; i++) {
            free(current->data[i]);
        }
        // Free the array itself
        free(current->data);

        next = current->next;
        free(current);

        current = next;
    }
}

int main() {
    // Example usage
    char* book1[] = { "Harry Potter and the Sorcerer's Stone | ", "4.33$ | ", "248 | ", "English | ", "350gm | ", "1997", NULL};
    char* book2[] = { "Harry Potter and the Chamber of Secrets | ", "4.05$ | ", "252 | ", "English | ", "360gm | ", "1998", NULL };
    char* book3[] = { "Harry Potter and the Prisoner of Azkaban | ", "4.50$ | ", "383 | ", "English | ", "420gm | ", "1999", NULL };
    char* book4[] = { "Harry Potter and the Goblet of Fire | ", "5,05$ | ", "672 | ", "English | ", "450gm | ", "2000", NULL };
    char* book5[] = { "Harry Potter and the Order of the Phoenix | ", "6$ | ", "815 | ", "English | ", "500gm | ", "2003", NULL };
    char* book6[] = { "Harry Potter and the Half-Blood Prince | ", "5$ | ", "514 | ", "English | ", "460gm | ", "2005", NULL };
    char* book7[] = { "Harry Potter and the Deathly Hallows | ", "5,20$ | ", "640 | ", "English | ", "550gm | ", "2007", NULL };
    char* book8[] = { "Harry Potter and the Cursed Child | ", "4$ | ", "352 | ", "English | ", "390gm | ", "2016", NULL };

    // Create nodes with arrays of strings
    struct Node* node1 = createNode(book1);
    struct Node* node2 = createNode(book2);
    struct Node* node3 = createNode(book3);
    struct Node* node4 = createNode(book4);
    struct Node* node5 = createNode(book5);
    struct Node* node6 = createNode(book6);
    struct Node* node7 = createNode(book7);
    struct Node* node8 = createNode(book7);

    // Connect the nodes to form a linked list
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    // Print the linked list
    printf("Linked List:\n");
    printList(node1);

    // Free the memory used by the linked list
    freeList(node1);

    return 0;
}
