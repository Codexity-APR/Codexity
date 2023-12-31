#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 49

struct person {
    char name[MAX_NAME_LENGTH + 1];
    int age;
};

struct person getInput(void);

int main(void) {
    struct person users[3];

    for (int i = 0; i < 3; i++) {
        users[i] = getInput();
    }

    for (int i = 0; i < 3; i++) {
        printf("Name: %s\nAge: %d\n", users[i].name, users[i].age);
    }

    return 0;
}

struct person getInput(void) {
    struct person p;

    printf("Enter name (max 50 characters): ");
    if (fgets(p.name, sizeof p.name, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input.\n");
        exit(EXIT_FAILURE);
    }

    // Remove trailing newline character
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Enter age: ");
    if (scanf("%d", &p.age) != 1) {
        fprintf(stderr, "Error: Invalid input for age.\n");
        exit(EXIT_FAILURE);
    }

    // Flush the input buffer to consume the newline character
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return p;
}