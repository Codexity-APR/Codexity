#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_input_line(char *line, int max);

int main(int argc, char *argv[]) {
	char line[MAXLINE];
	int len, i;
	while ((len = get_input_line(line, MAXLINE)) > 0) {
		for(i=0; i<len; i++){
			printf("%c", line[i]);
		}
		printf("\n");
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