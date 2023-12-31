#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed!");
        return;
    }
    temp->a = n;
    temp->next = NULL;

    if (head->next == NULL) {
        head->next = temp;
        return;
    }

    node* curr = head->next;
    while (curr->next != NULL && curr->next->a < n) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void add(node* head, int n) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed!");
        return;
    }
    temp->a = n;
    temp->next = head->next;
    head->next = temp;
}

void print(node* head) {
    node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    head->next = NULL;
    add(head, 1);
    add(head, 2);
    add(head, 3);
    addSpecific(head, 4);
    print(head);
    return 0;
}