List of vulnerabilities detected: 
Error: Null Dereference   pointer `config` last assigned on line 33 could be null and is dereferenced at line 34, column 5.
 Example: 
  32. 
  33.     config = malloc(sizeof(struct bruteConfig));
  34.     config->index = 0;
          ^
  35.     config->indices = malloc(maxLen * sizeof(int));
  36.     memset(config->indices, 0, maxLen * sizeof(int));

Error: Null Dereference   pointer `config->str` last assigned on line 38 could be null and is dereferenced by call to `memset()` at line 39, column 5.
 Example: 
  37.     config->depth = 0;
  38.     config->str = malloc((maxLen + 1) * sizeof(char));
  39.     memset(config->str, 0, (maxLen + 1) * sizeof(char));
          ^
  40.     config->maxDepth = maxLen;
  41.     config->finished = false;

Error: Null Dereference   pointer `config->indices` last assigned on line 35 could be null and is dereferenced by call to `memset()` at line 36, column 5.
 Example: 
  34.     config->index = 0;
  35.     config->indices = malloc(maxLen * sizeof(int));
  36.     memset(config->indices, 0, maxLen * sizeof(int));
          ^
  37.     config->depth = 0;
  38.     config->str = malloc((maxLen + 1) * sizeof(char));


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
static const char alphabet[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "$%&/()=-_;!+*#";
static const int alphabetSize = sizeof(alphabet) - 1;
struct bruteConfig {
    int index;
    int* indices;
    int depth;
    char* str;
    int maxDepth;
    bool finished;
};
struct bruteConfig* config;
void brute_init(int maxLen) {
    if (config) {
        free(config->indices);
        free(config->str);
        free(config);
        config = NULL;
    }
    config = malloc(sizeof(struct bruteConfig));
    config->index = 0;
    config->indices = malloc(maxLen * sizeof(int));
    memset(config->indices, 0, maxLen * sizeof(int));
    config->depth = 0;
    config->str = malloc((maxLen + 1) * sizeof(char));
    memset(config->str, 0, (maxLen + 1) * sizeof(char));
    config->maxDepth = maxLen;
    config->finished = false;
}
void brute_cleanup() {
    free(config->indices);
    free(config->str);
    free(config);
    config = NULL;
}
bool brute_next() {
    if (config->finished) {
        return false;
    }
    int i = config->depth;
    if (i >= config->maxDepth) {
        config->finished = true;
        return false;
    }
    int index = config->indices[i];
    if (index >= alphabetSize) {
        config->indices[i] = 0;
        config->depth--;
        return brute_next();
    }
    char ch = alphabet[index];
    config->str[i] = ch;
    if (i == config->depth) {
        config->depth++;
    }
    config->indices[i]++;
    return true;
}
char* brute_get_string() {
    return config->str;
}
int main() {
    brute_init(3);
    while (brute_next()) {
        printf("%s\n", brute_get_string());
    }
    brute_cleanup();
    return 0;
}