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
    current->next = NULL;

    while(fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character

        addToEnd(current, singleLine);
        current = current->next;
    }

    fclose(words);

    printList(head);

    free(head);
}

void reverStr(char *str)
{
    int i, j;
    char temp;
    for(i = 0, j = strlen(str)-1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

bool isInDic(char *reversed)
{
    FILE* dictionary;
    char line[21];

    dictionary = fopen("dictionary.txt", "r");
    if(dictionary == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line, sizeof(line), dictionary) != NULL)
    {
        line[strcspn(line, "\n")] = '\0'; // Remove trailing newline character

        if(strcmp(reversed, line) == 0)
        {
            fclose(dictionary);
            return true;
        }
    }

    fclose(dictionary);
    return false;
}

void addToEnd(node* head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->entry, entry);
    newNode->next = NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = newNode;
}

unsigned int searchAndDestroy(node **head, char *entry)
{
    unsigned int count = 0;
    node *current = *head;
    node *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->entry, entry) == 0)
        {
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

            count++;
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
    node* current = head->next;

    printf("Dictionary:\n");

    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}