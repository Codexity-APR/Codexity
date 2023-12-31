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
        struct creature new_creature;
        
        printf("Enter the ID for creature %d: ", (i + 1));
        scanf("%d", &new_creature.id);
        
        printf("Enter the name for creature %d: ", (i + 1));
        scanf("%s", new_creature.name);
        
        creatures[i] = new_creature;
    }

    // Print the created creatures
    printf("=== Created Creatures ===\n");
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature %d:\n", (i + 1));
        printf("ID: %d\n", creatures[i].id);
        printf("Name: %s\n", creatures[i].name);
        printf("========================\n");
    }

    // Free the allocated memory
    free(creatures);

    return 0;
}