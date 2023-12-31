#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

void load_mnist_images(char *filename, uint8_t **images, uint32_t *num_images);
void print_images(uint8_t *images, uint32_t num_images);
void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels);
void print_labels(uint8_t *labels, uint32_t num_labels);
void print_idx_header_info(FILE *fp);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    uint8_t *data = NULL;
    uint32_t num_items = 0;
    uint32_t magic_number = 0;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Print the IDX file header information
    print_idx_header_info(fp);

    // Read the magic number and number of items from the IDX file header
    if (fread(&magic_number, sizeof(magic_number), 1, fp) != 1) {
        fprintf(stderr, "Error reading magic number from file %s\n", filename);
        fclose(fp);
        return EXIT_FAILURE;
    }
    if (fread(&num_items, sizeof(num_items), 1, fp) != 1) {
        fprintf(stderr, "Error reading number of items from file %s\n", filename);
        fclose(fp);
        return EXIT_FAILURE;
    }
    magic_number = ntohl(magic_number);
    num_items = ntohl(num_items);

    // Load either the image or label data, depending on the magic number
    if (magic_number == 2051) {
        // Images file
        load_mnist_images(filename, &data, &num_items);
        print_images(data, num_items);
        free(data);
    } else if (magic_number == 2049) {
        // Labels file
        load_mnist_labels(filename, &data, &num_items);
        print_labels(data, num_items);
        free(data);
    } else {
        fprintf(stderr, "Error: unknown magic number %u\n", magic_number);
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(fp);
    return EXIT_SUCCESS;
}