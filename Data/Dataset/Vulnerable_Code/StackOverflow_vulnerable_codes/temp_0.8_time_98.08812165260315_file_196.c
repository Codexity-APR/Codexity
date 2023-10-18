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
    
    // Initialize the head node
    strcpy(head->entry, "");
    head->next = NULL;
    
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        // Remove the newline character from the end
        singleLine[strcspn(singleLine, "\n")] = '\0';
        
        if (isInDic(singleLine))
        {
            addToEnd(head, singleLine);
        }
    }
    
    fclose(words);

    printList(head);

    // Cleanup memory
    node* current = head;
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

void addToEnd(node* head, char entry[21])
{
    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    
    current->next = newNode;
}

bool isInDic(char *reversed)
{
    char original[21];
    strcpy(original, reversed);
    reverStr(reversed);
    if (strcmp(reversed, original) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void reverStr(char *str)
{
    int length = strlen(str);
    int i;
    char temp;
    for (i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
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