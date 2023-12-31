List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 37 by call to `malloc`, is not freed after the last access at line 52, column 5.
 Example: 
  50. 
  51.     fclose(words);
  52.     printList(head);
          ^
  53. }
  54.

Error: Integer Overflow L2   ([0, 20] - 1):unsigned64.
 Example: 
  45.     while (fgets(singleLine, sizeof(singleLine), words) != NULL)
  46.     {
  47.         singleLine[strlen(singleLine) - 1] = '\0';
              ^
  48.         addToEnd(head, singleLine);
  49.     }

Error: Buffer Overrun L3   Offset: [-1, 19] Size: 21.
 Example: 
  45.     while (fgets(singleLine, sizeof(singleLine), words) != NULL)
  46.     {
  47.         singleLine[strlen(singleLine) - 1] = '\0';
              ^
  48.         addToEnd(head, singleLine);
  49.     }


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
    if (words == NULL)
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
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strlen(singleLine) - 1] = '\0';
        addToEnd(head, singleLine);
    }
    fclose(words);
    printList(head);
}
void reverStr(char *str)
{
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
bool isInDic(char *reversed)
{
    // Add your code to check if the reversed string is in the dictionary
    return false;
}
void addToEnd(node* head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
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
    // Add your code to search for and remove the entry from the linked list
    return 0;
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