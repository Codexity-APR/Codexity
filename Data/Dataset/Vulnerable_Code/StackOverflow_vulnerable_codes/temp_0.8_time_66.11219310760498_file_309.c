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
            scanf(" %c", &(combo[j].letters));
        }

        // enter the strength
        scanf("%lld", &strength);

        // call the function to find variations
        FindVariations(passlength, strength, combo, 0, 0);

        // print the result
        printf("%lld\n", magical(combo, passlength));
    }

    free(combo);
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (x == passlength) {
        combo[j].skips = combo[j].yourpass / strength;
        combo[j].temp = combo[j].yourpass % strength;
        return;
    }

    int i;
    for (i = 0; i < ALPHA; i++) {
        combo[j].letters[x] = i + 'a';
        FindVariations(passlength, strength, combo, j, x + 1);
        j++;
    }
}

long long magical(password *combo, int passlength) {
    int i;
    long long result = 0;
    for (i = 0; i < passlength; i++) {
        result += combo[i].skips;
        if (combo[i].temp > 0) {
            result++;
            combo[i].temp--;
        }
    }
    return result;
}