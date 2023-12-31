#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len, i;

    for (i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Unable to open file: %s\n", argv[i]);
            continue;
        }

        while ((len = get_input_line(line, MAXLINE)) > 0) {
            // Process the line here
            // ...
            // Print the line
            printf("%s\n", line);
        }

        fclose(file);
    }

    return 0;
}

int get_input_line(char *line, int max) {
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (i == max - 1 && c != '\n') {
        // Handle the case where the line exceeds the buffer size
        while ((c = getchar()) != EOF && c != '\n') {
            // Discard the remaining characters in the line
        }
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}