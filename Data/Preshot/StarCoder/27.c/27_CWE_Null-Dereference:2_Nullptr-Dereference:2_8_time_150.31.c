#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LEN 100

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

    int search_value;
    printf("Enter the value to search in the list: ");
    scanf("%d", &search_value);
    printf("locInList %d: %d\n", search_value, locInList(head, search_value));

    head = removeNode(head, 6);
    print(head);
    head = removeNode(head, 4);
    print(head);
    head = removeNode(head, 7);
    print(head);

    // Free nodes memory
    return 0;
}

void print(node* head) {
    node* tmp = head;
    while (tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void printRev(node* head) {
    node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    while (tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->prev;
    }
    printf("NULL\n");
}

node* removeNode(node* head, int d) {
    node* tmp = head;
    node* prev = NULL;

    // Find the node to remove
    while (tmp != NULL && tmp->data != d) {
        prev = tmp;
        tmp = tmp->next;
    }

    // If the node is not found, return
    if (tmp == NULL) {
        return head;
    }

    // If the node is the head, update the head
    if (prev == NULL) {
        head = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    // If the node is not the last node, update the next node's prev pointer
    if (tmp->next != NULL) {
        tmp->next->prev = prev;
    }

    // Free the memory
    free(tmp);

    return head;
}

node* insertFront(node* head, int d) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = d;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }

    return new_node;
}

node* insertBack(node* head, int d) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = d;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        return new_node;
    }

    node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = new_node;
    new_node->prev = tmp;

    return head;
}

int max(node* head) {
    int max_val = head->data;
    node* tmp = head->next;

    while (tmp != NULL) {
        if (tmp->data > max_val) {
            max_val = tmp->data;
        }
        tmp = tmp->next;
    }

    return max_val;
}

int min(node* head) {
    int min_val = head->data;
    node* tmp = head->next;

    while (tmp != NULL) {
        if (tmp->data < min_val) {
            min_val = tmp->data;
        }
        tmp = tmp->next;
    }

    return min_val;
}

int locInList(node* head, int x) {
    int loc = 0;
    node* tmp = head;

    while (tmp != NULL) {
        if (tmp->data == x) {
            return loc;
        }
        tmp = tmp->next;
        loc++;
    }

    return -1;
}