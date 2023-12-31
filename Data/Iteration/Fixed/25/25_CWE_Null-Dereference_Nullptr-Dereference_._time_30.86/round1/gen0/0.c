#include <stdio.h>
#include <stdlib.h>

struct creature {
    int id;
    char name[12];
};

int main() {
    int num_creatures = 100;
    struct creature *creatures = malloc(sizeof(struct creature) * num_creatures);
    
    if (creatures == NULL) {
        printf("Failed to allocate memory for creatures.\n");
        return 1;
    }
    
    for (int i = 0; i < num_creatures; i++) {
        creatures[i].id = i + 1;
        sprintf(creatures[i].name, "Creature %d", i + 1);
        printf("Created creature with ID %d and name %s\n", creatures[i].id, creatures[i].name);
    }
    
    free(creatures);
    return 0;
}