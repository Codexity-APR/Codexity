#include <stdio.h>
#include <stdlib.h>

struct creature {
    int id;
    char name[12];
};

int main() {
    int num_creatures = 100;  // Define the number of creatures to create and store

    struct creature *creatures = malloc(sizeof(struct creature) * num_creatures);  // Allocate memory for the creatures array

    if (creatures == NULL) {
        printf("Error: Memory allocation error.\n");
        exit(1);
    }

    // Create and store new creature structs
    for (int i = 0; i < num_creatures; i++) {
        creatures[i].id = i;
        snprintf(creatures[i].name, sizeof(creatures[i].name), "Creature #%d", i);
    }

    // Print the creature names
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature #%d: %s\n", creatures[i].id, creatures[i].name);
    }

    free(creatures);  // Free the memory allocated to the creatures array

    return 0;
}