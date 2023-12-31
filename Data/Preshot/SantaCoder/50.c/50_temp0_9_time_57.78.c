#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

struct person userInput(void);

int main(void) {
    struct person users[3];

    for (int i = 0; i < 3; i++) {
        users[i] = userInput();
    }

    for (int i = 0; i < 3; i++) {
        printf("Name: %s\nAge: %d\n", users[i].name, users[i].age);
    }

    return 0;
}

struct person userInput(void) {
    struct person p;
    printf("Enter name: ");
    fgets(p.name, MAX_NAME_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; // remove trailing newline character
    printf("Enter age: ");
    scanf("%d", &p.age);
    getchar(); // consume the newline character left in the input buffer
    return p;
}