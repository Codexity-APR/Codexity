#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPHA 28
typedef struct {
    int yourpass;
    char letters[ALPHA];
    int temp;
    long long skips;
} password;
// Declare functions
void FindVariations(int passlength, int strength, password *combo, long long j, int x);
long long magical(password *combo, int passlength);
int main() {
    int i, j, d, cases, passlength;
    long long strength;
    password* combo;
    // Enter number of passwords to compute
    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
        // Enter number of strings/length of password
        scanf("%d", &passlength);
        // Allocate memory for combo elements
        combo = malloc(passlength * sizeof(password));
        if (combo == NULL) {
            printf("Memory allocation failed.\n");
            return 1; // Exit the program with an error code
        }
        // Input the letters for password
        for (j = 0; j < passlength; j++) {
            combo[j].yourpass = 0; // Initialize yourpass to avoid uninitialized value
            scanf(" %c", &combo[j].letters[0]); // Read a single character into letters array
        }
        // Input the strength of password
        scanf("%lld", &strength);
        // Calculate and print the number of possible variations
        printf("%lld\n", magical(combo, passlength));
        // Free allocated memory
        free(combo);
    }
    return 0;
}
void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // Code for finding variations
}
long long magical(password *combo, int passlength) {
    long long totalVariations = 1;
    for (int i = 0; i < passlength; i++) {
        totalVariations *= combo[i].yourpass;
    }
    return totalVariations;
}