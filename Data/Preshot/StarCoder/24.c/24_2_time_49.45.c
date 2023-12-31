#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    char* str = strdup(input);
    char* token;
    int count = 0;
    char** tokens = NULL;

    token = strtok(str, delimiters);
    while (token!= NULL) {
        ++count;
        char** tmp = realloc(tokens, sizeof(char*) * count);
        if (!tmp) {
            for (int i = 0; i < count - 1; ++i) {
                free(tokens[i]);
            }
            free(tokens);
            free(str);
            return NULL;
        }
        tokens = tmp;
        char* token_copy = strdup(token);
        if (!token_copy) {
            // free memory allocated so far
            for (int i = 0; i < count - 1; ++i) {
                free(tokens[i]);
            }
            free(tokens);
            free(str);
            return NULL;
        }
        tokens[count - 1] = token_copy;
        token = strtok(NULL, delimiters);
    }

    free(str);
    *token_count = count;
    return tokens;
}

int main(int argc, char** argv) {
    char* input = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";
    char* delimiters = ",";
    int token_count = 0;
    char** tokens = parse_string(input, delimiters, &token_count);
    if (!tokens) {
        printf("Failed to tokenize string\n");
        return 1;
    }

    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}