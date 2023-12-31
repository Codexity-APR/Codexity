List of vulnerabilities detected: 
Error: Null Dereference   pointer `head` last assigned on line 50 could be null and is dereferenced at line 51, column 5.
 Example: 
  49. int main() {
  50.     node* head = (node*)malloc(sizeof(node));
  51.     head->next = NULL;
          ^
  52. 
  53.     addSpecific(head, 2);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 50.
 Example: 
  49. int main() {
  50.     node* head = (node*)malloc(sizeof(node));
  51.     head->next = NULL;
          ^
  52. 
  53.     addSpecific(head, 2);

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 50 by call to `malloc`, is not freed after the last access at line 59, column 5.
 Example: 
  57. 
  58.     printf("Linked List: ");
  59.     printList(head);
          ^
  60. 
  61.     return 0;


#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int a;
    struct node* next;
} node;
void addSpecific(node* head, int n) {
    node* temp = NULL;
    if (head->next == NULL) {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL) {
            printf("Memory allocation failed.");
            return;
        }
        temp->a = n;
        temp->next = NULL;
        head->next = temp;
    } else {
        temp = head->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed.");
            return;
        }
        newNode->a = n;
        newNode->next = NULL;
        temp->next = newNode;
    }
}
void printList(node* head) {
    if (head->next == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    addSpecific(head, 2);
    addSpecific(head, 4);
    addSpecific(head, 6);
    addSpecific(head, 8);
    printf("Linked List: ");
    printList(head);
    return 0;
}