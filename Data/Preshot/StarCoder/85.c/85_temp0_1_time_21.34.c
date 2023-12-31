#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
	char line[MAXLINE];
	int len;
	while ((len = get_input_line(line, MAXLINE)) > 0) {
		printf("Line length: %d\n", len);
		printf("Line contents: %s\n", line);
	}
	return 0;
}

int get_input_line(char *line, int max) {
	int len;
	if (fgets(line, max, stdin) == NULL) {
		return -1;
	}
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n') {
		line[len - 1] = '\0';
	}
	return len;
}