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
    if(words == NULL)
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

    node* current = head;
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        strcpy(current->entry, singleLine);
        current->next = malloc(sizeof(node));
        
        if (current->next == NULL)
        {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        
        current = current->next;
    }
    
    current->next = NULL;
    
    fclose(words);
    
    printList(head);
}

void reverStr(char *str)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
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
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        
        if (strcmp(singleLine, reversed) == 0)
        {
            fclose(words);
            return true;
        }
    }
    
    fclose(words);
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
    unsigned int count = 0;
    node* prev = NULL;
    node* current = *head;
    
    while (current != NULL)
    {
        if (strcmp(current->entry, entry) == 0)
        {
            count++;
            
            if (prev == NULL)
            {
                *head = current->next;
                free(current);
                current = *head;
            }
            else
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
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