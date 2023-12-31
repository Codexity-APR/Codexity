#include <stdio.h>
#include <string.h>

int main(){
    char c, w[51], s[301]; // increase the size of w and s by 1 to accommodate the null terminator
    int i, j;
    
    printf("Enter a word (up to 50 characters):\n"); // provide user prompt
    if(scanf("%50s", w) != 1){ // limit the input to 50 characters to prevent buffer overflow
        printf("Error: Failed to read input.\n");
        return 1;
    }
    
    printf("Enter a string (up to 300 characters):\n"); // provide user prompt
    if(scanf("%300s", s) != 1){ // limit the input to 300 characters to prevent buffer overflow
        printf("Error: Failed to read input.\n");
        return 1;
    }
    
    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    printf("\n"); // add a newline character for readability
    return 0;
}