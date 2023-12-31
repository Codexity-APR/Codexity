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

clientdata* createClient(char name[254], int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter++;
    newClient->next = NULL;
    return newClient;
}

clientdata* addClient(clientdata* head, clientdata* newClient) {
    if (head == NULL) {
        head = newClient;
    } else {
        clientdata* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    return head;
}

int main() {
    clientdata* head = NULL;
    // Example usage
    head = addClient(head, createClient("John Doe", 19900101, 1234567, 9876543));
    head = addClient(head, createClient("Jane Smith", 19851212, 2345678, 8765432));

    // Rest of the code...

    return 0;
}