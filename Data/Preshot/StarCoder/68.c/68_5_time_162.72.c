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
    node* temp = head;
    while (temp != NULL)
    {
        node* temp1 = temp;
        temp = temp->next;
        free(temp1);
    }
}

node* insertFront(node* head, int d)
{
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    temp->data = d;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
    return head;
}

node* insertBack(node* head, int d)
{
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    temp->data = d;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    node* temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
    return head;
}

void print(node* head)
{
    node* temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printRev(node* head)
{
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("List: ");
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
    while (temp != NULL && temp->data != d)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return head;
    }
    if (temp->prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

int max(node* head)
{
    node* temp = head;
    int max = temp->data;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int min(node* head)
{
    node* temp = head;
    int min = temp->data;
    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

int locInList(node* head, int x)
{
    node* temp = head;
    int loc = 0;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return loc;
        }
        temp = temp->next;
        loc++;
    }
    return -1;
}