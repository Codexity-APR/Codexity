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
    free(config->indices);
    free(config->str);
    free(config);
    config = malloc(sizeof(struct bruteConfig));
    if (config == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    config->index = 0;
    config->indices = malloc(maxLen * sizeof(int));
    if (config->indices == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    config->depth = 0;
    config->str = malloc((maxLen + 1) * sizeof(char));
    if (config->str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    config->maxDepth = maxLen;
    config->finished = false;
}

int main() {
    // Example usage of the brute_init function
    int maxLen = 5;
    config = malloc(sizeof(struct bruteConfig));
    if (config == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    brute_init(maxLen);
    return 0;
}