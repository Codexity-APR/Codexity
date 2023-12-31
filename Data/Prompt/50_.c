#include <stdio.h>

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
