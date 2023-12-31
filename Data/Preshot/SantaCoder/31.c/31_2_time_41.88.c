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
        getchar(); // consume the newline character left in the input buffer
        fgets(var[i].ab, 10, stdin); // read up to 10 characters from the input buffer, including whitespace
    }
    fwrite(&var, sizeof(var), 1, f);
    fclose(f);
    printf("Values entered in structure: %d\n", i+1);
    return 0;
}