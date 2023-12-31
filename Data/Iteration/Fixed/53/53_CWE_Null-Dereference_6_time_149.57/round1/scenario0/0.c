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
void brute_cleanup() {
    if (config != NULL) {
        free(config->indices);
        free(config->str);
        free(config);
        config = NULL;
    }
}
void brute_print() {
    if (config != NULL) {
        printf("%s\n", config->str);
    }
}
void brute_next() {
    if (config != NULL) {
        if (config->depth < config->maxDepth) {
            config->str[config->depth] = alphabet[config->indices[config->depth]];
            config->depth++;
        } else {
            while (config->depth > 0) {
                if (config->indices[config->depth - 1] < alphabetSize - 1) {
                    config->indices[config->depth - 1]++;
                    config->str[config->depth - 1] = alphabet[config->indices[config->depth - 1]];
                    return;
                } else {
                    config->indices[config->depth - 1] = 0;
                    config->str[config->depth - 1] = alphabet[0];
                    config->depth--;
                }
            }
            config->finished = true;
        }
    }
}
int main() {
    brute_init(3);
    while (config != NULL && !config->finished) {
        brute_print();
        brute_next();
    }
    brute_cleanup();
    return 0;
}