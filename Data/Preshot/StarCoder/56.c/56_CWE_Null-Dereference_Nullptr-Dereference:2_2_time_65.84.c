#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &passlength);

        combo = malloc(passlength * sizeof(password));
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo[j].letters[j]);
        }

        scanf("%lld", &strength);
        FindVariations(passlength, strength, combo, 0, 0);
        printf("%lld\n", magical(combo, passlength));
        free(combo);
    }

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    int i;

    if (strength == 0) {
        for (i = 0; i < passlength; i++) {
            printf("%c", combo[i].letters[i]);
        }
        printf("\n");
        return;
    }

    for (i = x; i < passlength; i++) {
        if (combo[i].yourpass == 0) {
            combo[i].yourpass = 1;
            combo[i].temp = strength;
            combo[i].skips = 0;
            if (i == 0) {
                combo[i].skips = 1;
            }
            if (i == passlength - 1) {
                combo[i].skips = 1;
            }
            FindVariations(passlength, strength - 1, combo, j + 1, i + 1);
            combo[i].yourpass = 0;
            combo[i].temp = 0;
            combo[i].skips = 0;
        }
    }
}

long long magical(password *combo, int passlength) {
    int i;
    long long k = 0;

    for (i = 0; i < passlength; i++) {
        if (combo[i].yourpass == 1) {
            k++;
        }
    }

    return k;
}