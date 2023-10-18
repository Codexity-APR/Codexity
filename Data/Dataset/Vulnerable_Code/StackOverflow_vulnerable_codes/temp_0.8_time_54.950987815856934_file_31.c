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
            scanf(" %c", &combo[j].letters);
        }

        // enter strength of password
        scanf("%lld", &strength);

        // call FindVariations function
        FindVariations(passlength, strength, combo, 0, 0);

        // calculate and print the total number of combinations
        long long totalCombinations = magical(combo, passlength);
        printf("%lld\n", totalCombinations);
    }

    free(combo);
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // base case
    if (j == passlength) {
        combo[j].temp = x;
        return;
    }

    int i;
    for (i = 0; i < ALPHA; i++) {
        combo[j].temp = i;
        FindVariations(passlength, strength, combo, j+1, x+1);
    }
}

long long magical(password *combo, int passlength) {
    int i;
    long long totalCombinations = 1;

    for (i = 0; i < passlength; i++) {
        totalCombinations *= combo[i].temp;
    }

    return totalCombinations;
}