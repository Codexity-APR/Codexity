#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct creature {
    int id;
    char name[12];
};

int main() {
    int num_creatures = 100;
    struct creature *creatures = malloc(sizeof(struct creature) * num_creatures);
    
    if (creatures == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    
    for (int i = 0; i < num_creatures; i++) {
        struct creature new_creature;
        printf("Enter the ID for creature %d: ", (i + 1));
        scanf("%d", &new_creature.id);
        printf("Enter the name for creature %d: ", (i + 1));
        scanf("%11s", new_creature.name);
        creatures[i] = new_creature;
    }
    
    printf("=== Created Creatures ===\n");
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature %d:\n", (i + 1));
        printf("ID: %d\n", creatures[i].id);
        printf("Name: %s\n", creatures[i].name);
        printf("========================\n");
    }
    
    free(creatures);
    return 0;
}