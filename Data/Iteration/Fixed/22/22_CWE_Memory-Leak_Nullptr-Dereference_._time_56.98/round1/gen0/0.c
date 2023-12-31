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

clientdata* createClient(char name[254], int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    if (newClient != NULL) {
        strcpy(newClient->name, name);
        newClient->birthday = birthday;
        newClient->landline = landline;
        newClient->cellphone = cellphone;
        newClient->clientnum = clientcounter++;
        newClient->next = NULL;
    }
    return newClient;
}

clientdata* addClient(clientdata* head, clientdata* newClient) {
    if (head == NULL) {
        head = newClient;
    } else {
        clientdata* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    return head;
}

void freeClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        clientdata* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    clientdata* head = NULL;
    // Example usage
    head = addClient(head, createClient("John Doe", 19900101, 1234567, 9876543));
    head = addClient(head, createClient("Jane Smith", 19851212, 2345678, 8765432));
    // Rest of the code...

    // Free allocated memory
    freeClients(head);

    return 0;
}