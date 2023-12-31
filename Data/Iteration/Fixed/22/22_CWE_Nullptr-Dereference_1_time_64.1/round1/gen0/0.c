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
        // Handle memory allocation failure
        // You can choose to log an error or take appropriate action
    }
}

void freeMemory() {
    clientdata* temp = head;
    while (temp != NULL) {
        clientdata* nextClient = temp->next;
        free(temp);
        temp = nextClient;
    }
    head = NULL;
    clientcounter = 0;
}

int main() {
    // Your code here
    return 0;
}