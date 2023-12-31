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
	while(words != NULL)
	{
        if(isInDic(readLine(singleLine, words)))
        {
            addToEnd(head, singleLine);
        }
        words = fread(words, 1, NULL);
    }
    fclose(words);
    printf("Done reading\n");
}

void reverseStr(char *str)
{
    char *reversed;
    int i;
    reversed = str;
    for(i = 0; i < 21; i++)
    {
        if(i < 10)
        {
            reversed = str + str[i];
        }
        else
        {
            reversed = str + str[i].swapcase();
        }
    }
    printf("Reversed string is: %s\n", reversed);
}