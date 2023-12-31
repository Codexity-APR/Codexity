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

clientdata* add_client(clientdata* head, char* name, int birthday, int landline, int cellphone) {
    clientdata* new_client = (clientdata*)malloc(sizeof(clientdata));
    strcpy(new_client->name, name);
    new_client->birthday = birthday;
    new_client->landline = landline;
    new_client->cellphone = cellphone;
    new_client->clientnum = clientcounter++;
    new_client->next = head;
    return new_client;
}