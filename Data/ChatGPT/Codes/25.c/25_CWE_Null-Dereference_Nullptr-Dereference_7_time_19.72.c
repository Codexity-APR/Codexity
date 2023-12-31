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
        creatures[i].id = i;  // Assign the ID of the creature
        sprintf(creatures[i].name, "Creature %d", i);  // Assign the name of the creature using a formatted string
    }

    // Print the details of each creature
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature %d: ID = %d, Name = %s\n", i, creatures[i].id, creatures[i].name);
    }

    free(creatures);  // Free the allocated memory

    return 0;
}