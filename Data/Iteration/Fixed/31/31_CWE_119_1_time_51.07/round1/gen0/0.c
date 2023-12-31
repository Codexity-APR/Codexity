#include <stdio.h>
#define MAX_STRING_LENGTH 10

int main()
{
    FILE *f;
    int i;
    typedef struct {
        int a;
        char ab[MAX_STRING_LENGTH];
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
        printf("Enter string: ");
        scanf("%9s", var[i].ab); // Limiting input to 9 characters to avoid buffer overflow
    }
    fwrite(&var, sizeof(var), 1, f);
    fclose(f);
    f = fopen("new.c", "rb");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    fread(&var, sizeof(var), 1, f);
    fclose(f);
    printf("Contents of file:\n");
    for (i = 0; i < 2; i++) {
        printf("Structure %d\n", i + 1);
        printf("a: %d\n", var[i].a);
        printf("ab: %s\n", var[i].ab);
    }
    return 0;
}