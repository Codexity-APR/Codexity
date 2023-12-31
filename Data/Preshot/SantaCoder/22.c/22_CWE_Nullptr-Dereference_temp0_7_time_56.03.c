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

clientdata *head = NULL; // initialize the head of the linked list to NULL

// function to add a new client to the linked list
void add_client(char name[], int birthday, int landline, int cellphone) {
    clientdata *new_client = (clientdata*) malloc(sizeof(clientdata)); // allocate memory for the new client
    strcpy(new_client->name, name);
    new_client->birthday = birthday;
    new_client->landline = landline;
    new_client->cellphone = cellphone;
    new_client->clientnum = ++clientcounter;
    new_client->next = NULL;
    
    if (head == NULL) { // if the linked list is empty, set the new client as the head
        head = new_client;
    } else { // otherwise, add the new client to the end of the linked list
        clientdata *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_client;
    }
}