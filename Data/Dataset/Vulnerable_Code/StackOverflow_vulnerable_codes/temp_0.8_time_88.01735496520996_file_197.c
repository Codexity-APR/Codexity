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
    clientdata* newClient = (clientdata*) malloc(sizeof(clientdata));
    strncpy(newClient->name, name, 254);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientnum;
    newClient->next = NULL;
    return newClient;
}

void addClient(clientdata** head, char name[], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = createClient(name, birthday, landline, cellphone, clientnum);
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

void deleteClient(clientdata** head, int clientnum) {
    clientdata* current = *head;
    clientdata* prev = NULL;
    while (current != NULL) {
        if (current->clientnum == clientnum) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            clientcounter--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void displayClients(clientdata* head) {
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

void freeClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        clientdata* temp = current;
        current = current->next;
        free(temp);
    }
    clientcounter = 0;
}

int main() {
    clientdata* head = NULL;
    
    // Add clients
    addClient(&head, "John Doe", 19900101, 1234567890, 9876543210, 1);
    addClient(&head, "Jane Smith", 19951020, 9876543210, 1234567890, 2);
    addClient(&head, "Mike Johnson", 19871205, 5555555555, 4444444444, 3);
    
    // Display clients
    displayClients(head);
    
    // Delete a client
    deleteClient(&head, 2);
    
    // Display clients after deletion
    displayClients(head);
    
    // Free memory
    freeClients(head);
    
    return 0;
}