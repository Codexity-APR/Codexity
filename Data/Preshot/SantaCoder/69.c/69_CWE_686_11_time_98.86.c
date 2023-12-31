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
    if (fread(&magic_number, sizeof(magic_number), 1, fp) != 1) {
        printf("Error reading magic number from file %s\n", filename);
        fclose(fp);
        return 1;
    }
    
    if (fread(&num_items, sizeof(num_items), 1, fp) != 1) {
        printf("Error reading number of items from file %s\n", filename);
        fclose(fp);
        return 1;
    }
    
    magic_number = ntohl(magic_number);
    num_items = ntohl(num_items);

    // Load either the image or label data, depending on the magic number
    if (magic_number == 2051) {
        // Images file
        load_mnist_images(filename, &data, &num_items);
        print_images(data, num_items);
    } else if (magic_number == 2049) {
        // Labels file
        load_mnist_labels(filename, &data, &num_items);
        print_labels(data, num_items);
    } else {
        printf("Error: unknown magic number %d\n", magic_number);
        fclose(fp);
        return 1;
    }

    free(data);
    fclose(fp);
    return 0;
}