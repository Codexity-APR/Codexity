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

clientdata* createClient(char name[], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientnum;
    newClient->next = NULL;
    return newClient;
}

void addClient(clientdata** head, clientdata* newClient) {
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

void printClients(clientdata* head) {
    clientdata* temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Birthday: %d\n", temp->birthday);
        printf("Landline: %d\n", temp->landline);
        printf("Cellphone: %d\n", temp->cellphone);
        printf("Client Number: %d\n", temp->clientnum);
        printf("\n");
        temp = temp->next;
    }
}

void deleteClients(clientdata** head) {
    clientdata* current = *head;
    clientdata* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
    clientcounter = 0;
}

int main() {
    clientdata* head = NULL;
    
    clientdata* client1 = createClient("John Doe", 1980, 1234567, 987654321, 1);
    addClient(&head, client1);
    
    clientdata* client2 = createClient("Jane Smith", 1990, 9876543, 123456789, 2);
    addClient(&head, client2);
    
    printClients(head);
    
    deleteClients(&head);
    
    return 0;
}