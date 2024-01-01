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
        node* current = head->next;
        while (current->next != NULL && current->a != n) {
            current = current->next;
        }
        if (current->a == n) {
            printf("Node with value %d already exists\n", n);
        } else {
            temp = (node*)malloc(sizeof(node));
            temp->a = n;
            temp->next = current->next;
            current->next = temp;
        }
    }
}
