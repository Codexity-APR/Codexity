#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // implementation of the load_mnist function
}

int main(int argc, char **argv) {
    int i;
    char *filename;
    uint8_t *images = NULL;
    uint8_t *labels = NULL;
    uint32_t num_images = 0;

    if (argc < 2) {
        printf("Usage: %s <mnist_file> <images> <labels> <num_images>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    load_mnist(filename, &images, &labels, &num_images);

    printf("Loaded %u images and labels from MNIST file %s\n", num_images, filename);

    for (i = 0; i < num_images; i++) {
        printf("%u %u\n", images[i], labels[i]);
    }

    free(images);
    free(labels);

    return 0;
}