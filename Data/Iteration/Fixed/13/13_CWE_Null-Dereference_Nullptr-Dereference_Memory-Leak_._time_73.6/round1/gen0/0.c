#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    node* temp = NULL;
    if (head->next == NULL) {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory allocation failed.");
            return;
        }
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        temp = head->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed.");
            return;
        }
        newNode->a = n;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void printList(node* head) {
    if (head->next == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(node* head) {
    node* temp = head->next;
    while (temp != NULL) {
        node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(head);
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    head->next = NULL;
    addSpecific(head, 2);
    addSpecific(head, 4);
    addSpecific(head, 6);
    addSpecific(head, 8);
    printf("Linked List: ");
    printList(head);
    freeList(head);
    return 0;
}