#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    if (head == NULL) {
        printf("Error: head pointer is NULL\n");
        return;
    }

    if (head->next == NULL) {
        node* temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            printf("Error: Memory allocation failed\n");
            return;
        }
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        node* temp = head->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (node*)malloc(sizeof(node));
        if (temp->next == NULL) {
            printf("Error: Memory allocation failed\n");
            return;
        }
        temp->next->a = n;
        temp->next->next = NULL;
    }
}

void add(node* head, int n) {
    if (head == NULL) {
        printf("Error: head pointer is NULL\n");
        return;
    }

    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    temp->a = n;
    temp->next = head->next;
    head->next = temp;
}

void print(node* head) {
    if (head == NULL) {
        printf("Error: head pointer is NULL\n");
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
    if (head == NULL) {
        printf("Error: Memory allocation failed\n");
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