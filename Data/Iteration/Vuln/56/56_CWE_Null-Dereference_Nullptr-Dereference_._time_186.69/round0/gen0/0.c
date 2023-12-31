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

        // input the strength of password
        scanf("%lld", &strength);

        // calculate and print the number of possible variations
        printf("%lld\n", magical(combo, passlength));

    }

    free(combo); // free allocated memory

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // code for finding variations
}

long long magical(password *combo, int passlength) {
    long long totalVariations = 1;

    for (int i = 0; i < passlength; i++) {
        totalVariations *= combo[i].yourpass;
    }

    return totalVariations;
}