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
    password* combo = NULL;

    // enter number of passwords to compute
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {

        //enter number of strings/length of password
        scanf("%d", &passlength);

        // allocate memory for combo
        combo = malloc(passlength * sizeof(password));
        if(combo == NULL){
            printf("Memory allocation failed!");
            return 1;
        }

        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo[j].letters[j]);
        }

        // input the strength of the password
        scanf("%lld", &strength);

        // call the function to find all possible combinations
        FindVariations(passlength, strength, combo, 0, 0);

        // print the number of combinations
        printf("%lld\n", magical(combo, passlength));

        // free the allocated memory
        free(combo);
        combo = NULL;
    }

    return 0;
}

// function to find all possible combinations
void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    int i;
    long long k;

    // if the password is the same as the strength, print it
    if (strength == 0) {
        for (i = 0; i < passlength; i++) {
            printf("%c", combo[i].letters[i]);
        }
        printf("\n");
        return;
    }

    // if the password is not the same as the strength, find all possible combinations
    for (i = x; i < passlength; i++) {
        // if the letter is not already in the password, add it
        if (combo[i].yourpass == 0) {
            combo[i].yourpass = 1;
            combo[i].temp = strength;
            combo[i].skips = 0;

            // if the letter is the first letter, skip the first letter
            if (i == 0) {
                combo[i].skips = 1;
            }

            // if the letter is the last letter, skip the last letter
            if (i == passlength - 1) {
                combo[i].skips = 1;
            }

            // call the function recursively
            FindVariations(passlength, strength - 1, combo, j + 1, i + 1);

            // remove the letter from the password
            combo[i].yourpass = 0;
            combo[i].temp = 0;
            combo[i].skips = 0;
        }
    }
}

// function to print all possible combinations
long long magical(password *combo, int passlength) {
    int i;
    long long k;

    // initialize the number of combinations to 0
    k = 0;

    // loop through all possible combinations
    for (i = 0; i < passlength; i++) {
        // if the letter is in the password, print it
        if (combo[i].yourpass == 1) {
            k++;
        }
    }

    // return the number of combinations
    return k;
}