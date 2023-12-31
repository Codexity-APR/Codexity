List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 82.
 Example: 
  81. {
  82.     node* newNode = malloc(sizeof(node));
  83.     strcpy(newNode->entry, entry);
          ^
  84.     newNode->next = NULL;
  85.     if (*head == NULL)

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 76 by call to `addToEnd()`, is not freed after the last access at line 77, column 12.
 Example: 
  75.     node* head = NULL;
  76.     addToEnd(&head, reversed);
  77.     return searchAndDestroy(&head, reversed);
                 ^
  78. }
  79.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 49.
 Example: 
  50.             current = current->next;
  51.         }
  52.         strcpy(current->entry, singleLine);
              ^
  53.         current->next = NULL;
  54.     }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 44.
 Example: 
  50.             current = current->next;
  51.         }
  52.         strcpy(current->entry, singleLine);
              ^
  53.         current->next = NULL;
  54.     }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 44 by call to `malloc`, is not freed after the last access at line 56, column 5.
 Example: 
  54.     }
  55.     fclose(words);
  56.     printList(head);
          ^
  57. }
  58.


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
unsigned int searchAndDestroy(node** head, char *entry);
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
    if (words == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    node* head = NULL;
    node* current = NULL;
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0';
        if (head == NULL)
        {
            head = malloc(sizeof(node));
            current = head;
        }
        else
        {
            current->next = malloc(sizeof(node));
            current = current->next;
        }
        strcpy(current->entry, singleLine);
        current->next = NULL;
    }
    fclose(words);
    printList(head);
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
    addToEnd(&head, reversed);
    return searchAndDestroy(&head, reversed);
}
void addToEnd(node** head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
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
unsigned int searchAndDestroy(node** head, char *entry)
{
    unsigned int count = 0;
    node* current = *head;
    node* prev = NULL;
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