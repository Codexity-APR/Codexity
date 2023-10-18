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
        creatures[i].id = i + 1;  // Assign unique ID to each creature
        sprintf(creatures[i].name, "Creature %d", i + 1);  // Assign a name to each creature
    }

    // Print the details of each creature
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature ID: %d\n", creatures[i].id);
        printf("Creature Name: %s\n", creatures[i].name);
        printf("\n");
    }

    free(creatures);  // Free the allocated memory

    return 0;
}