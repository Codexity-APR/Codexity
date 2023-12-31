#include <stdio.h>

int main(){
    char c, w[50], s[300];
    
    // Get a single character from the user
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("You entered: %c\n", c);
    
    // Get a single word from the user
    printf("Enter a word: ");
    scanf("%s", w);
    printf("You entered: %s\n", w);
    
    // Get a full sentence from the user
    printf("Enter a sentence: ");
    scanf(" %[^\n]", s);
    printf("You entered: %s\n", s);
    
    return 0;
}