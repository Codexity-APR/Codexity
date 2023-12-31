#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

int main() {
  char word[MAX_WORD_LENGTH + 1];
  char guessed_letters[MAX_WORD_LENGTH] = {0}; // Initialize guessed_letters to zeros
  int num_guesses = 0;
  int num_incorrect_guesses = 0;
  int word_length;
  int i;

  // List of words to choose from
  const char *word_list[] = {
    "apple",
    "banana",
    "cherry",
    "orange",
    "pear",
    "watermelon"
  };
  const int num_words = sizeof(word_list) / sizeof(word_list[0]);

  // Seed the random number generator with the current time
  srand(time(NULL));

  // Choose a random word from the list
  const int word_index = rand() % num_words;

#ifdef DEBUG
  printf("The word is: %s\n", word_list[word_index]);
#endif

  // Get the length of the word
  word_length = strlen(word_list[word_index]);
  if (word_length > MAX_WORD_LENGTH) {
    fprintf(stderr, "Word length is too long.\n");
    exit(EXIT_FAILURE);
  }

  // Loop until the player guesses the word or runs out of guesses
  while (num_guesses < MAX_ATTEMPTS && num_incorrect_guesses < word_length) {
    // Print the current state of the game
    printf("Guessed letters: ");
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] != 0) {
        printf("%c ", guessed_letters[i]);
      } else {
        printf("_ ");
      }
    }
    printf("\n");
    printf("Incorrect guesses: %d\n", num_incorrect_guesses);
    printf("Guesses left: %d\n", MAX_ATTEMPTS - num_guesses);

    // Get the next guess from the player
    printf("Guess a letter: ");
    char guess;
    if (scanf(" %c", &guess) != 1) {
      fprintf(stderr, "Invalid input.\n");
      exit(EXIT_FAILURE);
    }
    guess = tolower(guess);

    // Check if the guess is correct
    if (strchr(word_list[word_index], guess) != NULL) {
      // Check if the letter has already been guessed
      if (strchr(guessed_letters, guess) == NULL) {
        // Add the letter to the list of guessed letters
        guessed_letters[num_guesses] = guess;
        num_guesses++;
      }
    } else {
      // The guess is incorrect
      num_incorrect_guesses++;
    }
  }

  // Print the final state of the game
  printf("Guessed letters: ");
  for (i = 0; i < word_length; i++) {
    if (guessed_letters[i] != 0) {
      printf("%c ", guessed_letters[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
  printf("Incorrect guesses: %d\n", num_incorrect_guesses);
  printf("Guesses left: %d\n", MAX_ATTEMPTS - num_guesses);

  // Check if the player won or lost
  if (num_guesses == MAX_ATTEMPTS) {
    printf("You lost. The word was: %s\n", word_list[word_index]);
  } else {
    printf("You won!\n");
  }

  return 0;
}