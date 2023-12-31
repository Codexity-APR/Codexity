List of vulnerabilities detected: 
Error: Null Dereference   pointer `creatures` last assigned on line 12 could be null and is dereferenced at line 24, column 9.
 Example: 
  22.         scanf("%s", new_creature.name);
  23.         
  24.         creatures[i] = new_creature;
              ^
  25.     }
  26.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 12.
 Example: 
  22.         scanf("%s", new_creature.name);
  23.         
  24.         creatures[i] = new_creature;
              ^
  25.     }
  26.

 Error type: CWE-119 at line: 22. Error message: scanf() without field width limits can crash with huge input data.


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