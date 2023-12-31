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
    char input[50];
    printf("Enter name: ");
    if (fgets(input, 50, stdin)) {
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
        strncpy(p.name, input, 50);
    }
    printf("Enter age: ");
    if (fgets(input, 50, stdin)) {
        p.age = atoi(input);
    }
    return p;
}