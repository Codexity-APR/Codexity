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

void brute_print() {
    printf("%s\n", config->str);
}

void brute_increment() {
    config->index++;
    if (config->index >= alphabetSize) {
        config->index = 0;
        config->depth++;
        if (config->depth > config->maxDepth) {
            config->finished = true;
            return;
        }
    }
    config->str[config->depth] = alphabet[config->index];
}

void brute_loop(void (*callback)()) {
    while (!config->finished) {
        callback();
        brute_increment();
    }
}

int main() {
    int maxLen = 4; // Define the maximum length of the generated string
    brute_init(maxLen);

    brute_loop(brute_print);

    brute_cleanup();

    return 0;
}