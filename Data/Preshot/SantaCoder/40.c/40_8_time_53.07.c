#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void LetterCapitalize(char str[]) {
    int i;
    char res[MAX_LENGTH];

    res[0] = toupper(str[0]);
    for(i = 1; i < strlen(str); i++) {
        if(str[i-1] == ' ') {
            res[i] = toupper(str[i]);
        } else {
            res[i] = str[i];
        }
    }
    res[i] = '\0';

    printf("%s\n", res);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        LetterCapitalize(str);
    } else {
        printf("Error reading input!");
    }
    return 0;
}