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
    memset(config->indices, 0, maxLen * sizeof(int));
    config->depth = 1;
    config->str = malloc((maxLen + 1) * sizeof(char));
    memset(config->str, 0, (maxLen + 1) * sizeof(char));
    config->maxDepth = maxLen;
    config->finished = false;
}

void brute_generate() {
    if (config->depth <= config->maxDepth) {
        config->str[config->depth - 1] = alphabet[config->indices[config->depth - 1]];

        if (config->depth == config->maxDepth) {
            config->finished = true;
        } else {
            config->depth++;
        }
    } else {
        int i = config->depth - 1;

        while (i >= 0 && config->indices[i] == alphabetSize - 1) {
            i--;
        }

        if (i < 0) {
            config->finished = true;
            return;
        }

        config->indices[i]++;

        for (int j = i + 1; j < config->depth; j++) {
            config->indices[j] = 0;
        }

        config->str[i] = alphabet[config->indices[i]];
    }
}

int main() {
    int maxLen = 4; // Change this value to set the maximum length of the generated string

    brute_init(maxLen);

    while (!config->finished) {
        brute_generate();
        printf("%s\n", config->str);
    }

    free(config->indices);
    free(config->str);
    free(config);

    return 0;
}