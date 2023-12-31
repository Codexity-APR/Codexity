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
		tokens[count-1] = str;
	    }
	    str = strdup(str);
	    token_start = str;
	    count = 0;
	} else {
	    if (count == MAX_TOKEN_LENGTH) {
		return -1;
	    }
	    ++count;
	}
    }

    if (count > 0) {
	tokens[count-1] = str;
    }

    return 0;
}

int main() {
    char tokens[MAX_TOKENS];
    int ret = parse_string(argv[1], " \t\n\r\f\v", tokens);
    if (ret < 0) {
	printf("Error: %s\n", argv[1]);
	return -1;
    }

    for (size_t i = 0; i < MAX_TOKENS; ++i) {
	printf("%s\n", tokens[i]);
    }

    return 0;
}