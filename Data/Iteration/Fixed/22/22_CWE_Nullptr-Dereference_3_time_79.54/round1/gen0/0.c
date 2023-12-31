#include <stdlib.h>
#include <string.h>

int clientcounter = 0;

typedef struct client {
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client* next;
} clientdata;

void addClient(clientdata** head, char* name, int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    if (newClient != NULL) {
        strcpy(newClient->name, name);
        newClient->birthday = birthday;
        newClient->landline = landline;
        newClient->cellphone = cellphone;
        newClient->clientnum = clientcounter++;
        newClient->next = NULL;

        if (*head == NULL) {
            *head = newClient;
        } else {
            clientdata* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newClient;
        }
    } else {
        // Handle memory allocation failure
        // You can choose to log an error or take appropriate action
    }
}

void freeClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        clientdata* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    clientdata* head = NULL;

    // Add clients
    addClient(&head, "John Doe", 1980, 1111111, 2222222);
    addClient(&head, "Jane Smith", 1995, 3333333, 4444444);
    addClient(&head, "Bob Johnson", 1975, 5555555, 6666666);

    // Print client details
    clientdata* current = head;
    while (current != NULL) {
        printf("Client Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("Client Number: %d\n\n", current->clientnum);
        current = current->next;
    }

    // Free memory
    freeClients(head);

    return 0;
}