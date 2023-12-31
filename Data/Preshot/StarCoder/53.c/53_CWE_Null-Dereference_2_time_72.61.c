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

struct bruteConfig* config = NULL;

void brute_init(int maxLen) {
    if (config != NULL) {
        free(config->indices);
        free(config->str);
        free(config);
    }
    config = malloc(sizeof(struct bruteConfig));
    config->index = 0;
    config->indices = malloc(sizeof(int) * maxLen);
    config->depth = 0;
    config->str = malloc(sizeof(char) * maxLen);
    config->maxDepth = maxLen;
    config->finished = false;
}

void brute_next() {
    if (config->index == config->maxDepth) {
        config->finished = true;
        return;
    }

    config->indices[config->depth] = config->index;
    config->str[config->depth] = alphabet[config->index];
    config->depth++;
    config->index++;
}

void brute_reset() {
    config->index = 0;
    config->depth = 0;
    config->finished = false;
}

void brute_print() {
    for (int i = 0; i < config->depth; i++) {
        printf("%c", config->str[i]);
    }
    printf("\n");
}

void brute_print_all() {
    for (int i = 0; i < config->maxDepth; i++) {
        for (int j = 0; j < config->depth; j++) {
            if (i == config->indices[j]) {
                printf("%c", config->str[j]);
            }
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {
    brute_init(10);
    while (!config->finished) {
        brute_next();
        brute_print();
    }
    brute_reset();
    brute_init(10);
    while (!config->finished) {
        brute_next();
        brute_print_all();
    }
    return 0;
}