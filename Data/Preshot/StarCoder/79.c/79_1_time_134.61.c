#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

void load_mnist_images(char *filename, uint8_t **images, uint32_t *num_images);
void print_images(uint8_t *images, uint32_t num_images);
void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels);
void print_labels(uint8_t *labels, uint32_t num_labels);
void print_idx_header_info(FILE *fp);
void flatten_images(uint8_t *images, float *flattened_images, uint32_t num_images, uint32_t num_rows, uint32_t num_cols);
void print_flattened_images(float *flattened_images, uint32_t num_images, uint32_t num_rows, uint32_t num_cols);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    uint8_t *data;
    uint32_t num_items;
    uint32_t magic_number;

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Print the IDX file header information
    print_idx_header_info(fp);

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

        // Read the number of rows and columns from the IDX file header
        uint32_t num_rows, num_cols;
        fseek(fp, 8, SEEK_SET);
        fread(&num_rows, sizeof(num_rows), 1, fp);
        fread(&num_cols, sizeof(num_cols), 1, fp);
        num_rows = ntohl(num_rows);
        num_cols = ntohl(num_cols);

        float *flattened_images = (float*)malloc(num_items * num_rows * num_cols * sizeof(float));
        flatten_images(data, flattened_images, num_items, num_rows, num_cols);
        print_flattened_images(flattened_images, num_items, num_rows, num_cols);

        free(data);
        free(flattened_images);
    } else if (magic_number == 2049) {
        // Labels file
        load_mnist_labels(filename, &data, &num_items);
        if (data == NULL) {
            printf("Error loading label data from file %s\n", filename);
            fclose(fp);
            return 1;
        }
        print_labels(data, num_items);
        free(data);
    } else {
        printf("Error: Magic number %u is not supported\n", magic_number);
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

void load_mnist_images(char *filename, uint8_t **images, uint32_t *num_images) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the magic number and number of items from the IDX file header
    uint32_t magic_number;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    magic_number = ntohl(magic_number);
    if (magic_number != 2051) {
        printf("Error: Magic number %u is not supported\n", magic_number);
        fclose(fp);
        return;
    }

    fread(num_images, sizeof(*num_images), 1, fp);
    *num_images = ntohl(*num_images);

    // Read the number of rows and columns from the IDX file header
    uint32_t num_rows, num_cols;
    fseek(fp, 8, SEEK_SET);
    fread(&num_rows, sizeof(num_rows), 1, fp);
    fread(&num_cols, sizeof(num_cols), 1, fp);
    num_rows = ntohl(num_rows);
    num_cols = ntohl(num_cols);

    // Allocate memory for the images
    *images = (uint8_t*)malloc(*num_images * num_rows * num_cols);

    // Read the images from the IDX file
    fread(*images, sizeof(uint8_t), *num_images * num_rows * num_cols, fp);

    fclose(fp);
}

void print_images(uint8_t *images, uint32_t num_images) {
    for (uint32_t i = 0; i < num_images; i++) {
        printf("%u ", images[i]);
        if (i % 28 == 27) {
            printf("\n");
        }
    }
    printf("\n");
}

void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the magic number and number of items from the IDX file header
    uint32_t magic_number;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    magic_number = ntohl(magic_number);
    if (magic_number != 2049) {
        printf("Error: Magic number %u is not supported\n", magic_number);
        fclose(fp);
        return;
    }

    fread(num_labels, sizeof(*num_labels), 1, fp);
    *num_labels = ntohl(*num_labels);

    // Allocate memory for the labels
    *labels = (uint8_t*)malloc(*num_labels);

    // Read the labels from the IDX file
    fread(*labels, sizeof(uint8_t), *num_labels, fp);

    fclose(fp);
}

void print_labels(uint8_t *labels, uint32_t num_labels) {
    for (uint32_t i = 0; i < num_labels; i++) {
        printf("%u ", labels[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
}