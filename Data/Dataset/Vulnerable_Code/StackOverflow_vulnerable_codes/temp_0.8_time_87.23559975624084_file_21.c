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
    node* current = head;

    while (fgets(singleLine, sizeof(singleLine), words) != NULL)
    {
        singleLine[strcspn(singleLine, "\n")] = '\0';
        addToEnd(current, singleLine);
        current = current->next;
    }

    fclose(words);

    printf("Dictionary read successfully.\n");
    printList(head);

    // Do any additional processing or function calls here

    // Free allocated memory
    current = head;
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}

void reverStr(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

bool isInDic(char *reversed)
{
    // Implement your logic for checking if the reversed string is in the dictionary
    // Return true if it is, false otherwise
}

void addToEnd(node* head, char entry[21])
{
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->entry, entry);
    newNode->next = NULL;

    if (head->next == NULL)
    {
        head->next = newNode;
    }
    else
    {
        node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

unsigned int searchAndDestroy(node **head, char *entry)
{
    // Implement your logic for searching and removing the specified entry from the linked list
    // Return the number of occurrences of the entry that were removed
}

void printList(node* head)
{
    node* current = head->next;
    printf("Dictionary contents:\n");
    while (current != NULL)
    {
        printf("%s\n", current->entry);
        current = current->next;
    }
}