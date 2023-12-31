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
    if (config != NULL) {
        free(config->indices);
        free(config->str);
        free(config);
    }

    config = malloc(sizeof(struct bruteConfig));
    config->index = 0;
    config->depth = 0;
    config->maxDepth = maxLen;
    config->finished = false;
    config->indices = malloc(alphabetSize * sizeof(int));
    config->str = malloc((maxLen + 1) * sizeof(char));

    int i;
    for (i = 0; i < alphabetSize; i++) {
        config->indices[i] = 0;
    }
    config->str[0] = '\0';
}