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
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void printRev(node* head)
{
    node* current = head;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    printf("List in reverse: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    
    printf("\n");
}

node* removeNode(node* head, int d)
{
    node* current = head;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    
    if (current->data == d)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(current);
        printf("Node with data %d removed successfully.\n", d);
        return head;
    }
    
    while (current != NULL)
    {
        if (current->data == d)
        {
            current->prev->next = current->next;
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Node with data %d removed successfully.\n", d);
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
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL)
    {
        head->prev = newNode;
    }
    
    printf("Node with data %d inserted at the front.\n", d);
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
        printf("Node with data %d inserted as the first element.\n", d);
        return newNode;
    }
    
    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    printf("Node with data %d inserted at the back.\n", d);
    return head;
}

void print(node* head)
{
    node* current = head;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

int max(node* head)
{
    node* current = head;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    
    int maxVal = current->data;
    while (current != NULL)
    {
        if (current->data > maxVal)
        {
            maxVal = current->data;
        }
        current = current->next;
    }
    
    return maxVal;
}

int min(node* head)
{
    node* current = head;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    
    int minVal = current->data;
    while (current != NULL)
    {
        if (current->data < minVal)
        {
            minVal = current->data;
        }
        current = current->next;
    }
    
    return minVal;
}

int locInList(node* head, int x)
{
    node* current = head;
    int position = 0;
    
    while (current != NULL)
    {
        if (current->data == x)
        {
            return position;
        }
        position++;
        current = current->next;
    }
    
    return -1;
}