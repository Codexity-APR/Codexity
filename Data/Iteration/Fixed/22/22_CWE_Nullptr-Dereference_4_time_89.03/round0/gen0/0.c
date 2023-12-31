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

clientdata* createClient(char name[254], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* client = (clientdata*)malloc(sizeof(clientdata));
    strcpy(client->name, name);
    client->birthday = birthday;
    client->landline = landline;
    client->cellphone = cellphone;
    client->clientnum = clientnum;
    client->next = NULL;
    return client;
}

void addClient(clientdata** head, clientdata* newClient) {
    if (*head == NULL) {
        *head = newClient;
    } else {
        clientdata* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    clientcounter++;
}

void displayClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        printf("Client Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("Client Number: %d\n", current->clientnum);
        printf("\n");
        current = current->next;
    }
}

void freeMemory(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        clientdata* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    clientdata* clients = NULL;

    clientdata* client1 = createClient("John Doe", 19900101, 1234567, 987654321, 1);
    addClient(&clients, client1);

    clientdata* client2 = createClient("Jane Smith", 19901231, 2345678, 876543210, 2);
    addClient(&clients, client2);

    displayClients(clients);

    freeMemory(clients);

    return 0;
}