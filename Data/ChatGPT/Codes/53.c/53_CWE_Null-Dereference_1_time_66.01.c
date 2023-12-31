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
    config->indices = malloc(sizeof(int) * maxLen);
    config->str = malloc(sizeof(char) * (maxLen + 1));
    config->maxDepth = maxLen;
    config->finished = false;
    config->index = 0;
    config->depth = 0;
}

void brute_cleanup() {
    free(config->indices);
    free(config->str);
    free(config);
}

void brute_reset() {
    config->finished = false;
    config->index = 0;
    config->depth = 0;
    memset(config->indices, 0, sizeof(int) * config->maxDepth);
    memset(config->str, 0, sizeof(char) * (config->maxDepth + 1));
}

void brute_increment() {
    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    config->indices[config->depth]++;
    if (config->indices[config->depth] >= alphabetSize) {
        config->indices[config->depth] = 0;
        config->depth++;
    }
}

char* brute_get_next() {
    if (config->finished) {
        return NULL;
    }

    for (int i = 0; i < config->depth; i++) {
        config->str[i] = alphabet[config->indices[i]];
    }
    config->str[config->depth] = alphabet[config->indices[config->depth]];
    config->str[config->depth + 1] = '\0';

    brute_increment();

    return config->str;
}

int main() {
    brute_init(3); // Initialize with maximum length of 3

    char* password;
    while ((password = brute_get_next()) != NULL) {
        printf("%s\n", password);
    }

    brute_cleanup(); // Cleanup allocated memory

    return 0;
}