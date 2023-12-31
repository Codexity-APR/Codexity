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
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        temp = head->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* newNode = (node*)malloc(sizeof(node));
        newNode->a = n;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void printList(node* head) {
    node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;

    addSpecific(head, 5);
    addSpecific(head, 10);
    addSpecific(head, 15);
    addSpecific(head, 20);

    printList(head);

    return 0;
}