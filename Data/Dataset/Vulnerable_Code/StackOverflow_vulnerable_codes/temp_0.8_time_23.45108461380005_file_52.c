#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *macierz1, *macierz2, *fw;
    char *line = NULL;
    size_t count = 1000;
    macierz1 = fopen("macierz1.txt", "r");
    if (macierz1 == NULL)
    {
        printf("nie można otworzyć %s", argv[1]);
        exit(1);
    }

    macierz2 = fopen("macierz2.txt", "r");
    if (macierz2 == NULL)
    {
        printf("nie można otworzyć %s", argv[2]);
        exit(1);
    }

    double *data = (double *)malloc(1000 * sizeof(double));
    if (data == NULL)
    {
        fprintf(stderr, "Błąd alokacji pamięci");
        exit(1);
    }

    // Rest of your code goes here...

    return 0;
}