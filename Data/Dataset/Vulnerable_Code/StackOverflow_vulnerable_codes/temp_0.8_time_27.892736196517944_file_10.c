#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len;

    while ((len = get_input_line(line, MAXLINE)) > 0) {
        printf("Input: %s", line);
    }

    return 0;
}

int get_input_line(char *line, int max) {
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}