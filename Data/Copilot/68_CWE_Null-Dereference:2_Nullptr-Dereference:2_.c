#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void printRev(node* head){
    node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    while(current != NULL){
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

node* removeNode(node* head, int d){
    node* current = head;
    while(current != NULL){
        if(current->data == d){
            if(current == head){
                head = current->next;
                head->prev = NULL;
            }else if(current->next == NULL){
                current->prev->next = NULL;
            }else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return head;
        }
        current = current->next;
    }
    return head;
}

node* insertFront(node* head, int d){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    return newNode;
}

node* insertBack(node* head, int d){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        return newNode;
    }
    node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

void print(node* head){
    node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int max(node* head){
    node* current = head;
    int max = current->data;
    while(current != NULL){
        if(current->data > max){
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int min(node* head){
    node* current = head;
    int min = current->data;
    while(current != NULL){
        if(current->data < min){
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

int locInList(node* head, int x){
    node* current = head;
    int loc = 0;
    while(current != NULL){
        if(current->data == x){
            return loc;
        }
        loc++;
        current = current->next;
    }
    return -1;
}

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
    while(current != NULL){
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
