#include <stdio.h>
#include <string.h>

#define MAX_W 50
#define MAX_S 300

int main(){
    char c, w[MAX_W+1], s[MAX_S+1];
    int i, j, len_w, len_s;

    printf("Enter a string with at most %d characters: ", MAX_W);
    if(scanf("%49s", w) != 1){
        fprintf(stderr, "Error: failed to read string\n");
        return 1;
    }

    printf("Enter a string with at most %d characters: ", MAX_S);
    if(scanf("%299s", s) != 1){
        fprintf(stderr, "Error: failed to read string\n");
        return 1;
    }

    len_w = strlen(w);
    len_s = strlen(s);

    if(len_w == 0 || len_w > MAX_W){
        fprintf(stderr, "Error: invalid length for string w\n");
        return 1;
    }

    if(len_s == 0 || len_s > MAX_S){
        fprintf(stderr, "Error: invalid length for string s\n");
        return 1;
    }

    for(i = 0; i < len_w; i++){
        for(j = 0; j < len_s; j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }

    return 0;
}