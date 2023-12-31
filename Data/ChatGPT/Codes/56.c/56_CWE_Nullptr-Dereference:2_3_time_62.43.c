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

        // input the strength of password
        scanf("%lld", &strength);

        // calculate the variations
        FindVariations(passlength, strength, combo, 0, 0);

        // print the total number of variations
        printf("%lld\n", magical(combo, passlength));
    }

    free(combo); // free the memory allocated for combo

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (j == passlength) {
        combo[x].letters[passlength] = '\0';
        combo[x].yourpass = 0;
        combo[x].temp = 0;
    } else {
        if (combo[0].letters[j] == '?') {
            for (combo[x].letters[j] = 'a'; combo[x].letters[j] <= 'z'; combo[x].letters[j]++) {
                FindVariations(passlength, strength, combo, j + 1, x);
            }
            combo[x].letters[j] = '?';
        } else {
            FindVariations(passlength, strength, combo, j + 1, x);
        }
    }
}

long long magical(password *combo, int passlength) {
    long long result = 0;

    for (int i = 0; i < passlength; i++) {
        combo[i].skips = 1;
        combo[i].temp = 1;

        for (int j = i - 1; j >= 0; j--) {
            if (combo[j].letters[i] == combo[i].letters[i]) {
                combo[i].skips += combo[j].skips;
            }
        }

        combo[i].temp = combo[i].skips;
        result += combo[i].temp;
    }

    return result;
}