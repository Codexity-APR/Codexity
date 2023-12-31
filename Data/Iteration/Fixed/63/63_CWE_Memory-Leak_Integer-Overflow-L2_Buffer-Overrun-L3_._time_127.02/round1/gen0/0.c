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
    node* head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        addToEnd(head, singleLine);
    }
    fclose(words);
    printList(head);
    // Free allocated memory
    node* current = head;
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

void reverStr(char *str)
{
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

bool isInDic(char *reversed)
{
    // Add your code to check if the reversed string is in the dictionary
    return false;
}

void addToEnd(node* head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

unsigned int searchAndDestroy(node **head, char *entry)
{
    // Add your code to search for and remove the entry from the linked list
    return 0;
}

void printList(node* head)
{
    node* current = head->next;
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}