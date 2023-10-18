#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void printRev(node* head);
node* removeNode(node* head, int d);
node* insertFront(node* head, int d);
node* insertBack(node* head, int d);
void print(node* head);
int max(node* head);
int min(node* head);
int locInList(node* head, int x);

int main()
{
    node* head = NULL;

    head = insertFront(head, 5);
    head = insertFront(head, 4);
    head = insertBack(head, 6);
    head = insertBack(head, 7);
    print(head);
    printRev(head);

    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));
    printf("locInList 5: %d\n", locInList(head, 5));
    printf("locInList 9: %d\n", locInList(head, 9));

    head = removeNode(head, 6);
    print(head);
    head = removeNode(head, 4);
    print(head);
    head = removeNode(head, 7);
    print(head);

    // Free nodes memory
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

void printRev(node* head) 
{
    if (head == NULL) {
        printf("Empty list!\n");
        return;
    }

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("List in reverse order: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

node* removeNode(node* head, int d)
{
    if (head == NULL) {
        printf("Empty list!\n");
        return NULL;
    }

    node* current = head;
    while (current != NULL) {
        if (current->data == d) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current == head) {
                head = current->next;
            }
            free(current);
            return head;
        }
        current = current->next;
    }

    printf("Element not found!\n");
    return head;
}

node* insertFront(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->prev = NULL;

    if (head == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}

node* insertBack(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

void print(node* head)
{
    if (head == NULL) {
        printf("Empty list!\n");
        return;
    }

    printf("List: ");
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int max(node* head)
{
    if (head == NULL) {
        printf("Empty list!\n");
        return -1;
    }

    int maxVal = head->data;
    node* current = head->next;
    while (current != NULL) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }

    return maxVal;
}

int min(node* head)
{
    if (head == NULL) {
        printf("Empty list!\n");
        return -1;
    }

    int minVal = head->data;
    node* current = head->next;
    while (current != NULL) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }

    return minVal;
}

int locInList(node* head, int x)
{
    if (head == NULL) {
        printf("Empty list!\n");
        return -1;
    }

    int position = 0;
    node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}