#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_FILENAME_LENGTH 256

void load_mnist_images(const char *filename, uint8_t **images, uint32_t *num_images);
void print_images(uint8_t *images, uint32_t num_images);
void load_mnist_labels(const char *filename, uint8_t **labels, uint32_t *num_labels);
void print_labels(uint8_t *labels, uint32_t num_labels);
void print_idx_header_info(FILE *fp);
void flatten_images(uint8_t *images, float *flattened_images, uint32_t num_images, uint32_t num_rows, uint32_t num_cols);
void print_flattened_images(float *flattened_images, uint32_t num_images, uint32_t num_rows, uint32_t num_cols);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILENAME_LENGTH];
    strncpy(filename, argv[1], MAX_FILENAME_LENGTH - 1);
    filename[MAX_FILENAME_LENGTH - 1] = '\0';

    uint8_t *data;
    uint32_t num_items;
    uint32_t magic_number;

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
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
        print_labels(data, num_items);
        free(data);
    } else {
        printf("Error: unknown magic number %u\n", magic_number);
        fclose(fp);
        return 1;
    }

    // Close the IDX file
    fclose(fp);

    return 0;
}

void load_mnist_images(const char *filename, uint8_t **images, uint32_t *num_images) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Seek past the IDX file header
    fseek(fp, 16, SEEK_SET);

    // Allocate memory for the image data
    *images = (uint8_t*)malloc(*num_images * 28 * 28 * sizeof(uint8_t));

    // Read in the image data
    fread(*images, 1, *num_images * 28 * 28, fp);

    // Close the file
    fclose(fp);
}

void print_images(uint8_t *images, uint32_t num_images) {
    printf("%u images:\n", num_images);
    for (uint32_t i = 0; i < num_images; i++) {
        printf("Image %u:\n", i + 1);
        for (uint32_t j = 0; j < 28; j++) {
            for (uint32_t k = 0; k < 28; k++) {
                printf("%u ", images[i * 28 * 28 + j * 28 + k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void load_mnist_labels(const char *filename, uint8_t **labels, uint32_t *num_labels) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Seek past the IDX file header
    fseek(fp, 8, SEEK_SET);

    // Allocate memory for the label data
    *labels = (uint8_t*)malloc(*num_labels * sizeof(uint8_t));

    // Read in the label data
    fread(*labels, 1, *num_labels, fp);

    // Close the file
    fclose(fp);
}

void print_labels(uint8_t *labels, uint32_t num_labels) {
    printf("%u labels:\n", num_labels);
    for (uint32_t i = 0; i < num_labels; i++) {
        printf("%u ", labels[i]);
    }
    printf("\n");
}

void print_idx_header_info(FILE *fp) {
    uint32_t magic_number, num_items, num_rows, num_cols;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(&num_items, sizeof(num_items), 1, fp);
    magic_number = ntohl(magic_number);
    num_items = ntohl(num_items);
    if (magic_number == 2051) {  // Images file
        fread(&num_rows, sizeof(num_rows), 1, fp);
        fread(&num_cols, sizeof(num_cols), 1, fp);
        num_rows = ntohl(num_rows);
        num_cols = ntohl(num_cols);
        printf("Images file:\n");
        printf("Magic number: %u\n", magic_number);
        printf("Number of images: %u\n", num_items);
        printf("Number of rows: %u\n", num_rows);
        printf("Number of columns: %u\n", num_cols);
    } else if (magic_number == 2049) {  // Labels file
        printf("Labels file:\n");
        printf("Magic number: %u\n", magic_number);
        printf("Number of labels: %u\n", num_items);
    } else {
        printf("Unknown file format: magic number %u\n", magic_number);
    }
}

void flatten_images(uint8_t *images, float *flattened_images, uint32_t num_images, uint32_t num_rows, uint32_t num_cols) {
    for (uint32_t i = 0; i < num_images; i++) {
        for (uint32_t j = 0; j < num_rows; j++) {
            for (uint32_t k = 0; k < num_cols; k++) {
                flattened_images[i * num_rows * num_cols + j * num_cols + k] = (float)images[i * num_rows * num_cols + j * num_cols + k] / 255.0f;
            }
        }
    }
}

void print_flattened_images(float *flattened_images, uint32_t num_images, uint32_t num_rows, uint32_t num_cols) {
    printf("%u flattened images:\n", num_images);
    for (uint32_t i = 0; i < num_images; i++) {
        printf("Image %u:\n", i + 1);
        for (uint32_t j = 0; j < num_rows; j++) {
            for (uint32_t k = 0; k < num_cols; k++) {
                printf("%0.2f ", flattened_images[i * num_rows * num_cols + j * num_cols + k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}