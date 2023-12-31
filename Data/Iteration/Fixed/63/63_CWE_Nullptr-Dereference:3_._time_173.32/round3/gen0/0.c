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
    node* head = NULL; // Initialize head pointer to NULL
    node* current = NULL; // Initialize current pointer to NULL
    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0'; // Remove trailing newline character
        addToEnd(&head, singleLine); // Pass the address of head pointer
    }
    fclose(words);
    printList(head);
    
    // Free the dynamically allocated memory
    node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
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
    node* current = head;
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}