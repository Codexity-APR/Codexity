#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

void load_mnist_images(char *filename, uint8_t **images, uint32_t *num_images);
void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels);
void print_images(uint8_t *images, uint32_t num_images);
void print_labels(uint8_t *labels, uint32_t num_labels);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    uint8_t *data = NULL;
    uint32_t num_items = 0;
    uint32_t magic_number = 0;

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Read the magic number and number of items from the IDX file header
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(&num_items, sizeof(num_items), 1, fp);
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
        printf("Error: Invalid magic number %d\n", magic_number);
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

void load_mnist_images(char *filename, uint8_t **images, uint32_t *num_images) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the magic number and number of items from the IDX file header
    uint32_t magic_number = 0;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(num_images, sizeof(*num_images), 1, fp);
    magic_number = ntohl(magic_number);
    *num_images = ntohl(*num_images);

    // Check the magic number and ensure it is an images file
    if (magic_number != 2051) {
        printf("Error: Invalid magic number %u\n", magic_number);
        fclose(fp);
        return;
    }

    // Read the number of rows and columns from the IDX file header
    uint32_t num_rows = 0;
    uint32_t num_cols = 0;
    fread(&num_rows, sizeof(num_rows), 1, fp);
    fread(&num_cols, sizeof(num_cols), 1, fp);
    num_rows = ntohl(num_rows);
    num_cols = ntohl(num_cols);

    // Ensure the number of rows and columns are 28 and 28
    if (num_rows != 28 || num_cols != 28) {
        printf("Error: Invalid number of rows or columns %u x %u\n", num_rows, num_cols);
        fclose(fp);
        return;
    }

    // Allocate memory for the images
    *images = (uint8_t *) malloc(sizeof(uint8_t) * (*num_images * num_rows * num_cols));
    if (!*images) {
        printf("Error: Could not allocate memory for images\n");
        fclose(fp);
        return;
    }

    // Read the images from the IDX file
    fread(*images, sizeof(uint8_t), *num_images * num_rows * num_cols, fp);

    // Close the IDX file
    fclose(fp);
}

void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the magic number and number of items from the IDX file header
    uint32_t magic_number = 0;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(num_labels, sizeof(*num_labels), 1, fp);
    magic_number = ntohl(magic_number);
    *num_labels = ntohl(*num_labels);

    // Check the magic number and ensure it is a labels file
    if (magic_number != 2049) {
        printf("Error: Invalid magic number %u\n", magic_number);
        fclose(fp);
        return;
    }

    // Allocate memory for the labels
    *labels = (uint8_t *) malloc(sizeof(uint8_t) * (*num_labels));
    if (!*labels) {
        printf("Error: Could not allocate memory for labels\n");
        fclose(fp);
        return;
    }