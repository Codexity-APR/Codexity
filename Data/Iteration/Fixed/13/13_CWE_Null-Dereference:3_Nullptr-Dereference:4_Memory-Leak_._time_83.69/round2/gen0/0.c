#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    node* temp = NULL;
    if (head == NULL) {
        printf("Invalid head pointer.\n");
        return;
    }
    if (head->next == NULL) {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
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
        temp->next = (node*)malloc(sizeof(node));
        if (temp->next == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        temp->next->a = n;
        temp->next->next = NULL;
    }
}

void displayList(node* head) {
    if (head == NULL) {
        printf("Invalid head pointer.\n");
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
    if (head == NULL) {
        printf("Invalid head pointer.\n");
        return;
    }
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
        printf("Memory allocation failed.\n");
        return 1;
    }
    head->next = NULL;
    addSpecific(head, 1);
    addSpecific(head, 2);
    addSpecific(head, 3);
    displayList(head);
    freeList(head);
    return 0;
}