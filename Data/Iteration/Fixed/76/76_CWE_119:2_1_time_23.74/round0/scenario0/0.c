List of vulnerabilities detected: 
 Error type: CWE-119 at line: 10. Error message: scanf() without field width limits can crash with huge input data.

 Error type: CWE-119 at line: 13. Error message: scanf() without field width limits can crash with huge input data.


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