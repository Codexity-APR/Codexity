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
    combo = malloc(ALPHA * sizeof(password));
    for (i = 0; i < cases; i++) {
        // Enter number of strings/length of password
        scanf("%d", &passlength);
        // Input the letters for password
        for (j = 0; j < passlength; j++) {
            combo[j].letters[0] = malloc(ALPHA * sizeof(char));
            scanf(" %c", &combo[j].letters[0]);
        }
        // Enter the strength of the password
        scanf("%lld", &strength);
        // Call the magical function to calculate the number of variations
        long long variations = magical(combo, passlength);
        // Check if the strength is within the range of variations
        if (strength <= variations) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        // Free memory for each combo element
        for (j = 0; j < passlength; j++) {
            free(combo[j].letters[0]);
        }
    }
    // Free memory for combo array
    free(combo);
    return 0;
}
void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // Implementation of FindVariations function
    // ...
}
long long magical(password *combo, int passlength) {
    // Implementation of magical function
    // ...
    return 0;
}