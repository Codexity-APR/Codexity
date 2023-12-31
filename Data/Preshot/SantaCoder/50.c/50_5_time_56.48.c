#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 49

struct person {
    char name[MAX_NAME_LEN + 1];
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
    fgets(p.name, MAX_NAME_LEN + 1, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%d", &p.age);
    getchar(); // to clear the newline character left behind by scanf()
    return p;
}