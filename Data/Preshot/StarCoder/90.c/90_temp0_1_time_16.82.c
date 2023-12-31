#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images);

int main(int argc, char **argv) {
    uint8_t *images = NULL;
    uint8_t *labels = NULL;
    uint32_t num_images = 0;

    load_mnist("data/train-images.idx3-ubyte", &images, &labels, &num_images);

    printf("Loaded %u images\n", num_images);

    return 0;
}

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // implementation of load_mnist function
}