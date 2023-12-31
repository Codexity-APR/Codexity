#include <stdio.h>
#include <string.h> // for memset()

int main () {
    FILE *file;
    char str[1000];
    memset(str, 0, sizeof(str)); // initializing the str array with null characters

    file = fopen("random.txt", "r");

    if (file) {
        int i = 0;
        char c;
 
        while ((c = getc(file)) != EOF) {
            str[i++] = c;
        }

        str[i] = '\0';

        fclose(file);
    }

    printf("%s", str); // printing the string

    return 0;
}