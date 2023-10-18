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
        sprintf(creatures[i].name, "Creature %d", i + 1);  // Set the name of the creature
    }

    // Print the details of each creature
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature ID: %d\n", creatures[i].id);
        printf("Creature Name: %s\n", creatures[i].name);
        printf("---------------------\n");
    }

    // Free the memory allocated for the creatures array
    free(creatures);

    return 0;
}