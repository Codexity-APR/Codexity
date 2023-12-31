List of vulnerabilities detected: 
Error: Null Dereference   pointer `newNode` last assigned on line 122 could be null and is dereferenced at line 123, column 5.
 Example: 
  121. node* insertBack(node* head, int d) {
  122.     node* newNode = (node*)malloc(sizeof(node));
  123.     newNode->data = d;
           ^
  124.     newNode->next = NULL;
  125.     newNode->prev = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 122.
 Example: 
  121. node* insertBack(node* head, int d) {
  122.     node* newNode = (node*)malloc(sizeof(node));
  123.     newNode->data = d;
           ^
  124.     newNode->next = NULL;
  125.     newNode->prev = NULL;

Error: Null Dereference   pointer `newNode` last assigned on line 109 could be null and is dereferenced at line 110, column 5.
 Example: 
  108. node* insertFront(node* head, int d) {
  109.     node* newNode = (node*)malloc(sizeof(node));
  110.     newNode->data = d;
           ^
  111.     newNode->next = head;
  112.     newNode->prev = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 109.
 Example: 
  108. node* insertFront(node* head, int d) {
  109.     node* newNode = (node*)malloc(sizeof(node));
  110.     newNode->data = d;
           ^
  111.     newNode->next = head;
  112.     newNode->prev = NULL;


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
void printRev(node* head);
node* removeNode(node* head, int d);
node* insertFront(node* head, int d);
node* insertBack(node* head, int d);
void print(node* head);
int max(node* head);
int min(node* head);
int locInList(node* head, int x);
int main()
{
    node* head = NULL;
    head = insertFront(head, 5);
    head = insertFront(head, 4);
    head = insertBack(head, 6);
    head = insertBack(head, 7);
    print(head);
    printRev(head);
    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));
    printf("locInList 5: %d\n", locInList(head, 5));
    printf("locInList 9: %d\n", locInList(head, 9));
    head = removeNode(head, 6);
    print(head);
    head = removeNode(head, 4);
    print(head);
    head = removeNode(head, 7);
    print(head);
    // Free nodes memory
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
void printRev(node* head) {
    if (head == NULL) {
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}
node* removeNode(node* head, int d) {
    node* current = head;
    if (head == NULL) {
        return NULL;
    }
    if (head->data == d) {
        node* newHead = head->next;
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        free(head);
        return newHead;
    }
    while (current != NULL && current->data != d) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}
node* insertFront(node* head, int d) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}
node* insertBack(node* head, int d) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
void print(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int max(node* head) {
    if (head == NULL) {
        printf("Error: Empty list\n");
        return -1;
    }
    int maxVal = head->data;
    node* current = head->next;
    while (current != NULL) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    return maxVal;
}
int min(node* head) {
    if (head == NULL) {
        printf("Error: Empty list\n");
        return -1;
    }
    int minVal = head->data;
    node* current = head->next;
    while (current != NULL) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    return minVal;
}
int locInList(node* head, int x) {
    int loc = 0;
    node* current = head;
    while (current != NULL && current->data != x) {
        current = current->next;
        loc++;
    }
    if (current == NULL) {
        return -1;
    } else {
        return loc;
    }
}