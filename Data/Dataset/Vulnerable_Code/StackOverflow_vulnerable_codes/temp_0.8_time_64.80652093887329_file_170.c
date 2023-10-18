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

    // enter number of passwords to compute
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {

        // enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo->letters[j]);
        }

        // input the strength of password
        scanf("%lld", &strength);

        // call FindVariations function
        FindVariations(passlength, strength, combo, 0, 0);

        // call magical function and print the result
        printf("%lld\n", magical(combo, passlength));
    }

    free(combo);
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (x == passlength) {
        combo->skips = j;
        return;
    }

    FindVariations(passlength, strength, combo, j * 2, x + 1);

    if (x == 0) {
        combo->temp = 1;
        FindVariations(passlength, strength, combo, j * 2 + 1, x + 1);
    } else if (x > 0 && combo->temp < strength) {
        combo->temp++;
        FindVariations(passlength, strength, combo, j * 2 + 1, x + 1);
    }
}

long long magical(password *combo, int passlength) {
    long long result = 1;
    int i;

    for (i = 0; i < passlength; i++) {
        result *= combo->letters[i] - 'a' + 1;
    }

    return result - combo->skips;
}