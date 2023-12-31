#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_W_LENGTH 50
#define MAX_S_LENGTH 300

int main(){
    char c, w[MAX_W_LENGTH + 1], s[MAX_S_LENGTH + 1];
    memset(w, 0, sizeof(w));
    memset(s, 0, sizeof(s));
    int i, j;
    scanf("%49s", w);  // Limiting input to MAX_W_LENGTH to avoid buffer overflow
    scanf("%299s", s); // Limiting input to MAX_S_LENGTH to avoid buffer overflow
    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    return 0;
}