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
void reverseStr(char *str);
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
    while(fgets(singleLine, 21, words))
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // removing the newline character from the string
        if(isInDic(singleLine))
        {
            addToEnd(head, singleLine);
        }
    }
    fclose(words);
    printf("Done reading\n");
}

void reverseStr(char *str)
{
    int len = strlen(str);
    char temp;
    for(int i=0; i<(len/2); i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    printf("Reversed string is: %s\n", str);
}

bool isInDic(char *reversed)
{
    FILE* words;
    char line[21];
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(line, 21, words))
    {
        line[strcspn(line, "\n")] = '\0'; // removing the newline character from the string
        if(strcmp(line, reversed) == 0)
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
    node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = malloc(sizeof(node));
    strcpy(current->next->entry, entry);
    current->next->next = NULL;
}

unsigned int searchAndDestroy(node **head, char *entry)
{
    node *current = *head;
    node *previous = NULL;
    unsigned int count = 0;

    while(current != NULL)
    {
        if(strcmp(current->entry, entry) == 0)
        {
            if(previous == NULL)
                *head = current->next;
            else
                previous->next = current->next;

            free(current);
            count++;
        }
        else
        {
            previous = current;
        }

        current = previous == NULL ? *head : previous->next;
    }

    return count;
}

void printList(node* head)
{
    node* current = head;
    while(current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}