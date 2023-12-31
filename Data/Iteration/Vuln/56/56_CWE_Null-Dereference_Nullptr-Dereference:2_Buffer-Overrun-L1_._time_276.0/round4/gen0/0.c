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
    int i, j, cases, passlength;
    long long strength;
    password* combo = NULL;

    // enter number of passwords to compute
    scanf("%d", &cases);
    combo = malloc(cases * sizeof(password));

    for (i = 0; i < cases; i++) {
        // enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo[i].letters[j]);
        }

        // enter the strength of password
        scanf("%lld", &strength);

        // find variations and output the result
        FindVariations(passlength, strength, &combo[i], 0, 0);
        printf("%lld\n", magical(&combo[i], passlength));
    }

    free(combo); // free the allocated memory
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (j == passlength) {
        combo->temp = 0;
        x++;
        return;
    }

    combo->letters[j] = 'a';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo->letters[j] = 'b';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo->letters[j] = 'c';
    FindVariations(passlength, strength, combo, j + 1, x);

    combo->temp++;
    if (combo->temp == strength)
        return;

    combo->letters[j] = 'A';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo->letters[j] = 'B';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo->letters[j] = 'C';
    FindVariations(passlength, strength, combo, j + 1, x);
}

long long magical(password *combo, int passlength) {
    long long count = 1;
    int i;
    for (i = 0; i < passlength; i++) {
        count *= combo->temp + 1;
    }
    return count;
}