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
        temp = (node*)malloc(sizeof(node));
        temp->a = n;
        temp->next = head->next;
        head->next = temp;
    }
}

void printList(node* head) {
    node* curr = head->next;
    while (curr != NULL) {
        printf("%d ", curr->a);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    
    addSpecific(head, 10);
    addSpecific(head, 20);
    addSpecific(head, 30);
    
    printList(head);
    
    return 0;
}