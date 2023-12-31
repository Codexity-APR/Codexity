#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    // Read the MNIST file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file");
        return;
    }
    
    // Read the magic number
    uint32_t magic_number;
    fread(&magic_number, sizeof(uint32_t), 1, file);
    magic_number = ntohl(magic_number);
    
    // Read the number of images
    fread(num_images, sizeof(uint32_t), 1, file);
    *num_images = ntohl(*num_images);
    
    // Allocate memory for the images and labels
    *images = (uint8_t *)malloc(*num_images * 28 * 28);
    *labels = (uint8_t *)malloc(*num_images);
    
    // Read the images and labels
    fread(*images, 28 * 28, *num_images, file);
    fread(*labels, 1, *num_images, file);
    
    // Close the file
    fclose(file);
}

int main() {
    // Example usage of the load_mnist function
    uint8_t *images;
    uint8_t *labels;
    uint32_t num_images;
    
    load_mnist("mnist_data.bin", &images, &labels, &num_images);
    
    // Do something with the images and labels
    
    // Free the allocated memory
    free(images);
    free(labels);
    
    return 0;
}