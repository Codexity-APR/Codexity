#include <stdio.h>
#include <stdlib.h>

struct creature {
    int id;
    char name[12];
};

int main() {
    int num_creatures = 100;  // Define the number of creatures to create and store

    struct creature *creatures = malloc(sizeof(struct creature) * num_creatures);  // Allocate memory for the creatures array

    // Create and store new creature structs
    for (int i = 0; i < num_creatures; i++) {
        creatures[i].id = i + 1;
        printf("Enter the name for creature %d: ", i + 1);
        fgets(creatures[i].name, sizeof(creatures[i].name), stdin);
    }

    // Print the stored creatures
    printf("Creatures:\n");
    for (int i = 0; i < num_creatures; i++) {
        printf("ID: %d, Name: %s", creatures[i].id, creatures[i].name);
    }

    // Free the allocated memory
    free(creatures);

    return 0;
}