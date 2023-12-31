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
