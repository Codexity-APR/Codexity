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
    head->next = NULL;

    while (fgets(singleLine, sizeof(singleLine), words))
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        
        addToEnd(head, singleLine);
    }

    fclose(words);
}

void addToEnd(node* head, char entry[21])
{
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->entry, entry);
    new_node->next = NULL;

    node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void printList(node* head)
{
    node* current = head->next; // Skip the dummy head node
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}