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
        sprintf(creatures[i].name, "Creature %d", i + 1);
    }

    // Print the created creatures
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature ID: %d, Name: %s\n", creatures[i].id, creatures[i].name);
    }

    // Free the allocated memory
    free(creatures);

    return 0;
}