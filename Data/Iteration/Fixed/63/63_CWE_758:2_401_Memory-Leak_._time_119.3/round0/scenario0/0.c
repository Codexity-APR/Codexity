List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 37 by call to `malloc`, is not freed after the last access at line 37, column 5.
 Example: 
  35.         exit(EXIT_FAILURE);
  36.     }
  37.     node* head = malloc(sizeof(node));
          ^
  38.     
  39.     // Add code here

 Error type: CWE-758 at line: 52. Error message: Found a exit path from function with non-void return type that has missing return statement

 Error type: CWE-758 at line: 62. Error message: Found a exit path from function with non-void return type that has missing return statement

 Error type: CWE-401 at line: 42. Error message: Memory leak: head


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
    // Add code here
    fclose(words);
}
void reverStr(char *str)
{
    // Add code here
}
bool isInDic(char *reversed)
{
    // Add code here
}
void addToEnd(node* head, char entry[21])
{
    // Add code here
}
unsigned int searchAndDestroy(node **head, char *entry)
{
    // Add code here
}
void printList(node* head)
{
    // Add code here
}