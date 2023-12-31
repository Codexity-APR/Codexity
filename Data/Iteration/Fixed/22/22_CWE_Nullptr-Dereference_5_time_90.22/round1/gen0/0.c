#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int clientcounter = 0;

typedef struct client {
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client* next;
} clientdata;

clientdata* createClient(char name[254], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = malloc(sizeof(clientdata));
    if (newClient != NULL) {
        strcpy(newClient->name, name);
        newClient->birthday = birthday;
        newClient->landline = landline;
        newClient->cellphone = cellphone;
        newClient->clientnum = clientnum;
        newClient->next = NULL;
    }
    return newClient;
}

void addClient(clientdata** head, char name[254], int birthday, int landline, int cellphone) {
    clientdata* newClient = createClient(name, birthday, landline, cellphone, clientcounter);
    if (newClient != NULL) {
        if (*head == NULL) {
            *head = newClient;
        } else {
            clientdata* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newClient;
        }
        clientcounter++;
    }
}

void printClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        printf("Client %d:\n", current->clientnum);
        printf("Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("---------------------\n");
        current = current->next;
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
    // Example usage
    addClient(&head, "John Doe", 19800101, 12345678, 98765432);
    addClient(&head, "Jane Smith", 19901231, 87654321, 12345678);
    addClient(&head, "Bob Johnson", 19780915, 55555555, 66666666);
    printClients(head);
    freeClients(head);
    return 0;
}