List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 52.
 Example: 
  51. {
  52.     node* newNode = malloc(sizeof(node));
  53.     strcpy(newNode->entry, entry);
          ^
  54.     newNode->next = NULL;
  55.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 37in call to `printList()` .
 Example: 
  45. 
  46.     fclose(words);
  47.     printList(head);
          ^
  48. }
  49.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 37in call to `addToEnd()` .
 Example: 
  41.         singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
  42. 
  43.         addToEnd(head, singleLine);
              ^
  44.     }
  45.


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
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        addToEnd(head, singleLine);
    }
    fclose(words);
    printList(head);
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
void printList(node* head)
{
    node* current = head->next;
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}