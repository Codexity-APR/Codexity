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
            scanf(" %c", &combo[j].letters);
        }

        // enter strength
        scanf("%lld", &strength);

        // calculate variations
        FindVariations(passlength, strength, combo, 0, 0);

        // print the number of variations
        printf("%lld\n", magical(&combo[0], passlength));
    }

    free(combo);
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    int i;

    if (j == passlength - 1) {
        combo[j].yourpass = x;
        return;
    }

    for (i = 0; i <= strength; i++) {
        combo[j].yourpass = i;
        FindVariations(passlength, strength - i, combo, j + 1, i);
    }
}

long long magical(password *combo, int passlength) {
    long long result = 1;
    int i;

    for (i = 0; i < passlength; i++) {
        result *= combo[i].yourpass + 1;
    }

    return result;
}