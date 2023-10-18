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

  // Copy the chosen word into the 'word' array
  strcpy(word, word_list[word_index]);

  // Get the length of the word
  word_length = strlen(word);

  // Initialize the 'guessed_letters' array with '_' for each letter of the word
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';  // Null-terminate the 'guessed_letters' string

  // Game loop
  while (num_guesses < MAX_ATTEMPTS && num_incorrect_guesses < word_length) {
    // Print the current state of the word
    printf("Word: %s\n", guessed_letters);
    printf("Enter a letter: ");

    // TODO: Complete the game logic here

    num_guesses++;
  }

  // Print the final result
  if (num_incorrect_guesses == word_length) {
    printf("You lost! The word was: %s\n", word);
  } else {
    printf("Congratulations! You guessed the word: %s\n", word);
  }

  return 0;
}