#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images);

int main(int argc, char **argv) {
    uint8_t *images = NULL;
    uint8_t *labels = NULL;
    uint32_t num_images = 0;

    load_mnist("data/train-images.idx3-ubyte", &images, &labels, &num_images);

    printf("Loaded %" PRIu32 " images\n", num_images);

    free(images);
    free(labels);

    return 0;
}

void load_mnist(char *filename, uint8_t **images, uint8_t **labels, uint32_t *num_images) {
    FILE *fp_images, *fp_labels;
    uint32_t magic_images, magic_labels;
    uint32_t num_images_, num_labels;
    uint32_t nrows, ncols;
    uint8_t *buf_images, *buf_labels;

    fp_images = fopen(filename, "rb");
    if (!fp_images) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(-1);
    }

    fread(&magic_images, sizeof(magic_images), 1, fp_images);
    magic_images = ntohl(magic_images);
    if (magic_images != 2051) {
        fprintf(stderr, "Invalid magic number found in %s\n", filename);
        exit(-1);
    }

    fread(&num_images_, sizeof(num_images_), 1, fp_images);
    num_images_ = ntohl(num_images_);
    *num_images = num_images_;

    fread(&nrows, sizeof(nrows), 1, fp_images);
    nrows = ntohl(nrows);

    fread(&ncols, sizeof(ncols), 1, fp_images);
    ncols = ntohl(ncols);

    buf_images = malloc(num_images_ * nrows * ncols * sizeof(uint8_t));
    if (!buf_images) {
        fprintf(stderr, "Failed to allocate memory for images\n");
        exit(-1);
    }

    for (int i = 0; i < num_images_; i++) {
        fread(buf_images + i * nrows * ncols, sizeof(uint8_t), nrows * ncols, fp_images);
    }

    *images = buf_images;

    fclose(fp_images);

    fp_labels = fopen("data/train-labels.idx1-ubyte", "rb");
    if (!fp_labels) {
        fprintf(stderr, "Failed to open file %s\n", "data/train-labels.idx1-ubyte");
        exit(-1);
    }

    fread(&magic_labels, sizeof(magic_labels), 1, fp_labels);
    magic_labels = ntohl(magic_labels);
    if (magic_labels != 2049) {
        fprintf(stderr, "Invalid magic number found in %s\n", "data/train-labels.idx1-ubyte");
        exit(-1);
    }

    fread(&num_labels, sizeof(num_labels), 1, fp_labels);
    num_labels = ntohl(num_labels);
    if (num_labels != num_images_) {
        fprintf(stderr, "Number of labels does not match number of images\n");
        exit(-1);
    }

    buf_labels = malloc(num_labels * sizeof(uint8_t));
    if (!buf_labels) {
        fprintf(stderr, "Failed to allocate memory for labels\n");
        exit(-1);
    }

    fread(buf_labels, sizeof(uint8_t), num_labels, fp_labels);

    *labels = buf_labels;

    fclose(fp_labels);
}