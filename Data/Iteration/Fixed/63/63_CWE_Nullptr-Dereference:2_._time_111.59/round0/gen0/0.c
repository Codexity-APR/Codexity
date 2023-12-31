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

    // Read lines from the file and add them to the linked list
    while(fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        // Remove the newline character at the end of the string
        singleLine[strcspn(singleLine, "\n")] = '\0';

        // Add the word to the end of the linked list
        addToEnd(head, singleLine);
    }

    // Close the file
    fclose(words);

    // Print the contents of the linked list
    printList(head);

    // Free the memory allocated for the linked list
    while(head != NULL)
    {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

void addToEnd(node* head, char entry[21])
{
    // Create a new node
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->entry, entry);
    newNode->next = NULL;

    // Find the last node in the linked list
    node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    // Add the new node to the end of the linked list
    current->next = newNode;
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