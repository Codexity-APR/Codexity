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
    uint8_t *data = NULL;
    uint32_t num_items = 0;
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
        printf("Error: Magic number is not 2049 or 2051\n");
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
    uint32_t magic_number;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(num_images, sizeof(*num_images), 1, fp);
    magic_number = ntohl(magic_number);
    *num_images = ntohl(*num_images);

    // Check the magic number and number of items
    if (magic_number!= 2051) {
        printf("Error: Magic number is not 2051\n");
        fclose(fp);
        return;
    }

    // Allocate memory for the images
    *images = (uint8_t *) malloc(*num_images * 28 * 28);
    if (!*images) {
        printf("Error: Could not allocate memory for images\n");
        fclose(fp);
        return;
    }

    // Read the images from the IDX file
    fread(*images, sizeof(uint8_t), *num_images * 28 * 28, fp);

    // Convert from big-endian to little-endian
    uint32_t i;
    for (i = 0; i < *num_images * 28 * 28; i++) {
        (*images)[i] = ntohl((*images)[i]);
    }

    fclose(fp);
}

void print_images(uint8_t *images, uint32_t num_images) {
    uint32_t i, j, k;
    for (i = 0; i < num_images; i++) {
        for (j = 0; j < 28; j++) {
            for (k = 0; k < 28; k++) {
                printf("%c", images[i * 28 * 28 + j * 28 + k]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

void load_mnist_labels(char *filename, uint8_t **labels, uint32_t *num_labels) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the magic number and number of items from the IDX file header
    uint32_t magic_number;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(num_labels, sizeof(*num_labels), 1, fp);
    magic_number = ntohl(magic_number);
    *num_labels = ntohl(*num_labels);

    // Check the magic number and number of items
    if (magic_number!= 2049) {
        printf("Error: Magic number is not 2049\n");
        fclose(fp);
        return;
    }

    // Allocate memory for the labels
    *labels = (uint8_t *) malloc(*num_labels);
    if (!*labels) {
        printf("Error: Could not allocate memory for labels\n");
        fclose(fp);
        return;
    }

    // Read the labels from the IDX file
    fread(*labels, sizeof(uint8_t), *num_labels, fp);

    // Convert from big-endian to little-endian
    uint32_t i;
    for (i = 0; i < *num_labels; i++) {
        (*labels)[i] = ntohl((*labels)[i]);
    }

    fclose(fp);
}

void print_labels(uint8_t *labels, uint32_t num_labels) {
    uint32_t i;
    for (i = 0; i < num_labels; i++) {
        printf("%d ", labels[i]);
    }
    printf("\n");
}

void print_idx_header_info(FILE *fp) {
    uint32_t magic_number;
    uint32_t num_items;
    fread(&magic_number, sizeof(magic_number), 1, fp);
    fread(&num_items, sizeof(num_items), 1, fp);
    magic_number = ntohl(magic_number);
    num_items = ntohl(num_items);
    printf("Magic number: %d\n", magic_number);
    printf("Number of items: %d\n", num_items);
}