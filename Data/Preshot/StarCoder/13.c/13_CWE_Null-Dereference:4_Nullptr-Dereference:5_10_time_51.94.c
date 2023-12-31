#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    if (head == NULL) {
        printf("Error: head is null");
        return;
    }
    node* temp = head;

    if (head->next == NULL) {
        temp->next = (node*)malloc(sizeof(node));
        temp->next->a = n;
        temp->next->next = NULL;
    } else {
        while (temp->next != NULL && temp->next->a < n) {
            temp = temp->next;
        }
        node* newNode = (node*)malloc(sizeof(node));
        newNode->a = n;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void add(node* head, int n) {
    if (head == NULL) {
        printf("Error: head is null");
        return;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->a = n;
    temp->next = head->next;
    head->next = temp;
}

void print(node* head) {
    if (head == NULL) {
        printf("Error: head is null");
        return;
    }
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
    add(head, 1);
    add(head, 2);
    add(head, 3);
    addSpecific(head, 4);
    print(head);
    return 0;
}