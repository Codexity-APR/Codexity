#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LEN 100

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

int main(void)
{
    node* head = NULL;
    char path[MAX_PATH_LEN];

    head = insertFront(head, 5);
    head = insertFront(head, 4);
    head = insertBack(head, 6);
    head = insertBack(head, 7);
    print(head);
    printRev(head);

    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));

    printf("Enter drive path to search: ");
    if (fgets(path, MAX_PATH_LEN, stdin) != NULL)
    {
        // Remove the newline character from the input
        int len = strlen(path);
        if (len > 0 && path[len - 1] == '\n')
        {
            path[len - 1] = '\0';
        }

        printf("locInList 5: %d\n", locInList(head, 5));
        printf("locInList 9: %d\n", locInList(head, 9));

        head = removeNode(head, 6);
        print(head);
        head = removeNode(head, 4);
        print(head);
        head = removeNode(head, 7);
        print(head);

        // Free nodes memory
    }
    else
    {
        printf("Error reading input\n");
    }

    return 0;
}