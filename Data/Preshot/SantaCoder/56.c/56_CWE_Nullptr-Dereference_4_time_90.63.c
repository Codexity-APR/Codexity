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

    combo = (password*) malloc(ALPHA*sizeof(password));

    // enter number of passwords to compute
    printf("Enter number of passwords to compute: ");
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {
        printf("Enter the length of the password: ");
        //enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        printf("Enter the letters for the password: ");
        for (j = 0; j < passlength; j++) {
#ifdef __cplusplus
            scanf(" %c", &combo[j].letters[j]);
#else
            scanf(" %c", &combo[j].letters[j]);
#endif
        }

        // compute the strength of the password
        strength = magical(combo, passlength);

        // print the strength
        printf("The strength of the password is: %lld\n", strength);

        // find the viable combinations
        FindVariations(passlength, strength, combo, j, i);
    }

    free(combo);

    return 0;
}