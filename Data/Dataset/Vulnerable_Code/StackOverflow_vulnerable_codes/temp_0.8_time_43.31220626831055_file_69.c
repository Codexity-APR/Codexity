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

clientdata *head = NULL; // head pointer to the first client node

void addClient(char name[], int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata *) malloc(sizeof(clientdata)); // allocate memory for new client
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = ++clientcounter;
    newClient->next = NULL;
    
    if (head == NULL) { // if list is empty
        head = newClient;
    } else {
        clientdata *current = head;
        while (current->next != NULL) { // find last node
            current = current->next;
        }
        current->next = newClient; // add new client to the end of the list
    }
}

int main() {
    // example usage of addClient function
    addClient("John Doe", 19900101, 123456789, 987654321);
    addClient("Jane Smith", 19851225, 987654321, 123456789);
    
    // rest of the code
    
    return 0;
}