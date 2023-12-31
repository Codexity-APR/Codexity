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
    if (config) {
        free(config->indices);
        free(config->str);
        free(config);
        config = NULL;
    }

    config = malloc(sizeof(struct bruteConfig));
    if (config == NULL) {
        fprintf(stderr, "Failed to allocate memory for config\n");
        exit(1);
    }

    config->index = 0;
    config->indices = malloc(maxLen * sizeof(int));
    if (config->indices == NULL) {
        fprintf(stderr, "Failed to allocate memory for indices\n");
        exit(1);
    }
    memset(config->indices, 0, maxLen * sizeof(int));

    config->depth = 0;
    config->str = malloc((maxLen + 1) * sizeof(char));
    if (config->str == NULL) {
        fprintf(stderr, "Failed to allocate memory for str\n");
        exit(1);
    }
    memset(config->str, 0, (maxLen + 1) * sizeof(char));

    config->maxDepth = maxLen;
    config->finished = false;
}

void brute_cleanup() {
    if (config) {
        free(config->indices);
        free(config->str);
        free(config);
        config = NULL;
    }
}

bool brute_next() {
    if (config == NULL || config->finished) {
        return false;
    }

    int i = config->depth;
    if (i >= config->maxDepth) {
        config->finished = true;
        return false;
    }

    int index = config->indices[i];
    if (index >= alphabetSize) {
        config->indices[i] = 0;
        config->depth--;
        return brute_next();
    }

    char ch = alphabet[index];
    config->str[i] = ch;
    if (i == config->depth) {
        config->depth++;
    }
    config->indices[i]++;
    return true;
}

char* brute_get_string() {
    if (config == NULL) {
        return NULL;
    }
    return config->str;
}

int main() {
    brute_init(3);
    while (brute_next()) {
        printf("%s\n", brute_get_string());
    }
    brute_cleanup();
    return 0;
}