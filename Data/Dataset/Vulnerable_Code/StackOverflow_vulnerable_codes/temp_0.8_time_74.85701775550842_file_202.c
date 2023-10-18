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

bool brute_next() {
    if (config->finished) {
        return false;
    }

    for (int i = config->depth; i < config->maxDepth; i++) {
        config->str[i] = alphabet[config->indices[i]];
    }

    for (int i = config->maxDepth - 1; i >= config->depth; i--) {
        if (config->indices[i] < alphabetSize - 1) {
            config->indices[i]++;
            break;
        }
        else if (i == config->depth) {
            config->depth++;
            if (config->depth >= config->maxDepth) {
                config->finished = true;
                return false;
            }
            config->indices[config->depth] = 0;
        }
        else {
            config->indices[i] = 0;
        }
    }

    return true;
}

int main() {
    brute_init(3); // Initialize with maximum string length

    do {
        printf("%s\n", config->str); // Print the current string
    } while (brute_next());

    free(config->indices);
    free(config->str);
    free(config);

    return 0;
}