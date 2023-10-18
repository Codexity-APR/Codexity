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

    while(fgets(singleLine, 21, words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0';
        addToEnd(current, singleLine);
        current = current->next;
    }

    fclose(words);

    printList(head);
}

void addToEnd(node* head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->entry, entry);
    newNode->next = NULL;

    while(head->next != NULL)
    {
        head = head->next;
    }

    head->next = newNode;
}

void printList(node* head)
{
    node* current = head->next;

    while(current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}