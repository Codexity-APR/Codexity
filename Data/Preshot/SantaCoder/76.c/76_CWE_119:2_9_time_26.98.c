#include <stdio.h>

int main(){
    char c, w[50], s[300];
    
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("Enter a word: ");
    scanf("%s", w);
    printf("Enter a sentence: ");
    scanf(" %[^\n]s", s);
    
    printf("\nCharacter entered: %c", c);
    printf("\nWord entered: %s", w);
    printf("\nSentence entered: %s", s);
    
    return 0;
}