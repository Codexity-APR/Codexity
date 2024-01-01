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
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
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
        free(data);
    } else if (magic_number == 2049) {
        // Labels file
        load_mnist_labels(filename, &data, &num_items);
        print_labels(data, num_items);
        free(data);
    } else {
        printf("Invalid magic number %d\n", magic_number);
        return 1;
    }

    fclose(fp);
    return 0;
}

void load_mnist_images(char *filename, uint8_t **images, uint32_t *num_images) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Skip the magic number and number of images
    fseek(fp, 16, SEEK_SET);

    // Allocate memory for the image data
    *images = (uint8_t *) malloc((*num_images) * 784);
    if (!*images) {
        printf("Error allocating memory for image data\n");
        exit(1);
    }

    // Read the image data
    fread(*images, 784, *num_images, fp);

    fclose(fp);
}

void print_images(uint8_t *images, uint32_t num_images) {
    for (int i = 0; i < num_images; i++) {
        printf("Image %d:\n", i + 1);
        for (int j = 0; j < 28; j++) {
            for (int k = 0; k < 28; k++) {
                printf("%3d ", images[i * 784 + j * 28 + k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Skip the magic number and number of labels
    fseek(fp, 8, SEEK_SET);

    // Allocate memory for the label data
    *labels = (uint8_t *) malloc(*num_labels);
    if (!*labels) {
        printf("Error allocating memory for label data\n");
        exit(1);
    }

    // Read the label data
    fread(*labels, 1, *num_labels, fp);

    fclose(fp);
}

void print_labels(uint8_t *labels, uint32_t num_labels) {
    for (int i = 0; i < num_labels; i++) {
        printf("Label %d: %d\n", i + 1, labels[i]);
    }
}

void print_idx_header_info(FILE *fp) {
    uint32_t magic_number;
    uint32_t num_items;
    uint32_t num_rows;
    uint32_t num_cols;

    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(&num_items, sizeof(num_items), 1, fp);
    magic_number = ntohl(magic_number);
    num_items = ntohl(num_items);

    if (magic_number == 2051) {
        // Images file
        fread(&num_rows, sizeof(num_rows), 1, fp);
        fread(&num_cols, sizeof(num_cols), 1, fp);
        num_rows = ntohl(num_rows);
        num_cols = ntohl(num_cols);

        printf("Magic number: %d\n", magic_number);
        printf("Number of images: %d\n", num_items);
        printf("Image dimensions: %d x %d\n", num_rows, num_cols);
    } else if (magic_number == 2049) {
        // Labels file
        printf("Magic number: %d\n", magic_number);
        printf("Number of labels: %d\n", num_items);
    } else {
        printf("Invalid magic number %d\n", magic_number);
        exit(1);
    }
}
