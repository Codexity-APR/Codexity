#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_string(const char* input, const char* delimiters, int* token_count) {
    char* str = strdup(input);
    if (!str) {
        printf("Error: failed to allocate memory\n");
        return NULL;
    }

    char* token;
    int count = 0;
    char** tokens = NULL;

    token = strtok(str, delimiters);
    while (token!= NULL) {
        ++count;
        char** temp = realloc(tokens, sizeof(char*) * count);
        if (!temp) {
            printf("Error: failed to allocate memory\n");
            free(str);
            return NULL;
        }

        tokens = temp;
        tokens[count - 1] = token;
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
        return 1;
    }

    for (int i = 0; i < token_count; ++i) {
        printf("%s\n", tokens[i]);
    }

    free(tokens);
    return 0;
}