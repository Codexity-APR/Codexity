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
    memset(config->indices, 0, maxLen * sizeof(int));
    memset(config->str, 0, (maxLen + 1) * sizeof(char));
}

void brute_reset() {
    config->index = 0;
    config->depth = 0;
    config->finished = false;
    memset(config->indices, 0, config->maxDepth * sizeof(int));
    memset(config->str, 0, (config->maxDepth + 1) * sizeof(char));
}

void brute_cleanup() {
    free(config->indices);
    free(config->str);
    free(config);
}

bool brute_next() {
    if (config->finished) {
        return false;
    }

    for (int i = config->depth; i < config->maxDepth; ++i) {
        config->str[i] = alphabet[config->indices[i]];
    }

    ++config->indices[config->depth];

    for (int i = config->depth; i < config->maxDepth; ++i) {
        if (config->indices[i] == alphabetSize) {
            config->indices[i] = 0;
            ++config->indices[i + 1];
        }
    }

    if (config->indices[config->maxDepth] == alphabetSize) {
        config->finished = true;
    }

    return true;
}

int main() {
    // Usage example
    int maxLen = 3;
    brute_init(maxLen);

    do {
        printf("%s\n", config->str);
    } while (brute_next());

    brute_cleanup();
    return 0;
}