List of vulnerabilities detected: 
Error: Buffer Overrun L1   Offset added: 254 Size: 40 by call to `createClient`.
 Example: 
  65. int main() {
  66.     clientdata* head = NULL;
  67.     clientdata* client1 = createClient("John", 1990, 1234567, 987654321);
                                ^
  68.     clientdata* client2 = createClient("Anna", 1985, 7654321, 123456789);
  69.     addClient(&head, client1);


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int clientcounter = 0;
typedef struct client {
    char name[255];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client* next;
} clientdata;
clientdata* createClient(const char* name, int birthday, int landline, int cellphone) {
    clientdata* newClient = (clientdata*)malloc(sizeof(clientdata));
    if (newClient != NULL) {
        strncpy(newClient->name, name, sizeof(newClient->name) - 1);
        newClient->name[sizeof(newClient->name) - 1] = '\0';
        newClient->birthday = birthday;
        newClient->landline = landline;
        newClient->cellphone = cellphone;
        newClient->clientnum = clientcounter++;
        newClient->next = NULL;
    }
    return newClient;
}
void addClient(clientdata** head, clientdata* newClient) {
    if (*head == NULL) {
        *head = newClient;
    }
    else {
        clientdata* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClient;
    }
}
void printClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Birthday: %d\n", current->birthday);
        printf("Landline: %d\n", current->landline);
        printf("Cellphone: %d\n", current->cellphone);
        printf("Client Number: %d\n", current->clientnum);
        printf("\n");
        current = current->next;
    }
}
void freeClients(clientdata* head) {
    clientdata* current = head;
    while (current != NULL) {
        clientdata* next = current->next;
        free(current);
        current = next;
    }
}
int main() {
    clientdata* head = NULL;
    clientdata* client1 = createClient("John", 1990, 1234567, 987654321);
    clientdata* client2 = createClient("Anna", 1985, 7654321, 123456789);
    addClient(&head, client1);
    addClient(&head, client2);
    printClients(head);
    freeClients(head);
    return 0;
}