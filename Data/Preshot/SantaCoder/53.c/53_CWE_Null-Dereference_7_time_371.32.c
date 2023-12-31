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
    config->indices = calloc(maxLen, sizeof(int));
    config->str = calloc(maxLen + 1, sizeof(char));
    config->index = 0;
    config->depth = 0;
    config->maxDepth = maxLen;
    config->finished = false;
}

void brute_add_char(char c, int index) {
    if (config->finished) {
        return;
    }

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    if (config->indices[index] != 0) {
        config->finished = true;
        return;
    }

    config->indices[index] = config->index;
    config->index++;

    if (config->index >= config->maxDepth) {
        config->finished = true;
        return;
    }

    config->str[config->depth] = c;
    config->depth++;

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    for (int i = 0; i < alphabetSize; i++) {
        brute_add_char(alphabet[i], index);
    }
}

void brute_add_string(const char* str, int index) {
    if (config->finished) {
        return;
    }

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    if (config->indices[index] != 0) {
        config->finished = true;
        return;
    }

    config->indices[index] = config->index;
    config->index++;

    if (config->index >= config->maxDepth) {
        config->finished = true;
        return;
    }

    int strLen = strlen(str);
    strncpy(config->str + config->depth, str, strLen);
    config->depth += strLen;

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    for (int i = 0; i < alphabetSize; i++) {
        brute_add_char(alphabet[i], index);
    }
}

void brute_add_string_with_indices(const char* str, int index, int* indices) {
    if (config->finished) {
        return;
    }

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    if (config->indices[index] != 0) {
        config->finished = true;
        return;
    }

    config->indices[index] = config->index;
    config->index++;

    if (config->index >= config->maxDepth) {
        config->finished = true;
        return;
    }

    int strLen = strlen(str);
    strncpy(config->str + config->depth, str, strLen);
    config->depth += strLen;

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    for (int i = 0; i < alphabetSize; i++) {
        if (indices[i] == 0) {
            brute_add_char(alphabet[i], i);
        }
    }
}

void brute_add_string_with_indices_with_depth(const char* str, int index, int* indices, int depth) {
    if (config->finished) {
        return;
    }

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    if (config->indices[index] != 0) {
        config->finished = true;
        return;
    }

    config->indices[index] = config->index;
    config->index++;

    if (config->index >= config->maxDepth) {
        config->finished = true;
        return;
    }

    int strLen = strlen(str);
    strncpy(config->str + config->depth, str, strLen);
    config->depth += strLen;

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    for (int i = 0; i < alphabetSize; i++) {
        if (indices[i] == 0) {
            brute_add_char(alphabet[i], i);
        }
    }
}

void brute_add_string_with_indices_with_depth_with_max_depth(const char* str, int index, int* indices, int depth, int maxDepth) {
    if (config->finished) {
        return;
    }

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    if (config->indices[index] != 0) {
        config->finished = true;
        return;
    }

    config->indices[index] = config->index;
    config->index++;

    if (config->index >= config->maxDepth) {
        config->finished = true;
        return;
    }

    int strLen = strlen(str);
    strncpy(config->str + config->depth, str, strLen);
    config->depth += strLen;

    if (config->depth >= config->maxDepth) {
        config->finished = true;
        return;
    }

    for (int i = 0; i < alphabetSize; i++) {
        if (indices[i] == 0) {
            brute_add_char(alphabet[i], i);
        }
    }
}