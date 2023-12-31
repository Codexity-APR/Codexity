List of vulnerabilities detected: 
Error: Null Dereference   pointer `creatures` last assigned on line 12 could be null and is dereferenced at line 16, column 9.
 Example: 
  14.     // Create and store new creature structs
  15.     for (int i = 0; i < num_creatures; i++) {
  16.         creatures[i].id = i + 1;
              ^
  17.         printf("Enter name for creature %d: ", i + 1);
  18.         scanf("%s", creatures[i].name);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 12.
 Example: 
  14.     // Create and store new creature structs
  15.     for (int i = 0; i < num_creatures; i++) {
  16.         creatures[i].id = i + 1;
              ^
  17.         printf("Enter name for creature %d: ", i + 1);
  18.         scanf("%s", creatures[i].name);

 Error type: CWE-119 at line: 18. Error message: scanf() without field width limits can crash with huge input data.


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
        creatures[i].id = i + 1;
        printf("Enter name for creature %d: ", i + 1);
        scanf("%s", creatures[i].name);
    }
    // Display the created creatures
    printf("\nCreatures created:\n");
    for (int i = 0; i < num_creatures; i++) {
        printf("Creature %d: ID=%d, Name=%s\n", i + 1, creatures[i].id, creatures[i].name);
    }
    // Free the allocated memory
    free(creatures);
    return 0;
}