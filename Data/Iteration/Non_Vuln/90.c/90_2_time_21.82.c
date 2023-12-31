#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // Load MNIST data from file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Read the number of images
    uint32_t magic_number;
    fread(&magic_number, sizeof(magic_number), 1, file);
    *num_images = ntohl(magic_number);

    // Allocate memory for images and labels
    *images = (uint8_t *)malloc(*num_images * 28 * 28);
    *labels = (uint8_t *)malloc(*num_images);
    
    // Read the images
    fread(*images, 28 * 28, *num_images, file);
    
    // Read the labels
    fread(*labels, 1, *num_images, file);
    
    // Close the file
    fclose(file);
}