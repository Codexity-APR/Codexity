List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 16.
 Example: 
  15. clientdata* createClient(char name[], int birthday, int landline, int cellphone, int clientnum) {
  16.     clientdata* newClient = (clientdata*) malloc(sizeof(clientdata));
  17.     strcpy(newClient->name, name);
          ^
  18.     newClient->birthday = birthday;
  19.     newClient->landline = landline;


#include <stdlib.h>
#include <string.h>
int clientcounter = 0;
typedef struct client {
    char name[254];
    int birthday;
    int landline;
    int cellphone;
    int clientnum;
    struct client *next;
} clientdata;
clientdata* createClient(char name[], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = (clientdata*) malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientnum;
    newClient->next = NULL;
    return newClient;
}
void addClient(clientdata** head, char name[], int birthday, int landline, int cellphone, int clientnum) {
    clientdata* newClient = createClient(name, birthday, landline, cellphone, clientnum);
    if (*head == NULL) {
        *head = newClient;
    } else {
        clientdata* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClient;
    }
    clientcounter++;
}
void printClients(clientdata* head) {
    clientdata* temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Birthday: %d\n", temp->birthday);
        printf("Landline: %d\n", temp->landline);
        printf("Cellphone: %d\n", temp->cellphone);
        printf("Client number: %d\n", temp->clientnum);
        printf("----------------------------------------\n");
        temp = temp->next;
    }
}
void freeClients(clientdata* head) {
    clientdata* temp = head;
    while (temp != NULL) {
        clientdata* prev = temp;
        temp = temp->next;
        free(prev);
    }
}
int main() {
    clientdata* head = NULL;
    addClient(&head, "John Doe", 19850101, 1234567890, 9876543210, 1);
    addClient(&head, "Jane Smith", 19901215, 9876543210, 1234567890, 2);
    addClient(&head, "Mike Johnson", 19780630, 5555555555, 6666666666, 3);
    printClients(head);
    freeClients(head);
    head = NULL;
    return 0;
}