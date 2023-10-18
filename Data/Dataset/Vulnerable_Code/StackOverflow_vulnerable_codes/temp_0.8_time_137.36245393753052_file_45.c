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
    node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

void printRev(node* head)
{
    printf("Printing list in reverse: ");

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = head;

    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Traverse backward and print data
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}

node* removeNode(node* head, int d)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    node* current = head;

    // Traverse to find the node with data 'd'
    while (current != NULL) {
        if (current->data == d) {
            // Check if the node is the head
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            return head;
        }
        current = current->next;
    }

    printf("Node with data %d not found in the list.\n", d);
    return head;
}

node* insertFront(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
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

    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

void print(node* head)
{
    printf("Printing list: ");

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

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
        printf("List is empty.\n");
        return -1;
    }

    int maxValue = head->data;
    node* current = head->next;

    while (current != NULL) {
        if (current->data > maxValue) {
            maxValue = current->data;
        }
        current = current->next;
    }

    return maxValue;
}

int min(node* head)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    int minValue = head->data;
    node* current = head->next;

    while (current != NULL) {
        if (current->data < minValue) {
            minValue = current->data;
        }
        current = current->next;
    }

    return minValue;
}

int locInList(node* head, int x)
{
    int index = 0;
    node* current = head;

    while (current != NULL) {
        if (current->data == x) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}