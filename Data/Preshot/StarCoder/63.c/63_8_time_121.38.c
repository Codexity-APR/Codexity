#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
    char entry[MAX_WORD_LENGTH + 1];
    struct node *next;
} node;

void readDic();
void reverStr(char *str);
bool isInDic(char *reversed);
void addToEnd(node **head, char entry[MAX_WORD_LENGTH + 1]);
unsigned int searchAndDestroy(node **head, char *entry);
void printList(node *head);

int main() {
    printf("Hello\n");
    readDic();
    printf("Goodbye!");
    return EXIT_SUCCESS;
}

void readDic() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    node *head = NULL;
    char word[MAX_WORD_LENGTH + 1];

    while (fgets(word, MAX_WORD_LENGTH + 1, fp) != NULL) {
        addToEnd(&head, word);
    }

    fclose(fp);
    printList(head);

    char entry[MAX_WORD_LENGTH + 1];
    printf("Enter a word to search for: ");
    if (scanf("%" str(MAX_WORD_LENGTH) "s", entry) != 1) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    searchAndDestroy(&head, entry);
    printList(head);
}

void reverStr(char *str) {
    size_t len = strlen(str);
    size_t i = 0, j = len - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        ++i;
        --j;
    }
}

bool isInDic(char *reversed) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    bool found = false;
    char word[MAX_WORD_LENGTH + 1];

    while (fgets(word, MAX_WORD_LENGTH + 1, fp) != NULL) {
        reverStr(word);
        if (strcmp(word, reversed) == 0) {
            found = true;
            break;
        }
    }

    fclose(fp);
    return found;
}

void addToEnd(node **head, char entry[MAX_WORD_LENGTH + 1]) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->entry, entry, MAX_WORD_LENGTH);
    newNode->entry[MAX_WORD_LENGTH] = '\0';
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

unsigned int searchAndDestroy(node **head, char *entry) {
    unsigned int count = 0;

    while (*head != NULL && strncmp((*head)->entry, entry, MAX_WORD_LENGTH) == 0) {
        node *toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        ++count;
    }

    if (*head == NULL) {
        return count;
    }

    node *current = (*head)->next;
    node *prev = *head;

    while (current != NULL) {
        if (strncmp(current->entry, entry, MAX_WORD_LENGTH) == 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
            ++count;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return count;
}

void printList(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s", current->entry);
        current = current->next;
    }
}