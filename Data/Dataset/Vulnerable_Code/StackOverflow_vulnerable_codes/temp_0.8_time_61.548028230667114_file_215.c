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
}clientdata;

void addClient(clientdata **head, char *name, int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata *)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter++;
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

void printClients(clientdata *head) {
    clientdata *temp = head;
    while (temp != NULL) {
        printf("Client Number: %d\n", temp->clientnum);
        printf("Name: %s\n", temp->name);
        printf("Birthday: %d\n", temp->birthday);
        printf("Landline: %d\n", temp->landline);
        printf("Cellphone: %d\n", temp->cellphone);
        printf("-----------------------\n");
        temp = temp->next;
    }
}

int main() {
    clientdata *head = NULL;
    
    // Example usage
    addClient(&head, "John Doe", 19900101, 12345678, 98765432);
    addClient(&head, "Jane Smith", 19951231, 87654321, 12345678);
    
    printClients(head);
    
    return 0;
}