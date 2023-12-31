#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    if (head == NULL) {
        return;
    }
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        return;
    }
    temp->a = n;
    temp->next = head->next;
    head->next = temp;
}

void printList(node* head) {
    if (head == NULL) {
        return;
    }
    node* current = head->next;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->a);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        return 1;
    }
    head->next = NULL;
    addSpecific(head, 3);
    addSpecific(head, 7);
    addSpecific(head, 10);
    printList(head);

    // Freeing dynamically allocated memory
    node* current = head->next;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
    return 0;
}