#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 49

struct person {
    char name[MAX_NAME_LENGTH + 1];  // Add 1 to account for null terminator
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
    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%49s", p.name);  // Limit input to 49 characters to prevent buffer overflow
    printf("Enter age: ");
    scanf("%d", &p.age);
    return p;
}