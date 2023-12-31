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

void brute_free() {
    free(config->indices);
    free(config->str);
    free(config);
}

bool brute_next() {
    if (config->finished) {
        return false;
    }

    int i = config->depth;
    int maxIndex = alphabetSize - 1;
    while (i >= 0 && config->indices[i] == maxIndex) {
        config->indices[i] = 0;
        config->str[i] = alphabet[0];
        i--;
    }

    if (i < 0) {
        config->finished = true;
        return false;
    }

    config->indices[i]++;
    config->str[i] = alphabet[config->indices[i]];
    config->depth = i;

    return true;
}

void brute_print() {
    printf("%s\n", config->str);
}

int main() {
    brute_init(4);

    while (brute_next()) {
        brute_print();
    }

    brute_free();

    return 0;
}