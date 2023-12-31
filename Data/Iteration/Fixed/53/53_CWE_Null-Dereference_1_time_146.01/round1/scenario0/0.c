List of vulnerabilities detected: 
Error: Null Dereference   pointer `config` last assigned on line 25 could be null and is dereferenced at line 26, column 5.
 Example: 
  24. void brute_init(int maxLen) {
  25.     config = malloc(sizeof(struct bruteConfig));
  26.     config->index = 0;
          ^
  27.     config->indices = malloc(maxLen * sizeof(int));
  28.     config->depth = 1;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25.
 Example: 
  24. void brute_init(int maxLen) {
  25.     config = malloc(sizeof(struct bruteConfig));
  26.     config->index = 0;
          ^
  27.     config->indices = malloc(maxLen * sizeof(int));
  28.     config->depth = 1;


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
    config = malloc(sizeof(struct bruteConfig));
    config->index = 0;
    config->indices = malloc(maxLen * sizeof(int));
    config->depth = 1;
    config->str = malloc((maxLen + 1) * sizeof(char));
    config->maxDepth = maxLen;
    config->finished = false;
}
void brute_cleanup() {
    free(config->indices);
    free(config->str);
    free(config);
}
void brute_generate() {
    if (config->depth > config->maxDepth) {
        config->finished = true;
        return;
    }
    for (int i = 0; i < alphabetSize; i++) {
        config->str[config->depth - 1] = alphabet[i];
        config->str[config->depth] = '\0';
        if (config->depth == config->maxDepth) {
            config->finished = true;
            return;
        }
        if (config->index < config->maxDepth - 1) {
            config->indices[config->index] = i;
            config->index++;
            config->depth++;
            brute_generate();
            config->index--;
            config->depth--;
        }
    }
}
int main() {
    int maxLen = 4;
    brute_init(maxLen);
    while (!config->finished) {
        brute_generate();
        printf("%s\n", config->str);
    }
    brute_cleanup();
    return 0;
}