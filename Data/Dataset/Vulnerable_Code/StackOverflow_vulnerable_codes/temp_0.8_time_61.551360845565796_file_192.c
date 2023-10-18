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

clientdata* createClient(char name[254], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = (clientdata*) malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientnum;
    newClient->next = NULL;
    return newClient;
}

void addClient(clientdata** clientList, char name[254], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = createClient(name, birthday, landline, cellphone, clientnum);
    if (*clientList == NULL) {
        *clientList = newClient;
    } else {
        clientdata* current = *clientList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
    clientcounter++;
}

void deleteClients(clientdata** clientList) {
    clientdata* current = *clientList;
    while (current != NULL) {
        clientdata* temp = current;
        current = current->next;
        free(temp);
    }
    *clientList = NULL;
    clientcounter = 0;
}

int main() {
    clientdata* clientList = NULL;
    
    // Example usage
    addClient(&clientList, "John Doe", 1985, 1234567, 987654321, 1);
    addClient(&clientList, "Jane Smith", 1990, 9876543, 123456789, 2);
    
    // Rest of the code...
    
    deleteClients(&clientList);
    
    return 0;
}