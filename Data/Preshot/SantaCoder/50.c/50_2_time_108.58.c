#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    int valid_input = 0;

    while (!valid_input) {
        printf("Enter name: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0 || isspace(input[0])) {
            printf("Error: Invalid name.\n");
            continue;
        }
        strncpy(p.name, input, sizeof(p.name) - 1);
        p.name[sizeof(p.name) - 1] = '\0';
        valid_input = 1;
    }

    valid_input = 0;

    while (!valid_input) {
        printf("Enter age: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        if (sscanf(input, "%d", &(p.age)) != 1) {
            printf("Error: Invalid age.\n");
            continue;
        }
        if (p.age < 0 || p.age > 150) {
            printf("Error: Age out of range.\n");
            continue;
        }
        valid_input = 1;
    }

    return p;
}