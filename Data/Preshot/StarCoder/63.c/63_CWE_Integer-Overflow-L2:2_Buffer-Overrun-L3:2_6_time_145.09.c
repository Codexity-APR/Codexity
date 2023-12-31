#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

typedef struct node
{
    char entry[MAX_WORD_LENGTH + 1];
    struct node* next;
} node;

void readDic();
void reverStr(char *str);
bool isInDic(char *reversed);
void addToEnd(node* head, char entry[MAX_WORD_LENGTH + 1]);
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
    char singleLine[MAX_WORD_LENGTH + 1];
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }
    node* head = malloc(sizeof(node));
    if (head == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;

    while(fgets(singleLine, MAX_WORD_LENGTH + 1, words) != NULL)
    {
        if (singleLine[strlen(singleLine) - 1] == '\n')
        {
            singleLine[strlen(singleLine) - 1] = '\0';
        }
        addToEnd(head, singleLine);
    }
    fclose(words);
    printList(head);

    char entry[MAX_WORD_LENGTH + 1];
    printf("Enter a word to search for: ");
    if (scanf("%20s", entry) != 1)
    {
        fprintf(stderr, "Input error!\n");
        exit(EXIT_FAILURE);
    }
    searchAndDestroy(&head, entry);
    printList(head);

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
    int i = 0;
    int j = strlen(str) - 1;
    while(i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

bool isInDic(char *reversed)
{
    FILE* words;
    char singleLine[MAX_WORD_LENGTH + 1];
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }
    bool found = false;
    while(fgets(singleLine, MAX_WORD_LENGTH + 1, words)!= NULL)
    {
        char line[MAX_WORD_LENGTH + 1];
        if (singleLine[strlen(singleLine) - 1] == '\n')
        {
            singleLine[strlen(singleLine) - 1] = '\0';
        }
        strcpy(line, singleLine);
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

void addToEnd(node* head, char entry[MAX_WORD_LENGTH + 1])
{
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    node* current = head;
    while(current->next!= NULL)
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
            count++;
            free(current);
            current = previous == NULL ? *head : previous->next;
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
    while(current!= NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}