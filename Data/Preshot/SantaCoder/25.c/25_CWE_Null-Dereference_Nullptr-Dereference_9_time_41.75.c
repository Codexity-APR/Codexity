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
        sprintf(creatures[i].name, "creature %d", i); // Use sprintf to format the name string
    }

    // Print the creature structs
    for (int i = 0; i < num_creatures; i++) {
        printf("%d: %s\n", creatures[i].id, creatures[i].name);
    }

    free(creatures); // free the allocated memory
    return 0;
}