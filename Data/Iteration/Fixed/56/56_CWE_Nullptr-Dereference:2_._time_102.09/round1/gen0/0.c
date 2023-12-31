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
    combo = malloc(ALPHA * sizeof(password));
    if (combo == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // enter number of passwords to compute
    scanf("%d", &cases);
    for (i = 0; i < cases; i++) {
        // enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo->letters[j]);
        }

        // input the strength of the password
        scanf("%lld", &strength);

        // compute the password variations
        FindVariations(passlength, strength, combo, 0, 0);

        // compute the total number of variations
        long long totalVariations = magical(combo, passlength);

        // print the total number of variations
        printf("Total variations for password %d: %lld\n", i + 1, totalVariations);
    }

    free(combo);
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (combo == NULL) {
        return;
    }

    if (j == passlength) {
        combo->yourpass = 1;
        return;
    }

    if (x > strength) {
        return;
    }

    combo->letters[j] += 1;
    combo->temp = 1;
    FindVariations(passlength, strength, combo, j + 1, x + 1);
    FindVariations(passlength, strength, combo, j, x + 1);
    combo->letters[j] -= 1;
    combo->temp = 0;
}

long long magical(password *combo, int passlength) {
    if (combo == NULL) {
        return 0;
    }

    long long totalVariations = 1;
    for (int i = 0; i < passlength; i++) {
        if (combo->letters[i] == 0) {
            totalVariations *= combo->temp;
        } else {
            totalVariations *= combo->letters[i];
        }
    }
    return totalVariations;
}