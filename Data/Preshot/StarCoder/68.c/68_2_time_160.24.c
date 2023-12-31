#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

Node* insertFront(Node* head, int d) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Error: Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    temp->data = d;
    temp->prev = NULL;
    if (head == NULL) {
        head = temp;
        temp->next = NULL;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}

Node* insertBack(Node* head, int d) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Error: Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    temp->data = d;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        temp->prev = NULL;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void printRev(Node* head) {
    Node* curr = head;
    if (curr == NULL) {
        return;
    }
    while (curr->next != NULL) {
        curr = curr->next;
    }
    printf("List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

Node* removeNode(Node* head, int d) {
    Node* curr = head;
    if (head == NULL) {
        return head;
    }
    if (curr->data == d) {
        head = curr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(curr);
        return head;
    }
    while (curr != NULL && curr->data != d) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error: Node not found");
        return head;
    }
    curr->prev->next = curr->next;
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    free(curr);
    return head;
}

int max(Node* head) {
    int max = 0;
    bool flag = false;
    Node* curr = head;
    while (curr != NULL) {
        if (!flag) {
            max = curr->data;
            flag = true;
        }
        if (curr->data > max) {
            max = curr->data;
        }
        curr = curr->next;
    }
    if (!flag) {
        printf("Error: List is empty");
        exit(EXIT_FAILURE);
    }
    return max;
}

int min(Node* head) {
    int min = 0;
    bool flag = false;
    Node* curr = head;
    while (curr != NULL) {
        if (!flag) {
            min = curr->data;
            flag = true;
        }
        if (curr->data < min) {
            min = curr->data;
        }
        curr = curr->next;
    }
    if (!flag) {
        printf("Error: List is empty");
        exit(EXIT_FAILURE);
    }
    return min;
}

int locInList(Node* head, int x) {
    int loc = 0;
    Node* curr = head;
    while (curr != NULL && curr->data != x) {
        loc++;
        curr = curr->next;
    }
    if (curr == NULL) {
        return -1;
    }
    return loc;
}

int main() {
    Node* head = NULL;

    head = insertFront(head, 5);
    head = insertFront(head, 4);
    head = insertBack(head, 6);
    head = insertBack(head, 7);

    printList(head);
    printRev(head);

    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));
    printf("locInList 5: %d\n", locInList(head, 5));
    printf("locInList 9: %d\n", locInList(head, 9));

    head = removeNode(head, 6);
    printList(head);
    head = removeNode(head, 4);
    printList(head);
    head = removeNode(head, 7);
    printList(head);

    // Free nodes memory
    Node* curr;
    while (head != NULL) {
        curr = head;
        head = head->next;
        free(curr);
    }

    return 0;
}