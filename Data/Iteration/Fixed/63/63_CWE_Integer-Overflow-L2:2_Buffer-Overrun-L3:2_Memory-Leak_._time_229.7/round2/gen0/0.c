#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char entry[21];
    struct node* next;
} node;

void readDic();
void reverStr(char* str);
bool isInDic(char* reversed);
void addToEnd(node* head, char entry[21]);
unsigned int searchAndDestroy(node** head, char* entry);
void printList(node* head);
void freeList(node* head); // New function to free the linked list

int main() {
    printf("Hello\n");
    readDic();
    printf("Goodbye!");
    return EXIT_SUCCESS;
}

void readDic() {
    FILE* words;
    char singleLine[21];
    words = fopen("words.txt", "r");
    if (words == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    node* head = malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    while (fgets(singleLine, sizeof(singleLine), words) != NULL) {
        size_t length = strlen(singleLine);
        if (length > 0 && singleLine[length - 1] == '\n') {
            singleLine[length - 1] = '\0';
        }
        if (!isInDic(singleLine)) {
            addToEnd(head, singleLine);
        }
    }
    fclose(words);
    printList(head);
    freeList(head); // Free the linked list before exiting
}

void reverStr(char* str) {
    size_t length = strlen(str);
    for (size_t i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

bool isInDic(char* reversed) {
    FILE* dictionary;
    char word[21];
    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(word, sizeof(word), dictionary) != NULL) {
        size_t length = strlen(word);
        if (length > 0 && word[length - 1] == '\n') {
            word[length - 1] = '\0';
        }
        if (strcmp(word, reversed) == 0) {
            fclose(dictionary);
            return true;
        }
    }
    fclose(dictionary);
    return false;
}

void addToEnd(node* head, char entry[21]) {
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->entry, entry);
    newNode->next = NULL;
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

unsigned int searchAndDestroy(node** head, char* entry) {
    node* current = *head;
    node* previous = NULL;
    unsigned int count = 0;
    while (current != NULL) {
        if (strcmp(current->entry, entry) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            count++;
        }
        previous = current;
        current = current->next;
    }
    return count;
}

void printList(node* head) {
    node* current = head->next;
    while (current != NULL) {
        printf("%s\n", current->entry);
        current = current->next;
    }
}

void freeList(node* head) {
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}