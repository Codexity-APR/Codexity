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
    if (config != NULL) {
        free(config->indices);
        free(config->str);
        free(config);
    }
    config = malloc(sizeof(struct bruteConfig));
    config->indices = malloc(sizeof(int) * maxLen);
    config->str = malloc(sizeof(char) * (maxLen + 1));
    config->maxDepth = maxLen;
    config->finished = false;
}

void brute_next(struct bruteConfig* config) {
    if (config->depth < config->maxDepth) {
        config->str[config->depth] = alphabet[config->indices[config->depth]];
        config->depth++;
    } else {
        int i = config->maxDepth - 1;
        while (i >= 0 && config->indices[i] == alphabetSize - 1) {
            config->indices[i] = 0;
            i--;
        }
        if (i < 0) {
            config->finished = true;
            return;
        }
        config->indices[i]++;
        config->depth = i + 1;
        config->str[i] = alphabet[config->indices[i]];
    }
}

bool brute_finished(struct bruteConfig* config) {
    return config->finished;
}

char* brute_get_string(struct bruteConfig* config) {
    return config->str;
}

int main() {
    int maxLen = 4;
    brute_init(maxLen);
    while (!brute_finished(config)) {
        char* str = brute_get_string(config);
        printf("%s\n", str);
        brute_next(config);
    }
    free(config->indices);
    free(config->str);
    free(config);
    return 0;
}