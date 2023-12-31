#include <stdio.h>

int main() {
    char c, w[50], s[300];
    
    printf("Enter a character: ");
    scanf("%c", &c);
    
    printf("Enter a word: ");
    scanf("%49s", w); // Added field width limit of 49 to prevent buffer overflow
    
    printf("Enter a sentence: ");
    scanf(" %299[^\n]", s); // Added field width limit of 299 to prevent buffer overflow
    
    printf("Character: %c\n", c);
    printf("Word: %s\n", w);
    printf("Sentence: %s\n", s);
    
    return 0;
}