List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 15 by call to `malloc`, is not freed after the last access at line 22, column 13.
 Example: 
  20.         scanf("%d", &n);
  21.         if (n != -1) {
  22.             extend(&v, i);
                  ^
  23.             v[i] = n;
  24.             i++;


#include <stdio.h>
#include <stdlib.h>
void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(1);
    }
}
int main() {
    int *v = malloc(sizeof(int));
    int n = 0;
    int i = 0;
    while (n != -1) {
        scanf("%d", &n);
        if (n != -1) {
            extend(&v, i);
            v[i] = n;
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    free(v); // Free the dynamically allocated memory
    return 0;
}