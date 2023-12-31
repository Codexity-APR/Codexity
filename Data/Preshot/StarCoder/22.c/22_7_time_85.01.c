#include <stdlib.h> // need this for realloc
#include <string.h> // need this for memcpy
#include <stdio.h> // need this for printf

int clientcounter = 0; //Global variable since this will be needed in other functions

typedef struct client{
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client *next; 
}clientdata;


clientdata *clientlist = NULL; //Global variable for the linked list

void addClient(char *name, int birthday, int landline, int cellphone){
    clientdata *newclient = malloc(sizeof(clientdata)); //allocate memory for the new client
    if(newclient == NULL){
        printf("Error: Out of memory\n");
        return;
    }
    strcpy(newclient->name, name); //copy the name into the new client
    newclient->birthday = birthday; //copy the birthday into the new client
    newclient->landline = landline; //copy the landline into the new client
    newclient->cellphone = cellphone; //copy the cellphone into the new client
    newclient->clientnum = clientcounter; //copy the client number into the new client
    newclient->next = clientlist; //point the next pointer of the new client to the head of the list
    clientlist = newclient; //point the head of the list to the new client
    clientcounter++; //increment the client counter
}

void deleteClient(int clientnum){
    if(clientlist == NULL){
        printf("Error: List is empty\n");
        return;
    }
    clientdata *current = clientlist; //set the current client to the head of the list
    clientdata *previous = NULL; //set the previous client to NULL
    while(current!= NULL){ //while the current client is not NULL
        if(current->clientnum == clientnum){ //if the current client number is equal to the client number to delete
            if(previous == NULL){ //if the previous client is NULL
                clientlist = current->next; //point the head of the list to the next client
            }
            else{
                previous->next = current->next; //point the next client of the previous client to the next client of the current client
            }
            free(current); //free the memory of the current client
            return; //return
        }
        previous = current; //set the previous client to the current client
        current = current->next; //set the current client to the next client
    }
    printf("Error: Client not found\n");
}

void editClient(int clientnum, char *name, int birthday, int landline, int cellphone){
    if(clientlist == NULL){
        printf("Error: List is empty\n");
        return;
    }
    clientdata *current = clientlist; //set the current client to the head of the list
    while(current!= NULL){ //while the current client is not NULL
        if(current->clientnum == clientnum){ //if the current client number is equal to the client number to edit
            strcpy(current->name, name); //copy the name into the current client
            current->birthday = birthday; //copy the birthday into the current client
            current->landline = landline; //copy the landline into the current client
            current->cellphone = cellphone; //copy the cellphone into the current client
            return; //return
        }
        current = current->next; //set the current client to the next client
    }
    printf("Error: Client not found\n");
}

void printClient(int clientnum){
    if(clientlist == NULL){
        printf("Error: List is empty\n");
        return;
    }
    clientdata *current = clientlist; //set the current client to the head of the list
    while(current!= NULL){ //while the current client is not NULL
        if(current->clientnum == clientnum){ //if the current client number is equal to the client number to print
            printf("Name: %s\nBirthday: %d\nLandline: %d\nCellphone: %d\n", current->name, current->birthday, current->landline, current->cellphone); //print the client
            return; //return
        }
        current = current->next; //set the current client to the next client
    }
    printf("Error: Client not found\n");
}

void printAllClients(){
    if(clientlist == NULL){
        printf("Error: List is empty\n");
        return;
    }
    clientdata *current = clientlist; //set the current client to the head of the list
    while(current!= NULL){ //while the current client is not NULL
        printf("Name: %s\nBirthday: %d\nLandline: %d\nCellphone: %d\n", current->name, current->birthday, current->landline, current->cellphone); //print the client
        current = current->next; //set the current client to the next client
    }
}