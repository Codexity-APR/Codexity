#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Read the number of images
    uint32_t magic_number;
    fread(&magic_number, sizeof(uint32_t), 1, file);
    *num_images = ntohl(magic_number);

    // Allocate memory for the images
    *images = (uint8_t *)malloc((*num_images) * 784);
    if (*images == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    // Allocate memory for the labels
    *labels = (uint8_t *)malloc((*num_images) * sizeof(uint8_t));
    if (*labels == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    // Read the images
    fread(*images, sizeof(uint8_t), (*num_images) * 784, file);

    // Read the labels
    fread(*labels, sizeof(uint8_t), *num_images, file);

    fclose(file);
}

int main() {
    // Example usage of the load_mnist function
    char *filename = "mnist_data.bin";
    uint8_t *images;
    uint8_t *labels;
    uint32_t num_images;

    load_mnist(filename, &images, &labels, &num_images);

    // Add your code here to process the loaded MNIST data

    // Free the allocated memory
    free(images);
    free(labels);

    return 0;
}