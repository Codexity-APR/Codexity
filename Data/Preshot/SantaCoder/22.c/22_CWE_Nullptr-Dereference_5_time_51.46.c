#include <stdlib.h>
#include <string.h>

int clientcounter = 0;

typedef struct client{
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client *next; 
}clientdata;

clientdata* addClient(clientdata *head, char name[], int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata*)malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter++;
    newClient->next = NULL;
    if(head == NULL) {
        head = newClient;
    } else {
        clientdata *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClient;
    }
    return head;
}