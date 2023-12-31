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

#define MAX_PATH_LEN 100

int main()
{
    node* head = NULL;
    char path[MAX_PATH_LEN + 1];

    // Prompt user for the drive path to search
    printf("Enter drive path to search: ");
    if (fgets(path, MAX_PATH_LEN + 1, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    // Remove trailing newline character
    path[strcspn(path, "\n")] = '\0';

    // Search the directory
    search_dir(path);

    return 0;
}