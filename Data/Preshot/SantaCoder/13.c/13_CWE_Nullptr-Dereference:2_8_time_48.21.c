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
        temp = *head;
    }
    else {
        temp = (*head)->next;
    }
    for (int i = 0; i < n; i++) {
        temp->a = i;
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
    }
    temp->next = NULL;
}

int main() {
    node* head = NULL;
    int n = 10;
    addSpecific(&head, n);
    return 0;
}