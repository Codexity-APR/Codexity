#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // Implement the function logic here
    // ...
}

int main() {
    char *filename = "mnist_data.txt";
    uint8_t *images;
    uint8_t *labels;
    uint32_t num_images;

    load_mnist(filename, &images, &labels, &num_images);

    // Further code logic goes here
    // ...
    
    free(images);
    free(labels);

    return 0;
}