#include <stdio.h>

int main(){
    char c, w[50], s[300];
    
    printf("Enter a character: ");
    scanf("%c", &c);
    
    printf("Enter a word: ");
    scanf("%s", w);
    
    printf("Enter a sentence: ");
    scanf(" %[^\n]s", s);
    
    printf("Character: %c\n", c);
    printf("Word: %s\n", w);
    printf("Sentence: %s\n", s);
    
    return 0;
}