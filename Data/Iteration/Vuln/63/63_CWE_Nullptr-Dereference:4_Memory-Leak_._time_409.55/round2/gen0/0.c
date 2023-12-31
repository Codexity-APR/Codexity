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
unsigned int searchAndDestroy(node** head, char* entry);
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
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove newline character
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

    // Free allocated memory
    current = head;
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

void reverStr(char* str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

bool isInDic(char* reversed)
{
    FILE* words;
    char singleLine[21];
    words = fopen("words.txt", "r");
    if (words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove newline character
        if (strcmp(singleLine, reversed) == 0)
        {
            fclose(words);
            return true;
        }
    }
    fclose(words);
    return false;
}

void addToEnd(node** head, char entry[21])
{
    node* current = *head;
    if (current == NULL)
    {
        *head = malloc(sizeof(node));
        current = *head;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(node));
        current = current->next;
    }
    strcpy(current->entry, entry);
    current->next = NULL;
}

unsigned int searchAndDestroy(node** head, char* entry)
{
    unsigned int count = 0;
    node* current = *head;
    node* previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->entry, entry) == 0)
        {
            if (previous == NULL) // If the node to be deleted is the head
            {
                *head = current->next;
                free(current);
                current = *head;
            }
            else
            {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
            count++;
        }
        else
        {
            previous = current;
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