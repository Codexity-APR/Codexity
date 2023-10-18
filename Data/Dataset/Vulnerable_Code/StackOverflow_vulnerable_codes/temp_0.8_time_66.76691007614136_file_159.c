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
            scanf(" %c", &(combo->letters[j]));
        }
        combo->letters[passlength] = '\0';

        // enter the strength for password
        scanf("%lld", &strength);

        // calculate variations
        FindVariations(passlength, strength, combo, 0, 0);

        // calculate skips
        combo->skips = magical(combo, passlength);

        printf("Case #%d: %lld\n", i + 1, combo->skips);
    }

    free(combo);

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (x == passlength) {
        combo->yourpass = 1;
        return;
    }

    if (j >= combo->skips) {
        combo->yourpass = 1;
        return;
    }

    int i;
    for (i = 0; i < ALPHA; i++) {
        combo[x].letters[i] = combo->letters[i];
        FindVariations(passlength, strength, combo, j + 1, x + 1);
        if (combo->yourpass == 1)
            return;
        combo[x].letters[i] = combo->letters[j];
    }
}

long long magical(password *combo, int passlength) {
    long long skip = 1;

    int i;
    for (i = 0; i < passlength; i++) {
        int j = 0;
        while (combo->letters[j] != combo->letters[i])
            j++;
        skip *= (j + 1);
    }

    return skip;
}