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

clientdata* head = NULL;

void addClient(char name[], int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    if (newClient != NULL) {
        strcpy(newClient->name, name);
        newClient->birthday = birthday;
        newClient->landline = landline;
        newClient->cellphone = cellphone;
        newClient->clientnum = clientcounter++;
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
    }
    else {
        // Handle memory allocation failure
        printf("Error: Memory allocation failed!\n");
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