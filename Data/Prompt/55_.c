
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
