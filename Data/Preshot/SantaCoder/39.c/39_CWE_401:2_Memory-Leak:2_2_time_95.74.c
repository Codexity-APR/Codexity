#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
    int first;
    struct linkedList* rest;
} linkedList;

void addToList(linkedList* ll, int a);
void deleteList(linkedList* ll);
linkedList* makeList(int a, int b, int c);

int main() {
    linkedList* ll = makeList(1, 3, 5);
    addToList(ll, 7);
    addToList(ll, 9);
    // Do something with list
    deleteList(ll);
    return 0;
}

linkedList* makeList(int a, int b, int c) {
    linkedList* head = (linkedList*) malloc(sizeof(linkedList));
    if (head == NULL)
        return NULL;
    head->first = a;
    head->rest = (linkedList*) malloc(sizeof(linkedList));
    if (head->rest == NULL)
        return NULL;
    head->rest->first = b;
    head->rest->rest = (linkedList*) malloc(sizeof(linkedList));
    if (head->rest->rest == NULL)
        return NULL;
    head->rest->rest->first = c;
    head->rest->rest->rest = NULL;
    return head;
}

void addToList(linkedList* ll, int a) {
    if (ll == NULL)
        return;
    linkedList *current = ll;
    while (current->rest != NULL) {
        current = current->rest;
    }
    current->rest = (linkedList*) malloc(sizeof(linkedList));
    if (current->rest == NULL)
        return;
    current->rest->first = a;
    current->rest->rest = NULL;
}

void deleteList(linkedList* ll) {
    linkedList* current = ll;
    while (current != NULL) {
        linkedList* next = current->rest;
        free(current);
        current = next;
    }
}