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
    FILE* words = fopen("words.txt", "r");
    if(words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    node* head = malloc(sizeof(node));
    if(head == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    char singleLine[21];
    while(fgets(singleLine, 21, words) != NULL)
    {
        addToEnd(&head, singleLine);
    }
    fclose(words);
    printList(head);
    char entry[21];
    printf("Enter a word to search for: ");
    scanf("%20s", entry);
    searchAndDestroy(&head, entry);
    printList(head);
}

void reverStr(char *str)
{
    size_t len = strlen(str);
    for(size_t i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

bool isInDic(char *reversed)
{
    FILE* words = fopen("words.txt", "r");
    if(words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    char singleLine[21];
    bool found = false;
    while(fgets(singleLine, 21, words) != NULL)
    {
        char line[21];
        strncpy(line, singleLine, 21);
        reverStr(line);
        if(strcmp(line, reversed) == 0)
        {
            found = true;
            break;
        }
    }
    fclose(words);
    return found;
}

void addToEnd(node** head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->entry, entry, 21);
    newNode->next = NULL;
    node* current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

unsigned int searchAndDestroy(node **head, char *entry)
{
    node* current = *head;
    node* previous = NULL;
    unsigned int count = 0;
    while(current != NULL)
    {
        if(strcmp(current->entry, entry) == 0)
        {
            if(previous == NULL)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            count++;
        }
        else
        {
            previous = current;
        }
        current = current->next;
    }
    return count;
}

void printList(node* head)
{
    node* current = head->next;
    while(current != NULL)
    {
        printf("%s", current->entry);
        current = current->next;
    }
}