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

//declare functions
void FindVariations(int passlength, int strength, password *combo, long long j, int x);
long long magical(password *combo, int passlength);

int main() {
    int i, j, d, cases, passlength;
    long long strength;
    password* combo;

    combo = malloc(ALPHA*sizeof(password));

    // enter number of passwords to compute
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {

        //enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo->letters[j]);
        }

        // enter the strength
        scanf("%lld", &strength);

        // find variations and print result
        FindVariations(passlength, strength, combo, 0, 0);
        printf("%lld\n", magical(combo, passlength));
    }

    free(combo);

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (j == passlength) {
        combo->temp++;
        if (combo->temp == strength) {
            combo->temp = 0;
            combo->skips++;
        }
        return;
    }
    if (combo->letters[j] != '?') {
        FindVariations(passlength, strength, combo, j + 1, x * 28 + (combo->letters[j] - 'a' + 1));
    } else {
        for (int k = 0; k < ALPHA - 1; k++) {
            combo->letters[j] = 'a' + k;
            FindVariations(passlength, strength, combo, j + 1, x * 28 + k + 1);
            combo->letters[j] = 0;
        }
    }
}

long long magical(password *combo, int passlength) {
    long long result = combo->skips;
    for (int i = 0; i < passlength; i++) {
        result *= 28;
    }
    return result;
}