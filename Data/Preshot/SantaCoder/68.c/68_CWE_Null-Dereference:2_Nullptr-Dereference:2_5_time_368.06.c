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

void print(node* head)
{
    node* current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printRev(node* head)
{
    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printf("Reverse List: ");
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

    if (head == NULL)
    {
        return head;
    }

    if (head->data == d)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(current);
        return head;
    }

    while (current->next != NULL && current->next->data != d)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        return head;
    }

    node* temp = current->next;
    current->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = current;
    }
    free(temp);
    return head;
}

node* insertFront(node* head, int d)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = d;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL)
    {
        head->prev = new_node;
    }
    return new_node;
}

node* insertBack(node* head, int d)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = d;
    new_node->next = NULL;
    if (head == NULL)
    {
        new_node->prev = NULL;
        return new_node;
    }

    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    new_node->prev = current;
    current->next = new_node;

    return head;
}

int max(node* head)
{
    if (head == NULL)
    {
        return -1;
    }

    int max_val = head->data;
    node* current = head->next;

    while (current != NULL)
    {
        if (current->data > max_val)
        {
            max_val = current->data;
        }
        current = current->next;
    }

    return max_val;
}

int min(node* head)
{
    if (head == NULL)
    {
        return -1;
    }

    int min_val = head->data;
    node* current = head->next;

    while (current != NULL)
    {
        if (current->data < min_val)
        {
            min_val = current->data;
        }
        current = current->next;
    }

    return min_val;
}

int locInList(node* head, int x)
{
    if (head == NULL)
    {
        return -1;
    }

    node* current = head;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == x)
        {
            return index;
        }
        index++;
        current = current->next;
    }

    return -1;
}