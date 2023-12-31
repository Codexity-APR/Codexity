#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define MAX_WORD_LENGTH 20

int main() {
  char word[MAX_WORD_LENGTH + 1];
  char guessed_letters[MAX_WORD_LENGTH] = {0}; // Initialize guessed_letters array to 0
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

  // Copy the chosen word into the word array
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);

  // Ensure that the word array is null-terminated
  word[MAX_WORD_LENGTH] = '\0';

  // Loop until the player guesses the word or runs out of guesses
  while (num_guesses < MAX_ATTEMPTS && num_incorrect_guesses < word_length) {
    // Print the current state of the game
    printf("Guessed letters: %s\n", guessed_letters);
    printf("Incorrect guesses: %d\n", num_incorrect_guesses);
    printf("Guesses left: %d\n", MAX_ATTEMPTS - num_guesses);
    printf("Word: ");
    for (i = 0; i < word_length; i++) {
      if (guessed_letters[i] == '\0') {
        printf("_ ");
      } else {
        printf("%c ", guessed_letters[i]);
      }
    }
    printf("\n");

    // Get the next guess from the player
    printf("Guess a letter: ");
    char guess;
    scanf(" %c", &guess);
    guess = tolower(guess);

    // Check if the guess is correct
    if (strchr(word, guess) != NULL) {
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
  printf("Guessed letters: %s\n", guessed_letters);
  printf("Incorrect guesses: %d\n", num_incorrect_guesses);
  printf("Guesses left: %d\n", MAX_ATTEMPTS - num_guesses);
  printf("Word: ");
  for (i = 0; i < word_length; i++) {
    if (guessed_letters[i] == '\0') {
      printf("_ ");
    } else {
      printf("%c ", guessed_letters[i]);
    }
  }
  printf("\n");

  // Check if the player won or lost
  if (num_guesses == MAX_ATTEMPTS) {
    printf("You lost.\n");
  } else {
    printf("You won.\n");
  }

  return 0;
}