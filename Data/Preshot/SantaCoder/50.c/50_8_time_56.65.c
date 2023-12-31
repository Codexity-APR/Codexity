#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[50];
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
    fgets(p.name, 50, stdin);
    p.name[strcspn(p.name, "\n")] = 0; // remove the newline character at the end of the string
    printf("Enter age: ");
    char ageStr[10]; // temporary buffer to hold the age string
    fgets(ageStr, 10, stdin);
    p.age = atoi(ageStr);
    return p;
}