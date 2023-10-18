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
    config->indices = malloc(maxLen * sizeof(int));
    config->str = malloc((maxLen + 1) * sizeof(char));

    config->index = 0;
    config->depth = 0;
    config->maxDepth = maxLen;
    config->finished = false;
}

bool brute_next() {
    if (config->finished) {
        return false;
    }

    if (config->depth == 0) {
        memset(config->indices, 0, config->maxDepth * sizeof(int));
        memset(config->str, alphabet[0], config->maxDepth);
        config->index = 0;
        config->depth = 1;
        return true;
    }

    while (config->index < alphabetSize) {
        config->str[config->depth - 1] = alphabet[config->index];
        if (config->depth < config->maxDepth) {
            config->depth++;
            config->index = 0;
            return true;
        } else {
            config->index++;
        }
    }

    config->finished = true;
    return false;
}

void brute_print() {
    printf("%s\n", config->str);
}

int main() {
    int maxLen = 4;

    brute_init(maxLen);

    while (brute_next()) {
        brute_print();
    }

    free(config->indices);
    free(config->str);
    free(config);

    return 0;
}