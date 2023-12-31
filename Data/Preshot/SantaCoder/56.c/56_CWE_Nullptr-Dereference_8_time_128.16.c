#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
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
    int i, j, cases, passlength;
    long long strength;
    password* combo;

    combo = malloc(ALPHA*sizeof(password));

    // enter number of passwords to compute
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {

        //enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        for (j = 0; j < passlength; j++)
            scanf(" %c", &combo[j].letters[j]);

        // compute the strength of the password
        strength = magical(combo, passlength);

        // print the strength
        printf("%lld\n", strength);

        // find the viable combinations
        FindVariations(passlength, strength, combo, j, i);
    }

    free(combo);
    return 0;
}

// function to calculate the strength of a password
long long magical(password *combo, int passlength) {
    long long strength = 1;
    int i,j;

    for (i = 0; i < passlength; i++) {
        for (j = 0; j < ALPHA; j++) {
            if (combo[i].letters[j] == '\0')
                break;
            else if (combo[i].letters[j] == 's')
                strength *= 5;
            else if (combo[i].letters[j] == 'v')
                strength *= 4;
            else if (combo[i].letters[j] == 'u')
                strength *= 3;
            else if (combo[i].letters[j] == 'w')
                strength *= 2;
            else
                strength *= 1;
        }
    }

    return strength;
}

// function to find viable combinations of password letters
void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // implementation here
}