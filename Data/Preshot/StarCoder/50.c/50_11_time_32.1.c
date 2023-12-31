#include <stdio.h>

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
    struct person p = {0};
    printf("Enter name: ");
    if (fgets(p.name, MAX_NAME_LENGTH, stdin) == NULL) {
        printf("Error reading name\n");
        return p;
    }
    p.name[strcspn(p.name, "\n")] = '\0'; // remove trailing newline
    printf("Enter age: ");
    if (scanf("%d", &p.age) != 1) {
        printf("Error reading age\n");
        return p;
    }
    return p;
}