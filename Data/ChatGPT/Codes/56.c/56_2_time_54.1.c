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

        // enter the strength of the password
        scanf("%lld", &strength);

        // call the FindVariations function
        FindVariations(passlength, strength, combo, 0, 0);
    }

    // free memory allocated for combo
    free(combo);

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    int i;
    long long k;

    if (x == passlength) {
        // do something with the completed password
        // e.g. print it or perform some other operation
        printf("%s ", combo);

        return;
    }

    for (i = 0; i < ALPHA; i++) {
        for (k = 1; k <= strength; k++) {
            combo[x].letters = combo[j].letters[i];
            FindVariations(passlength, strength, combo, j + 1, x + 1);
        }
    }
}

long long magical(password *combo, int passlength) {
    // implementation of the magical function
    // replace with your own logic

    return 0;
}