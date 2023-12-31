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
    node* temp = NULL;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

node* insertFront(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL)
        head->prev = newNode;
    return newNode;
}

node* insertBack(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

node* removeNode(node* head, int d)
{
    node* current = head;
    node* temp = NULL;

    if(head == NULL)
        return head;

    if(head->data == d)
    {
        temp = head;
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    while(current->next != NULL && current->next->data != d)
    {
        current = current->next;
    }

    if(current->next == NULL)
        return head;

    temp = current->next;
    current->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = current;
    free(temp);
    return head;
}

int locInList(node* head, int x)
{
    int i = 0;
    node* current = head;
    while(current != NULL)
    {
        i++;
        if(current->data == x)
            return i;
        current = current->next;
    }
    return -1;
}

int max(node* head)
{
    if(head == NULL)
        return -1;

    int maxVal = head->data;
    node* current = head->next;
    while(current != NULL)
    {
        if(current->data > maxVal)
            maxVal = current->data;
        current = current->next;
    }
    return maxVal;
}

int min(node* head)
{
    if(head == NULL)
        return -1;

    int minVal = head->data;
    node* current = head->next;
    while(current != NULL)
    {
        if(current->data < minVal)
            minVal = current->data;
        current = current->next;
    }
    return minVal;
}

void print(node* head)
{
    node* current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printRev(node* head)
{
    node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}