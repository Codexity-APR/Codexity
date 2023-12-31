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
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}

void print(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printRev(node* head) {
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
    while (current != NULL) {
        if (current->data == d) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            break;
        } else {
            current = current->next;
        }
    }
    return head;
}

node* insertFront(node* head, int d) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = d;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    return new_node;
}

node* insertBack(node* head, int d) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = d;
    new_node->next = NULL;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        new_node->prev = current;
        current->next = new_node;
    }
    return head;
}

int max(node* head) {
    if (head == NULL) {
        return 0;
    }
    int max = head->data;
    node* current = head;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int min(node* head) {
    if (head == NULL) {
        return 0;
    }
    int min = head->data;
    node* current = head;
    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

int locInList(node* head, int x) {
    int loc = 0;
    node* current = head;
    while (current != NULL) {
        loc++;
        if (current->data == x) {
            return loc;
        }
        current = current->next;
    }
    return -1;
}