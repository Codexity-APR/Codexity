#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
    char input_line[MAXLINE];
    int length;

    while ((length = get_input_line(input_line, MAXLINE)) > 0) {
        // Do something with the input line
        printf("%s", input_line);
    }
    return 0;
}

int get_input_line(char *line, int max) {
    int c, i;

    for (i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; i++)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}