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

clientdata *head = NULL; //Global variable to store the head of the linked list

void addClient(char name[254], int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata*) malloc(sizeof(clientdata)); //Allocate memory for new client
    strncpy(newClient->name, name, sizeof(newClient->name)); //Copy name to newClient->name
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter++;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient; //If linked list is empty, make newClient the head
    } else {
        clientdata *temp = head;
        while (temp->next != NULL) {
            temp = temp->next; //Traverse to the end of the linked list
        }
        temp->next = newClient; //Append newClient to the end
    }
}

int main() {
    // Sample usage of addClient function
    addClient("John Doe", 1980, 1234567, 987654321);
    addClient("Jane Smith", 1995, 9876543, 123456789);

    return 0;
}