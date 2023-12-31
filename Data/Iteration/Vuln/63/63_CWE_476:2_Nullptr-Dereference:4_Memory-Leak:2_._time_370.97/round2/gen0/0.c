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
void addToEnd(node** head, char entry[21]);
unsigned int searchAndDestroy(node** head, char *entry);
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
    node* head = NULL;
    node* current = NULL;
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0';
        if (head == NULL)
        {
            head = malloc(sizeof(node));
            current = head;
        }
        else
        {
            current->next = malloc(sizeof(node));
            current = current->next;
        }
        strcpy(current->entry, singleLine);
        current->next = NULL;
    }
    fclose(words);
    printList(head);

    // Freeing the allocated memory
    current = head;
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

void reverStr(char *str)
{
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

bool isInDic(char *reversed)
{
    node* head = NULL;
    addToEnd(&head, reversed);
    return searchAndDestroy(&head, reversed);
}

void addToEnd(node** head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

unsigned int searchAndDestroy(node** head, char *entry)
{
    unsigned int count = 0;
    node* current = *head;
    node* prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->entry, entry) == 0)
        {
            count++;
            if (prev != NULL)
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
            else
            {
                *head = current->next;
                free(current);
                current = *head;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return count;
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