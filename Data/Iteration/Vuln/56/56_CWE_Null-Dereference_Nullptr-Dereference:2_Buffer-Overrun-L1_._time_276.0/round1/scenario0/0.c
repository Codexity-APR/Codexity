List of vulnerabilities detected: 
Error: Null Dereference   pointer `combo` last assigned on line 25 could be null and is dereferenced by call to `FindVariations()` at line 40, column 9.
 Example: 
  38.         
  39.         // find variations and output the result
  40.         FindVariations(passlength, strength, combo, 0, 0);
              ^
  41.         printf("%lld\n", magical(combo, passlength));
  42.     }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25in call to `FindVariations()` .
 Example: 
  38.         
  39.         // find variations and output the result
  40.         FindVariations(passlength, strength, combo, 0, 0);
              ^
  41.         printf("%lld\n", magical(combo, passlength));
  42.     }

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25.
 Example: 
  31.         // input the letters for password
  32.         for (j = 0; j < passlength; j++) {
  33.             scanf(" %c", &combo[j].letters[0]);
                  ^
  34.         }
  35.

Error: Buffer Overrun L1   Offset: -1 Size: 28 by call to `FindVariations`.
 Example: 
  38.         
  39.         // find variations and output the result
  40.         FindVariations(passlength, strength, combo, 0, 0);
              ^
  41.         printf("%lld\n", magical(combo, passlength));
  42.     }


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
    // enter number of passwords to compute
    scanf("%d", &cases);
    combo = malloc(ALPHA * sizeof(password));
    for (i = 0; i < cases; i++) {
        // enter number of strings/length of password
        scanf("%d", &passlength);
        // input the letters for password
        for (j = 0; j < passlength; j++) {
            scanf(" %c", &combo[j].letters[0]);
        }
        // enter the strength of password
        scanf("%lld", &strength);
        // find variations and output the result
        FindVariations(passlength, strength, combo, 0, 0);
        printf("%lld\n", magical(combo, passlength));
    }
    free(combo); // free the allocated memory
    return 0;
}
void FindVariations(int passlength, int strength, password *combo, long long j, int x) {
    if (j == passlength) {
        combo[x].temp = 0;
        x++;
        return;
    }
    if (j) {
        combo[x].temp = combo[x - 1].temp;
    }
    combo[x].letters[j] = 'a';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo[x].letters[j] = 'b';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo[x].letters[j] = 'c';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo[x].temp++;
    if (combo[x].temp == strength)
        return;
    combo[x].letters[j] = 'A';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo[x].letters[j] = 'B';
    FindVariations(passlength, strength, combo, j + 1, x);
    combo[x].letters[j] = 'C';
    FindVariations(passlength, strength, combo, j + 1, x);
}
long long magical(password *combo, int passlength) {
    long long count = 1;
    int i;
    for (i = 0; i < passlength; i++) {
        count *= combo[i].temp + 1;
    }
    return count;
}