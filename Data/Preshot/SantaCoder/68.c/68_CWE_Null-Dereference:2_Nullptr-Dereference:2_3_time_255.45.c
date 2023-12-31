#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void printRev(node* head)
{
    if(head == NULL)
        return;
    printRev(head->next);
    printf("%d ", head->data);
}

node* removeNode(node* head, int d)
{
    node* current = head;
    if(head == NULL)
        return NULL;
    if(head->data == d)
    {
        head = head->next;
        free(current);
        return head;
    }
    while(current->next != NULL)
    {
        if(current->next->data == d)
        {
            node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return head;
        }
        current = current->next;
    }
    return head;
}

node* insertFront(node* head, int d)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL)
        head->prev = temp;
    return temp;
}

node* insertBack(node* head, int d)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    node* current = head;
    while(current->next != NULL)
        current = current->next;
    current->next = temp;
    temp->prev = current;
    return head;
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

int max(node* head)
{
    int max = head->data;
    node* current = head->next;
    while(current != NULL)
    {
        if(current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

int min(node* head)
{
    int min = head->data;
    node* current = head->next;
    while(current != NULL)
    {
        if(current->data < min)
            min = current->data;
        current = current->next;
    }
    return min;
}

int locInList(node* head, int x)
{
    int i = 1;
    node* current = head;
    while(current != NULL)
    {
        if(current->data == x)
            return i;
        current = current->next;
        i++;
    }
    return -1;
}

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
    while(current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}