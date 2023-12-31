#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // implementation of the load_mnist function goes here
}

int main() {
    // test the load_mnist function
    char *filename = "mnist_data.txt";
    uint8_t *images;
    uint8_t *labels;
    uint32_t num_images;

    load_mnist(filename, &images, &labels, &num_images);

    // rest of the main function goes here

    return 0;
}