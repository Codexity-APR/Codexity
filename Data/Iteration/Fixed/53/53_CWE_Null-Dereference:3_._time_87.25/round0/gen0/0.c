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

    config->index = 0;
    config->depth = 0;
    config->maxDepth = maxLen;
    config->finished = false;
    memset(config->indices, 0, sizeof(int) * maxLen);
    memset(config->str, 0, sizeof(char) * (maxLen + 1));
}

int main() {
    int maxLen = 6;
    brute_init(maxLen);
    
    // Rest of your code goes here
    
    return 0;
}