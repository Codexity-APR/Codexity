#include <stdlib.h> // need this for realloc
#include <string.h> // need this for memcpy

int clientcounter = 0; // Global variable since this will be needed in other functions

typedef struct client {
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client *next;
} clientdata;

// Function to add a new client
void addClient(clientdata **head, char *name, int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata *)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = ++clientcounter;
    newClient->next = NULL;
    
    if (*head == NULL) {
        *head = newClient;
    } else {
        clientdata *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClient;
    }
}

// Function to display all clients' information
void displayClients(clientdata *head) {
    clientdata *temp = head;
    
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Birthday: %d\n", temp->birthday);
        printf("Landline: %d\n", temp->landline);
        printf("Cellphone: %d\n", temp->cellphone);
        printf("Client Number: %d\n\n", temp->clientnum);
        
        temp = temp->next;
    }
}

// Function to free the memory allocated for clients
void freeClients(clientdata *head) {
    clientdata *temp = head;
    
    while (temp != NULL) {
        clientdata *next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    clientdata *clients = NULL;
    
    // Example usage:
    addClient(&clients, "John Doe", 1990, 123456789, 987654321);
    addClient(&clients, "Jane Smith", 1985, 987654321, 123456789);
    addClient(&clients, "Bob Johnson", 1995, 555555555, 999999999);
    
    displayClients(clients);
    
    freeClients(clients);
    
    return 0;
}