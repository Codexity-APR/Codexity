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

clientdata *head = NULL; // Initialize head pointer to NULL

void add_client(char *name, int birthday, int landline, int cellphone){ 
    clientdata *new_client = malloc(sizeof(clientdata)); // Allocate memory for new client
    strcpy(new_client->name, name); // Copy name to new client's name field
    new_client->birthday = birthday; // Set new client's birthday
    new_client->landline = landline; // Set new client's landline
    new_client->cellphone = cellphone; // Set new client's cellphone number
    new_client->clientnum = ++clientcounter; // Set new client's unique number
    new_client->next = head; // Set new client's next pointer to head
    head = new_client; // Update head pointer to new client
}