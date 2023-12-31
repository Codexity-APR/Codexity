#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50

void LetterCapitalize(char str[]) {
    int i;
    char res[MAX_LEN];

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
    char str[MAX_LEN];
    printf("Enter a string: ");
    if(scanf("%49s", str) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    LetterCapitalize(str);
    return 0;
}