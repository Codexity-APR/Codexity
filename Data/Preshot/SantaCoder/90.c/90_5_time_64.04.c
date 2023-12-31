#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images);

int main(int argc, char **argv) {
    int i, j;
    char *filename;
    uint8_t *images = NULL;
    uint8_t *labels = NULL;
    uint32_t *num_images = NULL;

    if (argc < 2) {
        printf("Usage: %s <mnist_file>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    num_images = (uint32_t *) malloc(sizeof(uint32_t));
    if (num_images == NULL) {
        printf("Error: Unable to allocate memory for num_images.\n");
        exit(1);
    }

    load_mnist(filename, &images, &labels, num_images);

    printf("Loaded %u images and %u labels from MNIST file %s\n", *num_images, *num_images, filename);

    for (i = 0; i < *num_images; i++) {
        printf("%hhu %hhu\n", images[i], labels[i]);
    }

    // Free allocated memory
    free(num_images);
    free(images);
    free(labels);

    return 0;
}