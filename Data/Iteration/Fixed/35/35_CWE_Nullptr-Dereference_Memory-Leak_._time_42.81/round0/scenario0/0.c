List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 14.
 Example: 
  20.         if (n != -1) {
  21.             extend(&v, i);
  22.             v[i] = n;
                  ^
  23.             i++;
  24.         }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 14 by call to `malloc`, is not freed after the last access at line 21, column 13.
 Example: 
  19.         scanf("%d", &n);
  20.         if (n != -1) {
  21.             extend(&v, i);
                  ^
  22.             v[i] = n;
  23.             i++;


#include <stdio.h>
#include <stdlib.h>
void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
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
    printf("Array elements: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");
    free(v);
    return 0;
}