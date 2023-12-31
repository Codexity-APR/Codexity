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
            printf("Enter letter for position %d: ", j+1);
            scanf(" %c", &combo[j].letters);
        }

        // input the strength of password
        printf("Enter strength of password: ");
        scanf("%lld", &strength);

        // find variations for the given password
        FindVariations(passlength, strength, combo, 0, 0);
    }

    free(combo); // free allocated memory

    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (j == passlength) {
        combo[j].letters[passlength] = '\0'; // add null terminator
        combo[j].yourpass = x; // assign value to yourpass
        combo[j].temp = passlength; // assign value to temp
        combo[j].skips = magical(combo, passlength); // calculate skips
        return;
    }
    for (int i = 0; i < ALPHA; i++) {
        combo[j].letters = i + 'A'; // assign letter to combo
        FindVariations(passlength, strength, combo, j+1, x);
    }
}

long long magical(password *combo, int passlength) {
    // perform magical computation here
    return 0;
}