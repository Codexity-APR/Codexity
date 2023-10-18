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

        // enter the strength
        scanf("%lld", &strength);

        // call magical function
        long long variations = magical(combo, passlength);

        // check if variations exceed strength
        if (variations >= strength) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    free(combo); // free allocated memory
    return 0;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    // implementation of FindVariations function
    // ...

}

long long magical(password *combo, int passlength) {
    // implementation of magical function
    // ...

    long long variations = 0;
    
    return variations;
}