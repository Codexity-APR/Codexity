#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char entry[21];
    struct node* next;
} node;

void readDic();
void reverStr(char *str);
bool isInDic(char *reversed);
void addToEnd(node* head, char entry[21]);
unsigned int searchAndDestroy(node **head, char *entry);
void printList(node* head);

int main()
{
    printf("Hello\n");
    readDic();
    printf("Goodbye!");
    return EXIT_SUCCESS;
}

void readDic()
{
    FILE* words;
    char singleLine[21];
    words = fopen("words.txt", "r");
    if (words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    node* head = NULL;  // Initialize head to NULL
    node* current = NULL;  // Initialize current to NULL

    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0';  // remove newline character

        if (isInDic(singleLine))
        {
            if (head == NULL) {
                head = malloc(sizeof(node));
                strcpy(head->entry, singleLine);
                head->next = NULL;
                current = head;
            } else {
                addToEnd(current, singleLine);
                current = current->next;
            }
        }
    }

    fclose(words);
    printList(head);
}

void addToEnd(node* head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->entry, entry);
    newNode->next = NULL;

    head->next = newNode;
}

bool isInDic(char *reversed)
{
    // Implementation to check if reversed string is in dictionary
    // Return true or false accordingly
}

void printList(node* head)
{
    node* current = head;
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}

unsigned int searchAndDestroy(node **head, char *entry)
{
    // Implementation to search for and remove a node from the linked list if found
    // Return the number of nodes removed
}

void reverStr(char *str)
{
    // Implementation to reverse a string
}