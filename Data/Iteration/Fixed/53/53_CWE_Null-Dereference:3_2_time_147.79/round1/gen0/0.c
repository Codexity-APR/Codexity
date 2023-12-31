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
    config->indices = malloc(maxLen * sizeof(int));
    config->str = malloc((maxLen + 1) * sizeof(char));
    config->maxDepth = maxLen;
    config->finished = false;
    config->index = 0;
    config->depth = 0;
    memset(config->indices, 0, maxLen * sizeof(int));
    memset(config->str, 0, (maxLen + 1) * sizeof(char));
}

void brute_cleanup() {
    if (config != NULL) {
        free(config->indices);
        free(config->str);
        free(config);
    }
}

bool brute_next() {
    if (config == NULL || config->finished) {
        return false;
    }
    config->str[config->depth] = alphabet[config->indices[config->depth]];
    config->index++;
    if (config->indices[config->depth] == alphabetSize - 1) {
        while (config->depth > 0 && config->indices[config->depth] == alphabetSize - 1) {
            config->depth--;
        }
        config->indices[config->depth]++;
    } else {
        config->depth++;
        config->indices[config->depth] = 0;
    }
    if (config->depth == config->maxDepth) {
        config->finished = true;
    }
    return true;
}

int main() {
    // Example usage
    brute_init(4);
    do {
        printf("%s\n", config->str);
    } while (brute_next());
    brute_cleanup();
    return 0;
}