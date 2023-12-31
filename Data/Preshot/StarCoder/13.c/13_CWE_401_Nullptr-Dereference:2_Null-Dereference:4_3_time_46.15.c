#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    struct node* next;
} node;

void addSpecific(node* head, int n) {
    node* temp = NULL;
    if (head == NULL) {
        head = (node*)malloc(sizeof(node));
        head->a = n;
        head->next = NULL;
    } else if (head->next == NULL) {
        temp = (node*)malloc(sizeof(node));
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        temp = head->next;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = (node*)malloc(sizeof(node));
        temp->next->a = n;
        temp->next->next = NULL;
    }
}

void add(node** head, int n) {
    node* temp = NULL;
    temp = (node*)malloc(sizeof(node));
    temp->a = n;
    temp->next = *head;
    *head = temp;
}

void print(node* head) {
    node* temp = NULL;
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    addSpecific(head, 4);
    print(head);
    return 0;
}