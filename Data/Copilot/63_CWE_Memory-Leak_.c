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
    if(head == NULL)
        {
            printf("Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        head->next = NULL;
        while(fgets(singleLine, 21, words) != NULL)
        {
            singleLine[strcspn(singleLine, "\n")] = 0; // remove trailing newline character
            if(isInDic(singleLine))
            {
                addToEnd(head, singleLine);
            }
        }
        fclose(words);
        printList(head);
        unsigned int numDeleted = searchAndDestroy(&head, "apple");
        printf("Number of nodes deleted: %u\n", numDeleted);
        printList(head);
    }

    void addToEnd(node* head, char entry[21])
    {
        node* current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(node));
        if(current->next == NULL)
        {
            printf("Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(current->next->entry, entry);
        current->next->next = NULL;
    }

    unsigned int searchAndDestroy(node **head, char *entry)
    {
        node* current = *head;
        node* temp;
        unsigned int numDeleted = 0;
        while(current->next != NULL)
        {
            if(strcmp(current->next->entry, entry) == 0)
            {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                numDeleted++;
            }
            else
            {
                current = current->next;
            }
        }
        return numDeleted;
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
