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
        creatures[i].id = i;
        // Get the name of the creature from the user
        printf("Enter name for creature %d: ", i);
        scanf("%s", creatures[i].name);
    }

    // Print the information of all creatures
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature %d - ID: %d, Name: %s\n", i, creatures[i].id, creatures[i].name);
    }

    // Free the allocated memory
    free(creatures);

    return 0;
}