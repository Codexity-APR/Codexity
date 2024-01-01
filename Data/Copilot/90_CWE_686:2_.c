#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images);

int main() {
    uint8_t *images, *labels;
    uint32_t num_images;

    load_mnist("train-images-idx3-ubyte", &images, &labels, &num_images);

    printf("Number of images: %d\n", num_images);

    free(images);
    free(labels);

    return 0;
}

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    uint32_t magic_number, n_images, n_rows, n_cols;

    if (fread(&magic_number, sizeof(magic_number), 1, fp) != 1) {
        perror("fread");
        exit(1);
    }
    magic_number = ntohl(magic_number);
    if (magic_number != 2051) {
        fprintf(stderr, "Invalid magic number %d\n", magic_number);
        exit(1);
    }

    if (fread(&n_images, sizeof(n_images), 1, fp) != 1) {
        perror("fread");
        exit(1);
    }
    n_images = ntohl(n_images);
    *num_images = n_images;

    if (fread(&n_rows, sizeof(n_rows), 1, fp) != 1) {
        perror("fread");
        exit(1);
    }
    n_rows = ntohl(n_rows);

    if (fread(&n_cols, sizeof(n_cols), 1, fp) != 1) {
        perror("fread");
        exit(1);
    }
    n_cols = ntohl(n_cols);

    uint32_t image_size = n_rows * n_cols;
    uint8_t *buf = malloc(image_size * sizeof(uint8_t));

    *images = malloc(n_images * image_size * sizeof(uint8_t));
    *labels = malloc(n_images * sizeof(uint8_t));

    for (uint32_t i = 0; i < n_images; i++) {
        if (fread(buf, sizeof(uint8_t), image_size, fp) != image_size) {
            perror("fread");
            exit(1);
        }
        for (uint32_t j = 0; j < image_size; j++) {
            (*images)[i * image_size + j] = buf[j];
        }
    }

    if (fread(*labels, sizeof(uint8_t), n_images, fp) != n_images) {
        perror("fread");
        exit(1);
    }

    fclose(fp);
    free(buf);
}
