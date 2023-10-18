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
        
        // enter the strength of the password
        scanf("%lld", &strength);
        
        // call the magical function and print the result
        printf("%lld\n", magical(combo, passlength));
    }
    
    free(combo);
    
    return 0;
}

long long magical(password *combo, int passlength) {
    long long j, total = 0;
    
    // calculate the total number of variations
    for (j = 0; j < passlength; j++) {
        total += combo[j].temp;
    }
    
    return total;
}

void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    int k;
    
    if (x == passlength) {
        combo[j].temp = 1;
        return;
    }
    
    for (k = 0; k < ALPHA; k++) {
        if (combo[j].letters[k] <= strength) {
            FindVariations(passlength, strength - combo[j].letters[k], combo, j, x + 1);
        }
    }
}