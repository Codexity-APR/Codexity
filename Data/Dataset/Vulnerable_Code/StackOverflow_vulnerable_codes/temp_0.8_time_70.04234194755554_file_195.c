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
    config->index = 0;
    config->indices = malloc(maxLen * sizeof(int));
    config->depth = 0;
    config->str = malloc((maxLen + 1) * sizeof(char));
    config->maxDepth = maxLen;
    config->finished = false;
}

void brute_cleanup() {
    free(config->indices);
    free(config->str);
    free(config);
}

bool brute_next() {
    if (config->depth > 0) {
        config->indices[config->depth - 1]++;
        config->str[config->depth - 1] = alphabet[config->indices[config->depth - 1]];
    }

    while (config->indices[config->depth - 1] == alphabetSize) {
        if (config->depth == 1) {
            config->finished = true;
            return false;
        }
        config->depth--;
        config->indices[config->depth - 1]++;
        config->str[config->depth - 1] = alphabet[config->indices[config->depth - 1]];
    }

    if (config->depth < config->maxDepth) {
        config->str[config->depth] = alphabet[0];
        config->indices[config->depth] = 0;
        config->depth++;
        return true;
    }

    return false;
}

int main() {
    brute_init(3);

    while (!config->finished) {
        printf("%s\n", config->str);
        brute_next();
    }

    brute_cleanup();

    return 0;
}