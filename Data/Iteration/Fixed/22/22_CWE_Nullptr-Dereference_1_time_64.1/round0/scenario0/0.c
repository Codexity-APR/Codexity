List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 18.
 Example: 
  17. void addClient(char name[], int birthday, int landline, int cellphone) {
  18.     clientdata *newClient = (clientdata*) malloc(sizeof(clientdata));
  19.     strcpy(newClient->name, name);
          ^
  20.     newClient->birthday = birthday;
  21.     newClient->landline = landline;


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
clientdata *head = NULL; // Global variable to keep track of the head of the linked list
void addClient(char name[], int birthday, int landline, int cellphone) {
    clientdata *newClient = (clientdata*) malloc(sizeof(clientdata));
    strcpy(newClient->name, name);
    newClient->birthday = birthday;
    newClient->landline = landline;
    newClient->cellphone = cellphone;
    newClient->clientnum = clientcounter;
    newClient->next = NULL;
    if (head == NULL) {
        head = newClient;
    } else {
        clientdata *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClient;
    }
    clientcounter++;
}
void freeMemory() {
    clientdata *temp = head;
    while (temp != NULL) {
        clientdata *nextClient = temp->next;
        free(temp);
        temp = nextClient;
    }
    head = NULL;
    clientcounter = 0;
}
int main() {
    // Your code here
    return 0;
}