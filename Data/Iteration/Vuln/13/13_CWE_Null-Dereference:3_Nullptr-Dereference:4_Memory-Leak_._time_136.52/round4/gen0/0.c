#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node** head, int n) {
    node* temp = NULL;
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));
        (*head)->a = n;
        (*head)->next = NULL;
    }
    else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (node*)malloc(sizeof(node));
        temp->next->a = n;
        temp->next->next = NULL;
    }
}

// Test the code
int main() {
    node* head = NULL;
    addSpecific(&head, 5);
    addSpecific(&head, 10);
    addSpecific(&head, 15);
    node* temp = head;
    printf("Elements in the list: ");
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
    
    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        node* next = temp->next;
        free(temp);
        temp = next;
    }
    
    return 0;
}