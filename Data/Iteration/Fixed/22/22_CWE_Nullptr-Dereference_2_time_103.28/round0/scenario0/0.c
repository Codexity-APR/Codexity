List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 16.
 Example: 
  17. 
  18.     // Set values for the new client
  19.     strcpy(newClient->name, name);
          ^
  20.     newClient->birthday = birthday;
  21.     newClient->landline = landline;


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
clientdata* createClient(char name[], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata)); // Allocate memory for new client
    // Set values for the new client
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
        clientdata* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    clientcounter++;
}
void printClient(clientdata* client) {
    printf("Client Name: %s\n", client->name);
    printf("Birthday: %d\n", client->birthday);
    printf("Landline: %d\n", client->landline);
    printf("Cellphone: %d\n", client->cellphone);
    printf("Client Number: %d\n", client->clientnum);
}
void printAllClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        printClient(current);
        current = current->next;
    }
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
    // Create some clients
    clientdata* client1 = createClient("John Smith", 19900101, 1234567, 9876543, 1);
    clientdata* client2 = createClient("Alice Johnson", 19851225, 2345678, 8765432, 2);
    clientdata* client3 = createClient("Robert Davis", 19780415, 3456789, 7654321, 3);
    // Add clients to the list
    addClient(&head, client1);
    addClient(&head, client2);
    addClient(&head, client3);
    // Print all clients
    printAllClients(head);
    // Free memory
    freeClients(head);
    return 0;
}