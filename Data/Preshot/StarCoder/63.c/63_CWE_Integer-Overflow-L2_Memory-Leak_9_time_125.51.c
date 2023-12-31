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
unsigned int searchAndDestroy(node **head, char *entry);
void printList(node* head);

int main()
{
    printf("Hello\n");
    readDic();
    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}

void readDic()
{
    FILE* words;
    char singleLine[21];
    node* head = NULL;
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(singleLine, 21, words)!= NULL)
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
    char singleLine[21];
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    bool found = false;
    while(fgets(singleLine, 21, words)!= NULL)
    {
        char line[21];
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

void addToEnd(node** head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    node* current = *head;
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
    while(current!= NULL)
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
            node* temp = current;
            current = current->next;
            free(temp);
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
    while(current!= NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}