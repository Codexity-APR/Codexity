List of vulnerabilities detected: 
Error: Null Dereference   pointer `newNode` last assigned on line 132 could be null and is dereferenced at line 133, column 5.
 Example: 
  131. {
  132.     node* newNode = (node*)malloc(sizeof(node));
  133.     newNode->data = d;
           ^
  134.     newNode->next = NULL;
  135.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 132.
 Example: 
  131. {
  132.     node* newNode = (node*)malloc(sizeof(node));
  133.     newNode->data = d;
           ^
  134.     newNode->next = NULL;
  135.

Error: Null Dereference   pointer `newNode` last assigned on line 119 could be null and is dereferenced at line 120, column 5.
 Example: 
  118. {
  119.     node* newNode = (node*)malloc(sizeof(node));
  120.     newNode->data = d;
           ^
  121.     newNode->prev = NULL;
  122.     newNode->next = head;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 119.
 Example: 
  118. {
  119.     node* newNode = (node*)malloc(sizeof(node));
  120.     newNode->data = d;
           ^
  121.     newNode->prev = NULL;
  122.     newNode->next = head;


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
    printf("Reversed List: ");
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
        node* temp = current;
        head = current->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }
    while (current->next != NULL)
    {
        if (current->next->data == d)
        {
            node* temp = current->next;
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            free(temp);
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
        head->prev = newNode;
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
    int maxValue = head->data;
    node* current = head->next;
    while (current != NULL)
    {
        if (current->data > maxValue)
            maxValue = current->data;
        current = current->next;
    }
    return maxValue;
}
int min(node* head)
{
    int minValue = head->data;
    node* current = head->next;
    while (current != NULL)
    {
        if (current->data < minValue)
            minValue = current->data;
        current = current->next;
    }
    return minValue;
}
int locInList(node* head, int x)
{
    int index = 0;
    node* current = head;
    while (current != NULL)
    {
        if (current->data == x)
            return index;
        index++;
        current = current->next;
    }
    return -1;
}