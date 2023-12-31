#include <stdio.h>
#include <string.h>

#define MAX_W_LENGTH 50
#define MAX_S_LENGTH 300

int main(){
    char c, w[MAX_W_LENGTH+1], s[MAX_S_LENGTH+1];
    int i, j;

    printf("Enter a word (maximum %d characters): ", MAX_W_LENGTH);
    scanf("%" STRINGIFY(MAX_W_LENGTH) "s", w);

    printf("Enter a sentence (maximum %d characters): ", MAX_S_LENGTH);
    scanf(" %" STRINGIFY(MAX_S_LENGTH) "[^\n]s", s);

    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }

    return 0;
}