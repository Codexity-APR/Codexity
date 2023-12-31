#include <stdio.h>
#include <string.h>

int main(){
    char c, w[51], s[301];
    int i, j;
    printf("Enter a word (max 50 characters):\n");
    scanf("%50s", w);
    printf("Enter a sentence (max 300 characters):\n");    
    scanf("%300[^\n]", s);
    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    return 0;
}