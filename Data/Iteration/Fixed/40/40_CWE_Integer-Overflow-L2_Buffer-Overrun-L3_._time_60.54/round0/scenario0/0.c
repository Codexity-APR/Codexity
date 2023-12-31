List of vulnerabilities detected: 
Error: Integer Overflow L2   ([0, 49] - 1):unsigned64.
 Example: 
  25. 
  26.     // Remove trailing newline character
  27.     if (str[strlen(str) - 1] == '\n') {
              ^
  28.         str[strlen(str) - 1] = '\0';
  29.     }

Error: Buffer Overrun L3   Offset: [-1, 48] Size: 50.
 Example: 
  25. 
  26.     // Remove trailing newline character
  27.     if (str[strlen(str) - 1] == '\n') {
              ^
  28.         str[strlen(str) - 1] = '\0';
  29.     }


#include <stdio.h>
#include <string.h>
#include <ctype.h>
void LetterCapitalize(char str[]) {
    int i;
    char res[50];
    res[0] = toupper(str[0]);
    for(i = 1; i < strlen(str); i++) {
        if(str[i-1] == ' ') {
            res[i] = toupper(str[i]);
        } else {
            res[i] = str[i];
        }
    }
    printf("%s\n", res);
}
int main() {
    char str[50];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove trailing newline character
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    LetterCapitalize(str);
    return 0;
}