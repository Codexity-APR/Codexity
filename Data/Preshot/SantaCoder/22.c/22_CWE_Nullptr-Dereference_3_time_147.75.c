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

clientdata* createClient(char* name, int birthday, int landline, int cellphone, int clientnum);
void addClient(clientdata** head, clientdata* newClient);
void removeClient(clientdata** head, int clientnum);
clientdata* getClient(clientdata* head, int clientnum);
void printClients(clientdata* head);

// Function to create a new client with the given details
clientdata* createClient(char* name, int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientnum;
    newClient->next = NULL;
    return newClient;
}

// Function to add a new client to the end of the list
void addClient(clientdata** head, clientdata* newClient) {
    clientdata* current;
    if (*head == NULL) {
        *head = newClient;
    } else {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    clientcounter++;
}

// Function to remove a client from the list based on their client number
void removeClient(clientdata** head, int clientnum) {
    clientdata* current = *head;
    clientdata* previous = NULL;
    while (current != NULL) {
        if (current->clientnum == clientnum) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            clientcounter--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to get a client from the list based on their client number
clientdata* getClient(clientdata* head, int clientnum) {
    clientdata* current = head;
    while (current != NULL) {
        if (current->clientnum == clientnum) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print all clients in the list
void printClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        printf("Client Number: %d\n", current->clientnum);
        printf("Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("\n");
        current = current->next;
    }
}