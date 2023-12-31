#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    node* temp = NULL;
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            return;
        }
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        temp = head->next;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = (node*)malloc(sizeof(node));
        if (temp->next == NULL) {
            return;
        }
        temp->next->a = n;
        temp->next->next = NULL;
    }
}

void add(node* head, int n) {
    node* temp = NULL;
    if (head == NULL) {
        return;
    }
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        return;
    }
    temp->a = n;
    temp->next = head->next;
    head->next = temp;
}

void print(node* head) {
    node* temp = NULL;
    if (head == NULL) {
        return;
    }
    temp = head->next;
    while (temp!= NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        return -1;
    }
    head->next = NULL;
    add(head, 1);
    add(head, 2);
    add(head, 3);
    addSpecific(head, 4);
    print(head);
    return 0;
}