List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 73.
 Example: 
  72. {
  73.     node* newNode = malloc(sizeof(node));
  74.     strcpy(newNode->entry, entry);
          ^
  75.     newNode->next = NULL;
  76.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 66in call to `addToEnd()` .
 Example: 
  65. {
  66.     node* head = NULL;
  67.     addToEnd(head, reversed);
          ^
  68.     return searchAndDestroy(&head, reversed);
  69. }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 37.
 Example: 
  44.         current = current->next;
  45.     }
  46.     current->next = NULL;
          ^
  47.     fclose(words);
  48. }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 37.
 Example: 
  40.     {
  41.         singleLine[strcspn(singleLine, "\n")] = '\0';
  42.         strcpy(current->entry, singleLine);
              ^
  43.         current->next = malloc(sizeof(node));
  44.         current = current->next;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 37 by call to `malloc`, is not freed after the last access at line 46, column 5.
 Example: 
  44.         current = current->next;
  45.     }
  46.     current->next = NULL;
          ^
  47.     fclose(words);
  48. }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 37 by call to `malloc`, is not freed after the last access at line 44, column 9.
 Example: 
  42.         strcpy(current->entry, singleLine);
  43.         current->next = malloc(sizeof(node));
  44.         current = current->next;
              ^
  45.     }
  46.     current->next = NULL;

 Error type: CWE-476 at line: 78. Error message: Possible null pointer dereference: current

 Error type: CWE-476 at line: 82. Error message: Possible null pointer dereference: current


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
    while(fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0';
        strcpy(current->entry, singleLine);
        current->next = malloc(sizeof(node));
        current = current->next;
    }
    current->next = NULL;
    fclose(words);
}
void reverStr(char *str)
{
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
bool isInDic(char *reversed)
{
    node* head = NULL;
    addToEnd(head, reversed);
    return searchAndDestroy(&head, reversed);
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
    unsigned int count = 0;
    node *current = *head;
    node *prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->entry, entry) == 0)
        {
            count++;
            if (prev != NULL)
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
            else
            {
                *head = current->next;
                free(current);
                current = *head;
            }
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
    node* current = head;
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}