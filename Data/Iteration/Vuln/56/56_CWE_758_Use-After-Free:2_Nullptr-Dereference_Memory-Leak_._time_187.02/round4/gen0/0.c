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
// declare functions
void FindVariations(int passlength, int strength, password *combo, long long j, int x);
long long magical(password *combo, int passlength);
int main() {
    int i, j, d, cases, passlength;
    long long strength;
    password* combo;
    // enter number of passwords to compute
    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
        // enter number of strings/length of password
        scanf("%d", &passlength);
        // allocate memory for combo
        combo = malloc(passlength * sizeof(password));
        if (combo == NULL) {
            printf("Memory allocation failed.\n");
            return 1; // Exit with an error code
        }
        // input the letters for password
        for (j = 0; j < passlength; j++) {
            combo[j].letters[0] = '\0'; // Initialize the letters array
            scanf(" %c", &combo[j].letters[0]);
        }
        // enter the strength of the password
        scanf("%lld", &strength);
        // call the magical function to calculate the number of variations
        long long variations = magical(combo, passlength);
        // calculate the number of skips
        long long skips = strength / variations;
        // print the result
        printf("%lld\n", skips);
        // free memory
        free(combo);
    }
    return 0;
}
void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // implement the function to find variations of password
}
long long magical(password *combo, int passlength) {
    // implement the magical function
    return 0;
}