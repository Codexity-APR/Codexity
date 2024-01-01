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

clientdata *head = NULL; // Initialize the head of the linked list to NULL

// Function to add a new client to the linked list
void add_client(char name[], int birthday, int landline, int cellphone) {
    clientdata *new_client = (clientdata*) malloc(sizeof(clientdata)); // Allocate memory for the new client
    strcpy(new_client->name, name); // Copy the name to the new client
    new_client->birthday = birthday; // Set the birthday of the new client
    new_client->landline = landline; // Set the landline number of the new client
    new_client->cellphone = cellphone; // Set the cellphone number of the new client
    new_client->clientnum = ++clientcounter; // Set the client number of the new client and increment the global counter
    new_client->next = head; // Set the next pointer of the new client to the current head
    head = new_client; // Set the head to the new client
}

// Function to print all clients in the linked list
void print_clients() {
    clientdata *current = head; // Start at the head of the linked list
    while (current != NULL) { // Loop through all clients in the linked list
        printf("Client %d:\n", current->clientnum); // Print the client number
        printf("Name: %s\n", current->name); // Print the name of the client
        printf("Birthday: %d\n", current->birthday); // Print the birthday of the client
        printf("Landline: %d\n", current->landline); // Print the landline number of the client
        printf("Cellphone: %d\n", current->cellphone); // Print the cellphone number of the client
        current = current->next; // Move to the next client in the linked list
    }
}
