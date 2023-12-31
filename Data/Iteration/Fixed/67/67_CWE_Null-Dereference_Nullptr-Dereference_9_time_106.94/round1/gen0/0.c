#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *first = NULL;

void push(int);
void pop();

int main(void)
{
    int command = 0;
    while (command != 3)
    {
        printf("Enter your choice:\n1) Push integer\n2) Pop Integer\n3) Quit.\n");
        scanf("%d", &command);
        if (command == 1)
        {
            // push
            int num;
            scanf("%d", &num);
            push(num);
        }
        else if (command == 2)
        {
            pop();
        }
        else if (command != 3)
        {
            printf("Command not understood.\n");
        }
    }
    return 0;
}

void push(int x)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void pop()
{
    if (first == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        struct node *temp = first;
        while (temp->next != NULL && temp->next->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            printf("Popped element: %d\n", first->data);
            free(first);
            first = NULL;
        }
        else
        {
            printf("Popped element: %d\n", temp->next->data);
            free(temp->next);
            temp->next = NULL;
        }
    }
}