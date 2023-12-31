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

void FindVariations(int passlength, int strength, password *combo, long long j, int x);
long long magical(password *combo, int passlength);

int main() {
    int i, j, d, cases, passlength;
    long long strength;
    password *combo;

    // enter number of passwords to compute
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {
        // enter number of strings/length of password
        scanf("%d", &passlength);

        combo = malloc(passlength * sizeof(password));
        if (combo == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo[j].letters);
        }

        // enter the strength
        scanf("%lld", &strength);

        // find the variations
        FindVariations(passlength, strength, combo, 0, 0);

        // print the result
        printf("%lld\n", combo[passlength - 1].skips);

        free(combo);
    }

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (j == passlength) {
        combo[passlength - 1].skips++;
        return;
    }

    // check if the letter has been used before
    for (int i = 0; i < j; i++) {
        if (combo[i].yourpass == x) {
            return;
        }
    }

    combo[j].yourpass = x;

    // check for different variations
    for (int k = 0; k < ALPHA - 1; k++) {
        if (combo[j].letters[k] != '\0') {
            combo[j].temp = combo[j].letters[k] - 'a';
            if (strength >= combo[j].temp) {
                FindVariations(passlength, strength - combo[j].temp, combo, j + 1, combo[j].temp);
            }
        }
    }
}

long long magical(password *combo, int passlength) {
    combo[passlength - 1].skips = 0;
    FindVariations(passlength, passlength, combo, 0, 0);
    return combo[passlength - 1].skips;
}