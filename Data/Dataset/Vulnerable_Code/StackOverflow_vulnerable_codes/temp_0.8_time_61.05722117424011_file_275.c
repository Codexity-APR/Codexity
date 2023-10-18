#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$%&/()=-_;!+*#";

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

void brute_generate() {
    if (config->depth == config->maxDepth) {
        config->finished = true;
        return;
    }

    int index = config->indices[config->depth];
    config->str[config->depth] = alphabet[index];

    if (index < alphabetSize - 1) {
        config->indices[config->depth] = index + 1;
    } else {
        while (config->depth > 0 && config->indices[config->depth] >= alphabetSize - 1) {
            config->depth--;
        }

        if (config->depth == 0 && config->indices[config->depth] == alphabetSize - 1) {
            config->finished = true;
            return;
        }

        config->indices[config->depth]++;

        for (int i = config->depth + 1; i < config->maxDepth; i++) {
            config->indices[i] = 0;
        }

        config->depth = config->maxDepth - 1;
    }

    config->depth++;
}

int main() {
    int maxLen = 4;
    brute_init(maxLen);

    while (!config->finished) {
        brute_generate();

        // Use the generated string
        printf("%s\n", config->str);
    }

    brute_cleanup();

    return 0;
}