#include <stdio.h>

int main(){
    char c, w[50], s[300];

    printf("Enter a character: ");
    scanf("%c", &c);

    printf("Enter a word: ");
    scanf("%s", w);

    printf("Enter a sentence: ");
    getchar(); // Clear the input buffer
    fgets(s, sizeof(s), stdin);
    
    // Rest of the code
    
    return 0;
}