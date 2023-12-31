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
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < num_creatures; i++) {
        creatures[i].id = i;
        snprintf(creatures[i].name, sizeof(creatures[i].name), "Creature #%d", i);
    }

    for (int i = 0; i < num_creatures; i++) {
        printf("Creature #%d: %s\n", creatures[i].id, creatures[i].name);
    }

    free(creatures);
    return 0;
}