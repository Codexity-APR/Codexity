#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

void draw_hangman(int num_incorrect_guesses) {
  printf("   +----+\n");
  printf("   |    |\n");
  printf("   |    %c\n", num_incorrect_guesses >= 1 ? 'O' : ' ');
  printf("   |   %c%c%c\n", num_incorrect_guesses >= 3 ? '/' : ' ', num_incorrect_guesses >= 2 ? '|' : ' ', num_incorrect_guesses >= 4 ? '\\' : ' ');
  printf("   |   %c %c\n", num_incorrect_guesses >= 5 ? '/' : ' ', num_incorrect_guesses >= 6 ? '\\' : ' ');
  printf("=======\n");
}

int main() {
  char word[MAX_WORD_LENGTH + 1];
  char guessed_letters[MAX_WORD_LENGTH];
  int num_guesses = 0;
  int num_incorrect_guesses = 0;
  int word_length;
  int i;

  // List of words to choose from
  char *word_list[] = {
    "apple",
    "banana",
    "cherry",
    "orange",
    "pear",
    "watermelon"
  };
  int num_words = sizeof(word_list) / sizeof(word_list[0]);

  // Seed the random number generator with the current time
  srand(time(NULL));

  // Choose a random word from the list
  int word_index = rand() % num_words;

  // Open file
  char *filename = "file.txt";
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  // Read the magic number and number of items from the IDX file header
  uint32_t magic_number;
  uint32_t num_items;

  fread(&magic_number, sizeof(magic_number), 1, fp);
  fread(&num_items, sizeof(num_items), 1, fp);
  magic_number = ntohl(magic_number);
  num_items = ntohl(num_items);

  // Load either the image or label data, depending on the magic number
  if (magic_number == 2051) {
    // Images file
    uint8_t *data;
    load_mnist_images(filename, &data, &num_items);
    print_images(data, num_items);
    free(data);
  } else if (magic_number == 2049) {
    // Labels file
    uint8_t *data;
    load_mnist_labels(filename, &data, &num_items);
    print_labels(data, num_items);
    free(data);
  } else {
    printf("Error: unknown magic number %u\n", magic_number);
    fclose(fp);
    return 1;
  }

  fclose(fp);

  return 0;
}