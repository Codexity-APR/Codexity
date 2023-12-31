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
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    // Create and store new creature structs
    for (int i = 0; i < num_creatures; i++) {
        creatures[i].id = i + 1;  // Assign a unique ID to each creature
        printf("Enter the name for creature %d: ", i + 1);
        scanf("%11s", creatures[i].name);  // Limit input to 11 characters to prevent buffer overflow
    }
    // Print the information of all creatures
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature %d\n", creatures[i].id);
        printf("Name: %s\n", creatures[i].name);
        printf("\n");
    }
    free(creatures);  // Free the memory allocated for creatures array
    return 0;
}