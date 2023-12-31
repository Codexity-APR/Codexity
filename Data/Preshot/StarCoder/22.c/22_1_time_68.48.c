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

clientdata *clientlist = NULL;

void addClient(char *name, int birthday, int landline, int cellphone){
    clientdata *newclient = (clientdata *) malloc(sizeof(clientdata));
    if(newclient == NULL){ //check if memory allocation was successful
        printf("Error: Memory allocation failed\n");
        return;
    }
    strcpy(newclient->name, name);
    newclient->birthday = birthday;
    newclient->landline = landline;
    newclient->cellphone = cellphone;
    newclient->clientnum = clientcounter;
    newclient->next = clientlist;
    clientlist = newclient;
    clientcounter++;
}

void deleteClient(int clientnum){
    clientdata *current = clientlist;
    clientdata *previous = NULL;
    while(current!= NULL){
        if(current->clientnum == clientnum){
            if(previous == NULL){
                clientlist = current->next;
            }
            else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void editClient(int clientnum, char *name, int birthday, int landline, int cellphone){
    clientdata *current = clientlist;
    while(current!= NULL){
        if(current->clientnum == clientnum){
            strcpy(current->name, name);
            current->birthday = birthday;
            current->landline = landline;
            current->cellphone = cellphone;
            return;
        }
        current = current->next;
    }
}

void printClient(int clientnum){
    clientdata *current = clientlist;
    while(current!= NULL){
        if(current->clientnum == clientnum){
            printf("Name: %s\nBirthday: %d\nLandline: %d\nCellphone: %d\n", current->name, current->birthday, current->landline, current->cellphone);
            return;
        }
        current = current->next;
    }
    printf("Error: Client not found\n");
}

void printAllClients(){
    clientdata *current = clientlist;
    while(current!= NULL){
        printf("Name: %s\nBirthday: %d\nLandline: %d\nCellphone: %d\n", current->name, current->birthday, current->landline, current->cellphone);
        current = current->next;
    }
}