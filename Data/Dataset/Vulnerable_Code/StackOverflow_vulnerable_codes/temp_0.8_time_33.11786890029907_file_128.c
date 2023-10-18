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
        creatures[i].id = i + 1;  // Set the ID of the creature
        
        // Set the name of the creature based on the ID
        snprintf(creatures[i].name, sizeof(creatures[i].name), "Creature %d", creatures[i].id);
    }

    // Print the details of all creatures
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature ID: %d\n", creatures[i].id);
        printf("Creature Name: %s\n", creatures[i].name);
        printf("\n");
    }

    // Free the allocated memory
    free(creatures);

    return 0;
}