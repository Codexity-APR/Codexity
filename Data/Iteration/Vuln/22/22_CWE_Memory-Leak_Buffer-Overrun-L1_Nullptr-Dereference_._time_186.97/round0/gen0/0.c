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

clientdata* createClient(char name[254], int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*) malloc(sizeof(clientdata));
    strncpy(newClient->name, name, 254);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter++;
    newClient->next = NULL;
    return newClient;
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
}

void printClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("Client Number: %d\n", current->clientnum);
        printf("\n");
        current = current->next;
    }
}

int main() {
    clientdata* head = NULL;
    
    clientdata* client1 = createClient("John", 1990, 1234567, 987654321);
    clientdata* client2 = createClient("Anna", 1985, 7654321, 123456789);
    
    addClient(&head, client1);
    addClient(&head, client2);
    
    printClients(head);
    
    return 0;
}