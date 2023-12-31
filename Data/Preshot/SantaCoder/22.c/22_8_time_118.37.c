#include <stdlib.h> // need this for realloc
#include <string.h> // need this for memcpy

int clientcounter = 0; //Global variable since this will be needed in other functions

typedef struct client{
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client *next; 
}clientdata;

// Function to add a client to the linked list
void addClient(clientdata **head, clientdata *newClient) {
    if (*head == NULL) {
        *head = newClient;
    } else {
        clientdata *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    clientcounter++;
}

// Function to remove a client from the linked list
void removeClient(clientdata **head, int clientnum) {
    clientdata *current = *head;
    clientdata *previous = NULL;
    while (current != NULL && current->clientnum != clientnum) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Client with client number %d not found.\n", clientnum);
    } else {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        clientcounter--;
    }
}

// Function to print all the clients in the linked list
void printClients(clientdata *head) {
    clientdata *current = head;
    while (current != NULL) {
        printf("Client Number: %d\n", current->clientnum);
        printf("Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("----------------------------------\n");
        current = current->next;
    }
}

// Function to free all the memory used by the linked list
void freeList(clientdata **head) {
    clientdata *current = *head;
    while (current != NULL) {
        clientdata *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    clientcounter = 0;
}