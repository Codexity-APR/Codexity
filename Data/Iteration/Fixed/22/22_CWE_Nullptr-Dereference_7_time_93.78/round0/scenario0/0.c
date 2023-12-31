List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 17.
 Example: 
  16. void addClient(clientdata **head, char name[], int birthday, int landline, int cellphone, int clientnum) {
  17.     clientdata *newClient = (clientdata *) malloc(sizeof(clientdata));
  18.     strcpy(newClient->name, name);
          ^
  19.     newClient->birthday = birthday;
  20.     newClient->landline = landline;


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
// Function to add a new client to the list
void addClient(clientdata **head, char name[], int birthday, int landline, int cellphone, int clientnum) {
    clientdata *newClient = (clientdata *) malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientnum;
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
    clientcounter++;
}
// Function to display all clients
void displayClients(clientdata *head) {
    clientdata *temp = head;
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
// Function to free all clients
void freeClients(clientdata **head) {
    clientdata *current = *head;
    clientdata *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
int main() {
    clientdata *head = NULL; // Initialize the head of the client list to NULL
    // Example usage
    addClient(&head, "John Doe", 19900101, 1234567, 9876543, 1);
    addClient(&head, "Jane Smith", 19951231, 2345678, 8765432, 2);
    addClient(&head, "Mike Johnson", 19870915, 3456789, 7654321, 3);
    displayClients(head);
    freeClients(&head);
    return 0;
}