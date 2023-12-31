#include <stdlib.h> // need this for realloc
#include <string.h> // need this for memcpy
#include <stdio.h> // need this for printf

int clientcounter = 0; // Global variable since this will be needed in other functions

typedef struct client {
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client* next;
} clientdata;

clientdata* head = NULL; // head of the linked list

void addClient(char name[], int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata)); // create a new client

    if (newClient != NULL) { // Check if malloc was successful
        strcpy(newClient->name, name);
        newClient->birthday = birthday;
        newClient->landline = landline;
        newClient->cellphone = cellphone;
        newClient->clientnum = clientcounter;
        newClient->next = NULL;

        if (head == NULL) {
            head = newClient;
        }
        else {
            clientdata* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newClient;
        }

        clientcounter++;
    }
    else {
        printf("Error: Failed to allocate memory for new client.\n");
    }
}

void displayClients() {
    clientdata* temp = head;
    while (temp != NULL) {
        printf("Client Number: %d\n", temp->clientnum);
        printf("Name: %s\n", temp->name);
        printf("Birthday: %d\n", temp->birthday);
        printf("Landline: %d\n", temp->landline);
        printf("Cellphone: %d\n", temp->cellphone);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    // Example usage
    addClient("John Doe", 1990, 1234567, 987654321);
    addClient("Jane Smith", 1985, 7654321, 123456789);
    displayClients();

    return 0;
}