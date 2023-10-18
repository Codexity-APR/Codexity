#include <stdio.h>

int main()
{
    FILE *f;
    int i;
    
    typedef struct {
        int a;
        char ab[10];
    } b;
    
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
        printf("Enter ab: ");
        scanf("%s", var[i].ab);
    }
    
    fwrite(var, sizeof(b), 2, f);
    
    fclose(f);
    
    f = fopen("new.c", "rb");
    
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    
    fread(var, sizeof(b), 2, f);
    
    for (i = 0; i < 2; i++) {
        printf("a: %d, ab: %s\n", var[i].a, var[i].ab);
    }
    
    fclose(f);
    
    return 0;
}