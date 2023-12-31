#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

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

#ifdef __cplusplus
  // Ensure that the random number generator is seeded with the current time
  // before generating the next word.
  srand(time(NULL));
#endif

  // Generate a random word
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    word[i] = word_list[word_index];
    word_index = (word_index + 1) % num_words;
  }

  // Print the word
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", word[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }
  printf("\n");

  // Generate a random guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    guesseed_letters[i] = word[i];
  }

  // Print the guess
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%c ", guesseed_letters[i]);
  }}