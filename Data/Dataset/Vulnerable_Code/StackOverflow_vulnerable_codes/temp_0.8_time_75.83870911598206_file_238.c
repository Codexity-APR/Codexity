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

        // enter the strength of password
        scanf("%lld", &strength);

        // call the FindVariations function
        FindVariations(passlength, strength, combo, 0, 0);

        // print the number of variations
        printf("%lld\n", combo->skips);
    }

    free(combo);

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    int i;
    char temp;

    if (j == passlength) {
        combo->skips++;
        return;
    }

    for (i = 0; i < ALPHA; i++) {
        if (i < ALPHA - 1) {
            combo->letters[x] = i + 'a';

            // recursive call to FindVariations
            FindVariations(passlength, strength, combo, j + 1, x + 1);
        } else {
            combo->letters[x] = '\0';

            // calculate the strength using the magical function
            combo->temp = magical(combo, passlength);

            // check if the strength is less than or equal to the given strength
            if (combo->temp <= strength) {
                // recursive call to FindVariations
                FindVariations(passlength, strength, combo, j + 1, x + 1);
            }
        }
    }
}

long long magical(password *combo, int passlength) {
    int i, j;
    long long sum = 0;

    for (i = 0; i < passlength - 1; i++) {
        for (j = i + 1; j < passlength; j++) {
            if (combo->letters[i] > combo->letters[j]) {
                sum++;
            }
        }
    }

    return sum;
}