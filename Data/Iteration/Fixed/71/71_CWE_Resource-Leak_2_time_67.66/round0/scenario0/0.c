List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `fopen()` at line 23, column 16 is not released after line 50, column 46.
 Example: 
  48.         free(data);
  49.     } else {
  50.         printf("Invalid magic number: %u\n", magic_number);
                                                   ^
  51.         return 1;
  52.     }


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
        printf("Invalid magic number: %u\n", magic_number);
        return 1;
    }
    fclose(fp);
    return 0;
}