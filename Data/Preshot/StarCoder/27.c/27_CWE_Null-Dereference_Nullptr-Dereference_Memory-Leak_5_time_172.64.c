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

    int loc5 = locInList(head, 5);
    if (loc5 != -1)
    {
        printf("locInList 5: %d\n", loc5);
    }
    else
    {
        printf("Element not found in the list\n");
    }

    int loc9 = locInList(head, 9);
    if (loc9 != -1)
    {
        printf("locInList 9: %d\n", loc9);
    }
    else
    {
        printf("Element not found in the list\n");
    }

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
    node* p = (node*)malloc(sizeof(node));
    if (p != NULL)
    {
        p->data = d;
        p->next = head;
        p->prev = NULL;
        if (head != NULL)
        {
            head->prev = p;
        }
        head = p;
    }
    return head;
}

node* insertBack(node* head, int d)
{
    node* p = (node*)malloc(sizeof(node));
    if (p != NULL)
    {
        p->data = d;
        p->next = NULL;

        if (head == NULL)
        {
            p->prev = NULL;
            head = p;
        }
        else
        {
            node* q = head;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
    }
    return head;
}

node* removeNode(node* head, int d)
{
    node* p = head;
    while (p != NULL)
    {
        if (p->data == d)
        {
            if (p == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
            }
            else
            {
                p->prev->next = p->next;
                if (p->next != NULL)
                {
                    p->next->prev = p->prev;
                }
            }
            free(p);
            break;
        }
        p = p->next;
    }
    return head;
}

void print(node* head)
{
    node* p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void printRev(node* head)
{
    node* p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

int max(node* head)
{
    int max = head->data;
    node* p = head->next;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int min(node* head)
{
    int min = head->data;
    node* p = head->next;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

int locInList(node* head, int x)
{
    node* p = head;
    int i = 0;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}