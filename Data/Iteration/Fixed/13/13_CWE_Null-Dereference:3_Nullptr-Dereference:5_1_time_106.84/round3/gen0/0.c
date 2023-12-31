#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    if (head == NULL) {
        printf("Invalid head pointer.\n");
        return;
    }

    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->a = n;
    temp->next = NULL;

    if (head->next == NULL) {
        head->next = temp;
    } else {
        temp->next = head->next;
        head->next = temp;
    }
}

void printList(node* head) {
    if (head == NULL) {
        printf("Invalid head pointer.\n");
        return;
    }

    node* current = head->next;
    while (current != NULL) {
        printf("%d ", current->a);
        current = current->next;
    }
    printf("\n");
}

void freeList(node* head) {
    if (head == NULL) {
        return;
    }

    node* current = head->next;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    head->next = NULL;

    addSpecific(head, 2);
    addSpecific(head, 4);
    addSpecific(head, 6);
    addSpecific(head, 8);

    printList(head);

    freeList(head);

    return 0;
}