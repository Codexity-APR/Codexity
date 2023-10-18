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
        struct creature new_creature;  // Create a new creature struct
        
        new_creature.id = i;  // Set the id of the new creature
        sprintf(new_creature.name, "Creature %d", i);  // Set the name of the new creature
        
        creatures[i] = new_creature;  // Store the new creature in the creatures array
    }

    // Print the creatures
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature ID: %d, Name: %s\n", creatures[i].id, creatures[i].name);
    }

    free(creatures);  // Free the allocated memory

    return 0;
}