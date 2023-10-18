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
    node* current = head;
    while (fgets(singleLine, sizeof(singleLine), words))
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // remove trailing newline
        addToEnd(current, singleLine);
        current = current->next;
    }
    fclose(words);
    printList(head);
}

void reverStr(char *str)
{
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

bool isInDic(char *reversed)
{
    FILE* words;
    char singleLine[21];
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(singleLine, sizeof(singleLine), words))
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // remove trailing newline
        if(strcmp(reversed, singleLine) == 0)
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
    node *current = *head;
    node *prev = NULL;
    unsigned int count = 0;

    while (current != NULL)
    {
        if (strcmp(current->entry, entry) == 0)
        {
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            count++;
        }
        prev = current;
        current = current->next;
    }

    return count;
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