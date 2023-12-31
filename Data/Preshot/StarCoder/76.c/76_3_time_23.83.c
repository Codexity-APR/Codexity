#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_W_LENGTH 50
#define MAX_S_LENGTH 300

int main(){
    char c;
    char w[MAX_W_LENGTH+1];
    char s[MAX_S_LENGTH+1];

    memset(w, '\0', sizeof(w)); //Initialize w with null characters
    memset(s, '\0', sizeof(s)); //Initialize s with null characters
    
    printf("Enter a word: ");
    scanf("%"STR(MAX_W_LENGTH)"s", w); //Limiting the input length to prevent buffer overflow
    
    printf("Enter a string: ");
    scanf("%"STR(MAX_S_LENGTH)"s", s); //Limiting the input length to prevent buffer overflow
    
    for(int i = 0; i < strlen(w); i++){
        for(int j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    return 0;
}