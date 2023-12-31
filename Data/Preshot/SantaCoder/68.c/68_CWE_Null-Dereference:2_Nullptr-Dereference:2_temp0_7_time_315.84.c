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
        node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    return 0;
}

node* insertFront(node* head, int d)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->prev = NULL;
    newNode->next = head;
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
        head = newNode;
        return head;
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

node* removeNode(node* head, int d)
{
    node* current = head;
    while (current != NULL)
    {
        if (current->data == d)
        {
            if (current->prev == NULL)
            {
                head = current->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
            }
            else if (current->next == NULL)
            {
                current->prev->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return head;
        }
        current = current->next;
    }
    printf("Node with data %d not found\n", d);
    return head;
}

void print(node* head)
{
    printf("List: ");
    node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printRev(node* head)
{
    printf("Reverse List: ");
    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int max(node* head)
{
    int max = head->data;
    node* current = head->next;
    while (current != NULL)
    {
        if (current->data > max)
        {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int min(node* head)
{
    int min = head->data;
    node* current = head->next;
    while (current != NULL)
    {
        if (current->data < min)
        {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

int locInList(node* head, int x)
{
    int loc = 0;
    node* current = head;
    while (current != NULL)
    {
        loc++;
        if (current->data == x)
        {
            return loc;
        }
        current = current->next;
    }
    return -1;
}