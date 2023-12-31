#include <stdio.h>
#include <string.h>

int main(){
    char c, w[51], s[301]; // Increase size by 1 to accommodate null terminator
    int i, j;

    printf("Enter a word (maximum 50 characters):\n");
    scanf("%50s", w); // Limiting field width to 50 to prevent buffer overflow
    printf("Enter a sentence (maximum 300 characters):\n");
    scanf("%300[^\n]", s); // Limiting field width to 300 to prevent buffer overflow and using %[^\n] format specifier to read entire line until \n

    for(i = 0; i < strlen(w); i++){
        for(j = 0; j < strlen(s); j++){
            if(w[i] == s[j]){
                printf("%c", w[i]);
            }
        }
    }
    printf("\n");

    return 0;
}