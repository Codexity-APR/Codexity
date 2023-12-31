#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // Function implementation goes here
}

int main() {
    // Test the load_mnist function
    uint8_t *images;
    uint8_t *labels;
    uint32_t num_images;

    load_mnist("mnist_data.txt", &images, &labels, &num_images);

    // Print the loaded data
    for (uint32_t i = 0; i < num_images; i++) {
        printf("Image %u:\n", i);
        for (uint32_t j = 0; j < 784; j++) {
            printf("%u ", images[i * 784 + j]);
        }
        printf("\nLabel: %u\n\n", labels[i]);
    }

    // Free the allocated memory
    free(images);
    free(labels);

    return 0;
}