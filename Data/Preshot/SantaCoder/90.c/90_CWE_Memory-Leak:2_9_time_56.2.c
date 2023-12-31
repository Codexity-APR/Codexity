#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images);

int main(int argc, char **argv) {
    int i;
    char *filename;
    uint8_t *images;
    uint8_t *labels;
    uint32_t num_images;

    if (argc < 2) {
        printf("Usage: %s <mnist_file> <images> <labels> <num_images>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    images = (uint8_t *) malloc(sizeof(uint8_t) * (argc - 2));
    labels = (uint8_t *) malloc(sizeof(uint8_t) * (argc - 2));

    load_mnist(filename, &images, &labels, &num_images);

    printf("Loaded %u images and %u labels from MNIST file %s\n", num_images, num_images, filename);

    for (i = 0; i < num_images; i++) {
        printf("%hhu %hhu\n", images[i], labels[i]);
    }

    free(images);
    free(labels);

    return 0;
}