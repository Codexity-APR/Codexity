#include <stdio.h>
#include <stdlib.h>

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
    if (fgets(p.name, sizeof(p.name), stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }
    p.name[strcspn(p.name, "\n")] = '\0';
    printf("Enter age: ");
    if (scanf("%d", &p.age) != 1) {
        fprintf(stderr, "Error: Invalid input for age!\n");
        exit(EXIT_FAILURE);
    }
    return p;
}