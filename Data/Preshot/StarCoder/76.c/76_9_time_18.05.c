#include <stdio.h>
#include <string.h>

int main(){
    char c, w[51], s[301];
    int i, j;
    
    printf("Enter word (max 50 characters): ");
    scanf("%50s", w);
    
    printf("Enter string (max 300 characters): ");
    scanf("%300s", s);
    
    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    
    return 0;
}