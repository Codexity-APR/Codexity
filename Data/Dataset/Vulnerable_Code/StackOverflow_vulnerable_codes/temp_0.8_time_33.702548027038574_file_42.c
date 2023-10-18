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
        printf("Enter a string: ");
        scanf("%s", var[i].ab);
    }
    
    fwrite(var, sizeof(b), 2, f);
    fclose(f);
    
    f = fopen("new.c", "rb");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    
    b readVar[2];
    fread(readVar, sizeof(b), 2, f);
    
    printf("Data read from file:\n");
    for (i = 0; i < 2; i++) {
        printf("a: %d, ab: %s\n", readVar[i].a, readVar[i].ab);
    }
    
    fclose(f);
    
    return 0;
}