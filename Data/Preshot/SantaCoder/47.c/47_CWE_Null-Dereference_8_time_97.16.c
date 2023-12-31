#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

bool is_delimiter(char c, const char* delimiters) {
    for (size_t i = 0; i < strlen(delimiters); ++i) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

int parse_string(const char* input, const char* delimiters, char tokens[][MAX_TOKEN_LENGTH]) {
    size_t input_len = strlen(input);
    char* str = strdup(input);
    char* token_start = str;
    int count = 0;

    for (size_t i = 0; i <= input_len; ++i) {
	char c = str[i];
	if (is_delimiter(c, delimiters)) {
	    if (count > 0) {
		tokens[count-1][strlen(token_start)-count+1] = '\0';
		count = 0;
	    }
	    token_start = str+i+1;
	} else {
	    if (count == MAX_TOKEN_LENGTH) {
		return -1;
	    }
	    tokens[count][(size_t)(str+i-token_start)] = c;
	    ++count;
	}
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
	printf("Error: missing input string\n");
	return -1;
    }

    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int ret = parse_string(argv[1], " \t\n\r\f\v", tokens);
    if (ret < 0) {
	printf("Error: input string contains too many tokens\n");
	return -1;
    }

    for (int i = 0; i < MAX_TOKENS && tokens[i][0] != '\0'; ++i) {
	printf("%s\n", tokens[i]);
    }

    return 0;
}