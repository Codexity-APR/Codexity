#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_delimiter(char c, const char* delimiters) {
    for (size_t i = 0; i < strlen(delimiters); ++i) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    size_t input_len = strlen(input);
    char* str = strdup(input);
    char* token_start = str;
    int count = 0;
    char** tokens = NULL;

    for (size_t i = 0; i <= input_len; ++i) {
	if (is_delimiter(str[i], delimiters)) {
	    if (count > 0) {
		if (tokens == NULL) {
		    tokens = (char**) malloc(input_len + 1);
		}
		memcpy(tokens + count, str, input_len);
		token_count[0] = count;
		return tokens;
	    }
	    token_count[0] = 0;
	    return NULL;
	}
	++count;
	str += str[i];
    }
    if (count > 0) {
	if (tokens == NULL) {
	    tokens = (char**) malloc(input_len + 1);
	}
	memcpy(tokens + count, str, input_len);
	token_count[0] = count;
	return tokens;
    }
    token_count[0] = 0;
    return NULL;
}

int main() {
    char* input = "abc";
    char* delimiters = " ";
    char** tokens = parse_string(input, delimiters, &token_count);
    if (tokens) {
        for (size_t i = 0; i < token_count[0]; ++i) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
    return 0;
}