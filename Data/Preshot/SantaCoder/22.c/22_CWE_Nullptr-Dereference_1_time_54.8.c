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

clientdata *head = NULL;
clientdata *tail = NULL;

void add_client(char name[], int birthday, int landline, int cellphone){
    clientdata *newclient = (clientdata *) malloc(sizeof(clientdata));
    strcpy(newclient->name, name);
    newclient->birthday = birthday;
    newclient->landline = landline;
    newclient->cellphone = cellphone;
    newclient->clientnum = clientcounter++;
    newclient->next = NULL;

    if(head == NULL){
        head = newclient;
        tail = newclient;
    }
    else{
        tail->next = newclient;
        tail = newclient;
    }
}