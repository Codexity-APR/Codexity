#include <stdio.h>

typedef struct {
    int a;
    char ab[10];
} b;

int main()
{
    FILE *f;
    int i;
    b var[2];
    
    f = fopen("new.c", "wb");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    
    printf("Enter values in structure\n");
    for (i = 0; i < 2; i++) {
        scanf("%d", &var[i].a);
    }
    
    for (i = 0; i < 2; i++) {
        printf("Enter string for structure %d: ", i+1);
        scanf("%s", var[i].ab);
    }
    
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    
    return 0;
}