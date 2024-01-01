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
        config->depth = 1;
        config->maxDepth = maxLen;
        config->finished = false;

        config->indices = malloc(sizeof(int) * maxLen);
        config->str = malloc(maxLen + 1);
        memset(config->indices, 0, sizeof(int) * maxLen);
        memset(config->str, 0, maxLen + 1);
    }

    bool brute_increment() {
        if (config->finished) {
            return false;
        }

        config->str[config->maxDepth] = '\0';
        for (int i = config->maxDepth - 1; i >= 0; --i) {
            if (config->indices[i] == alphabetSize - 1) {
                if (i == 0) {
                    config->finished = true;
                    return false;
                }
                config->indices[i] = 0;
            } else {
                ++config->indices[i];
                break;
            }
        }

        for (int i = 0; i < config->maxDepth; ++i) {
            config->str[i] = alphabet[config->indices[i]];
        }

        return true;
    }

    void brute_reset() {
        config->index = 0;
        config->depth = 1;
        config->finished = false;
        memset(config->indices, 0, sizeof(int) * config->maxDepth);
        memset(config->str, 0, config->maxDepth + 1);
    }

    void brute_free() {
        free(config->indices);
        free(config->str);
        free(config);
    }
