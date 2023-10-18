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
        head->next = temp;
        temp->a = n;
        temp->next = NULL;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        temp->a = n;
        temp->next = NULL;
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

    addSpecific(head, 10);
    addSpecific(head, 20);
    addSpecific(head, 30);
    addSpecific(head, 40);

    printf("List: ");
    printList(head);

    return 0;
}