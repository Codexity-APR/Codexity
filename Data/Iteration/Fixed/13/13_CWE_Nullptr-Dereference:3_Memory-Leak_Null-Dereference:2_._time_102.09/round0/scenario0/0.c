List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 20 indirectly during the call to `addSpecific()`in call to `addSpecific()` .
 Example: 
  38.     addSpecific(&head, 5);
  39.     addSpecific(&head, 10);
  40.     addSpecific(&head, 15);
          ^
  41.     printList(head);
  42.     return 0;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 20 indirectly during the call to `addSpecific()`in call to `addSpecific()` .
 Example: 
  37.     node* head = NULL;
  38.     addSpecific(&head, 5);
  39.     addSpecific(&head, 10);
          ^
  40.     addSpecific(&head, 15);
  41.     printList(head);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 12 indirectly during the call to `addSpecific()`in call to `addSpecific()` .
 Example: 
  36. int main() {
  37.     node* head = NULL;
  38.     addSpecific(&head, 5);
          ^
  39.     addSpecific(&head, 10);
  40.     addSpecific(&head, 15);

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 38 by call to `addSpecific()`, is not freed after the last access at line 41, column 5.
 Example: 
  39.     addSpecific(&head, 10);
  40.     addSpecific(&head, 15);
  41.     printList(head);
          ^
  42.     return 0;
  43. }

Error: Null Dereference   pointer `temp` last assigned on line 12 could be null and is dereferenced at line 13, column 9.
 Example: 
  11.     if (temp == NULL) {
  12.         temp = (node*)malloc(sizeof(node));
  13.         temp->a = n;
              ^
  14.         temp->next = NULL;
  15.         *head = temp;

Error: Null Dereference   pointer `new_node` last assigned on line 20 could be null and is dereferenced at line 21, column 9.
 Example: 
  19.         }
  20.         node* new_node = (node*)malloc(sizeof(node));
  21.         new_node->a = n;
              ^
  22.         new_node->next = NULL;
  23.         temp->next = new_node;


#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int a;
    struct node* next;
} node;
void addSpecific(node** head, int n) {
    node* temp = *head;
    if (temp == NULL) {
        temp = (node*)malloc(sizeof(node));
        temp->a = n;
        temp->next = NULL;
        *head = temp;
    } else {
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
    return 0;
}