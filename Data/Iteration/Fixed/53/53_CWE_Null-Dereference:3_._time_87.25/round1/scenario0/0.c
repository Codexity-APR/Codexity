List of vulnerabilities detected: 
Error: Null Dereference   pointer `config` last assigned on line 31 could be null and is dereferenced at line 32, column 5.
 Example: 
  30.     
  31.     config = malloc(sizeof(struct bruteConfig));
  32.     config->indices = malloc(sizeof(int) * maxLen);
          ^
  33.     config->str = malloc(sizeof(char) * (maxLen + 1));
  34.     config->index = 0;

Error: Null Dereference   pointer `config->str` last assigned on line 33 could be null and is dereferenced by call to `memset()` at line 39, column 5.
 Example: 
  37.     config->finished = false;
  38.     memset(config->indices, 0, sizeof(int) * maxLen);
  39.     memset(config->str, 0, sizeof(char) * (maxLen + 1));
          ^
  40. }
  41.

Error: Null Dereference   pointer `config->indices` last assigned on line 32 could be null and is dereferenced by call to `memset()` at line 38, column 5.
 Example: 
  36.     config->maxDepth = maxLen;
  37.     config->finished = false;
  38.     memset(config->indices, 0, sizeof(int) * maxLen);
          ^
  39.     memset(config->str, 0, sizeof(char) * (maxLen + 1));
  40. }


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