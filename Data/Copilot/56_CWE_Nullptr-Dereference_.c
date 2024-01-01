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
        scanf(" %c", &combo[j].letters[0]);
                    combo[j].temp = 0;
                    combo[j].skips = 0;
                }

                // enter strength of password
                scanf("%lld", &strength);

                // find variations of password
                FindVariations(passlength, strength, combo, 0, 0);

                // calculate and print the number of possible passwords
                printf("%lld\n", magical(combo, passlength));
            }

            free(combo);
            return 0;
        }

        void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
            int i;
            if (j == passlength) {
                return;
            }
            for (i = 0; i < ALPHA; i++) {
                combo[j].letters[x] = i + 'a';
                if (x == strength - 1) {
                    combo[j].temp++;
                    if (combo[j].temp == 1) {
                        combo[j].yourpass = 1;
                    }
                }
                FindVariations(passlength, strength, combo, j, x + 1);
                if (x == 0) {
                    combo[j].skips += combo[j].temp - 1;
                    combo[j].temp = 0;
                }
            }
        }

        long long magical(password *combo, int passlength) {
            int i, j;
            long long result = 1;
            for (i = 0; i < passlength; i++) {
                if (combo[i].yourpass == 1) {
                    result *= (combo[i].skips + 1);
                }
            }
            return result;
        }
