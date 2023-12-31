#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHA 28

typedef struct {
    int yourpass;
    char letters[ALPHA];
    int temp;
    unsigned long long skips;
} password;

//declare functions
void FindVariations(int passlength, int strength, password *combo, unsigned long long j, int x);
unsigned long long magical(password *combo, int passlength);

int main() {
    int i, j, d, cases, passlength;
    unsigned long long strength;
    password* combo;

    combo = malloc(ALPHA*sizeof(password));

    // enter number of passwords to compute
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {

        //enter number of strings/length of password
        scanf("%d", &passlength);

        // input the letters for password
        for (j = 0; j < passlength; j++) {
#ifdef __cplusplus
            scanf("%c", &combo[j].letters[j]);
#else
            scanf("%c", &combo[j].letters[j]);
#endif
        }

        // compute the strength of the password
        strength = magical(combo, passlength);

        // print the strength
        printf("%llu\n", strength);

        // find the viable combinations
        FindVariations(passlength, strength, combo, j, i);
    }

    free(combo);
    return 0;
}