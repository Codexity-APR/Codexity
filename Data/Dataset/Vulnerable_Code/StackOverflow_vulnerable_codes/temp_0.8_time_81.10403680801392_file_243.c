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
} clientdata;

clientdata *addClient(clientdata *head, char name[], int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata *)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter++;
    newClient->next = head;
    return newClient;
}

void printClients(clientdata *head) {
    clientdata *current = head;
    while (current != NULL) {
        printf("Client Number: %d\n", current->clientnum);
        printf("Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("--------------------\n");
        current = current->next;
    }
}

void freeClients(clientdata *head) {
    clientdata *current = head;
    while (current != NULL) {
        clientdata *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    clientdata *head = NULL;
    
    // Test addClient function
    head = addClient(head, "John Doe", 1980, 1234567, 987654321);
    head = addClient(head, "Jane Smith", 1990, 2345678, 876543210);
    
    // Test printClients function
    printClients(head);
    
    // Test freeClients function
    freeClients(head);
    head = NULL;
    
    return 0;
}