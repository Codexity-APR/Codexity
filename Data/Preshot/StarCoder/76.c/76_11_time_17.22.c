#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_STR_SIZE 300

int main(){
    char c, w[MAX_WORD_SIZE+1], s[MAX_STR_SIZE+1];
    int i, j;
    memset(w, 0, sizeof(w)); // Initialize w with zeroes
    memset(s, 0, sizeof(s)); // Initialize s with zeroes
    scanf("%50s", w); // Read w with a field width limit of 50
    scanf("%300s", s); // Read s with a field width limit of 300
    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    return 0;
}