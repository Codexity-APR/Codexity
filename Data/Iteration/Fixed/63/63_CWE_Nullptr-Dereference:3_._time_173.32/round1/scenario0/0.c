List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 42 by call to `addToEnd()`, is not freed after the last access at line 39, column 12.
 Example: 
  37.     node* head = malloc(sizeof(node));
  38.     node* current = head; // Added current pointer
  39.     while (fgets(singleLine, sizeof(singleLine), words) != NULL)
                 ^
  40.     {
  41.         singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character


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
void addToEnd(node** head, char entry[21]); // Modified function signature
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
    node* current = head; // Added current pointer
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        addToEnd(&current, singleLine); // Pass the address of current pointer
    }
    fclose(words);
    printList(head);
}
void addToEnd(node** head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) // Check if allocation was successful
    {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void printList(node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node* current = head->next;
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}