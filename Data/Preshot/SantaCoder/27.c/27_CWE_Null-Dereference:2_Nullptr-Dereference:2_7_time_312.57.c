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
    char path[100];

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
}

node* insertFront(node* head, int d)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    return head;
}

node* insertBack(node* head, int d)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void print(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printRev(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

node* removeNode(node* head, int d)
{
    node* temp = head;

    if (head == NULL)
        return head;

    if (head->data == d)
    {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp->next != NULL && temp->next->data != d)
        temp = temp->next;

    if (temp->next == NULL)
        return head;

    node* nodeToRemove = temp->next;
    temp->next = nodeToRemove->next;
    if (nodeToRemove->next != NULL)
        nodeToRemove->next->prev = temp;

    free(nodeToRemove);
    return head;
}

int max(node* head)
{
    int max = head->data;

    while (head != NULL)
    {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }

    return max;
}

int min(node* head)
{
    int min = head->data;

    while (head != NULL)
    {
        if (head->data < min)
            min = head->data;
        head = head->next;
    }

    return min;
}

int locInList(node* head, int x)
{
    int loc = 0;

    while (head != NULL)
    {
        if (head->data == x)
            return loc;
        loc++;
        head = head->next;
    }

    return -1;
}