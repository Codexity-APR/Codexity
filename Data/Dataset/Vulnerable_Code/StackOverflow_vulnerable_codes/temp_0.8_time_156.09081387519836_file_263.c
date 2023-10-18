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
    while (current != NULL)
    {
        node* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}

void printRev(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    printf("Printing list in reverse: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

node* removeNode(node* head, int d)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    node* current = head;
    while (current != NULL)
    {
        if (current->data == d)
        {
            if (current->prev == NULL && current->next == NULL)
            {
                // Only one node in the list
                free(current);
                head = NULL;
            }
            else if (current->prev == NULL)
            {
                // Removing the first node
                head = current->next;
                head->prev = NULL;
                free(current);
            }
            else if (current->next == NULL)
            {
                // Removing the last node
                current->prev->next = NULL;
                free(current);
            }
            else
            {
                // Removing a node in the middle
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }
            return head;
        }
        current = current->next;
    }

    printf("Node with data %d not found\n", d);
    return head;
}

node* insertFront(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    return newNode;
}

node* insertBack(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

void print(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Printing list: ");
    node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int max(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    int maxValue = head->data;
    node* current = head;
    while (current != NULL)
    {
        if (current->data > maxValue)
        {
            maxValue = current->data;
        }
        current = current->next;
    }

    return maxValue;
}

int min(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    int minValue = head->data;
    node* current = head;
    while (current != NULL)
    {
        if (current->data < minValue)
        {
            minValue = current->data;
        }
        current = current->next;
    }

    return minValue;
}

int locInList(node* head, int x)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    int index = 0;
    node* current = head;
    while (current != NULL)
    {
        if (current->data == x)
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}