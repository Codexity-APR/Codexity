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

  // Copy the chosen word to 'word' array
  strncpy(word, word_list[word_index], MAX_WORD_LENGTH);
  word[MAX_WORD_LENGTH] = '\0';

  // Get the length of the chosen word
  word_length = strlen(word);

  // Initialize the guessed_letters array with empty spaces
  for (i = 0; i < word_length; i++) {
    guessed_letters[i] = '_';
  }
  guessed_letters[word_length] = '\0';

  // Main game loop
  while (num_incorrect_guesses < MAX_ATTEMPTS) {
    char guess;

    // Print the current state of the word
    printf("Word: %s\n", guessed_letters);

    // Prompt for a letter guess
    printf("Guess a letter: ");
    scanf(" %c", &guess);

    // Check if the guessed letter is in the word
    int found = 0;
    for (i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        guessed_letters[i] = guess;
        found = 1;
      }
    }

    // Update the number of guesses
    num_guesses++;

    // Check if the guessed letter was incorrect
    if (!found) {
      num_incorrect_guesses++;
      printf("Incorrect guess! Attempts remaining: %d\n", MAX_ATTEMPTS - num_incorrect_guesses);
    }

    // Check if the word has been fully guessed
    if (strcmp(word, guessed_letters) == 0) {
      printf("Congratulations! You guessed the word '%s' in %d attempts.\n", word, num_guesses);
      break;
    }
  }

  // Check if the game was lost
  if (num_incorrect_guesses == MAX_ATTEMPTS) {
    printf("You lost! The word was '%s'. Better luck next time!\n", word);
  }

  return 0;
}