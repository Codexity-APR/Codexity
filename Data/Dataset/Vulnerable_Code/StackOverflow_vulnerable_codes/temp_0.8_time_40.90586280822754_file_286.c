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
        temp->next = (node*)malloc(sizeof(node));
        temp->next->a = n;
        temp->next->next = NULL;
    }
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;

    addSpecific(head, 10);
    addSpecific(head, 20);
    addSpecific(head, 30);

    node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }

    return 0;
}