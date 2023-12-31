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

clientdata *clients = NULL; // Pointer to the first client

void add_client(char *name, int birthday, int landline, int cellphone){
    clientcounter++;
    clients = (clientdata*) realloc(clients, clientcounter * sizeof(clientdata));
    strcpy(clients[clientcounter-1].name, name);
    clients[clientcounter-1].birthday = birthday;
    clients[clientcounter-1].landline = landline;
    clients[clientcounter-1].cellphone = cellphone;
    clients[clientcounter-1].clientnum = clientcounter;
    clients[clientcounter-1].next = NULL;
}

int main(){
    add_client("John Doe", 19800101, 1234567, 9876543);
    add_client("Jane Doe", 19850505, 7654321, 3456789);

    // Accessing the first client's name
    printf("First client's name: %s\n", clients[0].name);

    // Accessing the second client's cellphone number
    printf("Second client's cellphone number: %d\n", clients[1].cellphone);

    return 0;
}