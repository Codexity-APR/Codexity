List of vulnerabilities detected: 
Error: Null Dereference   pointer `config` last assigned on line 30 could be null and is dereferenced at line 31, column 5.
 Example: 
  29.     }
  30.     config = malloc(sizeof(struct bruteConfig));
  31.     config->index = 0;
          ^
  32.     config->indices = malloc(maxLen * sizeof(int));
  33.     config->depth = 0;


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
    config->indices = malloc(maxLen * sizeof(int));
    config->depth = 0;
    config->str = malloc((maxLen + 1) * sizeof(char));
    config->maxDepth = maxLen;
    config->finished = false;
}
void brute_reset() {
    if (config != NULL) {
        config->index = 0;
        config->depth = 0;
        config->finished = false;
    }
}
void brute_cleanup() {
    if (config != NULL) {
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
    int i;
    for (i = 0; i < config->depth; i++) {
        config->str[i] = alphabet[config->indices[i]];
    }
    config->str[config->depth] = '\0';
    for (i = config->depth - 1; i >= 0; i--) {
        if (config->indices[i] < alphabetSize - 1) {
            config->indices[i]++;
            break;
        } else {
            config->indices[i] = 0;
            if (i == 0) {
                if (config->depth < config->maxDepth) {
                    config->depth++;
                } else {
                    config->finished = true;
                }
            }
        }
    }
    return true;
}
int main() {
    brute_init(3);
    while (brute_next()) {
        printf("%s\n", config->str);
    }
    brute_cleanup();
    return 0;
}