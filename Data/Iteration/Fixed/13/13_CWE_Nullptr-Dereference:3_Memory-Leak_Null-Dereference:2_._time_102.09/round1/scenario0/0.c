List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `addSpecific()`in call to `addSpecific()` .
 Example: 
  37.     addSpecific(&head, 5);
  38.     addSpecific(&head, 10);
  39.     addSpecific(&head, 15);
          ^
  40.     printList(head);
  41.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 19 indirectly during the call to `addSpecific()`in call to `addSpecific()` .
 Example: 
  36.     node* head = NULL;
  37.     addSpecific(&head, 5);
  38.     addSpecific(&head, 10);
          ^
  39.     addSpecific(&head, 15);
  40.     printList(head);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 11 indirectly during the call to `addSpecific()`in call to `addSpecific()` .
 Example: 
  35. int main() {
  36.     node* head = NULL;
  37.     addSpecific(&head, 5);
          ^
  38.     addSpecific(&head, 10);
  39.     addSpecific(&head, 15);

Error: Null Dereference   pointer `new_node` last assigned on line 19 could be null and is dereferenced at line 20, column 9.
 Example: 
  18.         }
  19.         node* new_node = (node*)malloc(sizeof(node));
  20.         new_node->a = n;
              ^
  21.         new_node->next = NULL;
  22.         temp->next = new_node;

Error: Null Dereference   pointer `*head` last assigned on line 11 could be null and is dereferenced at line 12, column 9.
 Example: 
  10.     if (*head == NULL) {
  11.         *head = (node*)malloc(sizeof(node));
  12.         (*head)->a = n;
              ^
  13.         (*head)->next = NULL;
  14.     } else {


#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int a;
    struct node* next;
} node;
void addSpecific(node** head, int n) {
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));
        (*head)->a = n;
        (*head)->next = NULL;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* new_node = (node*)malloc(sizeof(node));
        new_node->a = n;
        new_node->next = NULL;
        temp->next = new_node;
    }
}
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    node* head = NULL;
    addSpecific(&head, 5);
    addSpecific(&head, 10);
    addSpecific(&head, 15);
    printList(head);
    // Freeing the allocated memory
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    return 0;
}