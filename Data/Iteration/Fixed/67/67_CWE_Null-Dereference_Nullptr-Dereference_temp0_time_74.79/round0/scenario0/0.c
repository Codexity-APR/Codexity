List of vulnerabilities detected: 
Error: Null Dereference   pointer `newNode` last assigned on line 44 could be null and is dereferenced at line 45, column 5.
 Example: 
  43. {
  44.     struct node *newNode = malloc(sizeof(struct node));
  45.     newNode->data = x;
          ^
  46.     newNode->next = first;
  47.     first = newNode;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 44.
 Example: 
  43. {
  44.     struct node *newNode = malloc(sizeof(struct node));
  45.     newNode->data = x;
          ^
  46.     newNode->next = first;
  47.     first = newNode;


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
        scanf("%d",&command);
        if (command == 1)
        {
            // push
            int num;
            scanf("%d",&num);
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
void push (int x)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = first;
    first = newNode;
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
        printf("Popped value: %d\n", temp->data);
        first = first->next;
        free(temp);
    }
}